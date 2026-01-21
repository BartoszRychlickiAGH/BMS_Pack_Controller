/**
  ******************************************************************************
  * @file    pcb_cells.c
  * @author  Bartosz Rychlicki
  * @author  AGH Eko-Energia

  * @Title   Firmware for Cells' PCBs boards
  *

  * @brief   This file contains functions' bodies, whose implement workflow logic
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 AGH Eko-Energia.
  * All rights reserved.
  *
  ******************************************************************************
*/

/* Includes -----------------------------------------------------------------------------------  */
#include "pcb_cells.h"
#include "pcb_cells_can.h"
#include "pcb_cells_adc.h"

/* Variables ----------------------------------------------------------------------------------  */
static uint32_t lastTick; 		// static tick variable for providing LEDs blinking

/* Functions' bodies --------------------------------------------------------------------------  */

HAL_StatusTypeDef PCBCells_Init(PCBCells_TypeDef* pc, ADC_HandleTypeDef* hadc1, ADC_HandleTypeDef* hadc2, CAN_HandleTypeDef* hcan){

	// Assigning peripherals' handles to PCBCells' objects
	pc->pcadc.hadc1 = *hadc1;
	pc->pcadc.hadc2 = *hadc2;
	pc->pccan.hcan  = *hcan;

	// Setting default status
	pc->prevStatus = PCBCELLS_ACTIVE;
	pc->currStatus = PCBCELLS_ACTIVE;

	// Reseting buffers
	memset(pc->pcadc.PCBCells_temperatures, 0, sizeof(pc->pcadc.PCBCells_temperatures));

	// Reading PCB Index
	if(PCBCells_ConfigPCBIndex(pc) != HAL_OK){
		return HAL_ERROR;
	}

	// Init ADC1
	if(ADC_Init(&pc->pcadc.hadc1, &pc->pcadc.badc1, &pc->pcadc.cadc1) != HAL_OK){
		return HAL_ERROR;
	}


	// Init ADC2
	if(ADC_Init(&pc->pcadc.hadc2, &pc->pcadc.badc2, &pc->pcadc.cadc2) != HAL_OK){
		return HAL_ERROR;
	}

	// Init dual mode conversion for ADC1 and ADC2
	if(ADC_InitMultimode(&pc->pcadc.hadc1, &pc->pcadc.badc1) != HAL_OK){
		return HAL_ERROR;
	}

	// Adding frames to CAN buffer
	if(PCBCells_CAN_InitFrames(pc) != HAL_OK){
		return HAL_ERROR;
	}

	//Init CAN
	CAN_Init(&pc->pccan.hcan);

	// Check if can was properly initialized
	if(pc->pccan.hcan.Instance != CAN){
		return HAL_ERROR;
	}

	// Starting the rest peripherals
	if(PCBCells_Peripherals_Start(pc) != HAL_OK){
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_Mode_Normal(PCBCells_TypeDef* pc){

	// check if change of status occurred
	if(pc->prevStatus != PCBCELLS_ACTIVE){

		// start peripherals
		if(PCBCells_Peripherals_Start(pc) != HAL_OK){
			return HAL_ERROR;
		}

		// restore pervStatus flag to prevent multi start of peripherals
		pc->prevStatus = PCBCELLS_ACTIVE;

	}

	// Read Channels of ADC
	if(PCBCells_ADC_ReadValues(pc) != HAL_OK){
		return HAL_ERROR;
	}

	// Send Data via CAN
	if(PCBCells_CAN_SendFrames(pc) != HAL_OK){
		return HAL_ERROR;
	}

	return HAL_OK;
}


HAL_StatusTypeDef PCBCells_Mode_Error(PCBCells_TypeDef* pc){

	/*
	 * Under constructions
	 */

	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_Peripherals_Start(PCBCells_TypeDef* pc){

	// Starting ADC1
	if(HAL_ADC_Start(&pc->pcadc.hadc1) != HAL_OK){
		return HAL_ERROR;
	}

	// Starting ADC2
	if(HAL_ADC_Start(&pc->pcadc.hadc2) != HAL_OK){
		return HAL_ERROR;
	}

	// Launching Dual Mode Conversion
	if(HAL_ADCEx_MultiModeStart_DMA(&pc->pcadc.hadc1, (uint32_t*)pc->pcadc.badc1.ddma.BufferADC_Master, ADC_MAX_CHANNELS) != HAL_OK){
		return HAL_ERROR;
	}


	// Starting CAN
	if(HAL_CAN_Start(&pc->pccan.hcan) != HAL_OK){
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_Peripherals_Stop(PCBCells_TypeDef* pc){
	// Terminating ADC1
	if(HAL_ADC_Stop(&pc->pcadc.hadc1) != HAL_OK){
		return HAL_ERROR;
	}

	// Terminating ADC2
	if(HAL_ADC_Stop(&pc->pcadc.hadc2) != HAL_OK){
		return HAL_ERROR;
	}

	// Terminating Dual Mode Conversion
	if(HAL_ADCEx_MultiModeStop_DMA(&pc->pcadc.hadc1) != HAL_OK){
		return HAL_ERROR;
	}


	// Terminating CAN
	if(HAL_CAN_Stop(&pc->pccan.hcan) != HAL_OK){
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_ConfigPCBIndex(PCBCells_TypeDef* pc){

	uint8_t index = 0;

	// Reading index, if resistor is soldered on PCB board, then he pulls to GND, otherwise software set pull-up resistor pulls to 3V3
	index = (!HAL_GPIO_ReadPin(R1_GPIO_Port, R1_Pin) << 2) |
			(!HAL_GPIO_ReadPin(R2_GPIO_Port, R2_Pin) << 1) |
			 !HAL_GPIO_ReadPin(R3_GPIO_Port, R3_Pin);

	// checking if index is in correct range
	if(index > 7 || index < 1){
		return HAL_ERROR;
	}

	// assign index to PCBCells field
	pc->packetIndex = index;

	return HAL_OK;
}


HAL_StatusTypeDef PCBCells_Mode_Change(PCBCells_TypeDef* pc, PCBCells_StatusTypeDef_e status){

	// checking if given mode is correct
	if(status != PCBCELLS_ACTIVE && status != PCBCELLS_ERROR){
		return HAL_ERROR;
	}

	// saving previous status
	pc->prevStatus = pc->currStatus;

	// changing current status
	pc->currStatus = status;

	return HAL_OK;
}

void PCBCells_Mode_Blink(PCBCells_TypeDef* pc){

	lastTick = HAL_GetTick();

	if((HAL_GetTick() - lastTick -1) >= 500){

		switch(pc->currStatus){
			case PCBCELLS_ACTIVE:

				// toggling LED state after 250ms
				HAL_GPIO_TogglePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin);

				// Turning off RED LED
				HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);

				break;
			case PCBCELLS_ERROR:

				// Turning off Green LED
				HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);

				// Turning on RED LED
				HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);

				break;
		}

		lastTick = HAL_GetTick() - 1;
	}
}



