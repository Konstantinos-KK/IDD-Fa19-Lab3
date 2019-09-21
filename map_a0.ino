/*
  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int input = A0; 
int value = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(input,INPUT);
}
void loop() {
  value = analogRead(input);
  brightness = map(value, 0, 1023, 0, 255);
  analogWrite(led, brightness);
  delay(30);
}
