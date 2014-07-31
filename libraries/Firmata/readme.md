#Firmata

Firmata is a protocol for communicating with microcontrollers from software on a host computer. The [protocol](http://firmata.org/wiki/Protocol) can be implemented in firmware on any microcontroller architecture as well as software on any host computer software package. The arduino repository described here is a Firmata library for Arduino and Arduino-compatible devices. See the [firmata wiki](http://firmata.org/wiki/Main_Page) for additional informataion. If you would like to contribute to Firmata, please see the [Contributing](#contributing) section below.

##Usage

There are two main models of usage of Firmata. In one model, the author of the Arduino sketch uses the various methods provided by the Firmata library to selectively send and receive data between the Arduino device and the software running on the host computer. For example, a user can send analog data to the host using ``` Firmata.sendAnalog(analogPin, analogRead(analogPin)) ``` or send data packed in a string using ``` Firmata.sendString(stringToSend) ```. See File -> Examples -> Firmata -> AnalogFirmata & EchoString respectively for examples.

The second and more common model is to load a general purpose sketch called StandardFirmata on the Arduino board and then use the host computer exclusively to interact with the Arduino board. StandardFirmata is located in the Arduino IDE in File -> Examples -> Firmata.

##Firmata Client Libraries
Most of the time you will be interacting with arduino with a client library on the host computers. Several Firmata client libraries have been implemented in a variety of popular programming languages:

* procesing
  * [https://github.com/firmata/processing]
  * [http://funnel.cc]
* python
  * [https://github.com/firmata/pyduino]
  * [https://github.com/lupeke/python-firmata]
  * [https://github.com/tino/pyFirmata]
* perl
  * [https://github.com/ntruchsess/perl-firmata]
  * [https://github.com/rcaputo/rx-firmata]
* ruby 
  * [https://github.com/hardbap/firmata]
  * [https://github.com/PlasticLizard/rufinol]
  * [http://funnel.cc]
* clojure
  * [https://github.com/nakkaya/clodiuno]
* javascript 
  * [https://github.com/jgautier/firmata]
  * [http://breakoutjs.com]
  * [https://github.com/rwldrn/johnny-five]
* java 
  * [https://github.com/4ntoine/Firmata]
  * [https://github.com/shigeodayo/Javarduino]
* .NET
  * [http://www.imagitronics.org/projects/firmatanet/]
* Flash/AS3
  * [http://funnel.cc]
  * [http://code.google.com/p/as3glue/]
* PHP
  * [https://bitbucket.org/ThomasWeinert/carica-firmata]

Note: The above libraries may support various versions of the Firmata protocol and therefore may not support all features of the latest Firmata spec nor all arduino and arduino-compatible boards. Refer to the respective projects for details.

##Updating Firmata in the Arduino IDE (< Arduino 1.5)
The version of firmata in the Arduino IDE contains an outdated version of Firmata. To update Firmata, clone the repo into the location of firmata in the arduino IDE or download the latest [tagged version](https://github.com/firmata/arduino/tags) (stable), rename the folder to "Firmata" and replace the existing Firmata folder in your Ardino application.

**Mac OSX**:

```bash
$ rm -r /Applications/Arduino.app/Contents/Resources/Java/libraries/Firmata
$ git clone git@github.com:firmata/arduino.git /Applications/Arduino.app/Contents/Resources/Java/libraries/Firmata
```

If you are downloading the latest tagged version of Firmata, rename it to "Firmata" and copy to /Applications/Arduino.app/Contents/Resources/Java/libraries/ overwriting the existing Firmata directory. Right-click (or conrol + click) on the Arduino application and choose "Show Package Contents" and navigate to the libraries directory.

**Windows**:

Using the Git Shell application installed with [GitHub for Windows](http://windows.github.com/) (set default shell in options to Git Bash) or other command line based git tool:

update the path and arduino version as necessary
```bash
$ rm -r c:/Program\ Files/arduino-1.x/libraries/Firmata
$ git clone git@github.com:firmata/arduino.git c:/Program\ Files/arduino-1.x/libraries/Firmata
```

Note: If you use GitHub for Windows, you must clone the firmata/arduino repository using the Git Shell application as described above. You can use the Github for Windows GUI only after you have cloned the repository. Drag the Firmata file into the Github for Windows GUI to track it.

**Linux**:

update the path and arduino version as necessary
```bash
$ rm -r ~/arduino-1.x/libraries/Firmata
$ git clone git@github.com:firmata/arduino.git ~/arduino-1.x/libraries/Firmata
```

##Updating Firmata in the Arduino IDE (>= Arduino 1.5.2)
As of Arduino 1.5.2 and there are separate library directories for the sam and
avr architectures. To update Firmata in Arduino 1.5.2 or higher, follow the 
instructions above for pre Arduino 1.5 versions but update the path as follows:

**Mac OSX**:
```
/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/avr/libraries/Firmata
/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/sam/libraries/Firmata
```

**Windows**:
```
/Program\ Files/arduino-1.5.x/hardware/arduino/avr/libraries/Firmata
/Program\ Files/arduino-1.5.x/hardware/arduino/sam/libraries/Firmata
```

**Linux**
```
~/arduino-1.5.x/hardware/arduino/avr/libraries/Firmata
~/arduino-1.5.x/hardware/arduino/sam/libraries/Firmata
```

<a name="contributing" />
##Contributing

If you discover a bug or would like to propose a new feature, please open a new [issue](https://github.com/firmata/arduino/issues?sort=created&state=open). Due to the limited memory of standard Arduino boards we cannot add every requested feature to StandardFirmata. Requests to add new features to StandardFirmata will be evaluated by the Firmata developers. However it is still possible to add new features to other Firmata implementations (Firmata is a protocol whereas StandardFirmata is just one of many possible implementations).

To contribute, fork this respository and create a new topic branch for the bug, feature or other existing issue you are addressing. Submit the pull request against the *dev* branch.

If you would like to contribute but don't have a specific bugfix or new feature to contribute, you can take on an existing issue, see issues labeled "pull-request-encouraged". Add a comment to the issue to express your intent to begin work and/or to get any additional information about the issue.

You must thorougly test your contributed code. In your pull request, describe tests performed to ensure that no existing code is broken and that any changes maintain backwards compatibility with the existing api. Test on multiple Arduino board variants if possible. We hope to enable some form of automated (or at least semi-automated) testing in the future, but for now any tests will need to be executed manually by the contributor and reviewsers.

Maintain the existing code style:

- Indentation is 2 spaces
- Use spaces instead of tabs
- Use camel case for both private and public properties and methods
- Document functions (specific doc style is TBD... for now just be sure to document)
- Insert first block bracket on line following the function definition:

<pre>void someFunction()
{
  // do something
}
</pre>
