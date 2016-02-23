#define LEFTMOTORB_PIN 4
#define LEFTMOTORF_PIN 2
#define LEFTMOTORS_PIN 5
#define RIGHTMOTORF_PIN 8
#define RIGHTMOTORB_PIN 7
#define RIGHTMOTORS_PIN 10
#define LEFTTRBRAITNES_PIN 11
#define RIGHTTRBRAITNES_PIN 9

int valleft=0;
int valright=0;
#define TURNTRESH 50 
void setup() {
  // put your setup code here, to run once:
 pinMode(LEFTMOTORF_PIN, OUTPUT);
 pinMode(LEFTMOTORB_PIN, OUTPUT);
 pinMode(LEFTMOTORS_PIN, OUTPUT);
 pinMode(RIGHTMOTORB_PIN, OUTPUT);
 pinMode(RIGHTMOTORF_PIN, OUTPUT);
 pinMode(RIGHTMOTORS_PIN, OUTPUT);
 pinMode(LEFTTRBRAITNES_PIN, OUTPUT);
 pinMode(RIGHTTRBRAITNES_PIN, OUTPUT);
Serial.begin(115200);
}

void turn_left()
{
  digitalWrite(LEFTMOTORF_PIN,LOW);
  digitalWrite(LEFTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORF_PIN,LOW);
  analogWrite(LEFTMOTORS_PIN,0);
  analogWrite(RIGHTMOTORS_PIN,100);
  analogWrite(LEFTTRBRAITNES_PIN,255);
  analogWrite(RIGHTTRBRAITNES_PIN,255);
}
void turn_right()
{
  digitalWrite(LEFTMOTORF_PIN,LOW);
  digitalWrite(LEFTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORF_PIN,LOW);
  analogWrite(LEFTMOTORS_PIN,100);
  analogWrite(RIGHTMOTORS_PIN,0);
}
void go_forward()
{
  digitalWrite(LEFTMOTORF_PIN,LOW);
  digitalWrite(LEFTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORF_PIN,LOW);
  analogWrite(LEFTMOTORS_PIN,100);
  analogWrite(RIGHTMOTORS_PIN,100);
}
void loop() {
  // put your main code here, to run repeatedly:
  valleft = analogRead(A3);
  valright = analogRead(A2);
  if((valleft-valright)>TURNTRESH)
 {
  turn_left();
 }
  else if((valleft-valright)<-TURNTRESH)
 {
  turn_right();
 }
  else
 {
  go_forward();
 }
 Serial.print(valleft);
 Serial.print(' ');
 Serial.println(valright);
}


void fixedPrint(int input)
{
  if (input < 10)
  {
    Serial.print("000");
    Serial.print(input);
  }
  if (input < 100 && input >= 10)
  {
    Serial.print("00");
    Serial.print(input);
  }
  if (input < 1000 && input >= 100)
  {
    Serial.print("0");
    Serial.print(input);
  }
  if (input > 999)
  {
    Serial.print(input);
  }
}
