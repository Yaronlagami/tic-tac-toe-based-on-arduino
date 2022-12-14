#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
const byte ROWS = 3; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'3', '6', '9'},
  {'2', '5', '8'},
  {'1', '4', '7'}};
byte rowPins[ROWS] = {7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void newgame(){
  lcd.setCursor(0, 0);
  //        [################]
  lcd.print("    New game    ");
  lcd.setCursor(0,1);
  //        [################]
  lcd.print("      in 3      ");
  delay(1000);
  lcd.setCursor(0,1);
  //        [################]
  lcd.print("      in 2      ");
  delay(1000);  
  lcd.setCursor(0,1);
  //        [################]
  lcd.print("      in 1      ");
  delay(1000);}

void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  for (int i=36;i<=53;i++){pinMode(i, OUTPUT);}
  newgame();}
int win1(int num1, int num2, int num3){
  if (digitalRead(num1)==HIGH && digitalRead(num2)==HIGH && digitalRead(num3)==HIGH){
  delay(500);
  int i;
  lcd.setCursor(0, 0);
  //        [################]
  lcd.print("  Player #1 is  ");
  lcd.setCursor(0,1);
  //        [################]
  lcd.print("   the winner   ");    
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  for(i=36;i<=53;i++){digitalWrite(i, LOW);}
  newgame();
  return 1;}
  else{return 0;}}

int win2(int num1, int num2, int num3){
  if (digitalRead(num1)==HIGH && digitalRead(num2)==HIGH && digitalRead(num3)==HIGH){
  delay(500);
  int i;
  lcd.setCursor(0, 0);
  //        [################]
  lcd.print("  Player #2 is  ");
  lcd.setCursor(0,1);
  //        [################]
  lcd.print("   the winner   ");    
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  digitalWrite(num1, HIGH);
  digitalWrite(num2, HIGH);
  digitalWrite(num3, HIGH);
  delay(500);
  digitalWrite(num1, LOW);
  digitalWrite(num2, LOW);
  digitalWrite(num3, LOW);
  delay(500);
  for(i=36;i<=53;i++){digitalWrite(i, LOW);}
  newgame();
  return 1;}
  else{return 0;}}    
  
void loop()
{
  int count = 0;
  int i;
  char key = customKeypad.getKey();
  while(key == NO_KEY){
    key = customKeypad.getKey();
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print(" Player 1 turn  ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("                ");}
  if (key == 49){digitalWrite(52, HIGH);}
  if (key == 50){digitalWrite(50, HIGH);}
  if (key == 51){digitalWrite(48, HIGH);}
  if (key == 52){digitalWrite(46, HIGH);}
  if (key == 53){digitalWrite(44, HIGH);}
  if (key == 54){digitalWrite(42, HIGH);}  
  if (key == 55){digitalWrite(40, HIGH);}
  if (key == 56){digitalWrite(38, HIGH);}
  if (key == 57){digitalWrite(36, HIGH);}
  int result;
  result  = win1(52,50,48);if (result == 1){return;}
  result  = win1(46,44,42);if (result == 1){return;}
  result  = win1(40,38,36);if (result == 1){return;}
  result  = win1(52,46,40);if (result == 1){return;}
  result  = win1(50,44,38);if (result == 1){return;}
  result  = win1(48,42,36);if (result == 1){return;}
  result  = win1(52,44,36);if (result == 1){return;}
  result  = win1(48,44,40);if (result == 1){return;}
  if ((digitalRead(52)==HIGH ||digitalRead(53)==HIGH) &&
      (digitalRead(50)==HIGH ||digitalRead(51)==HIGH) &&
      (digitalRead(48)==HIGH ||digitalRead(49)==HIGH) &&
      (digitalRead(46)==HIGH ||digitalRead(47)==HIGH) &&
      (digitalRead(44)==HIGH ||digitalRead(45)==HIGH) &&
      (digitalRead(42)==HIGH ||digitalRead(43)==HIGH) &&
      (digitalRead(40)==HIGH ||digitalRead(41)==HIGH) &&
      (digitalRead(38)==HIGH ||digitalRead(39)==HIGH) &&
      (digitalRead(36)==HIGH ||digitalRead(37)==HIGH))
    {
    delay(500);
    for(i=36;i<=53;i++)
    {
      digitalWrite(i, LOW);
    }
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("  There is no   ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("     winner     ");    
    delay(500);
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("                ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("                ");
    delay(500);
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("  There is no   ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("     winner     ");    
    delay(500);
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("                ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("                ");
    delay(500);
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("  There is no   ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("     winner     ");    
    delay(500);
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("                ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("                ");
    delay(500);
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print("    New game    ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("      in 3      ");
    delay(1000);
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("      in 2      ");
    delay(1000);  
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("      in 1      ");
    delay(1000);
    return;}

  key = NO_KEY;

  while(key == NO_KEY){
    key = customKeypad.getKey();
    lcd.setCursor(0, 0);
    //        [################]
    lcd.print(" Player 2 turn  ");
    lcd.setCursor(0,1);
    //        [################]
    lcd.print("                ");}
  if (key == 49){digitalWrite(53, HIGH);}
  if (key == 50){digitalWrite(51, HIGH);}
  if (key == 51){digitalWrite(49, HIGH);}
  if (key == 52){digitalWrite(47, HIGH);}
  if (key == 53){digitalWrite(45, HIGH);}
  if (key == 54){digitalWrite(43, HIGH);}  
  if (key == 55){digitalWrite(41, HIGH);}
  if (key == 56){digitalWrite(39, HIGH);}
  if (key == 57){digitalWrite(37, HIGH);}
  result  = win2(53,51,49);if (result == 1){return;}
  result  = win2(47,45,43);if (result == 1){return;}
  result  = win2(41,39,37);if (result == 1){return;}
  result  = win2(53,47,41);if (result == 1){return;}
  result  = win2(51,45,39);if (result == 1){return;}
  result  = win2(49,43,37);if (result == 1){return;}
  result  = win2(53,45,37);if (result == 1){return;}
  result  = win2(41,45,49);if (result == 1){return;}              
  key = NO_KEY;
}
