/* forked from themidibus Basic exemple 
 https://github.com/sparks/themidibus/blob/504d8b5bd9821cd71635411756f8f55478c087f5/examples/Basic/Basic.pde
*/
import themidibus.*; //Import the library

MidiBus myBus; // The MidiBus
int[] Pots = new int[8]; // les 8 potards

/* TODO :
  initialize value of Pots array with true value read 
  from pots and sent with a specific command or note at start

*/

void setup() {
  // init Pots array with 0;
  for (int i = 0; i<8;i++) {
    Pots[i] = 0;
  }
  size(400, 400);
  background(250);
  // List all available Midi devices on STDOUT. This will show each device's index and name.
  MidiBus.list(); 
  //                   Parent In Out
  //                     |    |  |
  //myBus = new MidiBus(this, 0, 1);
  //Create a new MidiBus using the device index to select the Midi input and output devices respectively.
  myBus = new MidiBus(this, 1, 2);
  println("initial value of Pots array");
  myBus.sendNoteOn(5, 99, 100);
  println("Pots array upToDate");
  // myBus.sendControllerChange(channel, number, value);  
}

void draw() {
}

void noteOn(int channel, int pitch, int velocity) {
  // Receive a noteOn
  println();
  print("Note On:");
  //println("--------");
  print(" Channel:"+channel);
  print(" Pitch:"+pitch);
  println(" Velocity:"+velocity);
}

void noteOff(int channel, int pitch, int velocity) {
  // Receive a noteOff
  println();
  print("Note Off:");
  //println("--------");
  print("Channel:"+channel);
  print(" Pitch:"+pitch);
  println(" Velocity:"+velocity);
}

void controllerChange(int channel, int number, int value) {
  // fill Pots array with pots values
  Pots[number-51] = value;
  printArray(Pots); // for debug purpose
}

void delay(int time) {
  int current = millis();
  while (millis () < current+time) Thread.yield();
}
