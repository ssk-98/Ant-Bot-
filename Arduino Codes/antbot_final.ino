/*
 * Team id : eYRC #902
 * Author List: Karthik Raj SS ,Jaffar Aleem,Likith S,Gagan L Naik
 * Filename : antbot_final
 * Theme : Ant Bot
 * Functions : get_sensor_left_data()
               get_sensor_right_data()
               get_sensor_center_data()
               move_straight(int spd)
               move_left(int spd)
               move_right(int spd)
               move_stop()
 *global variables :posleft_sensor_data,right_sensor_data,center_sensor_data,spd,spdstr
*/

#include<Servo.h>
//PWM Pins Defination
#define MOT1_EN 6
#define MOT2_EN 7

//Digital Pins for Motors
#define MOT1_IN1 2
#define MOT1_IN2 3

#define MOT2_IN1 4
#define MOT2_IN2 5

//Analog Pins for Sensors
#define SENSOR1 A0
#define SENSOR3 A2
#define SENSOR5 A4


int i,j,k,l;
char flag="n";
int left_sensor_data = 0;              //variable for left sensor data
int right_sensor_data = 0;             //variable for right sensor data
int center_sensor_data = 0;            //variable for center sensor data
int spd = 100;                         //speed 
int spdstr = 130;                      //speed for straight movement
Servo servo_left;
Servo servo_right;
Servo servo_main;
int flag_a=0;
int flag_b=0;

void setup()
{
  pinMode(MOT1_EN,OUTPUT);
  pinMode(MOT2_EN,OUTPUT);
  pinMode(MOT1_IN1,OUTPUT);
  pinMode(MOT1_IN2,OUTPUT);
  pinMode(MOT2_IN1,OUTPUT);
  pinMode(MOT2_IN2,OUTPUT);
  pinMode(SENSOR1,INPUT);                /*defining input and
                                             output pins*/
                               
  pinMode(SENSOR3,INPUT);
  pinMode(SENSOR5,INPUT);
  digitalWrite(MOT1_EN,HIGH);
  digitalWrite(MOT2_EN,HIGH);
  Serial.begin(9600);
  servo_left.attach(10);
  servo_right.attach(11);
  servo_main.attach(8);
}



/*
 *Function Name : path_correct
 *Input         : analog data from left,right,centre sensor
 *Output        : control of motors
 *Logic         : continously reading data from the left sensor , right sensor and centre sensor and pulse width modulation is being used to adjust the speed of the motors so that the antbot stays on the designed path
 *Example Call  : path_correct()
 */
void path_correct()
 
  {

  left_sensor_data = get_sensor_left_data();
  right_sensor_data = get_sensor_right_data();
  center_sensor_data = get_sensor_center_data();

  //condition for soft left
  if(left_sensor_data > 60 && right_sensor_data < 60 && center_sensor_data <60){
    spd = map(left_sensor_data,0,3000,0,255);  //mapping speed according to sensor reading
    move_left(spd);
    
  }

  //condition for soft right
  else{
    if(right_sensor_data > 60 && left_sensor_data < 60 && center_sensor_data <60){
      
      spd = map(right_sensor_data,0,3000,0,255); //mapping speed according to sensor reading
      move_right(spd);

  //condition for stop
      
    }
    else{
      if(right_sensor_data < 60 && left_sensor_data < 60 && center_sensor_data < 60 ){
        move_stop();
      }

   //comdition for forward
      else
      {
        move_straight(spdstr); 
        
      } 
    }
  }
  }
/*
 *Function Name : get_sensor_right_data()
 *Input         : analog data frm sensor
 *Output        : data
 *Logic         : continously reading data from right analog sensor 
 *Example Call  : get_sensor_right_data()
 */



int get_sensor_right_data(){
  int data = 0;
  data += analogRead(SENSOR5);
  return data;
  
}

/*
 *Function Name : get_sensor_left_data()
 *Input         : analog data frm sensor
 *Output        : data
 *Logic         : continously reading data from left analog sensor 
 *Example Call  : get_sensor_right_data()
 */


int get_sensor_left_data(){
  int data = 0;
  data += analogRead(SENSOR1);
  return data;
}

/*
 *Function Name : get_sensor_center_data()
 *Input         : analog data frm sensor
 *Output        : data
 *Logic         : continously reading data from center analog sensor 
 *Example Call  : get_sensor_right_data()
 */


int get_sensor_center_data(){
  int data = 0;
  data += analogRead(SENSOR3);
  return data;

}

/*
 *Function Name : move_straight()
 *Input         : spd
 *Output        : spdstr
 *Logic         : making IN1 & IN3 of motor driver high for forward movement
 *Example Call  : move_straight()
 */

void move_straight(int spd){
  analogWrite(MOT1_IN1,180);
  analogWrite(MOT1_IN2,0);

  
  analogWrite(MOT2_IN1,170);
  analogWrite(MOT2_IN2,0);
  delay(30);
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(100);
}

