#!/bin/bash -ex

VERSION=$1
if [ -z $VERSION ]; then
    echo Please specify an arduino-cli version
    exit 1
fi

git rm arduino-cli*.sha -f
rm -f arduino-cli_${VERSION}*

for VARIANT in Linux_32bit.tar.gz Linux_64bit.tar.gz Linux_ARM64.tar.gz macOS_64bit.tar.gz Linux_ARMv7.tar.gz Windows_32bit.zip; do
    wget https://downloads.arduino.cc/arduino-cli/arduino-cli_${VERSION}_${VARIANT}
    shasum arduino-cli_${VERSION}_${VARIANT} | cut -d " " -f 1 > arduino-cli_${VERSION}_${VARIANT}.sha
    git add arduino-cli_${VERSION}_${VARIANT}.sha
done

sed -i "s/\\(ARDUINO-CLI-VERSION\" value=\\)\"\\(.*\\)\"/\\1\"${VERSION}\"/" build.xml
git add build.xml

