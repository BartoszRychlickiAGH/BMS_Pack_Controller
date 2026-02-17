# BMS Pack Controller — Firmware

The **BMS Pack Controller** is a specialized monitoring unit designed to interface directly with individual battery packs. In a full system deployment, 7 of these controllers work in tandem to provide granular thermal data to the **BMS Master** via the CAN bus.

## Key Features

* **ADC Dual Mode Acquisition:** Utilizes **ADC1 and ADC2 in Dual Mode**, working synchronously to ensure precise and high-speed data capture.
* **DMA Integration:** Both ADCs use **DMA (Direct Memory Access)** to standardize and simplify data workflow while offloading the CPU.
* **Multi-Point Thermal Monitoring:** Supports up to 9 independent thermistor channels per board to ensure comprehensive temperature coverage across the pack.
* **Auto-Addressing Logic:** The firmware automatically detects the PCB's hardware ID via configuration pins (R1, R2, R3) and assigns the correct set of indexes for CAN communication.
* **Advanced Error Reporting:** Integrated error handling module is fully operational, providing real-time diagnostic feedback and status reporting.
* **CAN Bus Communication:** Optimized for the **CAN** network to report real-time telemetry from the pack to the central management unit.

---

## CAN Addressing & Spatial Mapping

To ensure that a specific temperature reading always corresponds to the same physical location (e.g., the upper-right corner of a pack), the firmware implements a smart orientation-aware addressing logic:

* **Hardware ID Detection**: The board identifies its position (1-7) via pins R1, R2, and R3.
* **Parity-Based Mapping**:
    * **Even-numbered Packs**: Data mapping follows a **Descending** order.
    * **Odd-numbered Packs**: Data mapping follows an **Ascending** order.
* **Consistency**: This logic compensates for the physical orientation of the PCBs in the battery assembly, ensuring that "Thermistor 1" in the software always points to the same geometric coordinate across all 7 packs.

---

## Hardware Pinout Configuration

The following table describes the pin mapping for the STM32 MCU on the Pack Controller PCB.

| PINOUT | STM PIN | DESCRIPTION |
| :--- | :--- | :--- |
| **CAN1_RX / TX** | PA11 / PA12 | CAN Bus Communication |
| **R1 / R2 / R3** | PA8, PA9, PA10 | Configuration Pins (ID Selection No.1 - No.3) |
| **THER1 - THER4** | PA0, PA1, PA2, PA3 | Thermal Sensors (ADC1_IN1 - ADC1_IN4) |
| **THER5 - THER8** | PA4, PA5, PA6, PA7 | Thermal Sensors (ADC2_IN1 - ADC2_IN4) |
| **THER9** | PB0 | Thermal Sensor (ADC1_IN11) |
| **LED1 / LED2** | PB5 / PB6 | Status Indicators (Green / Red LEDs) |
| **SWDIO / SWCLK** | PA13 / PA14 | Programming & Debugging (ST-Link) |

---

## Project Status

### ✅ Completed (Module Logic)
* **ADC Dual Mode:** ADC1 and ADC2 configuration in synchronized **Dual Mode** with DMA is fully implemented.
* **Auto-Addressing:** Logic for reading configuration pins and assigning CAN indexes is functional.
* **CAN Communication:** CAN stack for data transmission is ready.
* **Error Reporting:** Diagnostic and error reporting module is finished.

### 🧪 Testing & Validation
> [!IMPORTANT]
> This project is a **refactored version** of the firmware. While all modules are marked as complete, they are currently undergoing **validation tests**:
> * **ADC Stability:** Testing thermistor readings via ADC1 and ADC2 (Dual Mode) for accuracy and noise.
> * **CAN Reliability:** Monitoring data transmission consistency from all 7 controllers on the bus.

---

## How to Run

1.  **Hardware Addressing:** Ensure the configuration pins (R1-R3) are set correctly to identify the pack number.
2.  **Connection:** Connect the board to the pack's thermistors and the CAN bus.
3.  **Flashing:** Use an **ST-LINK V2** to upload the firmware via the SWD header. The firmware automatically assigns indexes based on the hardware ID.

---

## Authors

* **Bartosz Rychlicki** – Firmware Development
* **Bartek Masiak** – PCB Design
