avrdude -B 125kHz -c usbasp -p ATtiny4313 -U calibration:r:calib_data.txt:h
timeout /t -1