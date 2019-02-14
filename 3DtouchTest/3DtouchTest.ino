/*
 * Simple sketch to manually test 3D touch/BL touch XXtouch sensor using arduino
 * consisting on a servo or servo-like controlled coil as effector, 
 * controlled by servo library on ìn 9
 * and a position sensor (limit switch, optical, etc), connected to analog pin A0,
 * to deploy the probe open serial terminal and send a "1", then touch manually the probe
 * when probe detects the touch, the onboard led (if using arduino UNO) will be toggled
 * and the probe will be retracted. Then you can repeat the test sending "1" again.
 * To retract with code, just send a "0" with the terminal
 * also you can see in the serial monitor the analog reading of the probe pin so you can know
 * if it is 3v3 or 5v logic (typ. are 5v, but on some 3d printer boards you will need to convert it to 3v3)
 * 
 */

#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int pinProbe=A0;
int pinLed= 13;
int pinServo= 9 ; 

boolean state; 
int stateValue; 
boolean prevState; 
boolean ledState;
int pwm =0 ; 

void setup() {
  // put your setup code here, to run once:
  pinMode(pinProbe, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinServo, OUTPUT);
  myservo.attach(pinServo);
  Serial.begin(9600);
}




void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
        pwm=Serial.parseInt();
        if (pwm==1) {
          myservo.write(10);              // tell servo to go to DOWN position  
        } else if (pwm==0) {
          myservo.write(90);        // tell servo to go to UP position.
        }               
  }  
  state=digitalRead(pinProbe);
  stateValue=analogRead(pinProbe);
  if (prevState!=state){
    prevState=state;
    if (state){
      ledState=!ledState;
      digitalWrite(pinLed,ledState);
      
      myservo.write(90);
      pwm=0;
    }      
  }
  Serial.print(pwm);
  Serial.print('\t');
  Serial.print(state);  
  Serial.print('\t');  
  Serial.print(stateValue);  
  Serial.print('\t');  
  Serial.println(ledState);    
}
