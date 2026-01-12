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
HAL_StatusTypeDef PCBCells_CAN_ScaleValue(PCBCells_TypeDef* pc, uint8_t thermIndex, float* realValue){

	// checking if given thermistor index is correct
	if(thermIndex > 9 || thermIndex < 1){
		return HAL_ERROR;
	}

	uint8_t binaryType = 0; 	// Init of variable that will store calculated binary type of temperature, its type will be correct to those which should be sent via CAN

	// Calculating binary type of temperature | refers to: binaryType = (realValue - offset)/ gain;
	binaryType = (*realValue - PCBCELLS_CAN_THERM_OFFSET) / PCBCELLS_CAN_THERM_GAIN;

	// assigning calculated binary type of temperature to correct index in array (stored in PCBCells_TypeDef), index of array is equal to thermIndex - 1
	pc->pcadc.PCBCells_temperatures[thermIndex - 1] = binaryType;

	return HAL_OK;
}
