#include "comboconfig.h"
#include "I2Cdev.h"
#include "pidconfig.h"
#include <EEPROM.h> 
#include <VirtualWire.h>
#include <Wire.h>
#include <ServoTimer2.h>
//#include <ServoTimer2.h>
#include <PID_v1.h>

#include "MPU6050.h"



//#define DebugAngle
#define Debugpid
#define OUTPUT_READABLE_YAWPITCHROLL


int16_t aX11, aY11, aZ11;
int16_t gX11, gY11, gZ11;
int Sensor1Data;
int NNin,NNnot,mytime;
char *controller;
int ijk=0.01;
int debugmpu;
int prevNumber;

//motor init
int aa1=700;
int aa2=700;
int aa3=700;
int aa4=700;
int m1,m2,m3,m4;
//int maxSafeangle=60;// these are used in shutDown function;
//int minSafeangle=-60;// - -
boolean calibrate;
int charflag,mpuflag;
//int safetime=10000;// safe lands after this time limit.
int led = 13;
int addr10 =10,addr1=1,addr2=2,addr3=3,addr4=4,addr5=5,addr6=6,addr7=7,addr8=8,addr9=9;
boolean firstrun=0;
double pitch;double roll;double yaw;


void setup()
{
  
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW); 

   
  Serial.begin(115200);
  mpusetup(); 
   
    
  led1_init();
  led2_init();
  pidsetup();
  
}


//The loop section of the sketch will read the X,Y and Z output rates from the gyroscope and output them in the Serial Terminal
void loop()
{
  if (firstrun==0)
  {
    int aa=700;
    motor1.attach(MOTOR_PIN1);
    motor2.attach(MOTOR_PIN2);
    motor3.attach(MOTOR_PIN3);
    motor4.attach(MOTOR_PIN4);

    motor1.write(aa);
    motor2.write(aa);
    motor3.write(aa);
    motor4.write(aa);
    firstrun=1;
      
  }
  mpuloop();
  piManual(); 
  pid();

 
   /*double gap1 = abs(Setpoint1-Input1);
    double gap2 = abs(Setpoint2-Input2);
     double gap3 = abs(Setpoint3-Input3);
      double gap4 = abs(Setpoint4-Input4);*/
     // if(gap1<10)
    //we're close to setpoint, use conservative tuning parameters
  //  myPID1.SetTunings(consKp, consKi, consKd);
  
  /* else if(gap1>=10)
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID1.SetTunings(aggKp, aggKi, aggKd);
  }
   //    if(gap2<10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID2.SetTunings(consKp, consKi, consKd);
  }
   /*else if(gap2>=10)
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID2.SetTunings(aggKp, aggKi, aggKd);
  }
       if(gap3<10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID3.SetTunings(consKp, consKi, consKd);
  }
   else if(gap3>=10)
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID3.SetTunings(aggKp, aggKi, aggKd);
  }
       if(gap4<10)
  {  //we're close to setpoint, use conservative tuning parameters
    myPID4.SetTunings(consKp, consKi, consKd);
  }
   else if(gap4>=10)
  {
     //we're far from setpoint, use aggressive tuning parameters
     myPID4.SetTunings(aggKp, aggKi, aggKd);

  */

 
  
 myPID1.SetTunings(consKp12, consKi12, consKd12);
 myPID2.SetTunings(consKp12, consKi12, consKd12);
 myPID3.SetTunings(consKp34, consKi34, consKd34);
 myPID4.SetTunings(consKp34, consKi34, consKd34);
  
  //delay(100);
  
}
