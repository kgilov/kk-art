/*
Note:
Not all pins on the Mega and Mega 2560 support change interrupts,
so only the following can be used for RX:
10, 11, 12, 13, 14, 15, 50, 51, 52, 53,
A8 (62), A9 (63), A10 (64), A11 (65),
A12 (66), A13 (67), A14 (68), A15 (69)

Not all pins on the Leonardo support change interrupts, 
so only the following can be used for RX: 
8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI)

*/

#include <MIDI.h>
#include <SoftwareSerial.h>

SoftwareSerial midiSerial(50,51); // pins for software serial RX/TX
MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, MIDI);

// -----------------------------------------------------------------------------
void setup()
{

    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
	
    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);
	
	while(!Serial);
    Serial.begin(115200);
    Serial.println("Arduino Ready");
	
}
void loop()
{    
    MIDI.read();    
}

void handleNoteOn(byte channel, byte note, byte velocity)
{
	Serial.println("Note ON---");
	Serial.print("channel: ");
	Serial.println(channel);
	Serial.print("note: ");
	Serial.println(note);
	Serial.print("velocity: ");
	Serial.println(velocity);
	Serial.println("--------------------");
}
void handleNoteOff(byte channel, byte note, byte velocity)
{
	Serial.println("Note ON---");
   	Serial.print("channel: ");
	Serial.println(channel);
	Serial.print("note: ");
	Serial.println(note);
	Serial.print("velocity: ");
	Serial.println(velocity);
	Serial.println("--------------------");
}