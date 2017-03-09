//  set pin numbers:       
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
 


// data array 1960 - 2010 in Million US$
int data[] = {5998, 6590, 5721, 9334, 12291, 11532, 8603, 7472, 8400, 11606, 8889, 11194, 9941, 12088, 11778, 16111, 15463, 15789, 14696, 10095, 10985, 13775, 14096, 13547, 11540, 10591, 11487, 12276, 11696, 11079, 10495, 12578, 14254, 14516, 11700, 11188, 10839, 14247, 15293, 11293, 7220, 5694, 5091, 5596, 6750, 6600, 7394, 7658, 6090, 6795, 6000};
int startYear = 1960;

//--------------------------------------------------------------------//
//setup:
void setup() {
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

  
  // Init serial link
  delay(10000); 
  Serial.begin(115200);

  Serial.println("c");
}

//-------------------------------------------------------------------//
//main Program
void loop(){

  
  int diff; // data trend
  int i; // data index

  
  delay(1000);
  

  Serial.println("s0000");
  delay(500);
  Serial.println(String(startYear) + String(data[0]));
  delay(500);
  
 for (i = 1; i < 50; i++) {        //i - index 1 to 50
 
    diff = data[i] - data[i-1];
    
   Serial.println(String(startYear + i) + String(data[i]));
   delay(500);
 
    if (diff < 0){   // this will play if current number is smaller than previous

        // oda na radosta
playNote('x','F', 1600, 0, 0);//PAUSA NE SVIRI!!!  TEMA 2 :
playNote('x','D', 300, 0, 1);
playNote('x','D', 40, 0, 0);//pausa
playNote('x','D', 100, 0, 1);
playNote('x','D', 40, 0, 0);//pausa
playNote('x','D', 200, 0, 1);
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','G', 200, 0, 2);//1takt
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','F', 200, 0, 2);
playNote('x','G', 300, 0, 2);
playNote('x','E', 100, 0, 1); 
playNote('x','C', 200, 0, 1);//2takt
playNote('x','D', 300, 0, 1);
playNote('x','D', 40, 0, 0);//pausa
playNote('x','D', 100, 0, 1);
playNote('x','D', 40, 0, 0);//pausa
playNote('x','D', 200, 0, 1);
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','G', 200, 0, 2);//3takt
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','F', 200, 0, 2);
playNote('x','G', 300, 0, 2);
playNote('x','E', 100, 0, 1);
playNote('x','C', 200, 0, 1);//4takt
playNote('x','F', 300, 0, 2);
playNote('x','E', 100, 0, 1);
playNote('x','F', 200, 0, 2);
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','A', 200, 0, 2);//5 takt
playNote('b','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 200, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','A', 200, 0, 2);//6 takt
playNote('x','F', 300, 0, 2);
playNote('x','E', 100, 0, 1);
playNote('x','F', 200, 0, 2);
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','A', 200, 0, 2);//7 takt
playNote('b','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 200, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','A', 200, 0, 2);//8 takt
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('a','x', 200, 1, 0);
playNote('a','x', 40, 0, 0);//pausa
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('a','x', 200, 1, 0);//9 takt
playNote('b','x', 300, 1, 0);
playNote('a','x', 100, 1, 0);
playNote('a','x', 40, 0, 0);//pausa
playNote('a','x', 200, 1, 0);
playNote('a','x', 40, 0, 0);//pausa 
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','G', 200, 0, 2);//10 takt
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','A', 200, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','A', 200, 0, 2);//11takt
playNote('b','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 200, 0, 2);
playNote('x','A', 40, 0, 0);//pausa
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','F', 200, 0, 2);//12takt
playNote('x','G', 300, 0, 2);
playNote('x','F', 100, 0, 2);
playNote('x','G', 200, 0, 2);
playNote('x','G', 40, 0, 0);//pausa
playNote('x','G', 300, 0, 2);
playNote('x','F', 100, 0, 2);
playNote('x','G', 200, 0, 2);//13 takt
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','G', 200, 0, 2);
playNote('x','D', 300, 0, 1);
playNote('x','G', 100, 0, 2);
playNote('x','G', 40, 0, 0);//pausa
playNote('x','G', 200, 0, 2);
playNote('x','G', 40, 0, 0);//14 takt
playNote('x','G', 300, 0, 2);
playNote('x','F', 100, 0, 2);
playNote('x','G', 200, 0, 2);
playNote('x','G', 40, 0, 0);
playNote('x','G', 300, 0, 2);
playNote('x','F', 100, 0, 2);
playNote('x','G', 200, 0, 2);//15 takt
playNote('a','x', 300, 1, 0);
playNote('x','A', 100, 0, 2);
playNote('x','G', 200, 0, 2);
playNote('x','A', 300, 0, 2);
playNote('x','G', 100, 0, 2);
playNote('x','F', 200, 0, 2);
playNote('x','G', 1600, 0, 2);//16 takt 
playNote('x','X', 40, 0, 0);  //kraj// povtarja ot nacalo//


  }
    else {  
  
      //Matilda
//   THE LAST OF THE MOHICANS

playNote('g','x', 1200, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('x','F', 200, 0, 2);
playNote('x','C', 1200, 0, 1);
playNote('x','F', 200, 0, 2);
playNote('g','x', 200, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('a','x', 3000, 1, 0);
playNote('g','x', 200, 2, 0);
playNote('b','x', 1000, 1, 0);
playNote('a','x', 200, 1, 0);
playNote('g','x', 200, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('a','x', 1200, 1, 0);
playNote('x','G', 200, 0, 2);
playNote('x','G', 40, 0, 0);//pausa
playNote('x','G', 200, 0, 2);
playNote('x','F', 3000, 0, 2);//prima volta
playNote('g','x', 1200, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('x','F', 200, 0, 2);
playNote('x','C', 1200, 0, 1);
playNote('x','F', 200, 0, 2);
playNote('g','x', 200, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('a','x', 1200, 1, 0);
playNote('g','x', 200, 2, 0);
playNote('x','G', 1600, 0, 2);
playNote('g','x', 200, 2, 0);
playNote('b','x', 1000, 2, 0);
playNote('a','x', 200, 2, 0);
playNote('g','x', 200, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('a','x', 1200, 1, 0);
playNote('x','G', 200, 0, 2);
playNote('x','G', 40, 0, 0);//pausa
playNote('x','G', 200, 0, 2);
playNote('x','F', 2200, 0, 2);//secunda volta
playNote('g','x', 400, 2, 0);
playNote('x','G', 400, 0, 2);
playNote('x','F', 800, 0, 2);
playNote('x','F', 40, 0, 0);//pausa
playNote('x','F', 400, 0, 2);
playNote('d','x', 400, 2, 0);
playNote('x','C', 800, 0, 1);
playNote('g','x', 400, 2, 0);
playNote('x','G', 400, 0, 2);
playNote('x','F', 800, 0, 2);
playNote('x','F', 40, 0, 0);//pausa
playNote('x','F', 400, 0, 2);
playNote('d','x', 400, 2, 0);
playNote('b','x', 800, 1, 0);
playNote('g','x', 400, 2, 0);
playNote('a','x', 400, 1, 0);
playNote('b','x', 800, 1, 0);
playNote('a','x', 400, 1, 0); 
playNote('g','x', 400, 2, 0);
playNote('x','G', 200, 0, 2);
playNote('a','x', 1000, 1, 0);
playNote('x','G', 400, 0, 2);
playNote('x','G', 40, 0, 0);//pausa
playNote('x','G', 400, 0, 2);
playNote('x','F', 2800, 0, 2);//trio volta
playNote('x','X', 40, 0, 0);  //kraj// povtarja ot nacalo//


   }
   
   delay (1000000);   // time 15 min between songs
  //   delay(3000); //temp delay 3 sec for testing
 //   delay(60000);  // temp 1 min video
   
  }
}


//--------------------------------------------------------------------//
//Function:
void playNote(char noteR, char noteL, long duration, int breathR, int breathL){
  //--------------------------------------------------------------------//
  // noteR,breathD are for rigth, noteL, breathL are for left flute
  //set breath valves:
   if (breathR == 1){
    digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, LOW);
  }  
  else if (breathR == 2){
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, HIGH);
  }  
  else if (breathR == 3){            
    digitalWrite(BreathR1_valvePin, HIGH);
    digitalWrite(BreathR2_valvePin, HIGH);
  }
  else {  
    digitalWrite(BreathR1_valvePin, LOW);
    digitalWrite(BreathR2_valvePin, LOW);
  }
  
  if (breathL == 1){              //left flute
    digitalWrite(BreathL1_valvePin, HIGH);
    digitalWrite(BreathL2_valvePin, LOW);
  }  
  else if (breathL == 2){
   digitalWrite(BreathL1_valvePin, LOW);
   digitalWrite(BreathL2_valvePin, HIGH);
  }  
  else if (breathL == 3){            
   digitalWrite(BreathL1_valvePin, HIGH);
   digitalWrite(BreathL2_valvePin, HIGH);
  }
  else {  
   digitalWrite(BreathL1_valvePin, LOW);
   digitalWrite(BreathL2_valvePin, LOW);
  }
  //--------------------------------------------------------------------//
  //set noteR valves. Note D - default LOW 
 
if (noteR == 'd'){
  
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
  }  
  else if (noteR == 'l'){     
    
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
  }
  else if (noteR == 'f'){      
    
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
  }

  else if (noteR == 'g'){
    
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
  }
  else if (noteR == 'a'){
    
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(a_valvePin, HIGH);
    digitalWrite(b_valvePin, LOW);
  }
  else if (noteR == 'b'){
    
    digitalWrite(d_valvePin, HIGH);
    digitalWrite(l_valvePin, HIGH);
    digitalWrite(f_valvePin, HIGH);
    digitalWrite(g_valvePin, HIGH);
    digitalWrite(a_valvePin, HIGH);
    digitalWrite(b_valvePin, HIGH);
  }
  else {
    
    digitalWrite(d_valvePin, LOW);
    digitalWrite(l_valvePin, LOW);
    digitalWrite(f_valvePin, LOW);
    digitalWrite(g_valvePin, LOW);
    digitalWrite(a_valvePin, LOW);
    digitalWrite(b_valvePin, LOW);
  }
  
  if (noteL == 'D'){
   
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
  }
  else if (noteL == 'E'){        
  
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
  }
  else if (noteL == 'F'){
    
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
  }
  else if (noteL == 'G'){
    
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
  }
   else if (noteL == 'A'){

    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(B_valvePin, LOW);
  }
   else if (noteL == 'B'){
   
    digitalWrite(D_valvePin, HIGH);
    digitalWrite(E_valvePin, HIGH);
    digitalWrite(F_valvePin, HIGH);
    digitalWrite(G_valvePin, HIGH);
    digitalWrite(A_valvePin, HIGH);
    digitalWrite(B_valvePin, HIGH);
  }
  else {

    digitalWrite(D_valvePin, LOW);
    digitalWrite(E_valvePin, LOW);
    digitalWrite(F_valvePin, LOW);
    digitalWrite(G_valvePin, LOW);
    digitalWrite(A_valvePin, LOW);
    digitalWrite(B_valvePin, LOW);
  } 
  delay(duration);
  
}

