################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EKO_Drivers/I2C/Src/I2C_driver.c 

OBJS += \
./EKO_Drivers/I2C/Src/I2C_driver.o 

C_DEPS += \
./EKO_Drivers/I2C/Src/I2C_driver.d 


# Each subdirectory must supply rules for building sources it contributes
EKO_Drivers/I2C/Src/%.o EKO_Drivers/I2C/Src/%.su EKO_Drivers/I2C/Src/%.cyclo: ../EKO_Drivers/I2C/Src/%.c EKO_Drivers/I2C/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/ADC/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/CAN/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/PCB_Cells/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/TIM/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/EKO_Drivers/ADC/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/EKO_Drivers/CAN/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EKO_Drivers-2f-I2C-2f-Src

clean-EKO_Drivers-2f-I2C-2f-Src:
	-$(RM) ./EKO_Drivers/I2C/Src/I2C_driver.cyclo ./EKO_Drivers/I2C/Src/I2C_driver.d ./EKO_Drivers/I2C/Src/I2C_driver.o ./EKO_Drivers/I2C/Src/I2C_driver.su

.PHONY: clean-EKO_Drivers-2f-I2C-2f-Src

