#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
static const int ledPin = 2;
static const int en_1 = 14;
static const int en_2 = 32;
static const int in_1 = 27;
static const int in_2 = 26;
static const int in_3 = 33;
static const int in_4 = 25;

const int freq = 2000;
const int ledChannel = 0;
const int resolution = 8;
int dutyCycle = 0;

void setup() {
  // put your setup code here, to run once:
// put your setup code here, to run once:
  SerialBT.begin("ESP32-BT");
  pinMode(ledPin, OUTPUT);
  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);
  pinMode(en_1, OUTPUT);
  pinMode(en_2, OUTPUT);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(en_1, ledChannel);
  ledcAttachPin(en_2, ledChannel);  
  Serial.println("The device is ready to be paired.");  

}

void loop() {
  // put your main code here, to run repeatedly:
   if (SerialBT.available()) {
     char c = SerialBT.read();
     if (c == '1') {
     digitalWrite(ledPin, HIGH);
    } 
    else if (c == '0') {
      digitalWrite(ledPin, LOW);
      }
    else if (c == 'f') {
       digitalWrite(in_1, HIGH);
       digitalWrite(in_2, LOW);
       digitalWrite(in_3, HIGH);
       digitalWrite(in_4, LOW);
            
    } 
    else if (c == 'b') {
      digitalWrite(in_1, LOW);
      digitalWrite(in_2, HIGH);
      digitalWrite(in_3, LOW);
      digitalWrite(in_4, HIGH);
    } 
    else if (c == 'l') {
      digitalWrite(in_1, LOW);
      digitalWrite(in_2, HIGH);
      digitalWrite(in_3, HIGH);
      digitalWrite(in_4, LOW);      
    }
    else if (c == 'r') {
       digitalWrite(in_1, HIGH);
       digitalWrite(in_2, LOW);
       digitalWrite(in_3, LOW);
       digitalWrite(in_4, HIGH);      
    }
    else if (c == 's') {
      digitalWrite(in_1, LOW);
      digitalWrite(in_2, LOW);
      digitalWrite(in_3, LOW);
      digitalWrite(in_4, LOW);
    }
    else if (c == 't') {
      ledcWrite(ledChannel, 77);
    }
     else if (c == 'h') {
      ledcWrite(ledChannel, 128);       
     }
      else if (c == 'x') {
       ledcWrite(ledChannel, 255);        
      }      

  }


}
