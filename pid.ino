void pid()
{
     
  Setpoint1 =0;
  Setpoint2=-Setpoint1;
  Setpoint4=0;
  Setpoint3 =-Setpoint4;
   
   
  Input1 = -pitch;
  Input2 = pitch;
  Input3=roll;
  Input4=-roll;
  
  myPID1.Compute();
  myPID2.Compute();
  myPID3.Compute();
  myPID4.Compute();

  
  m1=aa1+Output1-Output2;
  m3=aa3+Output2-Output1;
  m2=aa2+Output3-Output4;
  m4=aa4+Output4-Output3;
       
  motor1.write(m1);
  motor2.write(m2);
  motor3.write(m3);
  motor4.write(m4);
    
 
 #ifdef Debugpid
  Serial.println(Sensor1Data);
  Serial.print("\t");
  Serial.print(m1);
  Serial.print("\t");
  Serial.print(m2);
  Serial.print("\t");
  Serial.print(m3);
  Serial.print("\t");
  Serial.print(m4);
  
  Serial.print("\t");
  Serial.print(pitch);
  Serial.print("\t");
  Serial.print(roll);
  Serial.print("\t");
  
  
  Serial.print("\t");
  Serial.print(consKp12);
  Serial.print("\t");
  Serial.print(consKi12);
  Serial.print("\t");
  Serial.print(consKd12);
  Serial.print("\t");
  

  
  Serial.print(consKp34);
  Serial.print("\t");
  Serial.print(consKi34);
  Serial.print("\t");
  Serial.print(consKd34);
  Serial.print("\t");
   
  Serial.print(Setpoint1);
  Serial.print("\t");
  Serial.print(Setpoint2);
  Serial.print("\t");
  Serial.print(Setpoint3);
  Serial.print("\t");
  Serial.println(Setpoint4);
  
 #endif
 
 


}

