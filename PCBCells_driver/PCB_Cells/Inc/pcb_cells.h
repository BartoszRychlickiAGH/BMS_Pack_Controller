/**
  ******************************************************************************
  * @file    pcb_cells.h
  * @author  Bartosz Rychlicki

  * @Title   Firmware for Cells' PCBs boards
  *
  * @brief   This file contains common defines, flags and macros that are used to provide high quality workflow Cells' PCBs in active, standby and error mode.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 AGH Eko-Energy.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef PCB_CELLS_H_
#define PCB_CELLS_H_

/* Includes ----------------------------------------------------------------------------------  */
#include "PCB_Cells_types.h"


/* Functions prototypes ----------------------------------------------------------------------- */
HAL_StatusTypeDef PCBCells_Init(PCBCells_TypeDef* pc, ADC_HandleTypeDef* hadc1, ADC_HandleTypeDef* hadc2, CAN_HandleTypeDef* hcan);

HAL_StatusTypeDef PCBCells_Mode_Normal(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_Mode_Error(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_Peripherals_Start(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_Peripherals_Stop(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_ConfigPCBIndex(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_Mode_Change(PCBCells_TypeDef* pc, PCBCells_StatusTypeDef_e status);

void PCBCells_Mode_Blink(PCBCells_TypeDef* pc);


/* Macros ------------------------------------------------------------------------------------- */


/* Variables ------------------------------------------------------------------------------------- */
extern uint32_t lastTick;

#endif /* PCB_CELLS_H_ */
