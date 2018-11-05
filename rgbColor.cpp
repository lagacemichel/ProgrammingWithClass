/*
rgbColor class (implementation)
Class rgbColor stores a color and operates on it

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

#include "rgbColor.h"

// Default constructor. Set to black.
rgbColor::rgbColor() {
  redComponent = 0;
  greenComponent = 0;
  blueComponent = 0;
}

// Destructor. Does nothing.
rgbColor::~rgbColor() {
}

// Copy constructor. Constructs a color from another.
rgbColor::rgbColor(const rgbColor& color) {
  redComponent = color.redComponent;
  greenComponent = color.greenComponent;
  blueComponent = color.blueComponent;
}

// Assignment operator. Assigns a color to another.
rgbColor& rgbColor::operator =(const rgbColor& color) {
  if (&color != this) {
    redComponent = color.redComponent;
    greenComponent = color.greenComponent;
    blueComponent = color.blueComponent;
  }
  return *this;
}

// Constructor with initializers. Initalizes the color with
// the specified red, green, and blue value.
rgbColor::rgbColor(float r, float g, float b) {
  // Limit red component between 0 and 255
  if (r <= 0.0) {
    redComponent = 0;
  }
  else if (r >= 1.0) {
    redComponent = 255;
  }
  else {
    redComponent = (byte)(r*255.0);
  }

  // Limit green component between 0 and 255
  if (g <= 0.0) {
    greenComponent = 0;
  }
  else if (g >= 1.0) {
    greenComponent = 255;
  }
  else {
    greenComponent = (byte)(g*255.0);
  }

  // Limit blue component between 0 and 255
  if (b <= 0.0) {
    blueComponent = 0;
  }
  else if (b >= 1.0) {
    blueComponent = 255;
  }
  else {
    blueComponent = (byte)(b*255.0);
  }
}

// Set color value as a gradient between two values.
// Color1 and color2 are the values between which the new value
// will be set as a gradient between the two values. Gradient
// is a value between 0 and 1.
void rgbColor::gradate(const rgbColor startColor,
                       const rgbColor endColor,
                       float gradient) {
  redComponent = startColor.redComponent +
    (endColor.redComponent - startColor.redComponent)*gradient;
  greenComponent = startColor.greenComponent +
    (endColor.greenComponent - startColor.greenComponent)*gradient;
  blueComponent = startColor.blueComponent +
    (endColor.blueComponent - startColor.blueComponent)*gradient;
}

// Red, green and blue accessors. Return values.

const float rgbColor::red() const {
  return redComponent/255.0;
}

const float rgbColor::green() const {
  return greenComponent/255.0;
}

const float rgbColor::blue() const {
  return blueComponent/255.0;
}
