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

/* Typedefs ----------------------------------------------------------------------------------  */

/*
 *	Enum type of of Cells PCB's status
 */
typedef enum{

	PCBCELLS_ACTIVE = 0,
	PCBCELLS_ERROR

}PCBCells_StatusTypeDef_e;

/*
 *	Structure of Cells PCB's ADC peripheral
 */
typedef struct{


	ADC_HandleTypeDef   	hadc1;						/*<  Handle to ADC1  >*/
	ADC_HandleTypeDef   	hadc2;						/*<  Handle to ADC2  >*/

	ADC_ChannelsTypeDef 	cadc1;						/*< Channels of ADC1 >*/
	ADC_ChannelsTypeDef 	cadc2;						/*< Channels of ADC2 >*/

	ADC_BufferTypeDef   	badc1;						/*< Buffer of ADC1 in dual mode conversion >*/
	ADC_BufferTypeDef   	badc2;						/*< Buffer of ADC2 in dual mode conversion >*/

	uint8_t				PCBCells_temperatures[9];	/*< Array of converted values of thermistors' temperatures >*/

}PCBCells_ADCTypeDef;

/*
 *	Structure of Cells PCB's CAN peripheral
 */
typedef struct{

	CAN_HandleTypeDef 		hcan;						/*<   Handle to CAN1   >*/

	CAN_ScheduledMsgList 	CAN_msgBuffer;				/*< CAN messages buffer >*/

}PCBCells_CANTypeDef;


/*
 *	Structure of Cells PCB object
 */
typedef struct{

	PCBCells_ADCTypeDef 	 pcadc;						/*< PCB's Cells ADC handle >*/
	PCBCells_CANTypeDef 	 pccan;						/*< PCB's Cells CAN handle >*/

	PCBCells_StatusTypeDef_e prevStatus;				/*< PCB Cells previous status, in case change of status occured >*/
	PCBCells_StatusTypeDef_e currStatus;				/*< PCB Cells current status >*/

	uint8_t 				 packetIndex : 3;			/*< Packet number (1 - 7) >*/

}PCBCells_TypeDef;

/* Macros ------------------------------------------------------------------------------------  */

// TIM
#define TIM_GREEN_LED TIM_CHANNEL_2

// ADC1
#define ADC1_CH1  	  ADC_CHANNEL_1
#define ADC1_CH2      ADC_CHANNEL_2
#define ADC1_CH3      ADC_CHANNEL_3
#define ADC1_CH4      ADC_CHANNEL_4
#define ADC1_CH11     ADC_CHANNEL_11

// ADC2
#define ADC2_CH1      ADC_CHANNEL_1
#define ADC2_CH2      ADC_CHANNEL_2
#define ADC2_CH3      ADC_CHANNEL_3
#define ADC2_CH4      ADC_CHANNEL_4

//PCB
#define VCC_SUPPLY_VOLTAGE (3.3f)

#endif /* PCB_CELLS_TYPES_H_ */
