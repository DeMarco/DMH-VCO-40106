# DMH-VCO-40106
 VCO module based on the design by Moritz Klein around a CD40106 Hex Inverter chip.
 I've modified the circuit considerably, but the essence is still the same:
  - Better CV processing:
      - Frequency modulation can now be attenuated completely when the amount knob is all the way CCW
      - Added trimpots to allow for fine frequency knob range adjustment and centering on a specific note (inspired by LMNC Performance VCO)
      - Added normalled connection to receive note CV directly from the Troley Bus power system
      - Added extra FM CV input (wanted to make it Linear FM instead of exponential, but gave up tryin to figure it out)
      - All CV inputs are now behind two stages of OpAmp based inverting amplifiers before hitting the transistor pair
      - Added trimpots to adjust PW knob range and symmetry, and adapted resistors to accept 100k potentiometer
  - Sync input added (so that the oscillator can be hard-synced to another)
  - Triangle wave shaper added (took from Moritz Klein Wave Folder circuit)
  - Sine wave shaper added (Thomas Henry design)
  - Tuner added (inspired by LMNC Performance VCO), my own design and firmware running on an ATtiny4313 (not Arduino)
