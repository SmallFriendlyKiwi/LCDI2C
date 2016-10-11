/* YourDuino.com Example Software Sketch
 20 character 4 line I2C Display
 Backpack Interface labelled "YwRobot Arduino LCM1602 IIC V1"
 Connect Vcc and Ground, SDA to A4, SCL to A5 on Arduino
 terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


/*-----( Declare Variables )-----*/
int len;
String duty_cycle;

void setup()
{
  lcd.begin(20,4);         // initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.backlight(); 

//-------- Write characters on the display ------------------
  // NOTE: Cursor Position: Lines and Characters start at 0  
  lcd.setCursor(0,0);
  lcd.print("Firmware:   1.16");
  lcd.setCursor(0,2);
  lcd.print("Duty Cycle:");
  // lcd.setCursor(0,2);
  // lcd.print("Outside Temp: 24.5 C");
  // lcd.setCursor(0,3);
  // lcd.print("Water Temp:   28.3 C"); 
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/

{
  for (int i=0; i <= 100; i++)
    {
      duty_cycle = String(i);
      // len = duty_cycle.length();
      lcd.setCursor(12,2);
      lcd.print(duty_cycle + "%" + "  ");
      delay(1000);
    }
}
