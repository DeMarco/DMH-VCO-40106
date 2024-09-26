avrdude -B 125kHz -c usbasp -p ATtiny4313 -U eeprom:w:better_calibration_value.txt:h
@echo off
timeout /t -1