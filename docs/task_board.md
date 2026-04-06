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

Stage 1: 

- [ ] Initial CubeMX configuration (I2C, UART)
- [ ] Calculate SPI prescaler for RFM95 (target <10MHz)

---

## ⚪ Backlog



---

## Stage 0 - Project Setup

### Tasks

- [x] create repo: `stm32g474-lora-telemetry-node`
- [x] create folders:
  - [x] `firmware/`
  - [x] `hardware/`
  - [x] `images/`
  - [x] `docs/`
- [x] create `docs/task_board.md`
- [x] create minimal `README.md` placeholder

---

## Stage 1 - CubeMX Base

### Tasks

- [x] calculate and set SPI prescaler (as I know max 10MHz for RFM95)
- [x] configure GPIO (SPI for RFM95) 
- [x] configure DIO0
- [x] set EXTI trigger = Rising edge
- [x] set-up NVIC
- [ ] configure I2C for BME280 and SSD1306
- [ ] configure ADC for power measurement
- [ ] connect DMA to ADC
- [x] enable USB CDC
- [x] enable FreeRTOS CMSIS_V2
- [ ] assign clean and consistent pin labels

---

## Stage 2 - Architecture

### Tasks

- [ ] create folder structure:
  - [x] `Components/rfm95`
  - [x] `Components/bme280`
  - [x] `Components/ssd1306`
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

- [x] Project direction selected
- [x] Decision: use AI as PM, not code generator


- [x] Stage 0: Project Setup

    Repository stm32g474-lora-telemetry-node created.

    Project structure initialized (firmware/, hardware/, docs/, images/).

    Documentation baseline established (README.md, task_board.md).


- [ ] Stage 1: CubeMX Base
    calculate and set SPI prescaler (as I know max 10MHz for RFM95)

    configure DIO0

    configure GPIO (SPI for RFM95) 

    set-up NVIC

    set EXTI trigger = Rising edge (for Lora DIO0)

    set-up NVIC


- [ ] Stage 2 - Architecture
  Components/rfm95

  Components/bme280
  
  Components/ssd1306

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

## Issues

1) SPI freq. limitation
According to the RFM95W datasheet, the maximum SPI clock frequency is 10 MHz
SPI Prescaler: We cannot achieve exactly 10 MHz from a 170 MHz APB clock using standard power-of-two dividers.

Options:
    1 Reduce APB to 144 MHz: Not an option (compromises overall system performance).

    2 Set Prescaler to 32: Results in ~5.3 MHz. Safe, but leaves 50% of the bandwidth unused.

    3 Use Independent Kernel Clock: In the G4 series, we can source the SPI clock from PLLQ or HSI/HSE via the RCC_CCIPR register. This allows us to hit the 9–10 MHz target regardless of the APB frequency.

Temporary: we can use SPI1 with 32 Baud rate prescaller (which is 3 MHz).

My future decision: Option 3 is preferred to maintain maximum CPU/Peripheral performance while maximizing SPI throughput.