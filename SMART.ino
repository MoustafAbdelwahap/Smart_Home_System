
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Password.h> 
#include <Keypad.h> 
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS 12
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int LDR = A5;
int val;
int led = 11;
int motor = 13;
LiquidCrystal lcd(A0,A1,A2,A3,A4,10);
Password password = Password( "123" );
const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 9,8,7,6 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 5,4,3,2, };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
Serial.begin(9600);
pinMode(LDR,INPUT);
pinMode(led,OUTPUT);
pinMode(motor,OUTPUT);
lcd.begin(16, 2);
lcd.print(" Enter Password ");
keypad.addEventListener(keypadEvent); 
}


void loop(){
keypad.getKey();
temperature();
light();
  
}

void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print(eKey);
  switch (eKey){
    case '*': checkPassword(); break;
    case '#': password.reset(); break;
    default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("      OPEN      ");
  }else{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("    Try Again   ");
  }
}
   void temperature(){
  sensors.requestTemperatures();
  float heat = sensors.getTempCByIndex(0);
  Serial.print("Temperature= ");
  Serial.println(heat);
if (heat > 30){
  digitalWrite(motor,HIGH);
}else{
 digitalWrite(motor,LOW); 
}
   }
void light(){
  val=analogRead(LDR);
if (val < 300){
  digitalWrite(led,HIGH);}
  else
    digitalWrite(led,LOW);

}
