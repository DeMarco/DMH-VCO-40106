avrdude -B 125kHz -c usbasp -p ATtiny4313 -U lfuse:w:0xE4:m
timeout /t -1
