# STM32G474 LoRa Telemetry Node - Task Board

Project: STM32G474RET + RFM95W-868S2 + FreeRTOS + BME280 + SSD1306 + ADC/DMA + USB CDC CLI

---

## Rules

- Keep scope under control.
- Do not jump between unrelated tasks.
- Move tasks to **Done** only when they are actually finished.
- Keep commits small and meaningful.
- Commit messages should match completed tasks.
- Understand every line of code.

---

## 🟡 In Progress

Whole Stage 0

---

## ⚪ Backlog

- [ ] calculate and set SPI prescaler (as I know max 10MHz for RFM95)
- [ ] configure SPI for RFM95
- [ ] configure DIO0

---

## Stage 0 - Project Setup

### Tasks

- [ ] create repo: `stm32g474-lora-telemetry-node`
- [ ] create folders:
  - [ ] `firmware/`
  - [ ] `hardware/`
  - [ ] `images/`
  - [ ] `docs/`
- [ ] create `docs/task_board.md`
- [ ] create minimal `README.md` placeholder

---

## Stage 1 - CubeMX Base

### Tasks

- [ ] calculate and set SPI prescaler (as I know max 10MHz for RFM95)
- [ ] configure SPI for RFM95
- [ ] configure DIO0
- [ ] set EXTI trigger = Rising edge
- [ ] set-up NVIC
- [ ] configure I2C for BME280 and SSD1306
- [ ] configure ADC for power measurement
- [ ] connect DMA to ADC
- [ ] enable USB CDC
- [ ] enable FreeRTOS CMSIS_V2
- [ ] assign clean and consistent pin labels

---

## Stage 2 - Architecture

### Tasks

- [ ] create folder structure:
  - [ ] `Drivers/rfm95`
  - [ ] `Drivers/bme280`
  - [ ] `Drivers/ssd1306`
  - [ ] `Services/protocol`
  - [ ] `Services/telemetry`
  - [ ] `Services/power`
  - [ ] `Services/cli`
  - [ ] `RTOS/tasks`
- [ ] define module ownership
- [ ] write architecture notes in `docs/architecture.md`

---

## Stage 3 - RTOS Skeleton

### Tasks

- [ ] create tasks:
  - [ ] `radio_task`
  - [ ] `sensor_task`
  - [ ] `telemetry_task`
  - [ ] `ui_task`
  - [ ] `cli_task`
- [ ] set stack sizes (I think 256 is our minimum)
- [ ] verify scheduler startup
- [ ] verify system stability

---

## Stage 4 - RTOS Communication

### Tasks

- [ ] create queues:
  - [ ] `radio_rx_queue`
  - [ ] `radio_tx_queue`
  - [ ] `telemetry_queue`
  - [ ] `ui_queue`
  - [ ] `cli_rx_queue`
- [ ] create sync objects:
  - [ ] `dio0_semaphore`
  - [ ] `config_mutex`
  - [ ] `oled_mutex` (if needed)

---

## Stage 5 - Radio (Interrupt-driven)

### Tasks

- [ ] configure DIO0 EXTI interrupt
- [ ] ISR only signals task (no heavy logic)
- [ ] process events inside `radio_task`
- [ ] split flows:
  - [ ] RX done
  - [ ] TX done
  - [ ] error / timeout
- [ ] remove polling completely

---

## Stage 6 - Protocol

### Tasks

- [ ] define packet header
- [ ] define packet types:
  - [ ] telemetry
  - [ ] command
  - [ ] ping
  - [ ] status / ack
- [ ] add fields:
  - [ ] source id
  - [ ] destination id
  - [ ] sequence number
  - [ ] payload length
- [ ] document format in README or docs

---

## Stage 7 - TX/RX Stability

### Tasks

- [ ] implement packet send
- [ ] implement packet receive
- [ ] basic parsing
- [ ] counters:
  - [ ] `tx_count`
  - [ ] `rx_count`
  - [ ] `seq`
- [ ] verify stable bidirectional communication

---

## Stage 8 - BME280

### Tasks

- [ ] integrate BME280 driver
- [ ] use forced mode (may be different)
- [ ] in `sensor_task`:
  - [ ] trigger measurement
  - [ ] wait (RTOS delay)
  - [ ] read values
  - [ ] build snapshot

---

## Stage 9 - Power Measurement (ADC + DMA)

### Tasks

- [ ] decide measurement point (battery / rail)
- [ ] configure ADC
- [ ] configure DMA
- [ ] raw → voltage conversion
- [ ] averaging / filtering
- [ ] validate readings

---

## Stage 10 - Telemetry

### Tasks

- [ ] collect:
  - [ ] temperature
  - [ ] humidity
  - [ ] pressure
  - [ ] voltage
  - [ ] uptime
  - [ ] packet counter
  - [ ] RSSI
  - [ ] SNR
- [ ] build telemetry packet
- [ ] send via `radio_tx_queue`

---

## Stage 11 - OLED UI

### Tasks

- [ ] screen 1:
  - [ ] role
  - [ ] TX/RX state
  - [ ] RSSI
  - [ ] SNR
  - [ ] packet counter
- [ ] screen 2:
  - [ ] temperature
  - [ ] humidity
  - [ ] pressure
  - [ ] voltage
- [ ] screen 3:
  - [ ] uptime
  - [ ] interval
  - [ ] errors

---

## Stage 12 - Buttons

### Tasks

```
Note: At this stage we should know how much buttons we need. Two or Three
```

- [ ] button 1:
  - [ ] switch OLED page
- [ ] button 2:
  - [ ] manual TX / ping
- [ ] debounce handling

---

## Stage 13 - CLI

### Tasks

- [ ] USB CDC CLI
- [ ] commands:
  - [ ] `status`
  - [ ] `radio`
  - [ ] `sensors`
  - [ ] `send ping`
  - [ ] `set interval`
  - [ ] `oled page`
  - [ ] `reboot`

---

## Stage 14 - Diagnostics

### Tasks

- [ ] uptime
- [ ] `tx_count`
- [ ] `rx_count`
- [ ] `last_rssi`
- [ ] `last_snr`
- [ ] `radio_error_count`
- [ ] `bme280_error_count`
- [ ] `adc_error_count`

---

## Stage 15 - PC Tool (Optional)

### Tasks

- [ ] Python + pyserial
- [ ] receive telemetry
- [ ] display values
- [ ] CSV export
- [ ] simple graphs

---

## Stage 16 - Final Polish

### Tasks

- [ ] update README
- [ ] add architecture diagram
- [ ] document protocol
- [ ] add screenshots
- [ ] clean repo

---

## 🟢 Done

- [x] Initial LoRa communication (basic TX/RX)
- [x] Project direction selected
- [x] Decision: use AI as PM, not code generator

---

## Notes

### Commit style

- `init: create repository structure`
- `ioc: configure spi and exti for rfm95`
- `rtos: add task skeleton`
- `radio: move dio0 to interrupt flow`
- `sensor: add bme280 read flow`
- `power: add adc dma measurement`
- `ui: add oled screens`
- `cli: add usb cdc interface`
- `docs: update task board`

---

## Daily log

```text
Today:
- worked on:
- working now:
- blocked by:
- next step: