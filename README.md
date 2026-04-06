# STM32G474 LoRa Telemetry Node

![Status](https://img.shields.io/badge/Status-Development-yellow)
![License](https://img.shields.io/badge/License-MIT-green)

High-performance, FreeRTOS-based telemetry node designed for environmental monitoring using LoRa technology.

## 📌 Project Overview
This project demonstrates a professional approach to embedded systems development, featuring a modular architecture, interrupt-driven radio communication, and a robust CLI for diagnostics.

### Core Technologies
* **MCU:** STM32G474 (Cortex-M4F @ 170MHz)
* **RTOS:** FreeRTOS (CMSIS-RTOS v2)
* **Radio:** LoRa RFM95W (SX1276) @ 868MHz
* **Sensors:** BME280 (I2C), Internal ADC (Battery Monitoring)
* **Display:** SSD1306 OLED via I2C

## 🛠 Repository Structure
* `firmware/` - STM32CubeIDE project and source code.
* `hardware/` - Schematics and BOM.
* `docs/` - Architecture details and [Development Task Board](docs/task_board.md).
* `images/` - System photos and UI screenshots.

## 🚀 Key Features (In Development)
- [ ] **Interrupt-driven Radio:** No polling, DIO0 events handled via semaphores.
- [ ] **USB CDC CLI:** Real-time system configuration and debugging.
- [ ] **Power Management:** ADC+DMA for precise battery tracking.
- [ ] **Modular Design:** Strict separation between hardware drivers and application logic.

---
*Created by [Denys Derihlazov](https://github.com/denysderihlazov)*