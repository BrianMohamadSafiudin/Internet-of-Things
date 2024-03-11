#include <LiquidCrystal_I2C.h>

int kolom = 16;
int baris = 2;

LiquidCrystal_I2C lcd(0x27, kolom, baris);  

void setup() 
{
  lcd.init();                      
  lcd.backlight();
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Selamat Datang");
  lcd.setCursor(0,1);
  lcd.print("Brian Safiudin");

  for (int kekanan = 0 ; kekanan < 2; kekanan++) {
    lcd.scrollDisplayRight(); 
    delay(500);
  } 
  for (int kekiri = 0 ; kekiri < 2; kekiri++) {
    lcd.scrollDisplayLeft(); 
    delay(500);
  } 
}