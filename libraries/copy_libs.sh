#!/bin/bash

LIBRARIES="aJson PubNub Temboo MQTTClient PubSubClient"
ARCHES="msp430 lm4f cc3200"
OSTYPE=`uname`

if [[ "$OSTYPE" == "Linux" ]]; then
	OS_PATH="linux/work/hardware"
elif [[ "$OSTYPE" == "Darwin" ]]; then
	OS_PATH="macosx/work/Energia.app/Contents/Resources/Java/hardware"
	echo $OS_PATH
elif [[ "$OSTYPE" == "MINGW32_NT-6.2" ]]; then
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
