#define LEFTMOTORB_PIN 4
#define LEFTMOTORF_PIN 2
#define LEFTMOTORS_PIN 5
#define RIGHTMOTORF_PIN 8
#define RIGHTMOTORB_PIN 7
#define RIGHTMOTORS_PIN 10
void setup() {
  // put your setup code here, to run once:
 pinMode(LEFTMOTORF_PIN, OUTPUT);
 pinMode(LEFTMOTORB_PIN, OUTPUT);
 pinMode(LEFTMOTORS_PIN, OUTPUT);
 pinMode(RIGHTMOTORB_PIN, OUTPUT);
 pinMode(RIGHTMOTORF_PIN, OUTPUT);
 pinMode(RIGHTMOTORS_PIN, OUTPUT);
digitalWrite(LEFTMOTORF_PIN,LOW);
digitalWrite(LEFTMOTORB_PIN,HIGH);
digitalWrite(RIGHTMOTORB_PIN,HIGH);
digitalWrite(RIGHTMOTORF_PIN,LOW);
analogWrite(LEFTMOTORS_PIN,150);
analogWrite(RIGHTMOTORS_PIN,150);
}

void loop() {
  // put your main code here, to run repeatedly:
}
