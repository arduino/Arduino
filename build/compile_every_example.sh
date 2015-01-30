#!/bin/bash -e

EXAMPLES=`find $1 -name '*.ino' | sort`

echo
echo
echo "### Testing Uno ###"
echo
echo

for EX in $EXAMPLES ; do
	echo $EX
	if [[ "$EX" == "examples/10.StarterKit/p13_TouchSensorLamp/p13_TouchSensorLamp.ino" || $EX == "examples/04.Communication/MultiSerialMega/MultiSerialMega.ino" || $EX == "examples/09.USB/"* ]] ; then
		echo "...skipping"
		continue;
	fi
	./arduino --verify --board arduino:avr:uno $EX
	echo
done

echo
echo
echo "### Testing Leonardo ###"
echo
echo

for EX in $EXAMPLES ; do
	echo $EX
	if [[ "$EX" == "examples/10.StarterKit/p13_TouchSensorLamp/p13_TouchSensorLamp.ino" ]] ; then
		echo "...skipping"
		continue;
	fi
	./arduino --verify --board arduino:avr:leonardo $EX
	echo
done

