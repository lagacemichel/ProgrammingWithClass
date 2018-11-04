/*
rgbLed class (implementation)
Class rgbLed represents an external rgbLed
This sketch was written by Michel Lagacé, 2018-10-21
This code is in the public domain

MIT License

Copyright (c) 2018, Michel Lagace

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Arduino.h"
#include "rgbLed.h"

const int ANALOGMAX = 255;       // Maximum analog output value

// Destructor. Does nothing.
rgbLed::~rgbLed() {
}

// Constructor with initializers. Initalizes the LED with
// the specified red, green, and blue pins.
rgbLed::rgbLed(int r, int g, int b) {
  redPin = r;
  greenPin = g;
  bluePin = b;
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
}

void rgbLed::set(rgbColor color) {
  // Output color to RGB LED
  analogWrite(redPin,color.red()*ANALOGMAX);
  analogWrite(greenPin,color.green()*ANALOGMAX);
  analogWrite(bluePin,color.blue()*ANALOGMAX);
}
