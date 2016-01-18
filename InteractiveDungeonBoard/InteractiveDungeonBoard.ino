// Variables for the LED pins:
int greenLed      = 11;
int orangeLed     = 12;
int redLed        = 13;
// Variables for the color codes:
int white = 0;
int green = 1;
int orange= 2;
int red   = 3;
// Buzzer pin:
int buzzer = A0;
// Variables for the square pins:
int a1  = A1;
int a2  = A2;
int b1  = A3;
int b2  = A4;
// Variables for the readings of the square pins:
int squareA1   = analogRead(a1);
int squareB1   = analogRead(b1);
int squareA2   = analogRead(a2);
int squareB2   = analogRead(b2);
/* The function that checks if and how a square should react, and what the reaction does:
Currently loops because I only have a very small board as a proof of concept, but can easily
be made to reset a square to white after activation. In this case adjust the delays too.*/
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
// The code rewritten to reset the squares after activation; not quite there yet.
/*int resetColorSquare(int square, int color) {
  int squareState = (analogRead(square));
    if (color != white){
    
    if (color == red){
      if (squareState  > 0){
        tone(buzzer, 50000, 500);
        digitalWrite(redLed,HIGH);
        delay(2000);
        digitalWrite(redLed,LOW);
        color = white;
      }
    }
    else if (color != red){
      if (squareState == 0){
        if (color == orange) {
          tone(buzzer, 40000, 500);
          digitalWrite(orangeLed,HIGH);
          delay(2000);
          digitalWrite(orangeLed,LOW);
          color = white;
        }
        else if (color == green) {
          tone(buzzer, 60000, 500);
          digitalWrite(greenLed,HIGH);
          delay(2000);
          digitalWrite(greenLed,LOW);
          color = white;
        }
      }
    }
  }
}
*/
void setup() {
 
  // Output pins (LED and Buzzer)
  pinMode(greenLed,OUTPUT);
  pinMode(orangeLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(buzzer, OUTPUT);
  
 // Input pins (squares)
  pinMode(a1,INPUT);
  pinMode(b1,INPUT);
  pinMode(a2,INPUT);
  pinMode(b2,INPUT);
  
  // Resetting squares ; Not yet working
  /*
  resetColorSquare(a1, green);
  resetColorSquare(a2, orange);
  resetColorSquare(b1, red);
  resetColorSquare(b2, white);
  */
}

void loop() {
  // Here I call upon the function that checks the squares. 
  // This is where the DM can easily program each tile.
  colorSquare(a1, green);
  colorSquare(a2, orange);
  colorSquare(b1, red);
  colorSquare(b2, white);


  // Serial code to check the functionality of the sensors
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
