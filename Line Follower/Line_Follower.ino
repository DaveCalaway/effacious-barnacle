/*
 * Line Follower without enable (no high impedance state)
 * Sensor's eyes: 
 *                0 = black-line
 *                1 = white 
 * Led on for panic!
 * DaveCalaway
 */
int senSX, senCX, senDX = 0;
int runSX = 3;
int runDX = 9;
int forwSX = 5;
int forwDX = 6;
int led = 13;

void setup() {
  pinMode(runSX,OUTPUT); 
  pinMode(runDX,OUTPUT); 
  pinMode(forwSX,OUTPUT); 
  pinMode(forwDX,OUTPUT); 
  pinMode(0,INPUT);  // senSX
  pinMode(1,INPUT);  // senCX
  pinMode(2,INPUT);  // senDX
  pinMode(led,OUTPUT);
}

void loop() {
  
  // read for a sensors
  senSX = digitalRead(0);
  senCX = digitalRead(1);
  senDX = digitalRead(2);
  
  digitalWrite(led,LOW);
  
  // riga al centro
  if(senSX == 1 && senCX== 0 && senDX == 1){
    digitalWrite(runSX,HIGH);
    digitalWrite(runDX,HIGH);
  }
  
  // riga a sinistra
  if(senSX == 0 && senCX== 1 && senDX == 1){
    digitalWrite(runSX,LOW);
    digitalWrite(runDX,HIGH);
  }
  
  // riga a destra
  if(senSX == 1 && senCX== 1 && senDX == 0){
    digitalWrite(runSX,HIGH);
    digitalWrite(runDX,LOW);
  }

  // fermo! dove sono? lampeggio così mi aiuti
  else{
    digitalWrite(runSX,LOW);
    digitalWrite(runDX,LOW);
    digitalWrite(led,HIGH);
    delay(1000)
  }
  
}
