# Firmata

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/firmata/arduino?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Firmata is a protocol for communicating with microcontrollers from software on a host computer. The [protocol](https://github.com/firmata/protocol) can be implemented in firmware on any microcontroller architecture as well as software on any host computer software package. The Arduino repository described here is a Firmata library for Arduino and Arduino-compatible devices. If you would like to contribute to Firmata, please see the [Contributing](#contributing) section below.

# Contents

- [Usage](#usage)
- [Firmata Client Libraries](#firmata-client-libraries)
- [Updating Firmata in the Arduino IDE - Arduino 1.6.4 and higher](#updating-firmata-in-the-arduino-ide---arduino-164-and-higher)
- [Cloning Firmata](#cloning-firmata)
- [Updating Firmata in the Arduino IDE - older versions (<= 1.6.3 or 1.0.x)](#updating-firmata-in-the-arduino-ide---older-versions--163-or-10x)
  - [Mac OSX:](#mac-osx)
  - [Windows](#windows)
  - [Linux](#linux)
- [Using the Source code rather than release archive (only for versions older than Arduino 1.6.3)](#using-the-source-code-rather-than-release-archive-only-for-versions-older-than-arduino-163)
- [Contributing](#contributing)

## Usage

There are two main models of usage of Firmata. In one model, the author of the Arduino sketch uses the various methods provided by the Firmata library to selectively send and receive data between the Arduino device and the software running on the host computer. For example, a user can send analog data to the host using ``` Firmata.sendAnalog(analogPin, analogRead(analogPin)) ``` or send data packed in a string using ``` Firmata.sendString(stringToSend) ```. See File -> Examples -> Firmata -> AnalogFirmata & EchoString respectively for examples.

The second and more common model is to load a general purpose sketch called StandardFirmata (or one of the variants such as StandardFirmataPlus or StandardFirmataEthernet depending on your needs) on the Arduino board and then use the host computer exclusively to interact with the Arduino board. StandardFirmata is located in the Arduino IDE in File -> Examples -> Firmata.

## Firmata Client Libraries
Most of the time you will be interacting with Arduino with a client library on the host computers. Several Firmata client libraries have been implemented in a variety of popular programming languages:

* processing
  * [https://github.com/firmata/processing](https://github.com/firmata/processing)
  * [http://funnel.cc](http://funnel.cc)
* python
  * [https://github.com/MrYsLab/pymata-aio](https://github.com/MrYsLab/pymata-aio)
  * [https://github.com/MrYsLab/PyMata]([https://github.com/MrYsLab/PyMata)
  * [https://github.com/tino/pyFirmata](https://github.com/tino/pyFirmata)
  * [https://github.com/lupeke/python-firmata](https://github.com/lupeke/python-firmata)
  * [https://github.com/firmata/pyduino](https://github.com/firmata/pyduino)
* perl
  * [https://github.com/ntruchsess/perl-firmata](https://github.com/ntruchsess/perl-firmata)
  * [https://github.com/rcaputo/rx-firmata](https://github.com/rcaputo/rx-firmata)
* ruby
  * [https://github.com/hardbap/firmata](https://github.com/hardbap/firmata)
  * [https://github.com/PlasticLizard/rufinol](https://github.com/PlasticLizard/rufinol)
  * [http://funnel.cc](http://funnel.cc)
* clojure
  * [https://github.com/nakkaya/clodiuno](https://github.com/nakkaya/clodiuno)
  * [https://github.com/peterschwarz/clj-firmata](https://github.com/peterschwarz/clj-firmata)
* javascript
  * [https://github.com/firmata/firmata.js](https://github.com/firmata/firmata.js)
  * [https://github.com/rwldrn/johnny-five](https://github.com/rwldrn/johnny-five)
  * [http://breakoutjs.com](http://breakoutjs.com)
* java
  * [https://github.com/kurbatov/firmata4j](https://github.com/kurbatov/firmata4j)
  * [https://github.com/4ntoine/Firmata](https://github.com/4ntoine/Firmata)
  * [https://github.com/reapzor/FiloFirmata](https://github.com/reapzor/FiloFirmata)
* .NET
  * [https://github.com/SolidSoils/Arduino](https://github.com/SolidSoils/Arduino)
  * [http://www.acraigie.com/programming/firmatavb/default.html](http://www.acraigie.com/programming/firmatavb/default.html)
* Flash/AS3
  * [http://funnel.cc](http://funnel.cc)
  * [http://code.google.com/p/as3glue/](http://code.google.com/p/as3glue/)
* PHP
  * [https://github.com/ThomasWeinert/carica-firmata]()
  * [https://github.com/oasynnoum/phpmake_firmata](https://github.com/oasynnoum/phpmake_firmata)
* Haskell
  * [http://hackage.haskell.org/package/hArduino](http://hackage.haskell.org/package/hArduino)
* iOS
  * [https://github.com/jacobrosenthal/iosfirmata](https://github.com/jacobrosenthal/iosfirmata)
* Dart
  * [https://github.com/nfrancois/firmata](https://github.com/nfrancois/firmata)
* Max/MSP
  * [http://www.maxuino.org/](http://www.maxuino.org/)
* Elixir
  * [https://github.com/kfatehi/firmata](https://github.com/kfatehi/firmata)
* Modelica
  * [https://www.wolfram.com/system-modeler/libraries/model-plug/](https://www.wolfram.com/system-modeler/libraries/model-plug/)
* Go
  * [https://github.com/kraman/go-firmata](https://github.com/kraman/go-firmata)
* vvvv
  * [https://vvvv.org/blog/arduino-second-service](https://vvvv.org/blog/arduino-second-service)
* openFrameworks
  * [http://openframeworks.cc/documentation/communication/ofArduino/](http://openframeworks.cc/documentation/communication/ofArduino/)
* Rust
  * [https://github.com/zankich/rust-firmata](https://github.com/zankich/rust-firmata)

Note: The above libraries may support various versions of the Firmata protocol and therefore may not support all features of the latest Firmata spec nor all Arduino and Arduino-compatible boards. Refer to the respective projects for details.

## Updating Firmata in the Arduino IDE - Arduino 1.6.4 and higher

If you want to update to the latest stable version:

1. Open the Arduino IDE and navigate to: `Sketch > Include Library > Manage Libraries`
2. Filter by "Firmata" and click on the "Firmata by Firmata Developers" item in the list of results.
3. Click the `Select version` dropdown and select the most recent version (note you can also install previous versions)
4. Click `Install`.

### Cloning Firmata

If you are contributing to Firmata or otherwise need a version newer than the latest tagged release, you can clone Firmata directly to your Arduino/libraries/ directory (where 3rd party libraries are installed). This only works for Arduino 1.6.4 and higher, for older versions you need to clone into the Arduino application directory (see section below titled "Using the Source code rather than release archive"). Be sure to change the name to Firmata as follows:

```bash
$ git clone git@github.com:firmata/arduino.git ~/Documents/Arduino/libraries/Firmata
```

*Update path above if you're using Windows or Linux or changed the default Arduino directory on OS X*


## Updating Firmata in the Arduino IDE - older versions (<= 1.6.3 or 1.0.x)

Download the latest [release](https://github.com/firmata/arduino/releases/tag/2.5.8) (for Arduino 1.0.x or Arduino 1.5.6 or higher) and replace the existing Firmata folder in your Arduino application. See the instructions below for your platform.

*Note that Arduino 1.5.0 - 1.5.5 are not supported. Please use Arduino 1.5.6 or higher (or Arduino 1.0.5 or 1.0.6).*

### Mac OSX:

The Firmata library is contained within the Arduino package.

1. Navigate to the Arduino application
2. Right click on the application icon and select `Show Package Contents`
3. Navigate to: `/Contents/Resources/Java/libraries/` and replace the existing
`Firmata` folder with latest [Firmata release](https://github.com/firmata/arduino/releases/tag/2.5.8) (note there is a different download
for Arduino 1.0.x vs 1.6.x)
4. Restart the Arduino application and the latest version of Firmata will be available.

*If you are using the Java 7 version of Arduino 1.5.7 or higher, the file path
will differ slightly: `Contents/Java/libraries/Firmata` (no Resources directory).*

### Windows:

1. Navigate to `c:/Program\ Files/arduino-1.x/libraries/` and replace the existing
`Firmata` folder with the latest [Firmata release](https://github.com/firmata/arduino/releases/tag/2.5.8) (note there is a different download
for Arduino 1.0.x vs 1.6.x).
2. Restart the Arduino application and the latest version of Firmata will be available.

*Update the path and Arduino version as necessary*

### Linux:

1. Navigate to `~/arduino-1.x/libraries/` and replace the existing
`Firmata` folder with the latest [Firmata release](https://github.com/firmata/arduino/releases/tag/2.5.8) (note there is a different download
for Arduino 1.0.x vs 1.6.x).
2. Restart the Arduino application and the latest version of Firmata will be available.

*Update the path and Arduino version as necessary*

### Using the Source code rather than release archive (only for versions older than Arduino 1.6.3)

*It is recommended you update to Arduino 1.6.4 or higher if possible, that way you can clone directly into the external Arduino/libraries/ directory which persists between Arduino application updates. Otherwise you will need to move your clone each time you update to a newer version of the Arduino IDE.*

If you're stuck with an older version of the IDE, then follow these keep reading otherwise jump up to the "Cloning Firmata section above".

Clone this repo directly into the core Arduino application libraries directory. If you are using
Arduino 1.5.x or <= 1.6.3, the repo directory structure will not match the Arduino
library format, however it should still compile as long as you are using Arduino 1.5.7
or higher.

You will first need to remove the existing Firmata library, then clone firmata/arduino
into an empty Firmata directory:

```bash
$ rm -r /Applications/Arduino.app/Contents/Resources/Java/libraries/Firmata
$ git clone git@github.com:firmata/arduino.git /Applications/Arduino.app/Contents/Resources/Java/libraries/Firmata
```

*Update paths if you're using Windows or Linux*

To generate properly formatted versions of Firmata (for Arduino 1.0.x and Arduino 1.6.x), run the
`release.sh` script.

## Contributing

If you discover a bug or would like to propose a new feature, please open a new [issue](https://github.com/firmata/arduino/issues?sort=created&state=open). Due to the limited memory of standard Arduino boards we cannot add every requested feature to StandardFirmata. Requests to add new features to StandardFirmata will be evaluated by the Firmata developers. However it is still possible to add new features to other Firmata implementations (Firmata is a protocol whereas StandardFirmata is just one of many possible implementations).

To contribute, fork this repository and create a new topic branch for the bug, feature or other existing issue you are addressing. Submit the pull request against the *master* branch.

If you would like to contribute but don't have a specific bugfix or new feature to contribute, you can take on an existing issue, see issues labeled "pull-request-encouraged". Add a comment to the issue to express your intent to begin work and/or to get any additional information about the issue.

You must thoroughly test your contributed code. In your pull request, describe tests performed to ensure that no existing code is broken and that any changes maintain backwards compatibility with the existing api. Test on multiple Arduino board variants if possible. We hope to enable some form of automated (or at least semi-automated) testing in the future, but for now any tests will need to be executed manually by the contributor and reviewers.

Use [Artistic Style](http://astyle.sourceforge.net/) (astyle) to format your code. Set the following rules for the astyle formatter:

```
style = ""
indent-spaces = 2
indent-classes = true
indent-switches = true
indent-cases = true
indent-col1-comments = true
pad-oper = true
pad-header = true
keep-one-line-statements = true
```

If you happen to use Sublime Text, [this astyle plugin](https://github.com/timonwong/SublimeAStyleFormatter) is helpful. Set the above rules in the user settings file.
