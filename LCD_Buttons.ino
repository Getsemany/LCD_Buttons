#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 1, d7 = 0;
int btn1=6,btn2=7,btn3=8,btn4=9;
int led=10;
int screen=0;
int count=0;
bool on=false;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
pinMode(btn3,INPUT);
pinMode(btn4,INPUT);
pinMode(led,OUTPUT);

}
void screen1(){
  
  lcd.setCursor(0,0);
  lcd.print("Menu");
  lcd.setCursor(10,0);
  lcd.print("Inicio");
  lcd.setCursor(12,1);
  lcd.print("Sig.");
}
void screen2(){
  
  lcd.setCursor(0,0);
  lcd.print("Contador");
  lcd.setCursor(10,0);
  lcd.print("Inicio");
  lcd.setCursor(0,1);
  lcd.print("Cuenta");
  lcd.setCursor(6,1);
  lcd.print(count);
  lcd.setCursor(12,1);
  lcd.print("Sig.");
}
void screen3(){
  lcd.setCursor(0,0);
  lcd.print("Inicio");
  lcd.setCursor(10,0);
  lcd.print("Motor");
  lcd.setCursor(0,1);
  lcd.print("Atras");
  lcd.setCursor(11,1);
  lcd.print("ON/OF");
}
void button1(){
 switch (screen){
  case 0:
  break;
  case 1:
  count++;
  break;
  case 2:
  screen=0;
  break;
 }
 lcd.clear();
}
void button2(){
   switch (screen){
  case 0:
  break;
  case 1:
  count--;
  break;
  case 2:
  screen=1;
  break;
 }
  lcd.clear();
}
void button3(){
   switch (screen){
  case 0:
  break;
  case 1:
  screen=0;
  break;
  case 2:
  break;
 }
  lcd.clear();
}
void button4(){
   switch (screen){
  case 0:
  screen++;
  break;
  case 1:
  screen++;
  break;
  case 2:
  if(on){
      on=false;
      digitalWrite(led,LOW);
    }else{
      on=true;
      digitalWrite(led,HIGH);
    }
  break;
 }
  
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
switch (screen){
  case 0:
  screen1();
  break;
  case 1:
  screen2();
  break;
  case 2:
  screen3();
  break;
}
if(digitalRead(btn4)==HIGH){
delay(200);
if(digitalRead(btn4)==LOW){
  button4();
}
}
if(digitalRead(btn3)==HIGH){
delay(200);
if(digitalRead(btn3)==LOW){
  button3();
}
}
if(digitalRead(btn2)==HIGH){
delay(200);
if(digitalRead(btn2)==LOW){
  button2();
}
}
if(digitalRead(btn1)==HIGH){
delay(200);
if(digitalRead(btn1)==LOW){
  button1();
}
}
}
