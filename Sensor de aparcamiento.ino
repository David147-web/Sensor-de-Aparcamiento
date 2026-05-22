#include <LiquidCrystal.h>
const int Trigger = 3;
const int Echo = 2;

const int rojo = 4;
const int amarillo = 5;
const int verde = 6;

LiquidCrystal lcd(7,8,9,10,11,12);

const int buzzer = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  
  lcd.begin(16,2);
  lcd.print("Iniciando sensor...");
  delay(2000);
  lcd.clear();
}

void loop()
{
  long tiempo;
  long distancia;
  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  
  tiempo = pulseIn(Echo, HIGH);
  distancia = tiempo/59;
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm");
  Serial.println();
  delay(100);
  
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.print(distancia);
  lcd.print(" cm ");
  
  if(distancia >= 40){
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, HIGH);
    
    noTone(buzzer);
    delay(100);
    
  }else if(distancia >5 && distancia <40){
    delay(50);
    noTone(buzzer);
    delay(distancia * 10);
  }else{
    digitalWrite(rojo, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, LOW);
    
    tone(buzzer, 1500);
    delay(100);
  }
  
}