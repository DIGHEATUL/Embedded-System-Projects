
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 13);

#define trigPin 7
#define echoPin 8
#define eyeblink 12

int GL = A0;
int OL = A1;
int Alcohol = A3;
int buzzPin = A2;

int motorPin = 9;
int P1 = A4;
int P2 = A5;

int t = 0;

const int rs = 10, en = 11, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin (9600);
  mySerial.begin(9600);
  delay(100);

  pinMode(P1, OUTPUT);// define pin as OUTPUT for P1A
  pinMode(P2, OUTPUT);// define pin as OUTPUT for P2A
  pinMode(motorPin, OUTPUT);


  lcd.begin(16, 2);
  lcd.clear();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzPin, OUTPUT);
  pinMode(GL, OUTPUT);
  pinMode(OL, OUTPUT);
  pinMode(Alcohol, INPUT);
  pinMode(eyeblink, INPUT);



  digitalWrite (buzzPin, HIGH);
  delay(2000);
  digitalWrite (buzzPin, LOW);

  digitalWrite (GL, HIGH);

  lcd.setCursor(4, 0);
  lcd.print("Accident");
  lcd.setCursor(0, 1);
  lcd.print("Avoidance System");
  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gsm Initialising");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Searching For");
  lcd.setCursor(4, 1);
  lcd.print("Network");
  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gsm Ready !!");
  delay(3000);


  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("All Ok !!");


  digitalWrite (P1, LOW);
  digitalWrite (P2, LOW);
  delay(1000);


}


