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

//  set pin numbers - LAST GUN:       
int D_valvePin   =  55;    // the number of the LED pin
int E_valvePin  =  12;    // left barrel flute - C -> all low
int F_valvePin   =  11;
int G_valvePin   =  8;
int A_valvePin  =  6;
int B_valvePin   =  4;
int d_valvePin  =  54;      // right barrel flute
int l_valvePin   =  10;    // F on #, duplicate
int f_valvePin  =  9;     
int g_valvePin  = 7;
int a_valvePin =  5;
int b_valvePin  =  3;
//left flute
int BreathL1_valvePin =  57;
int BreathL2_valvePin =  56;
//right flute
int BreathR1_valvePin =  59;
int BreathR2_valvePin =  58;

// note values
byte noteC = 11;
byte noteD = 11;
byte noteE = 11;
byte noteF = 11;
byte noteG = 11;
byte noteA = 11;
byte noteB = 11;
byte notec = 11;
byte noted = 11;
byte notel = 11;
byte notef = 11;
byte noteg = 11;
byte notea = 11;
byte noteb = 11;

SoftwareSerial midiSerial(50,51); // pins for software serial RX/TX
MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, MIDI);

// -----------------------------------------------------------------------------
void setup()
{
	//set the digital pin as output:
   
	pinMode(D_valvePin,  OUTPUT);
	pinMode(E_valvePin, OUTPUT); 
	pinMode(F_valvePin,  OUTPUT); 
	pinMode(G_valvePin,  OUTPUT);
	pinMode(A_valvePin, OUTPUT);  
	pinMode(B_valvePin,  OUTPUT);
	pinMode(d_valvePin, OUTPUT);
	pinMode(l_valvePin, OUTPUT);
	pinMode(f_valvePin,  OUTPUT);
	pinMode(g_valvePin, OUTPUT); 
	pinMode(a_valvePin,  OUTPUT); 
	pinMode(b_valvePin,  OUTPUT);

	pinMode(BreathL1_valvePin, OUTPUT);
	pinMode(BreathL2_valvePin, OUTPUT);
	pinMode(BreathR1_valvePin, OUTPUT);
	pinMode(BreathR2_valvePin, OUTPUT);
	
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

// -----------------------------------------------------------------------------
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
			case noteG:
				playNoteG();
				break;
			case noteA:
				playNoteA();
				break;
			case noteB:
				playNoteB();
				break;		
		}
	}
	if (channel == 2) {
		switch (note) { //right flute - select playable notes ONLY!!
			case notec:
				playNotec();
				break;
			case noted:
				playNoted();
				break;
			case notel:
				playNotel();
				break;
			case notef:
				playNotef();
				break;
			case noteg:
				playNoteg();
				break;
			case notea:
				playNotea();
				break;
			case noteb:
				playNoteb();
				break;
		}
	}	    
}

// This function will be automatically called when a NoteOff is received.
// NoteOn messages with 0 velocity are interpreted as NoteOffs.
void handleNoteOff(byte channel, byte note, byte velocity)
{
	if (channel == 1 ) {
		closeBreathL();
	}
	if (channel == 2 ) {
		closeBreathR;
	}    
}

//left flute play notes
void playNoteC()
{
	digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(D_valvePin, LOW);
    digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
  
void playNoteD()
{
    digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}

void playNoteE()
{        
    digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteF()
{
    digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteG()
{
    digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteA()
{
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(B_valvePin, LOW);
}
void playNoteB()
{
    digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, HIGH);
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(B_valvePin, HIGH);
}
// right flute play notes
void playNotec()
{
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(d_valvePin, LOW);
    digitalWrite(l_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNoted()
{
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}  
void playNotel()
{     
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNotef()
{      
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNoteg()
{
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNotea()
{
    digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(a_valvePin, HIGH);
    digitalWrite(b_valvePin, LOW);
}
void playNoteb()
{
    digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(a_valvePin, HIGH);
    digitalWrite(b_valvePin, HIGH);
}

//note off is breath off
void closeBreathL()
{
	digitalWrite(BreathL1_valvePin, LOW);
	digitalWrite(BreathL2_valvePin, LOW);
}
void closeBreathR()
{
	digitalWrite(BreathR1_valvePin, LOW);
	digitalWrite(BreathR2_valvePin, LOW);
}