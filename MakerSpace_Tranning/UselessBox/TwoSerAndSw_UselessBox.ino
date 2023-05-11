#include <Servo.h>
Servo myservo9;  
Servo myservo8; 
int isWorking = 0;   int sw12 = 12;  

void setup() {
  pinMode(sw12, INPUT_PULLUP);  
  myservo9.attach(9);   
  myservo8.attach(8);  
   myservo8.write(0); 
    myservo9.write(0);
     delay(1000);
}
void loop() {
  int a = digitalRead(sw12);
  if(a==LOW && isWorking == 0){
    isWorking = 1;
    myservo8.write(0); 
    myservo9.write(0);
    delay(1000);   
    myservo8.write(180);  
    myservo9.write(180);     
    delay(1000);
    isWorking = 0;
  }
}
