#include "MIDIcontroller.h"

byte MIDIchannel = 5;
const int potPin = A4;  // Change this to the ANALOG pin you want to use

int analogPins[] = {
  14,15,16,17,18,19,20,21   // which analog pins to use
};
int const ANALOG_PINS_NBR = 8;
MIDIpot* Pots[ANALOG_PINS_NBR];// Just declare the pointer array here (notice the *)

int analogPinsCC[] = {
  51,52,53,54,55,56,57,58,59   // which CC to use
};

void setup(){
  pinMode(13, INPUT_PULLUP);
  for (int i = 0;  i < ANALOG_PINS_NBR; i++) {
    Pots[i] = new MIDIpot (analogPins[i], analogPinsCC[i]);
    //OPTIONAL: use outputRange() to limit the min/max MIDI output values
    Pots[i]->outputRange(127,0);
  }

  for (int i = 0; i<5; i++) {
    digitalWrite(13, HIGH);
    delay(50);                 // Blink LED once at startup
    digitalWrite(13, LOW);
    delay(100);
  }
  usbMIDI.setHandleNoteOn(OnNoteOn);
}

void OnNoteOn(byte channel, byte note, byte velocity) {
  if (note == 99) {
    digitalWrite(13, HIGH); // Any Note-On turns on LED
    for (int i = 0;  i < ANALOG_PINS_NBR; i++) {
      // librairie 2.5.3 update
      Pots[i]->send(FORCE); // notice the -> operator
      // if lib MIDIControler <2.5.3
      //usbMIDI.sendControlChange(analogPinsCC[i], newVal[i]>>3, channel);
      //use this if the wiring is backwards :\
      //usbMIDI.sendControlChange(analogPinsCC[i], map(analogRead(analogPins[i])>>3,0,127,127,0), 5);
    }
    delay(50);
    digitalWrite(13, LOW); // Any Note-On turns on LED
  }
}

void loop(){
  for (int i = 0;  i < ANALOG_PINS_NBR; i++) {
    Pots[i]->send(); // notice the -> operator
  }

// This prevents crashes that happen when incoming usbMIDI is ignored.
  while(usbMIDI.read()){}

// Also uncomment this if compiling for standard MIDI
//  while(MIDI.read()){}
}
