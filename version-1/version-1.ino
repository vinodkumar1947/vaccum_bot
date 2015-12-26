int LeftMotorForward = 10; // Pin 10 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 9; // Pin 9 has Left Motor connected on Arduino boards.

int RightMotorForward = 12; // Pin 12 has Right Motor connected on Arduino boards.
int RightMotorReverse = 13; // Pin 13 has Right Motor connected on Arduino boards.
int ir1 =8;
int ir2 =7;
//-----------------------------------------------------------------------------  
void setup()
{
  Serial.begin(9600);
  pinMode(LeftMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(LeftMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(ir1, INPUT);  // initialize the  pin as an output.
  pinMode(ir2, INPUT);  // initialize the  pin as an output.
}
//-----------------------------------------------------------------------------  

// The following Loop is to make the Robot go staright
void loop()
{
 
//Driveforward();
   if(digitalRead( ir1) == HIGH)
  {
  Allstop();
  
  digitalWrite(RightMotorReverse, LOW);
 digitalWrite(LeftMotorReverse, HIGH);
 Serial.println("Rev-1");
 delay (100);
  digitalWrite(LeftMotorReverse, LOW);
  
  Reverse();
  Serial.println("IR1 object found");
 }
 if(digitalRead( ir2) == HIGH)
  {
     Allstop();
     
     digitalWrite(RightMotorForward, LOW);
 digitalWrite(LeftMotorForward, HIGH);
 Serial.println("Rev-2");
 delay (100);
  digitalWrite(LeftMotorForward, LOW);
  
  Driveforward();
  Serial.println("IR2 object found");
 }
}

void Driveforward()
{  
   digitalWrite(RightMotorForward, HIGH);   // turn the Right Motor ON
   digitalWrite(LeftMotorForward, HIGH);   // turn the Left Motor ON
   //delay(10000);               // wait for  10 seconds
 
   //digitalWrite(RightMotorForward,LOW);   // turn the Right Motor OFF
   //digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   //delay(10000);   // wait for  10 seconds
}

 void Rightturn()
  {
   digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorForward, HIGH);   // turn the Left Motor ON
   //delay(10);               // wait for  10 seconds
 
  // digitalWrite(RightMotorForward,LOW);   // turn the Right Motor OFF
   //digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   //delay(10000);               // wait for 10 seconds
   }

   void Leftturn()
   {
  
   digitalWrite(RightMotorForward, HIGH);   // turn the Right Motor ON
   digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   //delay(10);               // wait for  10 seconds
 
   //digitalWrite(RightMotorForward,LOW);   // turn the Right Motor OFF
   //digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   //delay(10000);   // wait for  10 seconds
   }

    void Reverse()
    {
  
   digitalWrite(RightMotorReverse, HIGH);   // turn the Right Motor ON
   digitalWrite(LeftMotorReverse, HIGH);   // turn the Left Motor ON
   //delay(10000);               // wait for a 10 seconds
 
   //digitalWrite(RightMotorReverse, LOW);   // turn the Right Motor ON
   //digitalWrite(LeftMotorReverse, LOW);   // turn the Left Motor ON
  // delay(10000);               // wait for a 10 seconds
    }
    void Allstop()
  {
   digitalWrite(RightMotorReverse, LOW);   // turn the Right Motor ON
   digitalWrite(LeftMotorReverse, LOW);   // turn the Left Motor ON
   //delay(100);               // wait for  10 seconds
  
   digitalWrite(RightMotorForward,LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   delay(1000);    // wait for  10 seconds
  }
