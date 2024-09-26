avrdude -B 125kHz -c usbasp -p ATtiny4313 -U calibration:r:factory_calibration_values.txt:h
@echo off
echo.
echo.
echo ATtiny4313 internal RC Oscillator factory calibration values:
echo.
echo  8Hz, 4Hz
type factory_calibration_values.txt
echo.
echo.
timeout /t -1