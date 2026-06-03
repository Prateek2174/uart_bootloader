# uart_bootloader

A minimal UART bootloader for the STM32F446RE that jumps to the main application at flash offset 0x8000.

## Overview

The bootloader occupies the first 32 KB of flash (0x08000000-0x08007FFF). On startup it reads the reset vector from the main application region and jumps directly to it — serving as the jump-stub foundation for a full UART-based bootloader.

## Memory Map

| Region | Address | Size |
|---|---|---|
| Bootloader | 0x08000000 | 32 KB |
| Main App | 0x08008000 | remaining flash |

## Hardware

- **Board:** STM32 NUCLEO-F446RE
- **Toolchain:** STM32CubeIDE (GCC ARM)

## Build

Open `uart_bootloader/.project` in STM32CubeIDE and build/flash normally.
