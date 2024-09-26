avrdude -B 125kHz -c usbasp -p ATtiny4313 -U flash:w:DMH_VCO_40106_Firmware\Debug\DMH_VCO_40106_Firmware.hex:i
@echo off
timeout /t -1
