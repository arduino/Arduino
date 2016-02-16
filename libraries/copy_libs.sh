#!/bin/bash

LIBRARIES="Adafruit_TMP007 Adafruit_TMP006 OneWire CogLCD aJson PubNub Temboo MQTTClient PubSubClient OPT3001 M2XStreamClient OneMsTaskTimer LCD_SharpBoosterPack_SPI"
ARCHES="cc2600emt msp430 lm4f cc3200 msp432 cc3200emt"
OSTYPE=`uname`

if [[ "$OSTYPE" == "Linux" ]]; then
	OS_PATH="linux/work/hardware"
elif [[ "$OSTYPE" == "Darwin" ]]; then
	OS_PATH="macosx/work/Energia.app/Contents/Resources/Java/hardware"
	echo $OS_PATH
elif [[ $OSTYPE=="MINGW32*" ]]; then
	OS_PATH="windows/work/hardware"
fi


for ARCH in $ARCHES
do
	echo $ARCH
	for LIBRARY in $LIBRARIES
	do
		rsync -av --exclude=".*" ../libraries/$LIBRARY $OS_PATH/$ARCH/libraries/ > /dev/null 2>&1
	done
done
