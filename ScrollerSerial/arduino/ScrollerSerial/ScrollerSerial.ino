#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include "font.h"
#define PIN 1
#define N_PIXELS 320
#define WIDTH 40
#define HEIGHT 8


char message[] = "NYAN CAT FOREVER!!!";
int messageLength = sizeof(message) / sizeof(char);
int letterOffset = 0;
int columnOffset = 8;
uint32_t scrollBuffer[HEIGHT][WIDTH];
Adafruit_NeoPixel strip;

uint32_t remap(int x, int y) {
  int i = x % 2;
  return (x + i) * HEIGHT - i + (i ? -y : y);
}

void setup() {
  strip = Adafruit_NeoPixel(N_PIXELS, PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();
  initScrollBuffer();
}

void loop() {
  for (int y = 0; y < HEIGHT; y++) {
    scrollBuffer[y][WIDTH - 1] = 0;
  }
  strip.clear();
  nextScroll();
  scrollMe();
  scrollBufferToStrip();
  strip.show();
  delay(80);
}

void initScrollBuffer() {
  memset(scrollBuffer, 0, sizeof(scrollBuffer[0][0]) * 64);
}

void scrollBufferToStrip() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      strip.setPixelColor(remap(x, y), scrollBuffer[y][x]);
    }
  }
}

void nextScroll() {
  char letter = message[letterOffset];

  for (int y = 0; y < HEIGHT; y++) {
    char thisByte = font8x8_basic[(int)letter][y];
    if ((thisByte >> columnOffset) & 1) {
      scrollBuffer[y][WIDTH - 1] = 0x00110000;
    }
  }

  columnOffset = (columnOffset + 1) % 8;
  if (columnOffset == 0) {
    letterOffset = (letterOffset + 1) % messageLength;
  }
}

void scrollMe() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH - 1; x++) {
      scrollBuffer[y][x] = scrollBuffer[y][x + 1];
    }
  }
}
