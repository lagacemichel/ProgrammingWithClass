/*
rgbColor class (header)
Class rgbColor stores a color and operates on it.

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

#if !defined(RGBCOLOR_HEADER)
#define RGBCOLOR_HEADER
#include "Arduino.h"

// Class rgbColor
class rgbColor {
  public:
    // Orthodox Cannonical Form
    rgbColor(); // Default Constructor
    ~rgbColor(); // Destructor
    rgbColor(const rgbColor&); // Copy Constructor
    rgbColor& operator = (const rgbColor&); // Assignment operator
    // Other constructors 
    rgbColor(float r,float g,float b);
    // Object accessors (set/get)
    const float red() const;
    const float green() const;
    const float blue() const;
    // Object methods
    void gradate(const rgbColor, const rgbColor, float);
  private:
    // Color components
    byte redComponent;
    byte greenComponent;
    byte blueComponent;
};

// Global constant colors 
static const rgbColor redColor(1.0,0.0,0.0);
static const rgbColor greenColor(0.0,1.0,0.0);
static const rgbColor blueColor(0.0,0.0,1.0);
static const rgbColor yellowColor(1.0,0.6,0.0);
static const rgbColor cyanColor(0.0,1.0,1.0);
static const rgbColor magentaColor(1.0,0.0,0.5);
static const rgbColor orangeColor(1.0,0.1,0.0);
static const rgbColor purpleColor(0.2,0.0,0.2);
static const rgbColor whiteColor(1.0,1.0,1.0);
static const rgbColor blackColor(0.0,0.0,0.0);
#endif
