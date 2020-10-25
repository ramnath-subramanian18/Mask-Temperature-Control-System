#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
//LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);  /* For 8-bit mode */
LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);  /* For 4-bit mode */

unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; /* Custom Character 1 */
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; /* Custom Character 2 */
const int lm35_pin = A1;
char serialData;
int pin=9; 
void setup() {
  pinMode(pin,OUTPUT);
  lcd.begin(16,2);  /* Initialize 16x2 LCD */
  lcd.clear();  /* Clear the LCD */
  lcd.createChar(0, Character1);  /* Generate custom character */
  lcd.createChar(1, Character2);
  
}

void loop() {
  
    int temp_adc_val;
    float temp_val;
    temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
    temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
    temp_val = (temp_val/10)+85;
    lcd.setCursor(0,0); /* Set cursor to column 0 row 0 */
    lcd.print("Temprature is:");
    lcd.print(temp_val); /* Print data on display */
    delay(1000);
    lcd.setCursor(0,1);  
    lcd.write(byte(0)); /* Write a character to display */
    lcd.write(1);
    
    if(Serial.available()>0)
    {serialData=Serial.read();
    Serial.print(serialData);}
    
    if(serialData=='1'){
    digitalWrite(pin,HIGH);
    if(temp_val<138)
    {
      digitalWrite(pin,HIGH);
      
    }
    delay(1000);
    }
    else if(serialData=='0'){
      digitalWrite(pin,LOW);
      
   }
   
    
  
}
