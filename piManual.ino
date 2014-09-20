void piManual()
{
 
  char number;
  if(Serial.available())
  {
    
    number=(char)Serial.read();
    //time=millis();
  }
 /* if(millis()-time>5000)
  {
    safeLanding();
  }*/
 
   if(number=='a')
 {
  
    aa1=aa1+10;

  
 }
 
  
  else if(number=='8')
 {
   safeLanding();
 }


  else if(number=='z')
 {
   
 }


   else if(number=='5')
 {
   
   aa1=aa1+50;
   aa2=aa2+50;
   aa3=aa3+50;
   aa4=aa4+50;
   
   
  
 }
 
  else if(number=='f')
 {
  
   aa1=aa1-50;
   aa2=aa2-50;
   aa3=aa3-50;
   aa4=aa4-50;
   
   
  
 }
 //TTTTTTT
    else if(number=='t')
 {
  
   aa1=aa1-10;
   aa2=aa2-10;
   aa3=aa3-10;
   aa4=aa4-10;
   
   
  
 }
  //ttttttt
      else if(number=='c')
 {
   
   aa1=aa1+10;
   aa2=aa2+10;
   aa3=aa3+10;
   aa4=aa4+10;
   
   
  
 }
   
     else if(number=='r')
 {
  
   aa1=750;
   aa2=750;
   aa3=750;
   aa4=750;
   }
   
   
 
 //xxxxx
 



  //yyyyy
else if(number=='1')
 {
   consKi12=consKi12+0.01;
 }
 
  //XXXXXXXX
else if(number=='2')
 {
   consKp12=consKp12-0.01;
 }
  //YYYYY
else if(number=='4')
 {
   consKi12=consKi12-0.01;
 }
  //ZZZZZZZZ
 if(number=='6')
 {
   consKd12=consKd12-0.01;
 }
  //zzzzz
else if(number=='7')
 {
   consKp12=consKp12+0.01;
 }
 
else if(number=='9')
 {
   consKp12=consKp12+0.01;
 }


 //iiiiiiiii
else if(number=='p')
 {
   consKp34=consKp34+0.01;
 }
  //jjjjjj
else if(number=='i')
 {
   consKi34=consKi34+0.01;
 }
  //kkkkkkkkk
else if(number=='d')
 {
   consKd34=consKd34+0.01;
 }
   
    //IIIIIIII
else if(number=='P')
 {
   consKp34=consKp34-0.01;
 }
  //JJJJJJJJ
else if(number=='I')
 {
   consKi34=consKi34-0.01;
 }
  //KKKKKKKKKK
else if(number=='D')
 {
   consKd34=consKd34-0.01;
 }
   
   
   // safety cutoff
   // space bar
    else if(number=='s')
 {
 /* // motor1.writeMicroseconds(aa1);
    Serial.println("aa11 + reset");
    //Serial.println(aa1);
  aa1=700;
   aa2=700;
   aa3=700;
   aa4=700;
   */
    Setpoint1 =0;
     Setpoint2 =0;
      Setpoint3 =0;
       Setpoint4 =0;
   safeLanding();
 } 
//}
//prevNumber = number;

}
