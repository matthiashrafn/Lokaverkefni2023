#include <tdelay.h>

// Sonic skynjari
int echoPin = 9;
int trigPin = 10;
long duration;
int fjarlaegd;

// Mótor A
int pwmA = 3;
int Ai1 = 5;
int Ai2 = 4;

// Mótor B
int pwmB = 6;
int Bi1 = 7;
int Bi2 = 8;

int stefnal = 13;
int stefnah = 12;

const int LED = A1;
const int LED2 = 2;

const int headlightl = A4;
const int headlighth = A5;
const int myrkur = 400;
const int skynjari = A0;

int analogValue;

bool LED_on = true;

TDelay LED_bidtimi(250);


long randNumber;


void setup() {
  // Sonic pinnar
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication
  // Mótor pinnar
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(Ai1, OUTPUT);
  pinMode(Ai2, OUTPUT);
  pinMode(Bi1, OUTPUT);
  pinMode(Bi2, OUTPUT);
  pinMode(stefnal, OUTPUT);
  pinMode(stefnah, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(headlightl, OUTPUT);
  pinMode(headlighth, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  afram(255);

  maelaFjarlaegd();
  if (fjarlaegd < 50) {
    stoppa(0);
    delay(500);
    vinstri(100);
    delay(400);
    stoppa(0);
    delay(500);
    int v = maelaFjarlaegd();
    delay(500);
    haegri(100);
    delay(950);
    stoppa(0);
    delay(500);
    int h = maelaFjarlaegd();
    delay(500);
    if (v < h) {
      if (v && h < 50) {
        haegri(100);
        delay(475);
      } else {
        stoppa(0);
        delay(750);
        stoppa(0);
        delay(750);
      }
    } else {
      if (v > h) {
        if (v && h < 50) {
          haegri(100);
          delay(475);
        } else {
          haegri(100);
          delay(950);
          stoppa(0);
          delay(1000);
        }
      } else {
        if (v && h < 50) {
          haegri(100);
          delay(475);
          stoppa(0);
          delay(1000);
        } else {
          haegri(100);
          delay(950);
          stoppa(0);
          delay(1000);
          //afram(255);
        }
      }
    }
  }
}


void afram(int hradi) {
  // Set Motor A forward
  digitalWrite(Ai1, HIGH);
  digitalWrite(Ai2, LOW);

  // Set Motor B forward
  digitalWrite(Bi1, HIGH);
  digitalWrite(Bi2, LOW);

  // Set the motor speeds
  analogWrite(pwmA, hradi);
  analogWrite(pwmB, hradi);

  digitalWrite(stefnal, LOW);

  digitalWrite(LED, HIGH);
  digitalWrite(LED2, HIGH);

  if (LED_bidtimi.timiLidinn() == true) {
    LED_on = !LED_on;
  }
  digitalWrite(LED, LED_on);
  digitalWrite(LED2, !LED_on);

  analogValue = analogRead(skynjari);

  if (analogValue > myrkur) {
    digitalWrite(headlightl, HIGH);
    digitalWrite(headlighth, HIGH);
  } else {
    digitalWrite(headlightl, LOW);
    digitalWrite(headlighth, LOW);
  }
}
void bakka(int hradi) {
  digitalWrite(Ai1, LOW);
  digitalWrite(Ai2, HIGH);

  digitalWrite(Bi1, LOW);
  digitalWrite(Bi2, HIGH);

  analogWrite(pwmA, hradi);
  analogWrite(pwmB, hradi);

  digitalWrite(stefnah, LOW);
  digitalWrite(stefnal, LOW);

  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);

  analogValue = analogRead(skynjari);

  if (analogValue > myrkur) {
    digitalWrite(headlightl, HIGH);
    digitalWrite(headlighth, HIGH);
  } else {
    digitalWrite(headlightl, LOW);
    digitalWrite(headlighth, LOW);
  }
}
void stoppa(int hradi) {
  // Set Motor A forward
  digitalWrite(Ai1, LOW);
  digitalWrite(Ai2, LOW);

  // Set Motor B forward
  digitalWrite(Bi1, LOW);
  digitalWrite(Bi2, LOW);

  // Set the motor speeds
  analogWrite(pwmA, hradi);
  analogWrite(pwmB, hradi);

  digitalWrite(stefnal, LOW);
  digitalWrite(stefnah, LOW);

  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);

  analogValue = analogRead(skynjari);

  if (analogValue > myrkur) {
    digitalWrite(headlightl, HIGH);
    digitalWrite(headlighth, HIGH);
  } else {
    digitalWrite(headlightl, LOW);
    digitalWrite(headlighth, LOW);
  }
}
void vinstri(int hradi) {
  // Set Motor A forward
  digitalWrite(Ai1, LOW);
  digitalWrite(Ai2, HIGH);

  // Set Motor B forward
  digitalWrite(Bi1, HIGH);
  digitalWrite(Bi2, LOW);

  // Set the motor speeds
  analogWrite(pwmA, hradi);
  analogWrite(pwmB, hradi);

  digitalWrite(stefnal, HIGH);
  digitalWrite(stefnah, LOW);

  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);

  analogValue = analogRead(skynjari);

  if (analogValue > myrkur) {
    digitalWrite(headlightl, HIGH);
    digitalWrite(headlighth, HIGH);
  } else {
    digitalWrite(headlightl, LOW);
    digitalWrite(headlighth, LOW);
  }
}
void haegri(int hradi) {
  // Set Motor A forward
  digitalWrite(Ai1, HIGH);
  digitalWrite(Ai2, LOW);

  // Set Motor B forward
  digitalWrite(Bi1, LOW);
  digitalWrite(Bi2, HIGH);

  // Set the motor speeds
  analogWrite(pwmA, hradi);
  analogWrite(pwmB, hradi);

  digitalWrite(stefnah, HIGH);
  digitalWrite(stefnal, LOW);

  digitalWrite(LED, LOW);
  digitalWrite(LED2, LOW);

  analogValue = analogRead(skynjari);

  if (analogValue > myrkur) {
    digitalWrite(headlightl, HIGH);
    digitalWrite(headlighth, HIGH);
  } else {
    digitalWrite(headlightl, LOW);
    digitalWrite(headlighth, LOW);
  }
}

int maelaFjarlaegd() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Reiknar fjarlægð í cm
  fjarlaegd = duration * 0.034 / 2;
  // Prenntar fjarlægðina í Serial monitor
  Serial.print("maelaFjarlaegd: ");
  Serial.println(fjarlaegd);
  return fjarlaegd;
}
