#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial3
#define REMOTEXY_SERIAL_SPEED 19200


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,99,0,162,0,10,28,0,
  1,0,5,21,20,20,136,31,51,0,
  1,0,75,23,19,19,135,31,52,0,
  129,0,26,1,51,13,136,73,110,103,
  101,114,101,110,116,0,129,0,32,59,
  38,4,31,98,121,32,67,104,52,114,
  108,49,51,32,102,111,114,32,83,105,
  122,101,33,0,1,0,81,49,12,12,
  50,31,82,101,115,101,116,0,67,4,
  36,16,28,4,2,26,11,67,4,40,
  28,20,5,2,26,11,67,4,40,34,
  20,5,2,26,11,67,4,40,40,20,
  5,2,26,11,67,4,40,46,20,5,
  2,26,11,67,4,40,22,20,5,2,
  26,11,67,4,40,53,20,5,2,26,
  11,67,4,77,13,20,5,2,26,11,
  67,4,4,12,20,5,2,26,11 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t player_3; // =1 if button pressed, else =0 
  uint8_t player_4; // =1 if button pressed, else =0 
  uint8_t resetcounter; // =1 if button pressed, else =0 

    // output variables
  char dist1[11];  // string UTF8 end zero 
  char dist3[11];  // string UTF8 end zero 
  char dist4[11];  // string UTF8 end zero 
  char dist5[11];  // string UTF8 end zero 
  char dist6[11];  // string UTF8 end zero 
  char dist2[11];  // string UTF8 end zero 
  char dist7[11];  // string UTF8 end zero 
  char contador4[11];  // string UTF8 end zero 
  char contador3[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A5;
int sensor5 = A6;
int sensor6 = A8;
int sensor7 = A9;
int sdig0 = 52;
int sdig2 = 50;
int sdig3 = 48;
int sdig4 = 46;
int sdig5 = 44;
int sdig6 = 42;
int sdig7 = 40;
int pinA3 = 34;
int contador4p = 0;
int contador3p = 0;
float lectura1;
int cm1;
float lectura2;
int cm2;
float lectura3;
int cm3;
float lectura4;
int cm4;
float lectura5;
int cm5;
float lectura6;
int cm6;
float lectura7;
int cm7;
int digital1;
int digital2;
int digital3;
int digital4;
int digital5;
int digital6;
int digital7;
void setup() {
  RemoteXY_Init (); 
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pinA3, OUTPUT);
  pinMode(sdig0, INPUT);
  pinMode(sdig2, INPUT);
  pinMode(sdig3, INPUT);
  pinMode(sdig4, INPUT);
  pinMode(sdig5, INPUT);
  pinMode(sdig6, INPUT);
  pinMode(sdig7, INPUT);            
}

void loop() {
  RemoteXY_Handler ();
  delay(500);
  lectura1 = analogRead(sensor1);
  lectura2 = analogRead(sensor2);
  lectura3 = analogRead(sensor3);
  lectura4 = analogRead(sensor4);
  lectura5 = analogRead(sensor5);
  lectura6 = analogRead(sensor6);
  lectura7 = analogRead(sensor7);
  digital1 = digitalRead(sdig0);
  digital2 = digitalRead(sdig2);
  digital3 = digitalRead(sdig3);
  digital4 = digitalRead(sdig4);
  digital5 = digitalRead(sdig5);
  digital6 = digitalRead(sdig6);
  digital7 = digitalRead(sdig7);
  cm1 = pow (3027.4 /lectura1, 1.2134);
  cm2 = pow (3027.4 /lectura2, 1.2134);
  cm3 = pow (3027.4 /lectura3, 1.2134);
  cm4 = pow (3027.4 /lectura4, 1.2134);
  cm5 = pow (3027.4 /lectura5, 1.2134);
  cm6 = pow (3027.4 /lectura6, 1.2134);
  cm7 = pow (3027.4 /lectura7, 1.2134);
  Serial.print("Distancia 1: ");
  Serial.println(cm1);
  Serial.print("Distancia 2: ");
  Serial.println(cm2);
  Serial.print("Distancia 3: ");
  Serial.println(cm3);
  Serial.print("Distancia 4: ");
  Serial.println(cm4);
  Serial.print("Distancia 5: ");
  Serial.println(cm5);
  Serial.print("Distancia 6: ");
  Serial.println(cm6);
  Serial.print("Distancia 7: ");
  Serial.println(cm7);
  
  if(cm1<=10 && cm2 <=10 && cm3 <= 10 && cm4 <= 10 || digital1 == LOW && digital2 == LOW && digital3 == LOW && digital4 == LOW ){
        Serial.print("4 Tocando");    
        digitalWrite(pinA3,HIGH);
        delay(4000);
        digitalWrite(pinA3,LOW);
        delay(10000);
        contador4p = 0;
        Serial.print("Pulso 4J Mandado");
    }else{
      Serial.print("Sensores Digitales 4p sin tocar");
      }
  if( cm5<=10 && cm6 <=10 && cm7 <= 10 || digital5 == LOW && digital6 == LOW && digital7 == LOW ){
        Serial.print("4 Tocando");    
        digitalWrite(pinA3,HIGH);
        delay(3000);
        digitalWrite(pinA3,LOW);
        delay(10000);
        contador3p = 0;
        Serial.print("Pulso 3 Jugadores Mandado");     
    }else{
      Serial.print("Sensores Digitales 3p sin tocar");
    }
   if (RemoteXY.player_3!=0) {
        digitalWrite(pinA3,HIGH);
        delay(3000);
        digitalWrite(pinA3,LOW);
        delay(1000);
        contador3p = 0;
        Serial.print("Pulso 3 Jugadores Mandado");  
  }   
  if(RemoteXY.player_3!=0){
    digitalWrite(pinA3,HIGH);
    delay(4000);
    digitalWrite(pinA3,LOW);
    delay(1000);
    contador4p = 0;
    Serial.print("Pulso 4J Mandado");
   }
   if (RemoteXY.resetcounter!=0){
    contador4p = 0;
    contador3p = 0;
   }
  char str1[] = "Distancia 1:";
  sprintf (RemoteXY.dist1, "%s is %d", str1, cm1); // result: "Value is 1234"
  char str2[] = "Distancia 2:";
  sprintf (RemoteXY.dist2, "%s is %d", str2, cm2); // result: "Value is 1234"
  char str3[] = "Distancia 3:";
  sprintf (RemoteXY.dist3, "%s is %d", str3, cm3); // result: "Value is 1234"
  char str4[] = "Distancia 4:";
  sprintf (RemoteXY.dist4, "%s is %d", str4, cm4); // result: "Value is 1234"
  char str5[] = "Distancia 5:";
  sprintf (RemoteXY.dist5, "%s is %d", str5, cm5); // result: "Value is 1234"
  char str6[] = "Distancia 6:";
  sprintf (RemoteXY.dist6, "%s is %d", str6, cm6); // result: "Value is 1234"
  char str7[] = "Distancia 7:";
  sprintf (RemoteXY.dist7, "%s is %d", str7, cm7); // result: "Value is 1234"
  // put your main code here, to run repeatedly:
  char str8[] = "Contador 3:";
  sprintf (RemoteXY.contador3, "%s is %d", str8, contador3p); // result: "Value is 1234"
  char str9[] = "Contador 4:";
  sprintf (RemoteXY.contador4, "%s is %d", str9, contador4p); // result: "Value is 1234"
}
