# Drumduino

Drumdino is a drum kit implementation using an Arduino shield interfaced with Max/MSP for MIDI sound generation.

![Alt text](https://github.com/nehirakdag/Drumduino/blob/master/Kit.jpg)

In essence, an Arduino sketch is used to receive and process any impact received on the six pads. This data is sent to Max/MSP and converted to MIDI notes that can be outputted via the AU DLS Synth or be further processed for many interesting applications! 
