avrdude -B 125kHz -c usbasp -p ATtiny4313 -U lfuse:w:0xE4:m
avrdude -B 125kHz -c usbasp -p ATtiny4313 -U hfuse:w:0x9F:m
timeout /t -1
