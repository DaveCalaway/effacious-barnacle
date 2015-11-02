/*
Dave.Calaway
This program determines when the sensor see 0 or 1.

When arduino's pin 13 is HIGH, the sensor's out is HIGH.
*/

void setup() {
// sensor's pin out 
 pinMode(11,INPUT);
// internal led arduino
 pinMode(13,OUTPUT);

}

void loop() {
  int s = digitalRead(11);
  if(s == 1)
    digitalWrite(13,HIGH);
  else
    digitalWrite(13,LOW);
    
}
