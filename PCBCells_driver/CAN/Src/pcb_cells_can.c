/**
  ******************************************************************************
  * @file    pcb_cells_can.c
  * @author  Bartosz Rychlicki
  * #author  AGH Eko-Energia

  * @Title   Firmware for Cells' PCB's CAN peripheral
  *
  * @brief   This file contains functions' bodies, that implement functions logic and provide optimized workflow of PCB Cell's CAN peripheral
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 AGH Eko-Energy.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ----------------------------------------------------------------------------------  */
#include "PCB_Cells_CAN.h"

/* Functions' bodies --------------------------------------------------------------------------  */
<<<<<<< HEAD
=======
HAL_StatusTypeDef PCBCells_CAN_InitFrames(PCBCells_TypeDef* pc){

	// Init object for CAn frame
	CAN_ScheduledMsg msg;

	// basic configuration for all frames
	msg.period_ms = PCBCELLS_CAN_THERM_PERIOD;
	msg.header.DLC = PCBCELLS_CAN_THERM_DLC;
	msg.header.IDE = CAN_ID_STD;
	msg.header.RTR = CAN_RTR_DATA;

	for(int i = 0; i < 9; ++i){

		// configuration frames ID
		if(PCBCells_CAN_GetID(pc, i, &msg.header.StdId) != HAL_OK){
			return HAL_ERROR;
		}

		// configuration data for exact frame
		if(PCBCells_CAN_ConfigData(pc, &msg, i) != HAL_OK){
			return HAL_ERROR;
		}

		// Adding frame to buffer
		if(CAN_AddScheduledMessage(msg, &pc->pccan.CAN_msgBuffer) != HAL_OK){
			return HAL_ERROR;
		}
	}

	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_CAN_GetID(PCBCells_TypeDef* pc, uint8_t frameIndex, uint32_t* Id){

	// check if correct framesIndex was given
	if(frameIndex >= 9){
		return HAL_ERROR;
	}


	// Calculating Id for ascending or descending order of IDs assignment
	*Id = PCBCELLS_CAN_THERM_ID_BASE + pc->packetIndex * 10 + (pc->packetIndex % 2 != 0) ? framesAscendingBaseId : framesDescendingBaseId;



	// Checking if correct Id was assigned
	if(*Id > (PCBCELLS_CAN_THERM_ID_BASE + pc->packetIndex * 10 + 9) || *Id < (PCBCELLS_CAN_THERM_ID_BASE + pc->packetIndex * 10 + 1)){
		return HAL_ERROR;
	}

	// checking ID value range
	if(framesAscendingBaseId > 9 || framesDescendingBaseId < 1){
		return HAL_ERROR;
	}

	// locking reserved ID and changing values of indicators
	framesAscendingBaseId++;
	framesDescendingBaseId--;
	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_CAN_ConfigData(PCBCells_TypeDef* pc, CAN_ScheduledMsg* msg, uint8_t thermId){

	// checking ascending CAN frames' IDs organization
	int isEven = pc->packetIndex % 2; // 0 - even, 1 - odd


	// organizing proper assignment
	msg->GetData = CAN2_Therm_Handlers[thermId];

	return HAL_OK;
}

HAL_StatusTypeDef PCBCells_CAN_SendFrames(PCBCells_TypeDef* pc){

	// Send scheduled messages on CAN bus
	CAN_HandleScheduled(&pc->pccan.hcan, &pc->pccan.CAN_msgBuffer);

	return HAL_OK;
}

>>>>>>> 284de66 (Refactor: added changes mentioned in comments made by copilot)
HAL_StatusTypeDef PCBCells_CAN_ScaleValue(PCBCells_TypeDef* pc, uint8_t thermIndex, float* realValue){

	// checking if given thermistor index is correct
	if(thermIndex >= 9){
		return HAL_ERROR;
	}

	uint8_t binaryType = 0; 	// Init of variable that will store calculated binary type of temperature, its type will be correct to those which should be sent via CAN

	// Calculating binary type of temperature | refers to: binaryType = (realValue - offset)/ gain;
	binaryType = (*realValue - PCBCELLS_CAN_THERM_OFFSET) / PCBCELLS_CAN_THERM_GAIN;

	// assigning calculated binary type of temperature to correct index in array (stored in PCBCells_TypeDef), index of array is equal to thermIndex - 1
	pc->pcadc.PCBCells_temperatures[thermIndex] = binaryType;

	return HAL_OK;
}