/*
 *Function Name : move_left()
 *Input         : spd
 *Output        : spd
 *Logic         : making IN4 of motor driver high for slow left
 *Example Call  : move_left()
 */

void move_left(int spd){
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
  analogWrite(MOT2_IN2,130);
  delay(25);
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(100);
}


/*
 *Function Name : move_right()
 *Input         : spd
 *Output        : spd
 *Logic         : making IN2 of motor driver high for slow right
 *Example Call  : move_right()
 */

void move_right(int spd){
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,130);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(25);
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(100);
  
}


/*
 *Function Name : move_stop()
 *Input         : none
 *Output        : none
 *Logic         : making all pins of motor driver low for stop
 *Example Call  : move_straight()
 */
 

void move_stop(){  
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  delay(300);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(300);
}
/*
 *Function Name : hard_left
 *Input         : none
 *Output        : contol of motors
 *Logic         : hard left is achieved by rotating right  wheel forward and left wheel back
 *Example Call  : path_correct()
 */
void hard_left(){
  analogWrite(MOT1_IN1,200);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,200);
  delay(25);
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(100);
  
}

/*
 *Function Name : hard_right 
 *Input         : none
 *Output        : contol of motors
 *Logic         : hard right is achieved by rotating left wheel forward and right wheel back
 *Example Call  : hard_right()
 */
  void hard_right(){
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,200);
  analogWrite(MOT2_IN1,200);
  analogWrite(MOT2_IN2,0);
  delay(25);
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
  delay(100);
  }
/*
 *Function Name : left_servo_to_close()
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : in order to facilitate the rotation of the servo motor we are digitally writing angle values in a for loop 
 *Example Call  : left_servo_to_close()
 */
  void left_servo_to_close()
{
  
 for(int m=150;m>70;m--)
 {
  servo_left.write(m);
  delay(50);
   
 }
 
 
}

/*
 *Function Name : left_servo_to_open()
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : in order to facilitate the rotation of the servo motor we are digitally writing angle values in a for loop 
 *Example Call  : left_servo_to_open()
 */
void left_servo_to_open()
{
  
 for(int n=70;n>150;n++)
 {
  servo_left.write(n);
  delay(50);
   
 }
 
 
}
/*
 *Function Name : right_servo_to_close()
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : in order to facilitate the rotation of the servo motor we are digitally writing angle values in a for loop 
 *Example Call  : right_servo_to_close()
 */
 void right_servo_to_close()
 {
  
  for(int o=50;o<130;o++)
  {
    servo_right.write(o);
    delay(50);
    }
   
 }
 /*
 *Function Name : right_servo_to_open()
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : in order to facilitate the rotation of the servo motor we are digitally writing angle values in a for loop 
 *Example Call  : right_servo_to_open()
 */
 void right_servo_to_open()
 {
  
  for(int p=130;p>50;p--)
  {
    servo_right.write(p);
    delay(50);
    }
   
 }
/*
 *Function Name : main_servo_down()
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : in order to facilitate the rotation of the servo motor we are digitally writing angle values in a for loop 
 *Example Call  : main_servo_down()
 */
 void main_servo_down()
 {
  for(int q=180;q>95;q--)
  {
    servo_main.write(q);
    delay(70);
  }
 }

 /*
 *Function Name : main_servo_up
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : in order to facilitate the rotation of the servo motor we are digitally writing angle values in a for loop 
 *Example Call  : main_servo_up()
 */
   void main_servo_up()
 {
  for(int r=95;r<180;r++)
  {
    servo_main.write(r);
    delay(70);
  }
  
 }

 /*
 *Function Name : arm_pickup
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : a single function is used to call the other functions which inturn controls multiple servo motors for the pickup mechanism of the block
 *Example Call  : arm_pickup()
 */
void arm_pickup()
{
  if(flag_a==0) 
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
else
 Serial.println(flag_a);
flag_a=1;
}
/*
 *Function Name : arm_drop()
 *Input         : none
 *Output        : angle for servo to rotate
 *Logic         : a single function is used to call the other functions which inturn controls multiple servo motors for the pickup mechanism of the block
 *Example Call  : arm_drop()
 */
void arm_drop()
{
  if(flag_b==0)
  { 
  main_servo_down();
  left_servo_to_open();
  right_servo_to_open();
  delay(1000);
  main_servo_up();
}
else
 Serial.println(flag_a);
flag_b=1;

}

void loop()
{
  left_sensor_data = get_sensor_left_data();
  right_sensor_data = get_sensor_right_data();
  center_sensor_data = get_sensor_center_data();

  if(Serial.available()>0){
  if(Serial.read()=="f")
  {   
  while(center_sensor_data < 300)
  {
    path_correct();
    center_sensor_data=get_sensor_center_data();
    if(center_sensor_data > 300)
    {
      move_stop();
      Serial.println(1);
    }
  }
  }
  if(Serial.read()=="r")
  {
    for(i=0;i<22;i++)
    {
      hard_right();
    }
  }
  if(Serial.read()=="l")
  {
    for(i=0;i<25;i++)
    {
      hard_left();
    }
  }
}
}
