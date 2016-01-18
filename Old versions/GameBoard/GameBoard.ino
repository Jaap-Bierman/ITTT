
int greenLed      = 11;
int orangeLed     = 12;
int redLed        = 13;

int white = 0;
int green = 1;
int orange= 2;
int red   = 3;

int buzzer = A0;

int a1  = 3;
int a2  = 5;
int b1  = 6;
int b2  = 9;


int squareA1   = digitalRead(a1);
int squareB1   = digitalRead(b1);
int squareA2   = digitalRead(a2);
int squareB2   = digitalRead(b2);

int colorSquare(int square, int color) {
    int squareState = (digitalRead(square));
    if (color != white){

      if (color == red){
        if (squareState == 1){
          tone(buzzer, 500, 500);
          tone(buzzer, 50000, 500);
          digitalWrite(redLed,HIGH);
          delay(1000);
          digitalWrite(redLed,LOW);
        }
       }
      else if (color != red){
        if (squareState == 0){
          if (color == orange) {
            tone(buzzer, 1000, 1000);
            tone(buzzer, 40000, 500);
            digitalWrite(orangeLed,HIGH);
            delay(1000);
            digitalWrite(orangeLed,LOW);
          }
          else if (color == green) {
            tone(buzzer, 6000, 1000);
            tone(buzzer, 60000, 500);
            digitalWrite(greenLed,HIGH);
            delay(1000);
            digitalWrite(greenLed,LOW);
          }
        }
      }
    }
}

void setup() {
  
  pinMode(greenLed,OUTPUT);
  pinMode(orangeLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  
  pinMode(buzzer, OUTPUT);
  
  pinMode(squareA1,INPUT);
  pinMode(squareB1,INPUT);
  pinMode(squareA2,INPUT);
  pinMode(squareB2,INPUT);

  pinMode(a1,INPUT);
  pinMode(b1,INPUT);
  pinMode(a2,INPUT);
  pinMode(b2,INPUT);
}

void loop() {

  colorSquare(a1, green);
  colorSquare(a2, orange);
  colorSquare(b1, red);
  colorSquare(b2, white);
  
  Serial.print("A1 output: "); 
  Serial.println(digitalRead(a1));

  Serial.print("B1 output: ");
  Serial.println(digitalRead(b1));

  Serial.print("A2 output: ");
  Serial.println(digitalRead(a2));
  
  Serial.print("B2 output: ");
  Serial.println(digitalRead(b2));

  Serial.println("\n");
  
  delay(100);

}
