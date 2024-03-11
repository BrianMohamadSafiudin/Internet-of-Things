int ledHijau = 2;
int ledKuning = 4;
int ledMerah = 5;
const int trigpin = 22;
const int echopin = 23;
long timer;
int jarak;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledHijau, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  timer = pulseIn(echopin, HIGH);
  jarak = timer/58;
  Serial.println(jarak);
  delay(200);

  if(jarak >100) {
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, LOW);
  } else if(jarak >50 && jarak <100) {
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledMerah, LOW);
  } else if(jarak >0 && jarak <50) {
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, HIGH);
  }
}