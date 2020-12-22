
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int tableNUM1 = 0;         // variable for reading the pushbutton status
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
    lcd.begin();
 
  lcd.backlight();
}

void loop() {
  tableNUM1 = digitalRead(buttonPin);

  if (tableNUM1 == HIGH) {
    // turn LED on:
    Serial.write('1');
    delay(100);
     lcd.clear();
  lcd.print("la table numero");
  lcd.setCursor (0,1); // go to start of 2nd line
 lcd.print("1 reclame");
  //lcd.print(millis() / 1000);
  delay(500);
  }
  else
  {
         lcd.clear();

  }
}
