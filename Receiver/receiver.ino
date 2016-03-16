

#include <Servo.h>

String xBeeString;
float numero  = 0;
int pos  = 0;
Servo Lmyservo;
Servo Tmyservo;
void setup()
{


  Serial.begin(9600);
  Tmyservo.attach(9);
  Lmyservo.attach(10);
  Tmyservo.write(100); 
}

void loop()
{
ReceiveText ();
WorkWithReceivedData (); 
xBeeString =""; 
  
}

void ReceiveText ()
{

  
  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      //Serial.print (c); //makes the string readString
      xBeeString += c;
    }


  }

    
  }  

  



void WorkWithReceivedData ()
{
if (xBeeString[0]== 'L')
  {
    //Recibimos LUZ
    numero = xBeeString.substring(1).toFloat();
    pos = map (numero,0,1000,5,175);
    Lmyservo.write(pos);    
 
    

  }
if (xBeeString[0]== 'T')
  {
    //Recibimos Temperatura
    numero = xBeeString.substring(1).toFloat();
    //Serial.println(numero);
    pos = map (numero,5,40,5,175);
   
    Tmyservo.write(pos);    
 
    

  }

 
}

