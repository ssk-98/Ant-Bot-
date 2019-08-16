#include<Servo.h>
Servo servo_left;
Servo servo_right;
Servo servo_main;
int flag=0;



void setup() {
  Serial.begin(9600);
  servo_left.attach(10);
  servo_right.attach(11);
  servo_main.attach(8);
 
 
}
void left_servo_to_close()
{
  
 for(int i=150;i>70;i--)
 {
  servo_left.write(i);
  delay(50);
   
 }
 
 
}

void left_servo_to_open()
{
  
 for(int i=70;i>150;i++)
 {
  servo_left.write(i);
  delay(50);
   
 }
 
 
}

 void right_servo_to_close()
 {
  
  for(int j=50;j<130;j++)
  {
    servo_right.write(j);
    delay(j);
    }
   
 }
 void right_servo_to_open()
 {
  
  for(int j=130;j>50;j--)
  {
    servo_right.write(j);
    delay(j);
    }
   
 }

 void main_servo_down()
 {
  for(int k=180;k>98;k--)
  {
    servo_main.write(k);
    delay(70);
  }
 }
 
   void main_servo_up()
 {
  for(int k=98;k<180;k++)
  {
    servo_main.write(k);
    delay(70);
  }
  
 }
void arm_pickup()
{
  
  servo_main.write(180);
  servo_left.write(150);
  servo_right.write(50);
  main_servo_down();
  left_servo_to_close();
  right_servo_to_close();
  delay(1000);
  main_servo_up();  
}
void arm_drop()
{
  main_servo_down();
  left_servo_to_open();
  right_servo_to_open();
  delay(1000);
  main_servo_up();
}

void loop()
{
  if(flag==0) 
 { 
  arm_pickup(); 
   // in final code we need to call arm_drop when the bot is at destination nde and the block is ready to be dropped
  delay(1000);
  arm_drop();
  }
 else
 Serial.println(flag);
flag=1;
}
