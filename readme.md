# Pico-Scratchbook

Pico-Scratchbook is a collection of example projects for the Raspberry Pi Pico 2W, demonstrating basic functionalities such as blinking an LED and PWM control. This repository is structured to work with the Raspberry Pi Pico SDK and specifically targets the Pico 2W.

## Directory Structure

The repository follows this directory layout:
```
- pico/
  - pico-scratchbook/      # This project
  - pico-sdk/              # Raspberry Pi Pico SDK (must be correctly placed)
```

## Building the Project

To build any of the examples, use the provided script `run_build.sh`.

### Flashing the Pico 2W

1. Manually enter BOOTSEL mode by holding the **BOOTSEL** button while plugging in the Pico 2W.
2. Copy and paste the generated `.uf2` file onto the mounted Pico storage device.

## Setting Up the SDK

Before building, you must install the Raspberry Pi Pico SDK. Follow the manual installation instructions in the official documentation:

[Getting Started with Raspberry Pi Pico (Manually Configure your Environment)](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)

All the necessary tools and dependencies are listed in the appendix of the guide under the section "Manually Configure your Environment".

## Board Compatibility

- **This project is configured for Pico 2W (RP2350 boards)**.
- The original Raspberry Pi Pico is not supported **unless** you modify the build settings.


## Notes
- Ensure that `pico-sdk` is correctly placed inside the `pico/` directory, as the build process relies on `PICO_SDK_PATH`.
- If targeting a different board, modify `cmake` options accordingly.

Enjoy experimenting with your Raspberry Pi Pico 2W!

