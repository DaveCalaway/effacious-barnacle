#include <SoftwareSerial.h>

/*
 * Line Follower without enable (no high impedance state) and forword.
 * Sensor's eyes: 
 *                0 = black-line
 *                1 = white 
 * Led on for panic!
 * DaveCalaway
 */
 
int senSX, senCX, senDX = 0;
int runSX = 3;
int runDX = 9;
//int forwSX = 5;
//int forwDX = 6;
int led = 13;
int pwm=100; // 0-255
void readsen();

void setup() {
  pinMode(runSX,OUTPUT); 
  pinMode(runDX,OUTPUT); 
//  pinMode(forwSX,OUTPUT); 
//  pinMode(forwDX,OUTPUT); 
  pinMode(10,INPUT);  // senSX
  pinMode(11,INPUT);  // senCX
  pinMode(12,INPUT);  // senDX
  Serial.begin(9600);
  
}

void loop() {
 
  readsen();
  digitalWrite(led,LOW);
  
  // avanti
    analogWrite(runSX,pwm);
    analogWrite(runDX,pwm);
    //digitalWrite(runSX,HIGH);
    //digitalWrite(runDX,HIGH);
    Serial.println("Dritto");
    delay(100);
  
  // riga a sinistra
  if(senSX == 0 && senCX == 1 && senDX == 1){
    Serial.println("sinistra");
    // rimettimi al centro
    while(senCX!=0){ 
      analogWrite(runDX,pwm);
      digitalWrite(runSX,LOW);
      //digitalWrite(runDX,HIGH);
      readsen();
    }
  }
  
  // riga a destra
  if(senSX == 1 && senCX == 1 && senDX == 0){
    Serial.println("destra");
    // rimettimi al centro
    while(senCX!=0){
      analogWrite(runSX,pwm);
      //digitalWrite(runSX,HIGH);
      digitalWrite(runDX,LOW);
      readsen();
    }    
  }
  
  // tutto nero
  if(senSX == 0 && senCX == 0 && senDX == 0){
    digitalWrite(runSX,LOW);
    digitalWrite(runDX,LOW);
    digitalWrite(led,HIGH);
    Serial.println("dove sono?");
    delay(1000);
  }
  
}

 // read for a sensors
void readsen(){
  senSX = digitalRead(10);
  senCX = digitalRead(11);
  senDX = digitalRead(12);
}
