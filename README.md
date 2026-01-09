# Description

PCBs cells front:

The project includes implementations of functionalities included in the design:

    Some of these include: communication via CAN2 bus, reading temperature thank to ADC1 and ADC2.

    ADC1 and ADC2 are configured and launched in dual mode, both use DMA.

    This firmware can be loaded into 7 PCBs. Program auto checks number of PCB and assign correct set of indexes for CAN communication.

# Note

This version is refactor version of firmware.

# Status

    Non-started stages:
        - reading thermistors via ADC1 and ADC2

    	- sending data via CAN2

    Under construction stages:
    - None

    Completed stages:
    - None

# How to Run:

To properly launch project on PCB cells PCBs boards, it only requires correct hardware connection. Loading project on STM32 core is held via ST-LINK V2.

# Authors:

    - Bartosz Rychlicki 	  – Firmware
    - Bartek Masiak			  - PCB
