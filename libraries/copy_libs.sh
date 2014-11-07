#!/bin/bash

LIBRARIES="aJson PubNub Temboo MQTTClient PubSubClient"
ARCHES="msp430 lm4f cc3200"
OSTYPE=`uname`

if [[ "$OSTYPE" == "Linux" ]]; then
	echo "linux"
elif [[ "$OSTYPE" == "Darwin" ]]; then
	OS_PATH="macosx/work/Energia.app/Contents/Resources/Java/hardware"
	echo $OS_PATH
elif [[ "$OSTYPE" == "Cygwin" ]]; then
	echo "cygwin"
fi


for ARCH in $ARCHES
do
	echo $ARCH
	for LIBRARY in $LIBRARIES
	do
		rsync -av --exclude=".*" ../libraries/$LIBRARY $OS_PATH/$ARCH/libraries/ > /dev/null 2>&1
	done
done
