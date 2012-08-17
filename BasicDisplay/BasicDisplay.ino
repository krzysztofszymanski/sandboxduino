/*
This code sample was used with Arduino UNO R3
and SainSmart 1602 LCD Keypad Shield,
in order to get this to work with arduino 1.0.1 on MacOS,
you need to install modified version of DFR_Key library.
Library provided as a separate code example.

Based on Key Grab v0.2 Written by jacky, www.sainsmart.com

Modified by Krzysztof Szymanski
szymanski.krzysztof@gmail.com

Displays the currently pressed key on the LCD screen.

Key Codes:

None   - 0
Select - 1
Left   - 2
Up     - 3
Down   - 4
Right  - 5

Original application didn't work as expected, only one key would work fine, others would flicker.
*/

#include <LiquidCrystal.h>
#include <DFR_Key.h>

//Pin assignments for SainSmart LCD Keypad Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
//---------------------------------------------

DFR_Key keypad;

int localKey = 0;
int lastLocalKey=0;
int worldModel[180];
void setup() 
{ 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Display v0.1");
  delay(2500);
  lcd.clear();
  keypad.setRate(50);

}

String displayMessage(int messageNo) {
  if(messageNo==1) return "Select";
  if(messageNo==2) return "Left";
  if(messageNo==3) return "Up";
  if(messageNo==4) return "Down";
  if(messageNo==5) return "Right";
}

void loop() 
{ 
  /*
  keypad.getKey() - Grabs the current key.
  Returns a non-zero integer corresponding to the pressed key,
  OR
  Returns 0 for no keys pressed,
  OR
  Returns -1 (sample wait) when no key is available to be sampled.
  */
  
  localKey = keypad.getKey();
  
  if (localKey!= SAMPLE_WAIT && localKey!= 0 && localKey != lastLocalKey) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Key:");
    lcd.setCursor(0, 1);
    lcd.print(displayMessage(localKey));
    lastLocalKey = localKey;
  }
}
