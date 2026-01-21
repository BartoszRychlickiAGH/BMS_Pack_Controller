################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EKO_Drivers/PWM/Src/pwm_driver.c 

OBJS += \
./EKO_Drivers/PWM/Src/pwm_driver.o 

C_DEPS += \
./EKO_Drivers/PWM/Src/pwm_driver.d 


# Each subdirectory must supply rules for building sources it contributes
EKO_Drivers/PWM/Src/%.o EKO_Drivers/PWM/Src/%.su EKO_Drivers/PWM/Src/%.cyclo: ../EKO_Drivers/PWM/Src/%.c EKO_Drivers/PWM/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/ADC/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/CAN/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/PCB_Cells/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/PCBCells_driver/TIM/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/EKO_Drivers/ADC/Inc" -I"C:/Users/brych/OneDrive/Pulpit/PROJEKTY/STM32/EKO_ENERGY/PCB_Cells/EKO_Drivers/CAN/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EKO_Drivers-2f-PWM-2f-Src

clean-EKO_Drivers-2f-PWM-2f-Src:
	-$(RM) ./EKO_Drivers/PWM/Src/pwm_driver.cyclo ./EKO_Drivers/PWM/Src/pwm_driver.d ./EKO_Drivers/PWM/Src/pwm_driver.o ./EKO_Drivers/PWM/Src/pwm_driver.su

.PHONY: clean-EKO_Drivers-2f-PWM-2f-Src

