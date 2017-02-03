
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int len;
String duty_cycle;

void setup()
{
  // Initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.begin(20, 4);
  // Turn on the backlight
  lcd.backlight();

  // Write characters on the display
  // NOTE: Cursor Position: Lines and Characters start at 0
  lcd.setCursor(0, 0);
  lcd.print("Firmware:   2.16");
  lcd.setCursor(0, 2);
  lcd.print("Duty Cycle:");
}

// loop: RUNS CONSTANTLY
void loop()
{
  // Update the Duty Cycle percentage
  for (int i = 0; i <= 100; i++)
  {
    duty_cycle = String(i);
    lcd.setCursor(12, 2);
    lcd.print(duty_cycle + "%" + "  ");
    delay(500);
  }
}
