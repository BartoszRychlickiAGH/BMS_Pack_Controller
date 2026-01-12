/**
  ******************************************************************************
  * @file    pcb_cells_adc.h
  * @author  Bartosz Rychlicki
  * #author  AGH Eko-Energia

  * @Title   Firmware for Cells' PCB's ADC peripheral
  *
  * @brief   This file contains common defines, flags and macros that are used to provide high quality workflow Cells' PCB's ADC peripheral in active mode.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 AGH Eko-Energy.
  * All rights reserved.
  *
  ******************************************************************************
  */

#ifndef PCB_CELLS_ADC_H_
#define PCB_CELLS_ADC_H_

/* Includes ----------------------------------------------------------------------------------  */
#include "PCB_Cells_types.h"


/* Functions prototypes ----------------------------------------------------------------------- */
HAL_StatusTypeDef PCBCells_ADC_ReadValues(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_ADC1_ReadChannels(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_ADC2_ReadChannels(PCBCells_TypeDef* pc);

HAL_StatusTypeDef PCBCells_ADC_ReadTemperature(PCBCells_TypeDef* pc, uint8_t adcIndex, uint8_t thermIndex, float* retval);

float 			  PCBCells_ADC_NTC_calibrateTemperature(float measured);

float 			  PCBCells_ADC_NTC_GetTemperature(float Rt);

/* Macros ------------------------------------------------------------------------------------- */
#define ADC1_INDEX       1
#define ADC2_INDEX 	     2

#define ADC_THERM_OFFSET 5

#endif /* PCB_CELLS_ADC_H_ */
