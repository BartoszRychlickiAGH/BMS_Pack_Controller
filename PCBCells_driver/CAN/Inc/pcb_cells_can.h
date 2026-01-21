/**
  ******************************************************************************
  * @file    pcb_cells_can.h
  * @author  Bartosz Rychlicki
  * @author  AGH Eko-Energia

  * @Title   Firmware for Cells' PCB's CAN
  *
  * @brief   This file contains common macros and functions' prototypes to provide high quality workflow of CAN peripheral embedded in Cells' PCBs in active mode.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 AGH Eko-Energy.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef PCB_CELLS_CAN_H_
#define PCB_CELLS_CAN_H_

/* Includes ----------------------------------------------------------------------------------  */
#include "PCB_Cells_types.h"


/* Functions prototypes ----------------------------------------------------------------------- */
HAL_StatusTypeDef PCBCells_CAN_ScaleValue(PCBCells_TypeDef* pc, uint8_t thermIndex, float* realValue);

/* Macros ------------------------------------------------------------------------------------- */
#define PCBCELLS_CAN_THERM_OFFSET (49.8039f)
#define PCBCELLS_CAN_THERM_GAIN   (0.39216f)
#define PCBCELLS_CAN_THERM_PERIOD (200)

#endif /* PCB_CELLS_CAN_H_ */
