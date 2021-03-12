# Testing Firmata

Tests tests are written using the [ArduinoUnit](https://github.com/mmurdoch/arduinounit) library (version 2.0).

Follow the instructions in the [ArduinoUnit readme](https://github.com/mmurdoch/arduinounit/blob/master/readme.md) to install the library.

Compile and upload the test sketch as you would any other sketch. Then open the
Serial Monitor to view the test results.

If you make changes to Firmata.cpp, run the tests in /test/ to ensure
that your changes have not produced any unexpected errors.

You should also perform manual tests against actual hardware.
