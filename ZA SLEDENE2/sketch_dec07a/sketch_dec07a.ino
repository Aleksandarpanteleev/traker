#define LEFTTRBRAITNES_PIN 11
#define RIGHTTRBRAITNES_PIN 9
int PINS[] ={A5, A4, A3, A2, A1, A0};
void setup() {
  // put your setup code here, to run once:
 pinMode(LEFTTRBRAITNES_PIN, OUTPUT);
 pinMode(RIGHTTRBRAITNES_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(LEFTTRBRAITNES_PIN,255);
  analogWrite(RIGHTTRBRAITNES_PIN,255);
  Serial.print(analogRead(A5));
  Serial.print(' ');
  Serial.print(analogRead(A4));
  Serial.print(' ');
  Serial.print(analogRead(A3));
  Serial.print(' ');
  Serial.print(analogRead(A2));
  Serial.print(' ');
  Serial.print(analogRead(A1));
  Serial.print(' ');
  Serial.print(analogRead(A0));
  Serial.println();
}
