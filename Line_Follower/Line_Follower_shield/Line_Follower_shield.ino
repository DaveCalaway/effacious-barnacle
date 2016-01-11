/*Version 0.2
 * 
 * Library referece: https://goo.gl/D9dSPh
 * Line Follower shield , with high impedance state "RELEASE".
 * Sensor's eyes: 
 *                0 = black-line
 *                1 = white 
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
void readsen();

void setup() {
  pinMode(A1,INPUT);  // senSX
  pinMode(A2,INPUT);  // senCX
  pinMode(A3,INPUT);  // senDX
  m_SX.setSpeed(200);     // set the speed to 200/255
  m_DX.setSpeed(200);
  Serial.begin(9600);
}

void loop() {
 
  readsen();
  digitalWrite(led,LOW);
  
  // AVANTI
    //analogWrite(runSX,pwm);
    m_SX.run(FORWARD);
    //analogWrite(runDX,pwm);
    m_DX.run(FORWARD);
    Serial.println("Dritto");
    delay(100);
  
  // RIGA A SINISTRA
  if(senSX == 0 && senCX == 1 && senDX == 1){
    Serial.println("sinistra");
    // rimettimi al centro
    while(senCX!=0){ 
      //analogWrite(runDX,pwm);
      m_DX.run(FORWARD);
      //digitalWrite(runSX,LOW);
      m_SX.run(RELEASE);
      readsen();
    }
  }
  
  // RIGA A DESTRA
  if(senSX == 1 && senCX == 1 && senDX == 0){
    Serial.println("destra");
    // rimettimi al centro
    while(senCX!=0){
      //analogWrite(runSX,pwm);
      m_SX.run(FORWARD);
      //digitalWrite(runDX,LOW);
      m_DX.run(RELEASE);
      readsen();
    }    
  }
  
  // TUTTO NERO
  if(senSX == 0 && senCX == 0 && senDX == 0){
    //digitalWrite(runSX,LOW);
    m_SX.run(RELEASE);
    //digitalWrite(runDX,LOW);
    m_DX.run(RELEASE);
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
