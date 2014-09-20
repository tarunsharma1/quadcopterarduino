  #include <ServoTimer2.h>
  
  #include <PID_v1.h>
  
 // #define MAX_SIGNAL 2000
 // #define MIN_SIGNAL 7007
  #define MOTOR_PIN1 11//w
  #define MOTOR_PIN2 10//a
  #define MOTOR_PIN3 9//S
  #define MOTOR_PIN4 6//D

  ServoTimer2 motor1;
  ServoTimer2 motor2;
  ServoTimer2 motor3;
  ServoTimer2 motor4;
 // double aggKp=4, aggKi=0.2, aggKd=1;
// consKp12=0,consKi12=0, consKd12=0,consKp34=0,consKi34=0,consKd34=0;
double consKp12=0.00,consKi12=0.00, consKd12=0.00,consKp34=0.00,consKi34=0.00,consKd34=0.00;
 //double consKp12=0,consKi12=0, consKd12=0,consKp34=0,consKi34=0,consKd34=0;
  //Define Variables we'll be connecting to
   double Setpoint1,Setpoint2,Setpoint3,Setpoint4;
   double Input1,Input2,Input3,Input4;
   double Output1,Output2,Output3,Output4;
  
  //Specify the links and initial tuning parameters
  PID myPID1(&Input1, &Output1, &Setpoint1,consKp12,consKi12,consKd12,DIRECT);
  PID myPID2(&Input2, &Output2, &Setpoint2,consKp12,consKi12,consKd12,DIRECT);
  PID myPID3(&Input3, &Output3, &Setpoint3,consKp34,consKi34,consKd34,DIRECT);
  PID myPID4(&Input4, &Output4, &Setpoint4,consKp34,consKi34,consKd34,DIRECT);

