 /*Version 0.4
 * 
 * Library referece: https://goo.gl/D9dSPh
 * Line Follower shield , with high impedance state "RELEASE".
 * Sensor's eyes: 
 *                1 = black-line - led spento
 *                0 = white - led acceso
 * Led on for panic!
 * 
 * DaveCalaway
 */
#include <SoftwareSerial.h>
#include <AFMotor.h>

// motor define
AF_DCMotor m_SX(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor m_DX(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
 
int led = 13;
int senSX, senCX, senDX = 0;


void setup() {
  pinMode(A0,INPUT);  // senSX
  pinMode(A1,INPUT);  // senCX
  pinMode(A2,INPUT);  // senDX
  m_SX.setSpeed(70);     // set the speed to 0/255
  m_DX.setSpeed(70);
  Serial.begin(9600);
}

void loop() {
 
  readsen();
  digitalWrite(led,LOW);

   // RIGA A DESTRA
  if(senSX == 0 && senCX == 0 && senDX == 1){
    Serial.println("destra");
    // rimettimi al centro
    while(senCX!=1){
      //analogWrite(runSX,pwm);
      m_SX.run(FORWARD);
      //digitalWrite(runDX,LOW);
      m_DX.run(RELEASE);
      readsen();
    } 
  }   
  
  // RIGA A SINISTRA
  if(senSX == 1 && senCX == 0 && senDX == 0){
    Serial.println("sinistra");
    // rimettimi al centro
    while(senCX!=1){ 
      //analogWrite(runDX,pwm);
      m_DX.run(FORWARD);
      //digitalWrite(runSX,LOW);
      m_SX.run(RELEASE);
      readsen();
    }
  }

  // TUTTO NERO
  if(senSX == 1 && senCX == 1 && senDX == 1){
    //digitalWrite(runSX,LOW);
    m_SX.run(RELEASE);
    //digitalWrite(runDX,LOW);
    m_DX.run(RELEASE);
    digitalWrite(led,HIGH);
    Serial.println("dove sono?");
    delay(2000);
  }

    // AVANTI
  else{
    //analogWrite(runSX,pwm);
    m_SX.run(FORWARD);
    //analogWrite(runDX,pwm);
    m_DX.run(FORWARD);
    Serial.println("Dritto");
  }
}

 // read sensors
void readsen(){
  senSX = digitalRead(A0);
  senCX = digitalRead(A1);
  senDX = digitalRead(A2);
}

