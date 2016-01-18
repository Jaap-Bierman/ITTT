
int ledGreen      = 8;
int ledOrange     = 10;
int ledRed        = 12;

int buzzer        = A0;

boolean greenValue      = LOW;
boolean orangeValue     = LOW;
boolean redValue        = LOW;

int Square1a   = 1;
int Square1b   = 3;
int Square2a   = 5;
int Square2b   = 7;

int Color ;
ColorSquare(Color) {
    if !White {
      if Red {
        if (digitalRead(Square) == 0) {
          tone(buzzer, 6000, 500)tone(buzzer, 3000, 500)tone(buzzer, 1500, 1000);
          digitalWrite(greenValue = HIGH)digitalWrite(greenValue = LOW)delay(3000);}
      if !Red {
        (digitalRead(Square) == 1) {
          if Orange {
             tone(buzzer, 1500, 500)tone(buzzer, 3000, 500)tone(buzzer, 1000, 1000);
          digitalWrite(orangeValue = HIGH)digitalWrite(orangeValue = LOW)delay(3000);
          }
          if Green {
            tone(buzzer, 1500, 500)tone(buzzer, 3000, 500)tone(buzzer, 6000, 1000);
            digitalWrite(greenValue = HIGH)digitalWrite(greenValue = LOW)delay(3000);}
        }
      }
      }
    }
CheckSquare(Square) {
  Color
}

void setup() {
  
  pinMode(ledGreen,OUTPUT);
  pinMode(ledOrange,OUTPUT);
  pinMode(ledRed,OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(Square2b,INPUT);
  pinMode(Square2a,INPUT);
  pinMode(Square1b,INPUT);
  pinMode(Square1a,INPUT);
}

void loop() {
  
  ColorSquare1a(Red)
   
  Serial.print("Green output: "); 
  Serial.println(greenValue);

  Serial.print("Orange output: ");
  Serial.println(orangeValue);

  Serial.print("Red output: ");
  Serial.println(redValue);

  Serial.println("\n");
  
  delay(500);

}
