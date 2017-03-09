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

//  set pin numbers - double B:       
int E_valvePin   =  36;    // the number of the LED pin
int F_valvePin  =  34;    // Right barrel flute - small case 's' is for Diese (sharp)
int f_valvePin   =  32;
int G_valvePin   =  30; 
int g_valvePin  =  28;
int A_valvePin   =  26;
int a_valvePin  =  24;
int B_valvePin   =  22;
int e_valvePin  =  12;    // Left barrel flute 
int K_valvePin  =  8;   
int k_valvePin =  7;
int Z_valvePin  =  6; 
int z_valvePin =  5;
int J_valvePin  =  4;
int j_valvePin  =  3;
int b_valvePin   =  2;

//right flute
int BreathR1_valvePin =  38;
int BreathR2_valvePin =  40;
int BreathR3_valvePin =  42;
// int BreathR4_valvePin =  44; // not used
//left flute
int BreathL1_valvePin =  9;
int BreathL2_valvePin =  10;
int BreathL3_valvePin =  11;
//int BreathL4_valvePin =  13; // not used
 

// note values
byte noteD = 11;
byte noteE = 11;
byte noteF = 11;
byte notef = 11;
byte noteG = 11;
byte noteg = 11;
byte noteA = 11;
byte notea = 11;
byte noteB = 11;
byte noted = 11;  //left flute top note
byte notee = 11;
byte noteK = 11;
byte notek = 11;
byte noteZ = 11;
byte notez = 11;
byte noteJ = 11;
byte notej = 11;
byte noteb = 11;

SoftwareSerial midiSerial(50,51); // pins for software serial RX/TX
MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, MIDI);

void setup()
{
	//set the digital pin as output:
   
  pinMode(E_valvePin,  OUTPUT);
  pinMode(F_valvePin, OUTPUT); 
  pinMode(f_valvePin,  OUTPUT); 
  pinMode(G_valvePin,  OUTPUT);
  pinMode(g_valvePin, OUTPUT);  
  pinMode(A_valvePin,  OUTPUT);
  pinMode(a_valvePin, OUTPUT);
  pinMode(B_valvePin, OUTPUT);
  pinMode(e_valvePin,  OUTPUT);
  pinMode(K_valvePin, OUTPUT); 
  pinMode(k_valvePin,  OUTPUT); 
  pinMode(Z_valvePin,  OUTPUT);
  pinMode(z_valvePin, OUTPUT);  
  pinMode(J_valvePin,  OUTPUT);
  pinMode(j_valvePin, OUTPUT);
  pinMode(b_valvePin, OUTPUT);
  pinMode(BreathL1_valvePin, OUTPUT);
  pinMode(BreathL2_valvePin, OUTPUT);
  pinMode(BreathL3_valvePin, OUTPUT);
  // pinMode(BreathL4_valvePin, OUTPUT);
  pinMode(BreathR1_valvePin, OUTPUT);
  pinMode(BreathR2_valvePin, OUTPUT);
  pinMode(BreathR3_valvePin, OUTPUT);
  // pinMode(BreathR4_valvePin, OUTPUT);
  
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
			case noteB:
				playNoteB();
				break;					
		}
	}
	if (channel == 2) {
		switch (note) { //right flute - select playable notes ONLY!!
			case noted:
				playNoted();
				break;
			case notee:
				playNotee();
				break;
			case noteK:
				playNoteK();
				break;
			case notek:
				playNotek();
				break;
			case noteZ:
				playNoteZ();
				break;
			case notez:
				playNotez();
				break;
			case noteJ:
				playNoteJ();
				break;
			case notej:
				playNotej();
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
void playNoted()
{
	digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, LOW);
	digitalWrite(e_valvePin, LOW);
	digitalWrite(K_valvePin, LOW);
    digitalWrite(k_valvePin, LOW);
    digitalWrite(Z_valvePin, LOW);
    digitalWrite(z_valvePin, LOW);
    digitalWrite(J_valvePin, LOW);
    digitalWrite(j_valvePin, LOW);
	digitalWrite(b_valvePin, LOW);
}

void playNotee()
{  
	digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, LOW);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, LOW);
    digitalWrite(k_valvePin, LOW);
    digitalWrite(Z_valvePin, LOW);
    digitalWrite(z_valvePin, LOW);
    digitalWrite(J_valvePin, LOW);
    digitalWrite(j_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNoteK()
{          
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, HIGH);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, LOW);
    digitalWrite(Z_valvePin, LOW);
    digitalWrite(z_valvePin, LOW);
    digitalWrite(J_valvePin, LOW);
    digitalWrite(j_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNotek()
{    
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, HIGH);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, HIGH);
    digitalWrite(Z_valvePin, LOW);
    digitalWrite(z_valvePin, LOW);
    digitalWrite(J_valvePin, LOW);
    digitalWrite(j_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNoteZ()
{
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, HIGH);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, HIGH);
    digitalWrite(Z_valvePin, HIGH);
    digitalWrite(z_valvePin, LOW);
    digitalWrite(J_valvePin, LOW);
    digitalWrite(j_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNotez()
{
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, HIGH);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, HIGH);
    digitalWrite(Z_valvePin, HIGH);
    digitalWrite(z_valvePin, HIGH);
    digitalWrite(J_valvePin, LOW);
    digitalWrite(j_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNoteJ()
{   
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, HIGH);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, HIGH);
    digitalWrite(Z_valvePin, HIGH);
    digitalWrite(z_valvePin, HIGH);
    digitalWrite(J_valvePin, HIGH);
    digitalWrite(j_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
}
void playNotej()
{
	digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, HIGH);
    digitalWrite(BreathL3_valvePin, LOW);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, HIGH);
    digitalWrite(Z_valvePin, HIGH);
    digitalWrite(z_valvePin, HIGH);
    digitalWrite(J_valvePin, HIGH);
    digitalWrite(j_valvePin, HIGH);
    digitalWrite(b_valvePin, LOW);
}
void playNoteb()
{
	digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, HIGH);
    digitalWrite(BreathL3_valvePin, LOW);
    digitalWrite(e_valvePin, HIGH);
    digitalWrite(K_valvePin, HIGH);
    digitalWrite(k_valvePin, HIGH);
    digitalWrite(Z_valvePin, HIGH);
    digitalWrite(z_valvePin, HIGH);
    digitalWrite(J_valvePin, HIGH); 
    digitalWrite(j_valvePin, HIGH);    
    digitalWrite(b_valvePin, HIGH);
} 

//right flute play notes
void playNoteD()
{
	digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, LOW);
	digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteE()
{
	digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, LOW);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteF()
{          
	digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNotef()
{        
	digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteG()
{
	digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteg()
{
	digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNoteA()
{
	digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
}
void playNotea()
{
	digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(BreathR3_valvePin, LOW);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(a_valvePin, HIGH);
    digitalWrite(B_valvePin, LOW);
}
void playNoteB()
{
	digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, HIGH);
    digitalWrite(BreathR3_valvePin, LOW);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(B_valvePin, HIGH);
}

//note off is breath off  
void closeBreathL()
{
	digitalWrite(BreathL1_valvePin, LOW);
    digitalWrite(BreathL2_valvePin, LOW);
    digitalWrite(BreathL3_valvePin, LOW);
}

void closeBreathR()
{
	digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
    digitalWrite(BreathR3_valvePin, LOW);
}