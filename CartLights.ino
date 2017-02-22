#include <TimerOne.h>
#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>

#define PIN 8
#define SWRED 6
#define LEDRED 11
#define SWBLUE 3
#define LEDBLUE 12
#define SWWHITE 4
#define LEDWHITE 13
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
Bounce redSw = Bounce();
Bounce blueSw = Bounce();
Bounce whiteSw = Bounce();
boolean blue = false;
boolean red = false;
boolean white = false;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SWRED, INPUT_PULLUP);
  pinMode(LEDRED, OUTPUT);
  pinMode(SWBLUE, INPUT_PULLUP);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(SWWHITE, INPUT_PULLUP);
  pinMode(LEDWHITE, OUTPUT);
  digitalWrite(LEDWHITE, HIGH);
  redSw.attach(SWRED);
  redSw.interval(5);
  blueSw.attach(SWBLUE);
  blueSw.interval(5);
  whiteSw.attach(SWWHITE);
  whiteSw.interval(5);
  strip.begin();
  strip.show();
  Timer1.initialize(5000);
  Timer1.attachInterrupt(checkButts, 5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (state) {
    case 0:
      if (blue) {//Blue
        crawling(0, 0, 0, 0, 0, 255, true, 90);
      }
      else if (red) { //Red
        crawling(0, 0, 0, 255, 0, 0, true, 90);
      }
      else {
        crawling(0, 0, 255, 255, 150, 0, true, 90);
      }
      break;
    case 1:
      if (blue) {
        readingRainbowFade(180, 60, 5);
      }
      else if (red) {
        readingRainbowFade(340, 30, 20);
      }
      else {
        rainbowFade();
      }
      break;
    case 2:
      seizureMode(10);
      break;
    case 3:
      if (blue) {
        pulse(0, 0, 255, 0, 0, 0);
      }
      else if (red) {
        pulse(255, 0, 0, 0, 0, 0);
      }
      else {
        pulse(0, 0, 255, 255, 150, 0);
      }
      break;
    case 4:
      if (blue) {
        cylonEye(0, 0, 255, 158, 231, 255, 5, 25);
      }
      else if (red) {
        cylonEye(255, 0, 0, 175, 0, 219, 5, 25);
      }
      else {
        cylonEye(255, 150, 0, 0, 0, 255, 5, 25);
      }
      break;
    case 5:
      setAll(strip.Color(0, 0, 0, 255));//work light
      break;
  }
}

void checkButts() {
  redSw.update();
  blueSw.update();
  whiteSw.update();
  if (redSw.rose()) {
    red = !red;
    if (red) {
      blue = false;
    }
  }
  if (blueSw.rose()) {
    blue = !blue;
    if (blue) {
      red = false;
    }
  }
  if (whiteSw.rose()) {
    white = !white;
    if (state < 5) {
      state++;
    }
    else {
      state = 0;
    }
  }
  digitalWrite(LEDBLUE, blue ? HIGH : LOW);
  digitalWrite(LEDRED, red ? HIGH : LOW);
}

