//  set pin numbers:       
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
int Breath1_valvePin =  38;
int Breath2_valvePin =  40;
int Breath3_valvePin =  42;
int Breath4_valvePin =  44;
//left flute
int Breath5_valvePin =  10;
int Breath6_valvePin =  11;
int Breath7_valvePin =  13;
int Breath8_valvePin =  9; 


// data array 1960 - 2010 in Million US$
int data[] = {5998, 6590, 5721, 9334, 12291, 11532, 8603, 7472, 8400, 11606, 8889, 11194, 9941, 12088, 11778, 16111, 15463, 15789, 14696, 10095, 10985, 13775, 14096, 13547, 11540, 10591, 11487, 12276, 11696, 11079, 10495, 12578, 14254, 14516, 11700, 11188, 10839, 14247, 15293, 11293, 7220, 5694, 5091, 5596, 6750, 6600, 7394, 7658, 6090, 6795, 6000};
int startYear = 1960;

//--------------------------------------------------------------------//
//setup:
void setup() {
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
  pinMode(Breath1_valvePin, OUTPUT);
  pinMode(Breath2_valvePin, OUTPUT);
  pinMode(Breath3_valvePin, OUTPUT);
  pinMode(Breath4_valvePin, OUTPUT);
  pinMode(Breath5_valvePin, OUTPUT);
  pinMode(Breath6_valvePin, OUTPUT);
  pinMode(Breath7_valvePin, OUTPUT);
  pinMode(Breath8_valvePin, OUTPUT);
  
  // Init serial link
  Serial.begin(9600);
}

