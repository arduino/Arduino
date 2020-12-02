# Hello Circuit Playground
A set of very basic example sketches to demonstrate the various components
of the [Circuit Playground](https://www.adafruit.com/products/3000).
These sketches were tested and verified with:
* Circuit Playground Developer Edition
* Ubuntu 16.04 LTS
* Arduino IDE 1.6.11
* Adafruit AVR Boards 1.4.9
* Adafruit Circuit Playground Library 1.6.1

## Hello_Blink
Blinks the little red LED next to the micro USB connector once per second.

## Hello_SlideSwitch
The position (+ or -) of the slide switch is sent to the serial monitor once
per second.
```
Slide Switch: -
Slide Switch: +
Slide Switch: +
```

## Hello_Buttons
The position (UP or DOWN) of the two push buttons are sent to the serial
monitor once per second.
```
Left Button:   UP   Right Button:   UP
Left Button: DOWN   Right Button:   UP
Left Button:   UP   Right Button:   UP
Left Button:   UP   Right Button: DOWN
```

## Hello_LightSensor
The reading (0-1023) from the light sensor is sent to the serial monitor once
per second.
```
Light Sensor: 962
Light Sensor: 954
Light Sensor: 275
Light Sensor: 192
Light Sensor: 688
```

## Hello_Temperature
The temperature is sent to the serial monitor once per second.
```
tempC: 28.25  tempF: 83.02
tempC: 29.71  tempF: 85.64
tempC: 30.72  tempF: 87.30
tempC: 31.85  tempF: 89.32
```

## Hello_Accelerometer
The readings (in m/s<sup>2</sup>) from the 3 axes of the accelerometer are sent
to the serial monitor once per second. (1G ~= 9.8 m/s<sup>2</sup>)
```
X: -0.33  Y: 2.41  Z: 9.40
X: -1.25  Y: 4.20  Z: 1.86
X: -7.95  Y: -3.50  Z: -2.47
X: 0.11  Y: -8.38  Z: 2.25
X: -2.28  Y: 2.73  Z: 9.10
```

## Hello_SoundSensor
The reading (0-1023) from the sound sensor (microphone) is sent to the serial
monitor once per second.
```
Sound Sensor: 339
Sound Sensor: 339
Sound Sensor: 1023
Sound Sensor: 10
Sound Sensor: 15
Sound Sensor: 1023
Sound Sensor: 336
```

## Hello_Speaker
Plays a 500Hz tone for 0.1 seconds on the speaker, followed by 1 second of
silence.

## Hello_NeoPixels
Clears all pixels for 0.5 seconds then displays colors on the fist 5 pixels
using individual 8-bit values and the same colors on the next 5 pixels using
24-bit values. After 5 seconds, this repeats.
