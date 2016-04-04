/* Version 0.2

  Library referece: https://goo.gl/D9dSPh
  Line Follower shield , with high impedance state "RELEASE" and "BACKWARD".
  Sensor's eyes:
                 1 = black-line - led spento
                 0 = white - led acceso
  Led on for panic!

  DaveCalaway
*/
#include <SoftwareSerial.h>
#include <AFMotor.h>

// motor define
AF_DCMotor m_SX(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor m_DX(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

int led = 13;
int senSX, senCX, senDX = 0;


void setup() {
  pinMode(A0, INPUT); // senSX
  pinMode(A1, INPUT); // senCX
  pinMode(A2, INPUT); // senDX
  m_SX.setSpeed(70);     // set the speed to 0/255
  m_DX.setSpeed(70);
}

void loop() {

  readsen();
  digitalWrite(led, LOW);

  // AVANTI
  m_SX.run(FORWARD);
  m_DX.run(FORWARD);

  // RIGA A DESTRA
  if (senSX == 0 && senCX == 0 && senDX == 1) 
    m_DX.run(BACKWARD);

  // RIGA A SINISTRA
  if (senSX == 1 && senCX == 0 && senDX == 0)
    m_SX.run(BACKWARD);

  // TUTTO NERO
  if (senSX == 1 && senCX == 1 && senDX == 1) {
    m_SX.run(RELEASE);
    m_DX.run(RELEASE);
    digitalWrite(led, HIGH);
    delay(2000);
  }
}
// read sensors
void readsen() {
  senSX = digitalRead(A0);
  senCX = digitalRead(A1);
  senDX = digitalRead(A2);
}

