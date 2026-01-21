################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PCBCells_driver/TIM/Src/pcb_cells_tim.c 

OBJS += \
./PCBCells_driver/TIM/Src/pcb_cells_tim.o 

C_DEPS += \
./PCBCells_driver/TIM/Src/pcb_cells_tim.d 


# Each subdirectory must supply rules for building sources it contributes
PCBCells_driver/TIM/Src/%.o PCBCells_driver/TIM/Src/%.su PCBCells_driver/TIM/Src/%.cyclo: ../PCBCells_driver/TIM/Src/%.c PCBCells_driver/TIM/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Include -I../EKO_Drivers/ADC/Inc -I../EKO_Drivers/CAN/Inc -I../PCBCells_driver/ADC/Inc -I../PCBCells_driver/CAN/Inc -I../PCBCells_driver/PCB_Cells/Inc -I../PCBCells_driver/TIM/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-PCBCells_driver-2f-TIM-2f-Src

clean-PCBCells_driver-2f-TIM-2f-Src:
	-$(RM) ./PCBCells_driver/TIM/Src/pcb_cells_tim.cyclo ./PCBCells_driver/TIM/Src/pcb_cells_tim.d ./PCBCells_driver/TIM/Src/pcb_cells_tim.o ./PCBCells_driver/TIM/Src/pcb_cells_tim.su

.PHONY: clean-PCBCells_driver-2f-TIM-2f-Src

