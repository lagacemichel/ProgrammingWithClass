/*
Main ProgrammingWithClass sketch
Program that outputs squences of colors to an RGB LED. The
sequence shown can be selected by a push button. This sketch
demonstrates the use of classes. It is associated with the
Programming with Class blog post on https://lagacemichel.com

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

#include "rgbLed.h"
#include "rgbColor.h"

// RGB LED pins
#define REDPIN   9
#define GREENPIN 10
#define BLUEPIN  11

// Pushbutton pin
#define PUSHBUTTON 8

// Constants used to control timings
const int colorCycle = 1000;
const float cycleTime = 10.0;
const int stepTime = cycleTime/colorCycle*1000;

// Color step counter
static int colorStep = 0;

// Color scheme names
enum colorScheme {nothing,
                 wheel,
                 rainbow,
                 all,
                 white,
                 numberOfSchemes
};
static colorScheme scheme = nothing;

//Push Button current value
bool pushButton = HIGH;

// Global LED object
static rgbLed led(REDPIN,GREENPIN,BLUEPIN);

// Array of color sequences made of rgbColor objects
static const rgbColor wheelColors[] = 
  {redColor,yellowColor,greenColor,cyanColor,blueColor,magentaColor};
static const rgbColor rainbowColors[] = 
  {redColor,orangeColor,yellowColor,greenColor,blueColor,
   purpleColor,blackColor};
static const rgbColor allColors[] =
  {redColor,greenColor,blueColor,yellowColor,cyanColor,magentaColor,
   orangeColor,purpleColor,whiteColor,blackColor};

// Glide through colors
void glideThrough(const rgbColor colorArray[],int arraySize) {
  // Initialize color gradients
  float gradientSpan = (float)colorCycle/(float)arraySize;

  // Compute color array indeces and gradient between colors
  int gradateFrom = colorStep/gradientSpan;
  int gradateTo = (gradateFrom + 1)%arraySize;
  float gradient = colorStep/gradientSpan - (float)gradateFrom;

  // Gradate between the two colors
  rgbColor color;
  color.gradate(colorArray[gradateFrom],colorArray[gradateTo],gradient);
  led.set(color);
}

// Step through colors
void stepThrough(const rgbColor colorArray[],int arraySize) {
  // Initialize color gradients
  float gradientSpan = (float)colorCycle/(float)arraySize;

  // Compute color array indeces and gradient between colors
  int colorIndex = colorStep/gradientSpan;

  // Set the color according to time
  rgbColor color(colorArray[colorIndex]);
  led.set(color);
}

// Setup push button pin
void setup() {
  // Setup pin modes
  pinMode(PUSHBUTTON,INPUT);
}

// Main loop. Repeatedly through color sequences
void loop() {
  // Output color according to selected scheme
  switch (scheme) {
    case nothing:
      led.set(blackColor);
      break;
    case wheel:
      glideThrough(wheelColors,sizeof(wheelColors)/sizeof(rgbColor));
      break;
    case rainbow:
      glideThrough(rainbowColors,sizeof(rainbowColors)/sizeof(rgbColor));
      break;
    case all:
      stepThrough(allColors,sizeof(allColors)/sizeof(rgbColor));
      break;
    case white:
      led.set(whiteColor);
      break;
    default:
      led.set(redColor);
      break;
  }

  // Detect if button is going from HIGH to LOW. If so, select next
  // color scheme
  if (digitalRead(PUSHBUTTON) != pushButton) {
    if (pushButton) {
      scheme = (colorScheme)((int)scheme + 1);
      if (scheme >= numberOfSchemes) {
        scheme = nothing;
      }
    }
    pushButton = !pushButton;
    colorStep = 0;
  }

  // Wait a bit, then proceed to next color step
  delay(stepTime);
  colorStep++;
  if (colorStep >= colorCycle) {
    colorStep = 0;
  }
}
