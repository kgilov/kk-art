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

//  set pin numbers - Street Musician: 
int D_valvePin =  2;      // the number of the LED pin
int E_valvePin =  3;
int F_valvePin =  4;
int f_valvePin =  5;
int G_valvePin =  6; 
int g_valvePin =  7;
int A_valvePin =  8;
int a_valvePin =  9;
int Breath1_valvePin =  10;
int Breath2_valvePin =  11;
int Breath3_valvePin =  12;



// note values
byte noteC = 11;
byte noteD = 11;
byte noteE = 11;
byte noteF = 11;
byte notef = 11;
byte noteG = 11;
byte noteg = 11;
byte noteA = 11;
byte notea = 11;


SoftwareSerial midiSerial(14,16); // pins for software serial RX/TX
MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, MIDI);

// -----------------------------------------------------------------------------
void setup()
{
	//set the digital pin as output:
   
  pinMode(D_valvePin, OUTPUT); 
  pinMode(E_valvePin, OUTPUT); 
  pinMode(F_valvePin, OUTPUT);
  pinMode(f_valvePin, OUTPUT);  
  pinMode(G_valvePin, OUTPUT);
  pinMode(g_valvePin, OUTPUT);
  pinMode(A_valvePin, OUTPUT);
  pinMode(a_valvePin, OUTPUT);
  pinMode(Breath1_valvePin, OUTPUT);
  pinMode(Breath2_valvePin, OUTPUT);
  pinMode(Breath3_valvePin, OUTPUT);
	
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

/ -----------------------------------------------------------------------------
// This function will be automatically called when a NoteOn is received.
void handleNoteOn(byte channel, byte note, byte velocity)
{
    if (channel == 1) {
		switch (note) { //left flute - select playable notes ONLY!!
			case noteC:
				playNoteC();
				break;
			case noteD:
				playNoteD();
				break;
			case noteE:
				playNoteE();
				break;
			case noteF:
				playNoteF();
				break;
			case notef:
				playNotef();
				break;
			case noteG:
				playNoteG();
				break;
			case noteg:
				playNoteg();
				break;	
			case noteA:
				playNoteA();
				break;	
			case notea:
				playNotea();
				break;					
		}
	}
}

// This function will be automatically called when a NoteOff is received.
// NoteOn messages with 0 velocity are interpreted as NoteOffs.
void handleNoteOff(byte channel, byte note, byte velocity)
{
	if (channel == 1 ) {
		closeBreath();
	}
}

//play notes
void playNoteC()
{
	digitalWrite(Breath1_valvePin, HIGH);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, LOW);
    digitalWrite(D_valvePin, LOW);
	digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
	digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNoteD()
{
	digitalWrite(Breath1_valvePin, HIGH);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
	digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNoteE()
{
	digitalWrite(Breath1_valvePin, HIGH);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
	digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNoteF()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, HIGH);
	digitalWrite(Breath3_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, LOW);
	digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNotef()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, HIGH);
	digitalWrite(Breath3_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
	digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNoteG()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, HIGH);
	digitalWrite(Breath3_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
	digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNoteg()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
	digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);	
}
void playNoteA()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
	digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(a_valvePin, LOW);	
}
void playNotea()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
	digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
	digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(a_valvePin, HIGH);	
}

//note off is breath off
void closeBreath()
{
	digitalWrite(Breath1_valvePin, LOW);
    digitalWrite(Breath2_valvePin, LOW);
	digitalWrite(Breath3_valvePin, LOW);
}