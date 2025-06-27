# 🛠️ Firmware Extraction Workshop – BSides Athens 2025

Welcome to the **TwelveSec Firmware Extraction Workshop** presented at **BSides Athens 2025**! This hands-on session teaches participants how to extract firmware from embedded devices for security research and analysis.


![img](https://github.com/twelvesec/BSides-Athens-2025-Badge/blob/main/res/badge.gif?raw=true)

## 📚 Workshop Overview

This repository contains instructions, tools, and references for:

- Using Arduino as an ISP programmer
    
- Dumping firmware from ATmega microcontrollers
    
- Analyzing firmware with tools like AVRDUDE, `strings`, and Ghidra
    

## 🧰 Requirements

- Arduino Nano
    
- Target device (e.g., ATmega168 or compatible)
    
- Jumper wires
    
- Computer with:
    
    - Arduino IDE
        
    - AVRDUDE
        
    - Ghidra
        

---

## 🔧 Firmware Extraction Process

### 🛠 Create an ISP Programmer

1. Open Arduino IDE.
    
2. Connect your Arduino Nano via USB.
    
3. Load the `ArduinoISP` sketch from **File > Examples**.
    
4. Set board: `Arduino Nano`, processor: `ATmega168`.
    
5. Upload the sketch.
    

### 🔌 Wiring Setup

Connect the Arduino Nano to the target device using SPI:

- **D10 (CS)** ➜ RESET of target chip
    
- **D11 (MOSI)** ➜ MOSI
    
- **D12 (MISO)** ➜ MISO
    
- **D13 (SCK)** ➜ SCK
    
- **GND** ➜ GND
    
- **5V** ➜ VCC (double-check voltage requirements)
    

> ⚠️ Never connect or disconnect wires while the device is powered.

---

## 📥 Firmware Dumping with AVRDUDE

### Binary Format:

```bash
avrdude -C/etc/avrdude.conf -v -V -patmega168p -carduino -P/dev/ttyUSB0 -b19200 -D -Uflash:r:firmware.bin:r -F
```

### Hex Format:

```bash
avrdude -C/etc/avrdude.conf -v -V -patmega168p -carduino -P/dev/ttyUSB0 -b19200 -D -Uflash:r:firmware.hex:i -F
```

### Convert Hex to Binary (if needed):

```bash
objcopy --input-target=ihex --output-target=binary firmware.hex firmware.bin
```

### Quick String Analysis:

```bash
strings firmware.bin | less
```

---

## 🧠 Reverse Engineering with Ghidra

### Objectives:

- Analyze extracted firmware
    
- Locate hardcoded credentials, keys, or debug info
    

### Setup:

1. Open Ghidra and create a new project
    
2. Import `firmware.bin`
    
3. Select processor: `atmega328` (or appropriate AVR)
    
4. Use **Search > For Strings** to locate readable content
    

> 💡 Add support for AVR in Ghidra by editing `avr8.ldefs` under `Ghidra/Processors/Atmel/data/languages/` if needed.

---

## 🔗 Explore More

Check out our hardware hacking tools and other resources:  
[https://github.com/twelvesec/PwnPad](https://github.com/twelvesec/PwnPad)

---

**Presented by [TwelveSec](https://www.twelvesec.com/)** – Offensive Security Experts  
Questions? Open an issue or start a discussion right here on GitHub!
