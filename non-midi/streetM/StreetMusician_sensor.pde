//  set pin numbers: 
int D_valvePin =  2;      // the number of the LED pin
int E_valvePin =  3;
int f_valvePin =  4;
int F_valvePin =  5;
int g_valvePin =  6; 
int G_valvePin =  7;
int A_valvePin =  8;
int a_valvePin =  9;
int Breath1_valvePin =  10;
int Breath2_valvePin =  11;
int Breath3_valvePin =  12;
int sensor[] = {0, 0, 0, 0};
int sensorPin = 0;
int max1 = 0;
int max2 = 0;
int maxmax = 0;
int min1 = 0;
int min2 = 0;
int minmin = 0;
int melody = 0;

//--------------------------------------------------------------------//
//setup:
void setup() {
  //set the digital pin as output:
   pinMode(sensorPin, INPUT); 
  pinMode(D_valvePin, OUTPUT); 
  pinMode(E_valvePin, OUTPUT); 
  pinMode(f_valvePin, OUTPUT);
  pinMode(F_valvePin, OUTPUT);  
  pinMode(g_valvePin, OUTPUT);
  pinMode(G_valvePin, OUTPUT);
  pinMode(A_valvePin, OUTPUT);
  pinMode(a_valvePin, OUTPUT);
  pinMode(Breath1_valvePin, OUTPUT);
  pinMode(Breath2_valvePin, OUTPUT);
  pinMode(Breath3_valvePin, OUTPUT);
  Serial.begin(9600);
}

