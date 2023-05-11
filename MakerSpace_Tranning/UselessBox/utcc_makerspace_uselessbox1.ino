#include <Servo.h>
int buttonState = 0;
int sw12 = 12;
int led13 =13;
int pos8 = 0;
int pos9 = 0;

Servo servo_9;
Servo servo_8;

void setup()
{
  Serial.begin(9600);
  pinMode(sw12, INPUT_PULLUP); // INPUT_PULLUP
  pinMode(led13, OUTPUT);
  
  servo_8.attach(8);
  servo_9.attach(9); 
  StartUp();
}

void loop()
{
  int a = digitalRead(12);
  if(a==LOW){
    Serial.println("PullBotton");
    digitalWrite(led13,HIGH);
    int rnd = random(1, 5);
    switch  (rnd) {
      case 1: MyStep1(); break;
      case 2: MyStep2(); break;
      case 3: MyStep3(); break;
      case 4: MyStep4(); break;
      case 5: MyStep5(); break;
    }
    MyTestMotorSlow();
    digitalWrite(13,LOW);
  }
}

void StartUp() {
  Serial.println("StartUp");
  servo_8.write(0); 
  servo_9.write(0); 
  delay(1000);
   
  servo_8.write(180); 
  servo_9.write(180);
  delay(1000);
  servo_8.write(0); 
  servo_9.write(0);
  
  for (int pos1 = 0; pos1 <= 3; pos1 += 1) {   
    digitalWrite(led13, HIGH);  
    delay(250); // Wait for 15 millisecond(s)
    digitalWrite(led13, LOW);
    delay(250);
  }  
}

void MoveServo_8(int Ang1, int Ang2 , int Degree ,int DelayTime){
  for (pos8 = Ang1; pos8 <= Ang2; pos8 +=Degree) {   
    servo_8.write(pos8);    
    delay(DelayTime); // Wait for 15 millisecond(s)
  };   
}
void MoveServo_8neg(int Ang1, int Ang2 , int Degree ,int DelayTime){
  for (int pos8  = Ang1; pos8 >= Ang2; pos8 -=Degree) {   
    servo_8.write(pos8);    
    delay(DelayTime); // Wait for 15 millisecond(s)
  };   
}


void MoveServo_9(int Ang1, int Ang2 , int Degree ,int DelayTime){
  for (pos9 = Ang1; pos9 <= Ang2; pos9 +=Degree) {   
    servo_9.write(pos9);    
    delay(DelayTime); // Wait for 15 millisecond(s)
  };   
}

void MoveServo_9neg(int Ang1, int Ang2 , int Degree ,int DelayTime){
  for (pos9 = Ang1; pos9 >= Ang2; pos9 -=Degree) {   
    servo_9.write(pos9);    
    delay(DelayTime); // Wait for 15 millisecond(s)
  };   
}

void MyTestMotorSlow() {
  Serial.println("MyTestMotorSlow");
    MoveServo_8(0,180,1,15);   
  	MoveServo_9(0,180,1,15);   
  	delay(500);  	 
  	MoveServo_8neg(180,0,1,15);
  	MoveServo_9neg(180,0,1,15);   
}
 
void MyStep1() {
  Serial.println("MyStep1");
}
void MyStep2() {
  Serial.println("MyStep2");
}
void MyStep3() {
  Serial.println("MyStep3");
}
void MyStep4() {
  Serial.println("MyStep4");
}
void MyStep5() {
  Serial.println("MyStep5");
}