void loop ()
{


  ///////////////////////ULTRASONIC INTERFACE/////////////////////////
  int duration, distance;
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (1000);
  digitalWrite (trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print("distance: ");
  Serial.println(distance);
  delay(1000);



  if (distance >= 30) {
    digitalWrite(motorPin, HIGH);
    digitalWrite (P1, HIGH);
    analogWrite (P2, 0);
  }

  if (distance <= 25) {
    analogWrite(motorPin, 200);

  }

  if (distance <= 20) {
    analogWrite(motorPin, 150);

  }

  if (distance <= 15) {
    analogWrite(motorPin, 100);
  }

  if (distance <= 10) {
    analogWrite(motorPin, 50);

  }

  if (distance <= 5) {
    analogWrite(motorPin, 0);
    analogWrite (P1, 0);
    analogWrite (P2, 0);


    digitalWrite (GL, LOW);
    digitalWrite (OL, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TOO CLOSE !!");

    digitalWrite (buzzPin, HIGH);
    delay(1000);
    digitalWrite (buzzPin, LOW);
    delay(1000);
    digitalWrite (buzzPin, HIGH);
    delay(1000);
    digitalWrite (buzzPin, LOW);
    delay(1000);
    digitalWrite (buzzPin, HIGH);
    delay(1000);
    digitalWrite (buzzPin, LOW);
    delay(4000);


    digitalWrite (OL, LOW);
    digitalWrite (GL, HIGH);

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("All Ok !!");
  }


  ////////////////Alcohol INTERFACE/////////////////

  int AlcoholValue = analogRead(Alcohol);
  Serial.print("ALCOHOL: ");
  Serial.println(AlcoholValue);
  delay(1000);

  if (AlcoholValue > 500)

  {
    digitalWrite (GL, LOW);
    digitalWrite (OL, HIGH);



    digitalWrite (buzzPin, HIGH);
    delay(1000);
    digitalWrite (buzzPin, LOW);
    delay(1000);
    digitalWrite (buzzPin, HIGH);
    delay(1000);
    digitalWrite (buzzPin, LOW);
    delay(1000);
    digitalWrite (buzzPin, HIGH);
    delay(1000);
    digitalWrite (buzzPin, LOW);
    delay(3000);






    analogWrite(motorPin, 200);
    analogWrite (P1, 255);
    analogWrite (P2, 0);
    delay(400);
    analogWrite(motorPin, 180);
    delay(400);
    analogWrite(motorPin, 160);
    delay(400);
    analogWrite(motorPin, 140);
    delay(400);
    analogWrite(motorPin, 120);
    delay(400);
    analogWrite(motorPin, 100);
    delay(400);
    analogWrite(motorPin, 80);
    delay(400);
    analogWrite(motorPin, 60);
    delay(400);
    analogWrite(motorPin, 40);
    delay(400);
    analogWrite(motorPin, 20);
    delay(400);
    analogWrite(motorPin, 0);
    analogWrite (P1, 0);
    analogWrite (P2, 0);
    delay(400);

    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("DRINKING ALERT !");
    delay(5000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VEHICAL STOPED !");
    delay(3000);



    DrinkSMS();


    delay(5000);

    digitalWrite (OL, LOW);
    digitalWrite (GL, HIGH);

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("All Ok !!");
  }

  /////////////////////////////EYEBLINK INTERFACE///////////////////////////////

  while (digitalRead(eyeblink) == 0)
  {
    t = 2;


    while (t > 0)
    {
      if (digitalRead(eyeblink) == 0)
      {
        t--;
      }
      else
      {
        break;
      }
      delay(1000);
    }
    if (t == 0)
    {
      digitalWrite (GL, LOW);
      digitalWrite (OL, HIGH);



      digitalWrite (buzzPin, HIGH);
      delay(5000);
      digitalWrite (buzzPin, LOW);
      delay(2000);

      analogWrite(motorPin, 200);
      analogWrite (P1, 255);
      analogWrite (P2, 0);
      delay(400);
      analogWrite(motorPin, 180);
      delay(400);
      analogWrite(motorPin, 160);
      delay(400);
      analogWrite(motorPin, 140);
      delay(400);
      analogWrite(motorPin, 120);
      delay(400);
      analogWrite(motorPin, 100);
      delay(400);
      analogWrite(motorPin, 80);
      delay(400);
      analogWrite(motorPin, 60);
      delay(400);
      analogWrite(motorPin, 40);
      delay(400);
      analogWrite(motorPin, 20);
      delay(400);
      analogWrite(motorPin, 0);
      analogWrite (P1, 0);
      analogWrite (P2, 0);
      delay(400);


      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("SLEEP ALERT !!");
      delay(5000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("VEHICAL STOPED !");
      delay(3000);

      digitalWrite (buzzPin, HIGH);
      delay(1000);
      digitalWrite (buzzPin, LOW);
      delay(1000);
      digitalWrite (buzzPin, HIGH);
      delay(1000);
      digitalWrite (buzzPin, LOW);
      delay(1000);
      digitalWrite (buzzPin, HIGH);
      delay(1000);
      digitalWrite (buzzPin, LOW);
      delay(3000);

      SleepSMS();

      delay(4000);

      digitalWrite (OL, LOW);
      digitalWrite (GL, HIGH);

      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("All Ok !!");
    }

  }

}

void SleepSMS ()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sending SMS !!");

  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1 second
  mySerial.println("AT+CMGS=\"+91**********\"\r"); // enter mobile number
  delay(1000);
  mySerial.println("CAB DRIVER = 001");// The SMS text you want to send
  delay(100);
  mySerial.println("SLEEPING ALERT !!");// The SMS text you want to send
  delay(100);
  mySerial.println("TAKE ACTION !!");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMS Sent !!");
  delay(3000);

}


void DrinkSMS ()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sending SMS !!");


  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1 second
  mySerial.println("AT+CMGS=\"+91**********\"\r"); // enter mobile number
  delay(1000);
  mySerial.println("CAB DRIVER = 001");// The SMS text you want to send
  delay(100);
  mySerial.println("DRINKING ALERT !!");// The SMS text you want to send
  delay(100);
  mySerial.println("TAKE ACTION !!");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMS Sent !!");
  delay(3000);
}
