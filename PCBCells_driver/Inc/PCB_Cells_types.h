/*
 * PCB_Cells_types.h
 *
 *  Created on: Jan 8, 2026
 *      Author: brych
 */

#ifndef PCB_CELLS_TYPES_H_
#define PCB_CELLS_TYPES_H_

/* Includes ----------------------------------------------------------------------------------  */

// General
#include "main.h"
#include "string.h"

// Drivers
#include "adc_driver.h"
#include "can_driver.h"
#include "can_id_list.h"

/* Macros ------------------------------------------------------------------------------------  */


/* Typedefs ----------------------------------------------------------------------------------  */

/*
 *	Enum type of of Cells PCB's status
 */
typedef enum{

	PCBCELLS_ACTIVE = 0,
	PCBCELLS_STANDBY,
	PCBCELLS_ERROR

}PCBCells_StatusTypeDef_e;

/*
 *	Structure of Cells PCB's ADC peripheral
 */
typedef struct{





}PCBCells_ADCTypeDef;

/*
 *	Structure of Cells PCB's CAN peripheral
 */
typedef struct{




}PCBCells_CANTypeDef;


/*
 *	Structure of Cells PCB object
 */
typedef struct{




}PCBCells_TypeDef;

#endif /* PCB_CELLS_TYPES_H_ */
