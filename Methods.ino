void setAll(int r, int g, int b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();
}

void setAll(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

uint32_t randBlueGold(Adafruit_NeoPixel strip) {
  if (random(0, 2) == 0) {
    return strip.Color(0, 0, 255);
  }
  else {
    return strip.Color(255, 150, 0);
  }
}

uint32_t randColor() {
  return HSVtoRGB(random(0, 360), 100, 50);
}

void cylonEye(int r, int g, int b, int r2, int g2, int b2, int l, int del) {
  for (int i = l; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, r, g, b);
  }
  for (int i = 0; i < l; i++)
  {
    strip.setPixelColor(i, r2, g2, b2);
  }
  strip.show();
  for (int i = 0; i < strip.numPixels() - l; i++)
  {
    strip.setPixelColor(i, r, g, b);
    strip.setPixelColor(i + l, r2, g2, b2);
    delay(del);
    strip.show();
  }
  for (int i = strip.numPixels(); i > l; i--)
  {
    strip.setPixelColor(i, r, g, b);
    strip.setPixelColor(i - l, r2, g2, b2);
    delay(del);
    strip.show();
  }
}

void fadeFromTo(int r, int g, int b, int r2, int g2, int b2) {
  double rFade = (r2 - r) / 100.0;
  double gFade = (g2 - g) / 100.0;
  double bFade = (b2 - b) / 100.0;
  double r1 = r;
  double g1 = g;
  double b1 = b;
  for (int i = 0; i < 101; i++) {
    r1 += rFade;
    g1 += gFade;
    b1 += bFade;
    if (i != 100)
      setAll((int)r1, (int)g1, (int)b1);
    else if (i == 100)
      setAll(r2, g2, b2);
    if (i <= 23 || i >= 77)
      delay(8);
    delay(2);
  }
  delay(30);
}

void crawling(int r, int g, int b, int r2, int g2, int b2, boolean left, int del)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < strip.numPixels(); j += 4)
    {
      if (left)
      {
        if (i % 4 == 0)
        {
          strip.setPixelColor(j, r, g, b);
          strip.setPixelColor(j + 1, r, g, b);
          strip.setPixelColor(j + 2, r2, g2, b2);
          strip.setPixelColor(j + 3, r2, g2, b2);
        }
        else if (i % 4 == 1)
        {
          strip.setPixelColor(j, r2, g2, b2);
          strip.setPixelColor(j + 1, r, g, b);
          strip.setPixelColor(j + 2, r, g, b);
          strip.setPixelColor(j + 3, r2, g2, b2);
        }
        else if (i % 4 == 2)
        {
          strip.setPixelColor(j, r2, g2, b2);
          strip.setPixelColor(j + 1, r2, g2, b2);
          strip.setPixelColor(j + 2, r, g, b);
          strip.setPixelColor(j + 3, r, g, b);
        }
        else if (i % 4 == 3)
        {
          strip.setPixelColor(j, r, g, b);
          strip.setPixelColor(j + 1, r2, g2, b2);
          strip.setPixelColor(j + 2, r2, g2, b2);
          strip.setPixelColor(j + 3, r, g, b);
        }
      }
      else
      {
        if (i % 4 == 0)
        {
          strip.setPixelColor(j, r, g, b);
          strip.setPixelColor(j + 1, r2, g2, b2);
          strip.setPixelColor(j + 2, r2, g2, b2);
          strip.setPixelColor(j + 3, r, g, b);
        }
        else if (i % 4 == 1)
        {
          strip.setPixelColor(j, r2, g2, b2);
          strip.setPixelColor(j + 1, r2, g2, b2);
          strip.setPixelColor(j + 2, r, g, b);
          strip.setPixelColor(j + 3, r, g, b);
        }
        else if (i % 4 == 2)
        {
          strip.setPixelColor(j, r2, g2, b2);
          strip.setPixelColor(j + 1, r, g, b);
          strip.setPixelColor(j + 2, r, g, b);
          strip.setPixelColor(j + 3, r2, g2, b2);
        }
        else if (i % 4 == 3)
        {
          strip.setPixelColor(j, r, g, b);
          strip.setPixelColor(j + 1, r, g, b);
          strip.setPixelColor(j + 2, r2, g2, b2);
          strip.setPixelColor(j + 3, r2, g2, b2);
        }
      }
    }
    strip.show();
    delay(del);
  }
}

void rainbowFade() {
  for (int i = 0; i <= 360; i++) {
    for (int j = 0; j <= strip.numPixels(); j++) {
      strip.setPixelColor(j, HSVtoRGB(colorWrap(i + j * 6), 100, 50));
    }
    strip.show();
  }
}

void readingRainbowFade(int ctr, int rng, int del){
  for(int i = ctr+rng; i >= ctr - rng; i--){
    setAll(HSVtoRGB(colorWrap(i),100,50));
  }
  for(int i = ctr - rng; i >= ctr - rng; i++){
    setAll(HSVtoRGB(colorWrap(i),100,50));
  }
}

void dingDingDing() {
  for (int i = 0; i < 3; i++) {
    setAll(255, 255, 255);
    delay(120);
    setAll(0, 0, 0);
    delay(80);
  }
}

void dingDingDing(uint32_t color) {
  for (int i = 0; i < 3; i++) {
    setAll(color);
    delay(120);
    setAll(0, 0, 0);
    delay(80);
  }
}

void seizureMode(int del) {
  for (int i = 0; i <= strip.numPixels(); i++) {
    strip.setPixelColor(i, randColor());
  }
  strip.show();
  delay(del);
}

void fastSeizureMode(int del) {
  setAll(randColor());
  delay(del);
}

void pulseGreen() {
  fadeFromTo(0, 255, 0, 0, 0, 0);
  fadeFromTo(0, 0, 0, 0, 255, 0);
}

void pulse(int r, int g, int b, int r1, int g1, int b1) {
  fadeFromTo(r, g, b, r1, g1, b1);
  fadeFromTo(r1, g1, b1, r, g, b);
}

int colorWrap(int in) {
  if (in >= 360) {
    return colorWrap(in - 360);
  }
  else if (in < 0) {
    return colorWrap(in + 360);
  }
  else {
    return in;
  }
}

uint32_t HSVtoRGB(float h, float s, float v) {
  float f, p, q, t;
  int i, r, g, b;

  h = max(0.0, min(360.0, h));
  s = max(0.0, min(100.0, s));
  v = max(0.0, min(100.0, v));

  s /= 100;
  v /= 100;

  if (s == 0) {
    // Achromatic (grey)
    r = g = b = round(v * 255);
    return strip.Color(r, g, b);
  }

  h /= 60; // sector 0 to 5
  i = floor(h);
  f = h - i; // factorial part of h
  p = v * (1 - s);
  q = v * (1 - s * f);
  t = v * (1 - s * (1 - f));
  switch (i) {
    case 0:
      r = round(255 * v);
      g = round(255 * t);
      b = round(255 * p);
      break;
    case 1:
      r = round(255 * q);
      g = round(255 * v);
      b = round(255 * p);
      break;
    case 2:
      r = round(255 * p);
      g = round(255 * v);
      b = round(255 * t);
      break;
    case 3:
      r = round(255 * p);
      g = round(255 * q);
      b = round(255 * v);
      break;
    case 4:
      r = round(255 * t);
      g = round(255 * p);
      b = round(255 * v);
      break;
    default: // case 5:
      r = round(255 * v);
      g = round(255 * p);
      b = round(255 * q);
  }
  return strip.Color(r, g, b);
}
