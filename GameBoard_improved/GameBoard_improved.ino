
int greenLed      = 11;
int orangeLed     = 12;
int redLed        = 13;

int white = 0;
int green = 1;
int orange= 2;
int red   = 3;

int buzzer = A0;

int a1  = A1;
int a2  = A2;
int b1  = A3;
int b2  = A4;


int squareA1   = analogRead(a1);
int squareB1   = analogRead(b1);
int squareA2   = analogRead(a2);
int squareB2   = analogRead(b2);

int colorSquare(int square, int color) {
    int squareState = (analogRead(square));
    if (color != white){

      if (color == red){
        if (squareState  > 0){
          tone(buzzer, 50000, 500);
          digitalWrite(redLed,HIGH);
          delay(1);
          digitalWrite(redLed,LOW);
        }
       }
      else if (color != red){
        if (squareState == 0){
          if (color == orange) {
            tone(buzzer, 40000, 500);
            digitalWrite(orangeLed,HIGH);
            delay(1);
            digitalWrite(orangeLed,LOW);
          }
          else if (color == green) {
            tone(buzzer, 60000, 500);
            digitalWrite(greenLed,HIGH);
            delay(1);
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
  Serial.println(analogRead(a1));

  Serial.print("A2 output: ");
  Serial.println(analogRead(a2));

  Serial.print("B1 output: ");
  Serial.println(analogRead(b1));
  
  Serial.print("B2 output: ");
  Serial.println(analogRead(b2));

  Serial.println("\n");
  
  delay(100);

}
