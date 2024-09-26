avrdude -B 125kHz -c usbasp -p ATtiny4313 -U eeprom:r:eeprom_calibration_values.txt:h
@echo off
echo.
echo.
echo ATtiny4313 internal RC Oscillator user calibration values:
echo.
type eeprom_calibration_values.txt
echo.
echo.
timeout /t -1