//--------------------------------------------------------------------//
//main Program
void loop(){
  
  int diff; // data trend
  int i; // data index

  
  delay(1000);
  

  Serial.println("s");
  delay(500);
  Serial.println(String(startYear) + String(data[0]));
  delay(500);
  
 for (i = 1; i < 50; i++) {        //i - index 1 to 50
 
    diff = data[i] - data[i-1];
    
   Serial.println(String(startYear + i) + String(data[i]));
   delay(500);
 
    if (diff < 0){   // this will play if current number is smaller than previous
                                                     
        // oda radost                        
  
  
  ////
    playNote('g', 'x', 500, 2, 0);      
  playNote('g', 'x', 40, 0, 0);
  playNote('g', 'x', 500, 2, 0);      
  playNote('A', 'x', 500, 2, 0);
  playNote('B', 'x', 500, 3, 0);      
  playNote('B', 'x', 40, 0, 0);
  playNote('B', 'x', 500, 3, 0);
  playNote('A', 'x', 500, 2, 0);      
  playNote('g', 'x', 500, 2, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('g', 'x', 40, 0, 0);
  playNote('g', 'x', 1500, 2, 0);
  playNote('f', 'x', 500, 2, 0);      
  playNote('f', 'x', 40, 0, 0);
  playNote('f', 'x', 1500, 2, 0);
  playNote('f', 'x', 500, 0, 0);//------------------------------
  playNote('g', 'x', 500, 2, 0);      
  playNote('g', 'x', 40, 0, 0);
  playNote('g', 'x', 500, 2, 0);      
  playNote('A', 'x', 500, 2, 0);
  playNote('B', 'x', 500, 3, 0);      
  playNote('B', 'x', 40, 0, 0);
  playNote('B', 'x', 500, 3, 0);
  playNote('A', 'x', 500, 2, 0);      
  playNote('g', 'x', 500, 2, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('g', 'x', 40, 0, 0);
  playNote('f', 'x', 1500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 1500, 1, 0);
  playNote('E', 'x', 500, 0, 0);//------------------------------
  playNote('f', 'x', 500, 2, 0);      
  playNote('f', 'x', 40, 0, 0);
  playNote('f', 'x', 500, 2, 0);      
  playNote('g', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 250, 2, 0);      
  playNote('A', 'x', 250, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 250, 2, 0);      
  playNote('A', 'x', 250, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('f', 'x', 40, 0, 0);
  playNote('f', 'x', 500, 2, 0);//-----------------------------
  playNote('g', 'x', 500, 2, 0);      
  playNote('g', 'x', 40, 0, 0);
  playNote('g', 'x', 500, 2, 0);      
  playNote('A', 'x', 500, 2, 0);
  playNote('B', 'x', 500, 3, 0);      
  playNote('B', 'x', 40, 0, 0);
  playNote('B', 'x', 500, 3, 0);
  playNote('A', 'x', 500, 2, 0);      
  playNote('g', 'x', 500, 2, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('g', 'x', 40, 0, 0);
  playNote('f', 'x', 1500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 1500, 1, 0);
  playNote('E', 'x', 500, 0, 0);//------------------------------
  playNote('f', 'x', 500, 2, 0);      
  playNote('f', 'x', 40, 0, 0);
  playNote('f', 'x', 500, 2, 0);      
  playNote('g', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 250, 2, 0);      
  playNote('A', 'x', 250, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 250, 2, 0);      
  playNote('A', 'x', 250, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('f', 'x', 40, 0, 0);
  playNote('f', 'x', 500, 2, 0);//-----------------------------
  playNote('g', 'x', 500, 2, 0);      
  playNote('g', 'x', 40, 0, 0);
  playNote('g', 'x', 500, 2, 0);      
  playNote('A', 'x', 500, 2, 0);
  playNote('B', 'x', 500, 3, 0);      
  playNote('B', 'x', 40, 0, 0);
  playNote('B', 'x', 500, 3, 0);
  playNote('A', 'x', 500, 2, 0);      
  playNote('g', 'x', 500, 2, 0);
  playNote('f', 'x', 500, 2, 0);
  playNote('E', 'x', 500, 1, 0);
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('f', 'x', 500, 2, 0);
  playNote('g', 'x', 500, 2, 0);
  playNote('g', 'x', 40, 0, 0);
  playNote('f', 'x', 1500, 2, 0);
  playNote('E', 'x', 500, 1, 0);      
  playNote('E', 'x', 40, 0, 0);
  playNote('E', 'x', 1500, 1, 0);
  playNote('x', 'x', 500, 0, 0);//----------------------
                                                          
  playNote('x', 'x', 20, 0, 0);

  
  ////

  }
    else {  
  
      //Matilda
      
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 1000, 0, 3);    // 
    playNote('x', 'J', 50, 0, 0);    // pauza
    playNote('x', 'J', 250, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 250, 0, 3);    // 
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('x', 'b', 500, 0, 2);    //
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 750, 0, 3);    // 
    playNote('x', 'b', 250, 0, 2);    //
    playNote('x', 'k', 1000, 0, 3);    // 
    playNote('x', 'k', 40, 0, 0);    // pauza
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 750, 0, 3);    // 
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'k', 40, 0, 0);    // pauza
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'Z', 500, 0, 3);    // 
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'e', 500, 0, 1);    // 
    playNote('x', 'e', 40, 0, 0);    // pauza
    playNote('x', 'e', 500, 0, 1);    // 
    playNote('x', 'R', 1000, 0, 1);    //
    playNote('x', 'R', 1000, 0, 0);    // pauza  -------------------------------------------
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 250, 1, 0);    // 
    playNote('x', 'b', 250, 0, 2);    //
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'b', 500, 0, 2);    //
    playNote('x', 'k', 1000, 0, 3);    // 
    playNote('x', 'k', 40, 0, 0);    // pauza
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'k', 40, 0, 0);    // pauza
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'Z', 500, 0, 3);    // 
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'e', 500, 0, 1);    // 
    playNote('x', 'e', 40, 0, 0);    // pauza
    playNote('x', 'e', 500, 0, 1);    // 
    playNote('x', 'R', 1000, 0, 1);    //
    playNote('x', 'R', 1000, 0, 0);    // -----------------------------------------------------------
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 250, 1, 0);    // 
    playNote('x', 'b', 250, 0, 2);    //
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'b', 500, 0, 2);    //
    playNote('x', 'k', 1500, 0, 3);    // 
    playNote('x', 'k', 2500, 0, 0);    // pauza ----------------------------------------------
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'Z', 500, 0, 3);    // 
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'e', 500, 0, 1);    // 
    playNote('x', 'R', 2500, 0, 1);    // --------------------------
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 1000, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 750, 1, 0);    // 
    playNote('x', 'b', 250, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 500, 0, 2);    // 
    playNote('x', 'J', 1000, 0, 3);    // 
    playNote('x', 'J', 1000, 0, 0);    // pauza------------------------------
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'Z', 250, 0, 3);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 750, 0, 3);    // 
    playNote('D', 'x', 250, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('D', 'x', 40, 0, 0);    // pauza  
    playNote('D', 'x', 500, 1, 0);    // 
    playNote('x', 'b', 500, 0, 2);    // 
    playNote('x', 'J', 1500, 0, 3);    // 
    playNote('x', 'J', 1000, 0, 0);    // pauza------------------------  
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'b', 500, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 500, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 500, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 1000, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 250, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 250, 0, 2);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'b', 1000, 0, 2);    // 
    playNote('x', 'b', 40, 0, 0);    // pauza
    playNote('x', 'b', 500, 0, 2);    // 
    playNote('x', 'J', 500, 0, 3);    // 
    playNote('x', 'J', 40, 0, 0);    // pauza
    playNote('x', 'J', 500, 0, 3); 
    playNote('x', 'k', 500, 0, 3);    // 
    playNote('x', 'Z', 1000, 0, 3);    // 
    playNote('x', 'k', 250, 0, 3);    // 
    playNote('x', 'e', 250, 0, 1);    // 
    playNote('x', 'R', 2500, 0, 1);    //
    playNote('x', 'x', 2500, 0, 0);    //   pauza----------------------------
  
    playNote('x', 'x', 20, 0, 0);     
                                                             

   }
   
