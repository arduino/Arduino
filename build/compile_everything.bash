#!/bin/bash -e

cd linux/work

./arduino --board arduino:avr:uno --verify examples/01.Basics/Blink/Blink.ino

for s in `find examples/0{1,2,3,4,5,6,7,8}* -name '*.ino' -not -name '*MultiSerial*'`
do
	echo arduino:avr:uno $s
	./arduino-builder -hardware ./hardware -tools ./hardware/tools/avr -tools ./tools-builder -libraries ./libraries -fqbn arduino:avr:uno $s
	echo
done

for s in `find libraries/{Ethernet,Firmata,GSM,LiquidCrystal,SD,Servo,SpacebrewYun,Stepper,Temboo,TFT,WiFi} -name '*.ino' -not -name 'StandardFirmataEthernet.ino' -not -name 'StandardFirmataYun.ino' -not -name 'StandardFirmataChipKIT.ino' -not -name 'firmata_test.ino' -not -wholename 'libraries/Bridge/examples/Temboo*'`
do
	echo arduino:avr:uno $s
	./arduino-builder -hardware ./hardware -tools ./hardware/tools/avr -tools ./tools-builder -libraries ./libraries -fqbn arduino:avr:uno $s
	echo
done

for s in `find examples/0{1,2,3,4,5,6,7,8,9}* -name '*.ino'`
do
	echo arduino:avr:leonardo $s
	./arduino-builder -hardware ./hardware -tools ./hardware/tools/avr -tools ./tools-builder -libraries ./libraries -fqbn arduino:avr:leonardo $s
	echo
done

for s in `find libraries/{Bridge,Esplora,Ethernet,Firmata,GSM,Keyboard,LiquidCrystal,Mouse,Robot_Control,RobotIRremote,Robot_Motor,SD,Servo,SpacebrewYun,Stepper,Temboo,TFT,WiFi} -name '*.ino' -not -name 'StandardFirmataEthernet.ino' -not -name 'StandardFirmataChipKIT.ino' -not -name 'firmata_test.ino' -not -wholename 'libraries/Bridge/examples/Temboo*'`
do
	echo arduino:avr:leonardo $s
	./arduino-builder -hardware ./hardware -tools ./hardware/tools/avr -tools ./tools-builder -libraries ./libraries -fqbn arduino:avr:leonardo $s
	echo
done

for s in `find examples/0{1,2,3,4,5,6,7,8}* -name '*.ino'`
do
	echo arduino:avr:mega:cpu=atmega2560 $s
	./arduino-builder -hardware ./hardware -tools ./hardware/tools/avr -tools ./tools-builder -libraries ./libraries -fqbn arduino:avr:mega:cpu=atmega2560 $s
	echo
done

for s in `find libraries/{Bridge,Esplora,Ethernet,Firmata,GSM,Keyboard,LiquidCrystal,Mouse,Robot_Control,RobotIRremote,Robot_Motor,SD,Servo,SpacebrewYun,Stepper,Temboo,TFT,WiFi} -name '*.ino' -not -name 'StandardFirmataEthernet.ino' -not -name 'StandardFirmataChipKIT.ino' -not -name 'firmata_test.ino' -not -wholename 'libraries/Bridge/examples/Temboo*'`
do
	echo arduino:avr:mega:cpu=atmega2560 $s
	./arduino-builder -hardware ./hardware -tools ./hardware/tools/avr -tools ./tools-builder -libraries ./libraries -fqbn arduino:avr:mega:cpu=atmega2560 $s
	echo
done
