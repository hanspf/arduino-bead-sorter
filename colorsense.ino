/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// TCS230 or TCS3200 pins wiring to Arduino
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

#define RED 2
#define GREEN 12
#define BLUE 13

#define RGBR 11
#define RGBG 3
#define RGBB 10

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

// Stores the red. green and blue colors
float redColor = 0;
float greenColor = 0;
float blueColor = 0;

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

   pinMode(RGBR, OUTPUT);
  pinMode(RGBG, OUTPUT);
  pinMode(RGBB, OUTPUT);
  
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);
}

void loop() {
  
  
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  delay(50);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  redFrequency = redFrequency;
  // Remaping the value of the RED (R) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  //redColor = redFrequency;
  // redColor = map(redFrequency, 70, 120, 255,0);
  //redColor = map(redFrequency, XX, XX, 255,0);
  
  // Printing the RED (R) value
  //Serial.print("R = ");
  //Serial.print(redFrequency);
  
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);

  delay(50);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  greenFrequency = greenFrequency;
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  //greenColor = greenFrequency;
   //greenColor = map(greenFrequency, 100, 199, 255, 0);
  //greenColor = map(greenFrequency, XX, XX, 255, 0);
  
  // Printing the GREEN (G) value  
  //Serial.print(" G = ");
  //Serial.print(greenFrequency);
 
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  delay(50);
   
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  blueFrequency = blueFrequency;
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  //blueColor = blueFrequency;
   //blueColor = map(blueFrequency, 38, 84, 255, 0);
  //blueColor = map(blueFrequency, XX, XX, 255, 0);
  
  // Printing the BLUE (B) value 
  //Serial.print(" B = ");
  //Serial.print(blueFrequency);
  //delay(100);

  float sum = redFrequency + greenFrequency + blueFrequency;

  
  redColor = map(redFrequency, sum - redFrequency, 0, 0,255) * 0.85;
  greenColor = map(greenFrequency, sum - greenFrequency, 0, 0,255) * 1.05;
  blueColor = map(blueFrequency, sum - blueFrequency, 0, 0,255) * 0.8;


  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
  analogWrite(RGBR, 255);
    analogWrite(RGBG, 255);
    analogWrite(RGBB, 255);
  

  Serial.println("");
  Serial.print(redColor);
  Serial.print(":");
  Serial.print(greenColor);
  Serial.print(":");
  Serial.print(blueColor);


 

  analogWrite(RGBR, redColor);
  analogWrite(RGBG, greenColor);
  analogWrite(RGBB, blueColor);

 if(redColor > greenColor && redColor > blueColor)
 {
  digitalWrite(RED, HIGH);
  Serial.println(" - RED detected!");
 
 }

 if(greenColor > redColor && greenColor > blueColor)
 {
  digitalWrite(GREEN, HIGH);
  Serial.println(" - GREEN detected!");
 
 }
 if(blueColor > redColor && blueColor > greenColor)
 {
  digitalWrite(BLUE, HIGH);
  Serial.println(" - BLUE detected!");
 }
  

  // Checks the current detected color and prints
  // a message in the serial monitor
 // if(redFrequency < greenFrequency && redFrequency < blueFrequency){
 //     Serial.println(" - RED detected!");
 // }
 // if(greenFrequency < redFrequency && greenFrequency < blueFrequency){
 //   
 // }
 // if(blueFrequency < redFrequency && blueFrequency < greenFrequency){
    
 // }
}