//--------------------------------------------------------------------//
//main Program
void loop(){

//  Serial.print("start");
//  Serial.println();
  
  for (int x=0; x < 4; x++) {
    sensor[x] = analogRead(sensorPin);
    delay(40);
  }
  max1 = max(sensor[0], sensor[1]);
  max2 = max(sensor[2], sensor[3]);
  min1 = min(sensor[0], sensor[1]);
  min2 = min(sensor[2], sensor[3]);
  
  maxmax = max(max1, max2);
  minmin = min(min1, min2);
  
  
  if ((maxmax - minmin) > 60) {

     melody ++;
     if (melody == 4) {  melody = 1;}
     
     switch (melody) {
       case 1:
          dilmano();
          break;
       case 2:
          ergeni();
          break;
       case 3:
          cvete();
          break;
      // default:
          // pass 
     }
  }

}
      
 
void dilmano()
{
//Dilmano    
playNote('C', 500, 1);
playNote('f', 500, 2);
playNote('g', 250, 3);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('C', 40, 0);
playNote('C', 750, 1);
playNote('C', 40, 1);
playNote('C', 500, 1);
playNote('f', 500, 2);
playNote('g', 250, 3);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('C', 40, 0);
playNote('C', 750, 1);
playNote('C', 40, 0);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('C', 40, 0);
playNote('C', 750, 1);
playNote('C', 40, 0);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('C', 40, 0);
playNote('C', 750, 1);
playNote('C', 40, 0);
playNote('C', 500, 1);
playNote('g', 500, 3);
playNote('A', 250, 3);
playNote('g', 500, 3);
playNote('f', 250, 2);
playNote('f', 40, 0);
playNote('f', 250, 2);
playNote('E', 250, 1);
playNote('f', 500, 2);
playNote('E', 125, 1);
playNote('D', 125, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 500, 1);
playNote('g', 500, 3);
playNote('A', 250, 3);
playNote('g', 500, 3);
playNote('f', 250, 2);
playNote('f', 40, 0);
playNote('f', 250, 2);
playNote('E', 250, 1);
playNote('f', 500, 2);
playNote('E', 125, 1);
playNote('D', 125, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 250, 1);
playNote('D', 250, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('f', 500, 2);
playNote('E', 250, 1);
playNote('g', 500, 3);
playNote('f', 250, 2);
playNote('C', 500, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('D', 40, 0);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('D', 250, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('f', 500, 2);
playNote('E', 250, 1);
playNote('g', 500, 3);
playNote('f', 250, 2);
playNote('C', 500, 1);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('D', 40, 0);
playNote('D', 750, 1);
playNote('C', 500, 1);
playNote('f', 500, 2);
playNote('g', 250, 3);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 500, 1);
playNote('D', 500, 1);
playNote('C', 250, 1);
playNote('C', 40, 0);
playNote('C', 750, 1);
playNote('C', 40, 0);
playNote('C', 500, 1);
playNote('f', 500, 2);
playNote('g', 250, 3);
playNote('E', 500, 1);
playNote('D', 250, 1);
playNote('C', 1000, 1);
playNote('D', 1000, 1);
playNote('C', 500, 1);
playNote('C', 40, 0);
playNote('C', 1500, 1);
playNote('C', 1000, 0);

//end - Dilmano

playNote('x', 20, 0);

}

void ergeni()
{
  // Ergeni
    playNote('g', 500, 3);
    playNote('a', 500, 3);
    playNote('a', 40, 0);
    playNote('a', 500, 3);
    playNote('g', 250, 3);
    playNote('a', 1000, 3);
    playNote('g', 750, 3);
    playNote('a', 500, 3); 
    playNote('g', 500, 3);
    playNote('G', 500, 2);
    playNote('E', 250, 1);
    playNote('g', 1000, 3);
    playNote('E', 750, 1);
    playNote('a', 500, 3);
    playNote('g', 500, 3);
    playNote('G', 500, 2);
    playNote('E', 250, 1);
    playNote('G', 1000, 2);
    playNote('E', 500, 1);
    playNote('D', 250, 1);// 1 KOLJANO
    playNote('C', 500, 1);
    playNote('D', 500, 1);
    playNote('D', 40, 0);
    playNote('D', 500, 1);
    playNote('D', 40, 3); 
    playNote('D', 250, 1);
    playNote('g', 1000, 3);
    playNote('g', 40, 0);
    playNote('g', 750, 3);
    playNote('a', 500, 3);//POVTORENIE
    playNote('g', 500, 3);
    playNote('G', 500, 2);
    playNote('E', 250, 1);
    playNote('G', 1000, 2);
    playNote('E', 500, 1);
    playNote('D', 250, 1);
    playNote('C', 500, 1);
    playNote('D', 500, 1);
    playNote('D', 40, 0);
    playNote('D', 500, 1);
    playNote('D', 40, 0); 
    playNote('D', 250, 1); 
    playNote('D', 40, 0);
    playNote('D', 1000, 1);
    playNote('D', 40, 0);
    playNote('D', 750, 1);
    playNote('D', 40, 0);// 2KOLJANO
    playNote('E', 500, 1);
    playNote('E', 40, 0);
    playNote('E', 500, 1);
    playNote('E', 40, 0);
    playNote('E', 500, 1);
    playNote('E', 40, 0);
    playNote('E', 250, 1);
    playNote('E', 40, 0); 
    playNote('E', 500, 1);
    playNote('D', 500, 1);
    playNote('C', 750, 1);//1 PAT
    playNote('E', 500, 1);
    playNote('E', 40, 0);
    playNote('E', 500, 1);
    playNote('E', 40, 0);
    playNote('E', 500, 1);
    playNote('E', 40, 0);
    playNote('E', 250, 1);
    playNote('E', 40, 0); 
    playNote('E', 500, 1);
    playNote('D', 500, 1);
    playNote('C', 750, 1);//2 PAT
    playNote('a', 500, 3);
    playNote('g', 500, 3);
    playNote('g', 40, 0);
    playNote('g', 500, 3);
    playNote('g', 40, 0);
    playNote('g', 250, 3);
    playNote('G', 1000, 2); 
    playNote('E', 500, 1);
    playNote('D', 250, 1);
    playNote('C', 500, 1);
    playNote('D', 500, 1);
    playNote('D', 40, 0);
    playNote('D', 500, 1);
    playNote('D', 40, 0); 
    playNote('D', 250, 1); 
    playNote('D', 40, 0);
    playNote('D', 1000, 1);
    playNote('D', 40, 0);
    playNote('D', 750, 1);
    playNote('D', 1000, 0);//        KRAJ----------------------------------

  //End - Ergeni

   playNote('x', 20, 0);

}

void cvete()
{
    //cvete shareno
playNote('C', 750, 1);// 
playNote('C', 40, 0);
playNote('C', 500, 1);
playNote('F', 500, 2);
playNote('g', 1750, 3);
playNote('g', 40, 0);
playNote('g', 750, 3);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('D', 500, 1);
playNote('f', 250, 2);
playNote('f', 40, 0);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('D', 500, 1);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('F', 40, 0);
playNote('F', 1750, 2);// 1VO KOLJANO
playNote('C', 750, 1);
playNote('C', 40, 0);
playNote('C', 500, 1);
playNote('F', 500, 2);
playNote('g',1750, 3);
playNote('g', 40, 0);
playNote('g', 750, 3);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('D', 500, 1);
playNote('f', 250, 2);
playNote('f', 40, 0);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('D', 500, 1);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('f', 40, 0);
playNote('F', 1750, 2);//2 KOLJANO
playNote('C', 750, 1);
playNote('F', 500, 2);
playNote('D', 250, 1);
playNote('C', 250, 1);
playNote('D', 1750, 1);
playNote('C', 500, 1);
playNote('D', 250, 1);
playNote('F', 250, 2);
playNote('f', 250, 2);
playNote('g', 500, 3);
playNote('g', 40, 0);
playNote('g', 250, 3);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('D', 250, 1);
playNote('F', 250, 2);
playNote('D', 250, 1);
playNote('C', 250, 1);
playNote('C', 40, 0);
playNote('C', 1750, 1);
playNote('C', 40, 0);//3 KOLJANO
playNote('C', 750, 1);
playNote('F', 500, 2);
playNote('D', 250, 1);
playNote('C', 250, 1);
playNote('D', 1750, 1);
playNote('C', 500, 1);
playNote('D', 250, 1);
playNote('F', 250, 2);
playNote('f', 250, 2);
playNote('g', 500, 3);
playNote('g', 40, 0);
playNote('g', 250, 3);
playNote('f', 250, 2);
playNote('F', 250, 2);
playNote('D', 250, 1);
playNote('F', 250, 2);
playNote('D', 250, 1);
playNote('C', 250, 1);
playNote('C',40, 0);
playNote('C', 1750, 1);
playNote('C', 3000, 0);

playNote('x', 20, 0);

// end cvete sharen o
}
 
  

//--------------------------------------------------------------------//
//Function:
void playNote(char note, long duration, int breath){
  //--------------------------------------------------------------------//
  //set breath valves:
   if (breath == 1){
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }  
  else if (breath == 2){
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
     }  
  else if (breath == 3){
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
  else if (breath == 4){
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
  else {  
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  //--------------------------------------------------------------------//
  //set note valves: 
 
  if (note == 'D'){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }  
  else if (note == 'E'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  else if (note == 'F'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (note == 'f'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (note == 'G'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (note == 'g'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

  }
  else if (note == 'A'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if (note == 'a'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
 
  }
  else if (note == 'B'){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  delay(duration);
}



























