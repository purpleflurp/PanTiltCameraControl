#include <VarSpeedServo.h>

VarSpeedServo panservo;                // creating servo object
VarSpeedServo tiltservo;

int pan_input = A1;              // joystick x direction pin                                          
int tilt_input = A0;              // joystick y direction pin   
int pan;                         // declaring variable to store pan               
int tilt;                        // declaring variable to store tilt
int servo_pan=55;                 // storing servo positions
int servo_tilt=40;

const int SERVOSPEED = 20;
const int DELAY = 100;
const int STEPINCREMENT = 2;      //resolution of servo turning

void setup ( ) 
{
  Serial.begin (9600) ;
    panservo.attach (3) ;          // servo pan
    tiltservo.attach (4) ;          // servo tilt
    panservo.write (servo_pan);           
    tiltservo.write (servo_tilt);
  pinMode (pan_input, INPUT) ;                     
  pinMode (tilt_input, INPUT) ;                      
}

void loop ( ) 
{
  pan = analogRead (pan_input) ;  
  tilt = analogRead (tilt_input) ;   
    Serial.print("pan input: ");
    Serial.println(servo_pan);   
    Serial.print("tilt input: ");
    Serial.println(servo_tilt);               

if (pan < 300)            //if the horizontal value from joystick is less than 300
{
  if (servo_pan < 10)      //first servo moves right
  { 
  } 
  else
  { 
    servo_pan = servo_pan - STEPINCREMENT; 
    panservo.write ( servo_pan,SERVOSPEED ) ; 
      delay (DELAY); 
  } 
} 
if (pan > 700)
{
  if (servo_pan > 180)
  {  
  }  
  else
  {
    servo_pan = servo_pan + STEPINCREMENT;
    panservo.write ( servo_pan,SERVOSPEED ) ;
      delay (DELAY) ;
  }
}

if (tilt < 300)      //if the vertical value from joystick is less than 300
{
  if (servo_tilt < 50)  //second servo moves right
  { 
  } 
  else
  { 
    servo_tilt = servo_tilt - STEPINCREMENT; 
    tiltservo.write ( servo_tilt,SERVOSPEED ); 
      delay (DELAY); 
  } 
} 
if (tilt > 700)
{
  if (servo_tilt > 120)
  {  
  }        
  else
  {
    servo_tilt = servo_tilt + STEPINCREMENT;
    tiltservo.write(servo_tilt,SERVOSPEED) ;
      delay (DELAY) ;
  }
}

}
