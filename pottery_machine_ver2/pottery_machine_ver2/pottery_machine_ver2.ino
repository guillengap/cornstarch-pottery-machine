// AUTHOR: GUILLERMO PEREZ GUILLEN

#include <Keypad.h> 
#include <Servo.h> 
#include <Stepper.h> 
 
#define STEPS 48 //We put the number of steps you need to go around. 48 in our case
 
// Name of the motor, the number of steps and the control pins
Stepper stepper(STEPS, 8, 9, 10, 11);

Servo myservo;  
int pos = 103;    

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {30, 31, 32, 33}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {34, 35, 36, 37}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  myservo.attach(7);  
  stepper.setSpeed(60); // velocity of the etepper motor at 60 RPM
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  // go down the servo
  if (customKey == 'F'){ 
   Serial.println(customKey); 
   for (pos = 103; pos <= 140; pos += 1) 
   {
    myservo.write(pos);              
    delay(15);                       
   }
  }

  // go up the servo
  if (customKey == 'E'){ 
   Serial.println(customKey); 
   for (pos = 140; pos >= 103; pos -= 1) 
   {
    myservo.write(pos);              
    delay(15);                       
   }
  }  

  // move the mechanism to the first groove
  if (customKey == 'D'){    
    Serial.println(customKey);
    stepper.step(135);
    delay(15);         
  }

  // return the mechanism to the  origin
  if (customKey == 'C'){
    Serial.println(customKey);
    stepper.step(-135); 
    delay(15);     
  }

  // move the mechanism to the second groove
  if (customKey == 'B'){    
    Serial.println(customKey);
    stepper.step(120);
    delay(15);        
  }

  // return the mechanism to the origin
  if (customKey == 'A'){
    Serial.println(customKey);
    stepper.step(-120); 
    delay(15);    
  }

  // move the mechanism to the third groove
  if (customKey == '9'){    
    Serial.println(customKey);
    stepper.step(105);
    delay(15);   
  }

  // return the mechanism to the origin
  if (customKey == '8'){
    Serial.println(customKey);
    stepper.step(-105); 
    delay(15); 
  }

  // move the mechanism to the fourth groove
  if (customKey == '7'){    
    Serial.println(customKey);
    stepper.step(90);
    delay(15);     
  }

  // return the mechanism to the origin
  if (customKey == '6'){
    Serial.println(customKey);
    stepper.step(-90); 
    delay(15); 
  }
}
