#include <VarSpeedServo.h>

VarSpeedServo servo1;                // creating servo object
VarSpeedServo servo2;

int joystick_x = A0;              // joystick x direction pin                                          
int joystick_y = A1;              // joystick y direction pin                                         
int pos_x;                   // declaring variable to stroe horizontal value
int pos_y;                   // declaring variable to stroe vertical value
int servo1_pos=90;          // storing servo position
int servo2_pos=90;

const int SERVOSPEED = 20;
const int DELAY = 100;
const int STEPINCREMENT = 2;      //resolution of servo turning

void setup ( ) 
{
  Serial.begin (9600) ;
    servo1.attach (3) ;          // servo 1 attached pin
    servo2.attach (4) ;          // servo 2 attached pin
    servo1.write (servo1_pos);           
    servo2.write (servo2_pos);
  pinMode (joystick_x, INPUT) ;                     
  pinMode (joystick_y, INPUT) ;                      
}

void loop ( ) 
{
  pos_x = analogRead (joystick_x) ;  
  pos_y = analogRead (joystick_y) ;   
    Serial.println(servo2_pos);                

if (pos_x < 300)            //if the horizontal value from joystick is less than 300
{
  if (servo1_pos < 10)      //first servo moves right
  { 
  } 
  else
  { 
    servo1_pos = servo1_pos - STEPINCREMENT; 
    servo1.write ( servo1_pos,SERVOSPEED ) ; 
      delay (DELAY); 
  } 
} 
if (pos_x > 700)
{
  if (servo1_pos > 180)
  {  
  }  
  else
  {
    servo1_pos = servo1_pos + STEPINCREMENT;
    servo1.write ( servo1_pos,SERVOSPEED ) ;
      delay (DELAY) ;
  }
}

if (pos_y < 300)      //if the vertical value from joystick is less than 300
{
  if (servo2_pos < 40)  //second servo moves right
  { 
  } 
  else
  { 
    servo2_pos = servo2_pos - STEPINCREMENT; 
    servo2.write ( servo2_pos,SERVOSPEED ); 
      delay (DELAY); 
  } 
} 
if (pos_y > 700)
{
  if (servo2_pos > 180)
  {  
  }        
  else
  {
    servo2_pos = servo2_pos + STEPINCREMENT;
    servo2.write(servo2_pos,SERVOSPEED) ;
      delay (DELAY) ;
  }
}

}
