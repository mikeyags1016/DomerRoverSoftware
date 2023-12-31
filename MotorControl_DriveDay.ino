#include <Keyboard.h>
#include <Cytron_SmartDriveDuo.h>

int signalParLeft = 11; 
int signalParRight = 10;
int signalMidLeft = 5;
int signalMidRight = 3;

int directionParLeft = 7;
int directionParRight = 8;
int directionMidLeft = 4;
int directionMidRight = 2;

int translated = 0;

int LS = 0;
int RS = 0;
int MLS = 0;
int MRS = 0;

Cytron_SmartDriveDuo outer(PWM_INDEPENDENT, directionParLeft, directionParRight, signalParLeft, signalParRight);
Cytron_SmartDriveDuo inner(PWM_INDEPENDENT, directionMidLeft, directionMidRight, signalMidLeft, signalMidRight);

int onCount = 255;
char readthis;
//String stringPart1, stringPart2;
void setup() {
 // pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(13, HIGH);
  delay(2000); // Delay for 5 seconds.
  digitalWrite(13, LOW);
//  digitalWrite(13, HIGH);
//  delay(2000); // Delay for 5 seconds.
//  digitalWrite(13, LOW);
  
  Serial.println("Type wasdx");
}

void loop() {
      // put your main code here, to run repeatedly:
     if(Serial.available()) {
      readthis = (char)Serial.read();
  
      if(readthis == 'w'){
        translated = 0;
        Serial.print(readthis);
        }
      else if(readthis == 'a'){
        translated = 1;
        Serial.print(readthis);
        }
      else if(readthis == 's'){
        translated = 2;
        Serial.print(readthis);
        }
      else if(readthis == 'd'){
        translated = 3;
        Serial.print(readthis);
        }
      else if(readthis == 'q'){
        translated = 5;
        Serial.print(readthis);
        }
      else if(readthis == 'e'){
        translated = 6;
        Serial.print(readthis);
        }
      else if(readthis == 'z'){
        translated = 7;
        Serial.print(readthis);
        }
      else if(readthis == 'c'){
        translated = 8;
        Serial.print(readthis);
        }
      else if(readthis == 'x'){
        translated = 4;
      }

     switch(translated){
      // forward
      case 0:
        LS = -255/5;
        RS = 255/5;
        MLS = 255/5;
        MRS = 255/5;
        Serial.print(0);
        delay(10);
        break;
      //left zero radius
      case 1:
        LS = 127/3;
        RS = 127/3;
        MLS = -255/6;
        MRS = 255/6;
        Serial.print(0);
        delay(10);
        break;
      //back
      case 2: 
        LS = 255/6;
        RS = -255/6;
        MLS = 255/6;
        MRS = -255/6;
        Serial.print(0);
        delay(10);
        break;
      //right zero radius
      case 3:
        LS = -127/3;
        RS = -127/3;
        MLS = 255/6;
        MRS = -255/6;
        Serial.print(0);
        delay(10);
        break;
      
      //super fast
      case 5:
        LS = -255;
        RS = 255;
        MLS = 255;
        MRS = 255;
        Serial.print(0);
        delay(10);
        break;

      //slow
      case 6:
        LS = -255/8;
        RS = 255/8;
        MLS = 255/8;
        MRS = 255/8;
        Serial.print(0);
        delay(10);
        break;
      //left bigger radius
      case 7:
        LS = 127/6;
        RS = 127/3;
        MLS = 0;//-255/6;
        MRS = 0//255/6;
        Serial.print(0);
        delay(10);
      //right bigger radius
      case 8:
        LS = -127/3;
        RS = -127/6;
        MLS = 0;//255/6;
        MRS = 0;//-255/6;
        Serial.print(0);
        delay(10);
        break;
      
        
     case 4:
      LS = 0;
        RS = 0;
        MLS = 0;
        MRS = 0;
        Serial.print(0);
      break;
      default:
        outer.control(0, 0);
        inner.control(0, 0);
       break;
     
      }   
      outer.control(LS, RS);
      inner.control(MLS, MRS);
  }
}
//     digitalWrite(directionParLeft, HIGH);
//     digitalWrite(directionParRight, LOW);
//     digitalWrite(directionParLeft, LOW);
//     digitalWrite(directionMidRight, HIGH);
//     digitalWrite(directionMidLeft, HIGH);
//     digitalWrite(directionParRight, HIGH);
//     digitalWrite(directionPin3, HIGH);
//     digitalWrite(directionPin4, HIGH);
      
//     analogWrite(signalParRight, motorValue1); 
//     analogWrite(signalParRight, motorValue2); 
//     analogWrite(signalMidRight, motorValue3); 
//     analogWrite(signalMidLeft, motorValue4); 
//     analogWrite(signalParRight, motorValue4);
//     analogWrite(signalParLeft, motorValue1); 
//     analogWrite(signalMidRight, motorValue1); 
//     analogWrite(signalMidLeft, motorValue1); 

//     Serial.println(motorValue1);
//     Serial.println(motorValue2);
//     delay(100);  