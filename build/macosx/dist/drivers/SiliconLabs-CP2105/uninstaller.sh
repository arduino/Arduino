#!/bin/bash

if [ -d /System/Library/Extensions/SiLabsUSBDriver.kext ]; then
sudo rm -rf /System/Library/Extensions/SiLabsUSBDriver.kext
fi

if [ -d /System/Library/Extensions/SiLabsUSBDriver64.kext ]; then
sudo rm -rf /System/Library/Extensions/SiLabsUSBDriver64.kext
fi

if [ -d /Library/Extensions/SiLabsUSBDriverYos.kext ]; then
sudo rm -rf /Library/Extensions/SiLabsUSBDriverYos.kext
fi

if [ -d /Library/Extensions/SiLabsUSBDriver.kext ]; then
sudo rm -rf /Library/Extensions/SiLabsUSBDriver.kext
fi
