void safeLanding()
{
  led1_status(1);
   uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
    {
          int addr10 =10,addr1=1,addr2=2,addr3=3,addr4=4,addr5=5,addr6=6,addr7=7,addr8=8,addr9=9;
          EEPROM.write(addr1,aa1/10);
          EEPROM.write(addr2,aa2/10);
          EEPROM.write(addr3,aa3/10);
          EEPROM.write(addr4,aa4/10);
          
          EEPROM.write(addr5,consKp12*100);
          EEPROM.write(addr6,consKi12*100);
          EEPROM.write(addr7,consKd12*100);
          
          EEPROM.write(addr8,consKp34*100);
          EEPROM.write(addr9,consKi34*100);
          EEPROM.write(addr10,consKd34*100);
}

 // int St=millis();
//int st=safetime;//10secs
 // slow landing, reduces throttle by 200 in a second;
 // if(500 > millis()-St )
  {
 //   St= millis();
 while(1)
 {Serial.println("stuck");
 //  if(aa1>700 || aa2>700 || aa3>700 || aa4>700)
   {
     if(aa1>700)
   aa1=aa1-10;
   if(aa2>700 )
    aa2=aa2-10;
    if(aa3>700)
    aa3=aa3-10;
    if(aa4>700)
    aa4=aa4-10;
   }
   
    if(aa1<701 && aa2<701 & aa3<701 & aa4<701)
   break;
 // if(vw_get_message(buf, &buflen))
 {
//   break;
 } 
   
    motor1.write(aa1);
  motor2.write(aa2);
   motor3.write(aa3);
    motor4.write(aa4);
    
    
    Serial.print(aa1);
  Serial.print("\t");
   Serial.print(aa2);
  Serial.print("\t");
   Serial.print(aa3);
  Serial.print("\t");
  Serial.println(aa4);
  delay(100);
   
 }
/*    
  motor1.writeMicroseconds(aa1);
motor2.writeMicroseconds(aa2);
motor3.writeMicroseconds(aa3);
motor4.writeMicroseconds(aa4);  
Serial.println("safe");  */
  }
 
 
}

void safeShutDown()
{
  // danger shutdown;
 // if(pitch<minSafeangle || pitch>maxSafeangle || roll<minSafeangle || roll>maxSafeangle )
  {
    //t= millis();
  Serial.println("dont shut");
        while(1)
        {
           int aa=700;
           Serial.println("shut");
                   motor1.attach(MOTOR_PIN1);
           motor2.attach(MOTOR_PIN2);
            motor3.attach(MOTOR_PIN3);
           motor4.attach(MOTOR_PIN4);
      
            motor1.write(aa);
            motor2.write(aa);
             motor3.write(aa);
              motor4.write(aa);
        }
  }
}


void led1_init()
{
 pinMode(13,OUTPUT);
 //f
 pinMode(4,OUTPUT);
 digitalWrite(13,LOW); 
}

void led1_status(byte stat)
{
 digitalWrite(13,stat);  
}
void led2_init()
{
 pinMode(5,OUTPUT);
 digitalWrite(13,LOW); 
}

void led2_status(byte stat)
{
 analogWrite(5,stat);  
}
