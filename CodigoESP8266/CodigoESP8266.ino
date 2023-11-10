#include <ESP8266WiFi.h>
const char WiFiPassword[] = "123456789";
const char AP_NameChar[] = "BOANOITE" ;
 
WiFiServer server(80);
 
 
String request = "";

int enA = D1;   // Pino de habilitação do motor A
int in1 = D2;  // Pino de controle 1 do motor A
int in2 = D3;   // Pino de controle 2 do motor A

int enB = D4;   // Pino de habilitação do motor b
int in3 = D5;  // Pino de controle 1 do motor b
int in4 = D6;   // Pino de controle 2 do motor b


int velocidadeMotorUm = 125;
int velocidadeMotorDois = 135;

 
void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

   pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
   digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
    boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
   
    server.begin();
 
} 
 
 
void loop() 
{
 
   
    WiFiClient client = server.available();
    if (!client)  {  return;  }
 
   
    request = client.readStringUntil('\r');
 
    if       ( request.indexOf("FRENTE") > 0 )  {
                                              //MOTOR 1
      
                                              digitalWrite(in1, HIGH);
                                              digitalWrite(in2, LOW);
                                              analogWrite(enA,velocidadeMotorUm );

                                              //MOTOR 2

                                              digitalWrite(in3,LOW);
                                              digitalWrite(in4, HIGH );
                                              analogWrite(enB,velocidadeMotorDois );
                                                                                         
      }
     if  ( request.indexOf("TRAS") > 0 ) { 
                                              //MOTOR 1
      
                                              digitalWrite(in1, LOW);
                                              digitalWrite(in2, HIGH);
                                              analogWrite(enA,velocidadeMotorUm );

                                              //MOTOR 2

                                              digitalWrite(in3,HIGH);
                                              digitalWrite(in4, LOW );
                                              analogWrite(enB,velocidadeMotorDois );

}
 if       ( request.indexOf("DIREITA") > 0 )  {
                                              //motor 1
                                              digitalWrite(in1, LOW);
                                              digitalWrite(in2, LOW);
                                               
                                              //motor 2
                                              digitalWrite(in3,LOW);
                                              digitalWrite(in4, HIGH );
                                              analogWrite(enB,velocidadeMotorUm ); v 
                                              
                                               
                                                                                         
      }
     if  ( request.indexOf("ESQUERDA") > 0 ) { 
                                              //MOTOR 2
                                              digitalWrite(in3, LOW);
                                              digitalWrite(in4, LOW);
                                               
                                              //MOTOR 1
                                              digitalWrite(in1, HIGH);
                                              digitalWrite(in2, LOW);
                                              analogWrite(enB,velocidadeMotorUm );
                                             
}
  if  ( request.indexOf("PARAR") > 0 ) { 
                                              //Motor 1
                                              digitalWrite(in1, LOW);
                                              digitalWrite(in2, LOW);

                                               //Motor 2
                                              digitalWrite(in3, LOW);
                                              digitalWrite(in4, LOW);
                                               
                                                 

}
 
    client.flush();
 
 
    delay(5);
  
 
} 
