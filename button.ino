#include <stdio.h>
#include <string.h>
/////////////////////////////////////////////
#include <Wire.h>
#include <Keypad.h>
#include <Adafruit_PWMServoDriver.h>

#include <LiquidCrystal_I2C.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  140 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  570 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
int servonum = 0;
bool servo_6 = true;
bool servo_8 = true;
bool servo_4 = true;

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
/////////////////////////////////////////////////


//constants for rows and columns

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

//CONNECTION TO ARDUINO
byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {9, 10, 11};

//create keypad object

Keypad customkeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

////
#define code_length 3
char customkey;
char code[code_length];
char envoie[2];
byte code_count = 0;
char diez = '#';


char data;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.backlight();
  lcd.init();

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);


  pwm.setPWM(0, 0, 300);
  pwm.setPWM(1, 0, 310);
  pwm.setPWM(3, 0, 330);
  pwm.setPWM(4, 0, 310);
  pwm.setPWM(6, 0, 310);
  pwm.setPWM(8, 0, 320);
  pwm.setPWM(10, 0, 370);


  bool servo_6 = true;
  bool servo_8 = true;
  bool servo_4 = true;

  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
}

void activate_servo_0()
{
  pwm.setPWM(0, 0, 300);
  delay(500);

}

void deactivate_servo_0()
{
  pwm.setPWM(0, 0, 130);
  delay(500);
}
////////////////////////////////////////////////

void activate_servo_1()
{
  pwm.setPWM(1, 0, 310);
  delay(500);

}

void deactivate_servo_1()
{
  pwm.setPWM(1, 0, 130);
  delay(500);
}
////////////////////////////////////////////////
void activate_servo_3()
{
  pwm.setPWM(3, 0, 330);
  delay(500);

}

void deactivate_servo_3()
{
  pwm.setPWM(3, 0, 510);
  delay(500);
}
////////////////////////////////////////////////
void activate_servo_4()
{
  pwm.setPWM(4, 0, 310);
  delay(100);

}

void deactivate_servo_4()
{
  pwm.setPWM(4, 0, 490);
  delay(100);
}

bool condition_for_deactivate_servo_4(bool servo_4)
{
  if ( servo_4 == true )
  {
    if ( servo_6  == true )
    {
      pwm.setPWM(6, 0, 210);
      servo_6 = false;
    }
    if ( servo_8 == true )
    {
      pwm.setPWM(8, 0, 420);
      servo_8 = false;
    }


    pwm.setPWM(4, 0, 490);
    delay(100);

    if ( servo_6  == false )
    {
      pwm.setPWM(6, 0, 310);
      servo_6 = true;
    }
    if ( servo_8 == false )
    {
      pwm.setPWM(8, 0, 320);
      servo_8 = true;
    }


  }
  return false;
}

bool condition_for_activate_servo_4(bool servo_4)
{
  if ( servo_4 == false )
  {
    if ( servo_6  == true )
    {
      pwm.setPWM(6, 0, 210);
      servo_6 = false;
    }
    if ( servo_8 == true )
    {
      pwm.setPWM(8, 0, 420);
      servo_8 = false;
    }

    pwm.setPWM(4, 0, 310);
    delay(100);

    if ( servo_6  == false )
    {
      pwm.setPWM(6, 0, 310);
      servo_6 = true;
    }
    if ( servo_8 == false )
    {
      pwm.setPWM(8, 0, 320);
      servo_8 = true;
    }
  }
  return true;

}

////////////////////////////////////////////////
void activate_servo_6()
{
  pwm.setPWM(6, 0, 310);
  delay(500);

}

void deactivate_servo_6()
{
  pwm.setPWM(6, 0, 130);
  delay(500);
}

////////////////////////////////////////////////
void activate_servo_8()
{
  pwm.setPWM(8, 0, 320);
  delay(500);

}

void deactivate_servo_8()
{
  pwm.setPWM(8, 0, 500);
  delay(500);
}

////////////////////////////////////////////////
void activate_servo_10()
{
  pwm.setPWM(10, 0, 370);
  delay(500);

}

void deactivate_servo_10()
{
  pwm.setPWM(10, 0, 155);
  delay(500);
}
//////////////////////////////////////////////////////////////////

void loop() {
  // put your main code here, to run repeatedly:

  //for lcd
  


  if ( Serial.available() )
  {
    data = Serial.read();
  }
  if ( data == '1' )
  {
    //lcd
    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("le code d'invite est:");
    lcd.setCursor(0 , 1);
    lcd.print("est: 1");

    //pour afficher 1
    deactivate_servo_0();
    deactivate_servo_1();
    deactivate_servo_10();
    servo_4 = condition_for_deactivate_servo_4(servo_4);
    deactivate_servo_6();
    delay(1000);

  }
  if ( data == '2' )
  {
    //lcd
    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("le code d'invite est:");
    lcd.setCursor(0 , 1);
    lcd.print("est: 2");
    //pour afficher 2
    //Serial.println("afficher 2");
    deactivate_servo_1();
    deactivate_servo_8();
    delay(1000);

  }
  if ( data == '3' )
  {
    //lcd
    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("le code d'invite est:");
    lcd.setCursor(0 , 1);
    lcd.print("est: 3");
    //pour afficher 3
    //Serial.println("afficher 3");
    deactivate_servo_1();
    deactivate_servo_6();
    delay(1000);
  }
  if ( data == '4' )
  {
    //lcd
    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("le code d'invite est:");
    lcd.setCursor(0 , 1);
    lcd.print("est: 4");
    //pour afficher 4
    deactivate_servo_0();
    deactivate_servo_6();
    deactivate_servo_10();
    delay(1000);
  }
  if ( data == '5' )
  {
    //lcd
    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("le code d'invite est:");
    lcd.setCursor(0 , 1);
    lcd.print("est: 5");
    /////////pour afficher 5
    deactivate_servo_3();
    deactivate_servo_6();
    delay(1000);
  }

  if ( data == 'A' )
  {
    //lcd
    lcd.setCursor(6 , 1);
    lcd.print("A");
    // pour afficher la lettre A
    // Serial.println("afficher A");
    deactivate_servo_10();
    activate_servo_1();
    activate_servo_8();
    delay(1000);
    lcd.clear();
  }


  pwm.setPWM(0, 0, 300);
  pwm.setPWM(3, 0, 330);
  pwm.setPWM(1, 0, 310);
  pwm.setPWM(4, 0, 310);
  pwm.setPWM(6, 0, 310);
  pwm.setPWM(8, 0, 320);
  pwm.setPWM(10, 0, 370);

  servo_4 = true;
  delay(70);

  // put your main code here, to run repeatedly:
  customkey = customkeypad.getKey();

  if ( customkey && strcmp(customkey, diez) == 0 )
  {


    for ( byte i = 0 ; i <= code_count ; i++ )
    {
      envoie[i] = code[i];
    }
    Serial.write(envoie);

    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("Envoie du code ");
    lcd.setCursor(0 , 1);
    lcd.print("en cours");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0 , 0);
    lcd.print("done");
    delay(1000);
    for ( byte i = 0 ; i < code_count ; i++ )
    {
      code[i] = '0';
    }
    code_count = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Password");
  }

  if ( customkey && strcmp(customkey, diez) != 0 )
  {

    code[code_count] = customkey;
    lcd.setCursor(code_count, 1);
    lcd.print(code[code_count]);
    code_count++;

  }

  if ( code_count >= 3 )
  {
    code_count = 0;
  }
}
