## Description

This is a fork of [Firmata](http://firmata.org/wiki/Main_Page) for LaunchPads. Originally Firmata is a communication protocol written for Arduino that allows PC sending commands to the target device. Since LaunchPads now has [Energia](http://energia.nu/download/) support, all the great things Firmata offers can be used on LaunchPads.

**How to set up Firmata on LaunchPad (Windows)**
* Install [Energia](http://energia.nu/download/)
* Download the [latest Firmata folder] (https://github.com/energia/Energia/tree/master/libraries/Firmata) 
* Put the Firmata folder under "Energia\libraries\Energia\libraries\Firmata"
* Run Energia.exe. Go to File->Examples->Firmata->StandardFirmata.
* Then, go to Tools->Board->(your device, ex: F5529)
* Click the right arrow to upload to your device
* After uploading is done, one of your LEDs to flash for a few times. This confirms that Firmata is running properly on the target device.
