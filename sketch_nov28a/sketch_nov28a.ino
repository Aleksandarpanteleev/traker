#define LEFTMOTORB_PIN 4
#define LEFTMOTORF_PIN 2
#define LEFTMOTORS_PIN 5
#define RIGHTMOTORF_PIN 8
#define RIGHTMOTORB_PIN 7
#define RIGHTMOTORS_PIN 10
#define LEFTTRBRAITNES_PIN 11
#define RIGHTTRBRAITNES_PIN 9

#define LINE_THRESH 500
#define INTERVAL 10
#define BASE_SPD 255
#define KP 0.3
#define KI 0
#define KD 0.5


unsigned long long int now = 0;
unsigned long long int old = 0;
int res = 0;

int PINS[] = {A5, A4, A3, A2, A1, A0};
int MIN[6] = {1023, 1023, 1023, 1023, 1023, 1023};
int MAX[6] = {0, 0, 0, 0, 0, 0};
int COEF[6] = {10, 5, 1, -1, -5, -10};

void setup() {
  
  pinMode(LEFTMOTORF_PIN, OUTPUT);
  pinMode(LEFTMOTORB_PIN, OUTPUT);
  pinMode(LEFTMOTORS_PIN, OUTPUT);
  pinMode(RIGHTMOTORB_PIN, OUTPUT);
  pinMode(RIGHTMOTORF_PIN, OUTPUT);
  pinMode(RIGHTMOTORS_PIN, OUTPUT);
  pinMode(LEFTTRBRAITNES_PIN, OUTPUT);
  pinMode(RIGHTTRBRAITNES_PIN, OUTPUT);
 
  digitalWrite(LEFTMOTORF_PIN,LOW);
  digitalWrite(LEFTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORB_PIN,HIGH);
  digitalWrite(RIGHTMOTORF_PIN,LOW);
  
  analogWrite(LEFTTRBRAITNES_PIN,255);
  analogWrite(RIGHTTRBRAITNES_PIN,255);
  
  //Serial.begin(115200);
}

int left_spd = 0;
int right_spd = 0;

void loop()
{
  int line = readLine();
  now = millis();
  if (now > (old + INTERVAL))
  {
    res = PID(line, KP, KI, KD);
    left_spd = BASE_SPD - res;
    if(left_spd > 255) left_spd = 255;
    if(left_spd < 0)   left_spd = 0;
    
    right_spd = BASE_SPD + res;
    if(right_spd > 255) right_spd = 255;
    if(right_spd < 0)   right_spd = 0;
    
    analogWrite(LEFTMOTORS_PIN, left_spd);
    analogWrite(RIGHTMOTORS_PIN, right_spd);
    
    old = now;
  }
}

int readLine()
{
  int sum = 0;
  int k;
  int val = 0;
  static int line_num = -1;
  bool line_found = false;
  
  for (int i = 0; i <= 5; i++)
  {
    val = analogRead(PINS[i]);
    if (val > LINE_THRESH) 
    {
      line_num = i;
      line_found = true;
    }
    
    if (val < MIN[i])MIN[i] = val;
    if (val > MAX[i])MAX[i] = val;
    k = map(val, MIN[i], MAX[i], 1, 100);
    sum += k * COEF[i];
  }
  
  if (!line_found)
  {
    if (line_num == 0) sum = 100 * (COEF[0] + COEF[1] + COEF[2]);
    if (line_num == 5) sum = 100 * (COEF[3] + COEF[4] + COEF[5]);
  }
  
  return sum;
}

int PID(int Error, float Kp, float Ki, float Kd)
{
  static int lastError = 0;
  float Output = 0;
  float proportional, integral, derivetive;
  proportional = (Kp * Error);
  integral = (Error + lastError) * Ki;
  derivetive = (Error - lastError) * Kd;
  Output = proportional + integral + derivetive;
  lastError = Error;
  return Output;
}


