//18307
#include <Servo.h>
#include <LibPrintf.h>

const byte SERVOPIN = 5;
const byte STARTBUTTON = 2;
const byte CHOICEBUTTON = 1;
const byte LED1 = A0;
const byte LED2 = A1;
const byte LED3 = A2;
const byte LED4 = A3;

Servo lock;
const byte UNLOCK = 180;
const byte LOCK = 0;
const byte KEY = 4;

byte LedTracker = 0;
bool gameOn = false;

void setup() {
  pinMode(CHOICEBUTTON, INPUT);
  pinMode(STARTBUTTON, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  lock.attach(SERVOPIN);
  lock.write(LOCK);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(STARTBUTTON) == HIGH) {
    gameOn = !gameOn;
    printf("game is set to %b", gameOn);
    delay(250);
  }

  if (gameOn) {
    blink(400);
    printf("LedTracker is %i and KEY is %i/n", LedTracker, KEY);
    if (LedTracker == KEY && digitalRead(CHOICEBUTTON) == HIGH) {
      lock.write(UNLOCK);
    }
  }
}
void blink(int length) {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  LedTracker++;
  switch (LedTracker) {
    case 0:
      digitalWrite(LED1, HIGH);
      break;
    case 1:
      digitalWrite(LED2, HIGH);
      break;
    case 2:
      digitalWrite(LED3, HIGH);
      break;
    case 3:
      digitalWrite(LED4, HIGH);
      LedTracker = 0;
      break;
  }

  delay(length);

}
