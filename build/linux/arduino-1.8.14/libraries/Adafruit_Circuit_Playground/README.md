# Adafruit CircuitPlayground Library [![Build Status](https://travis-ci.com/adafruit/Adafruit_CircuitPlayground.svg?branch=master)](https://travis-ci.com/adafruit/Adafruit_CircuitPlayground)

<img src="https://cdn-shop.adafruit.com/970x728/3333-01.jpg" height="300"/>

## Description

All in one library to control Adafruit's Circuit Playground board. Requires no other dependencies and exposes all Circuit Playground components in a simple to use class. Adafruit Circuit Playground Express is a high-level library that provides objects that represent CircuitPlayground hardware.

## Installation

### First Method

![image](https://user-images.githubusercontent.com/36513474/68966019-f1521f00-07fe-11ea-97b6-78b621e5e2e4.png)

1. In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries
1. Then the Library Manager will open and you will find a list of libraries that are already installed or ready for installation.
1. Then search for Circuit playground using the search bar.
1. Click on the text area and then select the specific version and install it.

### Second Method

1. Navigate to the [Releases page](https://github.com/adafruit/Adafruit_CircuitPlayground/releases).
1. Download the latest release.
1. Extract the zip file
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

## Features

- ### Complete Package

    Everything that is needed to run Arduino code on Circuit Playground is wrapped up into a tidy library that integrates all the sensing and lighting.

- ### Self-contained

    Requires no other dependencies and exposes all Circuit Playground components in a simple to use class.

- ### High-Level Library

    This high-level library provides objects that represent CircuitPlayground hardware.

- ### Give back

    The library is free; you don’t have to pay for anything. However, if you want to support the development, or just thank the author of the library by purchasing products from Adafruit!
    Not only you’ll encourage the development of the library, but you’ll also learn how to best use the library and probably some C++ too

- ### MIT License

    Adafruit playground library is open-source and uses one of the most permissive licenses so you can use it on any project.

  - Commercial use
  - Modification
  - Distribution
  - Private use

## Functions

- begin()
- readCap()
- redLED()
- slideSwitch()
- leftButton()
- rightButton()
- playTone()
- lightSensor()
- soundSensor()
- motionX()
- motionY()
- motionZ()
- temperature()
- temperatureF()
- colorWheel()
- sensorColor()
- isExpress()

## Examples

  There are many examples implemented in this library. One of the examples is below. You can find other examples [here](https://github.com/adafruit/Adafruit_CircuitPlayground/tree/master/examples)

  soundPressureLevel.ino

```C++
#include <Adafruit_CircuitPlayground.h>
void setup() {
  CircuitPlayground.begin();
  Serial.begin(115200);
}
void loop() {
  Serial.println(CircuitPlayground.mic.soundPressureLevel(50));
}
```

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell others about this library
- Contribute new protocols

Please read [CONTRIBUTING.md](https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Credits

The author and maintainer of this library are Limor Fried/Ladyada and others for Adafruit Industries <info@adafruit.com>.

Based on previous work by:

- T. DiCola
- P. Y. Dragon
- deanm1278
- C. Nelson
- E. Saadia
- per1234
- driveblock
- C. Young
- D. Cogliano

This is a library for the Adafruit CircuitPlayground boards:

- [Circuit Playground Express](https://www.adafruit.com/products/3333)
- [Circuit Playground Classic](https://www.adafruit.com/product/3000)

Check out the links above for our tutorials and wiring diagrams.

Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

## License

This library is licensed under [MIT license](https://opensource.org/licenses/MIT). All text above must be included in any redistribution.