//   delay (900000);   // time 15 min between songs
     delay(3000); //temp delay 3 sec for testing

   
  }
}

//   
//****** L- tuning
// playNote('x','d', 2000, 0, 0);
// playNote('x','d', 2000, 0, 1);
// playNote('x','e', 2000, 0, 1);
// playNote('x','K', 2000, 0, 3);
// playNote('x','k', 2000, 0, 3);
// playNote('x','Z', 2000, 0, 3);
// playNote('x','z', 2000, 0, 3);
// playNote('x','J', 2000, 0, 3);
// playNote('x','j', 2000, 0, 2);
// playNote('x','b', 2000, 0, 2);

//****** D- tuning
// playNote('D','x', 2000, 0, 0);
// playNote('D','x', 2000, 1, 0);
// playNote('E','x', 2000, 1, 0);
// playNote('F','x', 2000, 2, 0);
// playNote('f','x', 2000, 2, 0);
// playNote('G','x', 2000, 2, 0);
// playNote('g','x', 2000, 2, 0);
// playNote('A','x', 2000, 2, 0);
// playNote('a','x', 2000, 3, 0);
// playNote('B','x', 2000, 3, 0);



//--------------------------------------------------------------------//
//Function:
void playNote(char noteD, char noteL, long duration, int breathD, int breathL){
  //--------------------------------------------------------------------//
  // noteD,breathD are for rigth, noteL, breathL are for left flute
  //set breath valves:
   if (breathD == 1){
    digitalWrite(38, HIGH);        //right flute
    digitalWrite(40, LOW);
    digitalWrite(42, LOW);
    //digitalWrite(44, LOW);
  }  
  else if (breathD == 2){
    digitalWrite(38, LOW);
    digitalWrite(40, LOW);
    digitalWrite(42, HIGH);
    //digitalWrite(44, LOW);
  }  
  else if (breathD == 3){            
    digitalWrite(38, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(42, LOW);
    //digitalWrite(44, LOW);
  }
  else if (breathD == 4){
    digitalWrite(38, LOW);
    digitalWrite(40, LOW);
    digitalWrite(42, LOW);
    //digitalWrite(44, HIGH);
     } 
  else {  
    digitalWrite(38, LOW);
    digitalWrite(40, LOW);
    digitalWrite(42, LOW);
    //digitalWrite(44, LOW);
  }
  
  if (breathL == 1){              //left flute
    digitalWrite(9, HIGH);        
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    //digitalWrite(13, LOW);
  }  
  else if (breathL == 2){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    //digitalWrite(13, LOW);
  }  
  else if (breathL == 3){            
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    //digitalWrite(13, LOW);
  }
  else if (breathL == 4){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    //digitalWrite(13, HIGH);
     } 
  else {  
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    //digitalWrite(13, LOW);
  }
  //--------------------------------------------------------------------//
  //set noteD valves. Note D - default LOW 
 
if (noteD == 'E'){
    digitalWrite(36, HIGH);
    digitalWrite(34, LOW);
    digitalWrite(32, LOW);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }  
  else if (noteD == 'F'){          
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, LOW);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
  else if (noteD == 'f'){        
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }

  else if (noteD == 'G'){
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
  else if (noteD == 'g'){
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
  else if (noteD == 'A'){
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
  else if (noteD == 'a'){
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(26, LOW);
    digitalWrite(24, HIGH);
    digitalWrite(22, LOW);
  }
  else if (noteD == 'B'){
    digitalWrite(36, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(24, LOW);
    digitalWrite(22, HIGH);
  }
  else {
    digitalWrite(36, LOW);
    digitalWrite(34, LOW);
    digitalWrite(32, LOW);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
  
  if (noteL == 'e'){
   
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(12, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (noteL == 'K'){        
  
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
     digitalWrite(12, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (noteL == 'k'){
    
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
     digitalWrite(12, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (noteL == 'Z'){

    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
     digitalWrite(12, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
   else if (noteL == 'z'){

    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
     digitalWrite(12, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
   else if (noteL == 'J'){
   
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (noteL == 'j'){

    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (noteL == 'b'){

    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH);    
    digitalWrite(4, HIGH);
  } 
  else {

    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(12, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  delay(duration);
  
}
