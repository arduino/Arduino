#/bin/bash

greadlink --help  >/dev/null 2>&1 || { echo >&2 "greadline is needed. Please install via homebrew \"brew install coreutils\".  Aborting."; exit 1; }

if [ $# -eq 0 ]
  then
    echo "Usage: $(basename $0) [version]"
    exit 1
fi

SCRIPT_PATH=$(greadlink -f $(dirname "$0"))
ROOT_PATH=$(greadlink -f ${SCRIPT_PATH}/..)
OUTPUT_PATH=$(greadlink -f ${ROOT_PATH}/output)

VERSION=$1
FILENAME=xmegaduino-${VERSION}.tar.bz2

if [ -e  ${OUTPUT_PATH}/${FILENAME} ]
  then
    echo "File ${FILENAME} alread exist. Aborting."
    exit 1
fi

if [ -e  ${OUTPUT_PATH}/${VERSION} ]
  then
    echo "Directory ${OUTPUT_PATH}/${VERSION} alread exist. Aborting."
    exit 1
fi


cd ${ROOT_PATH}
mkdir ${OUTPUT_PATH}
cp -r hardware/arduino/xmega ${OUTPUT_PATH}/${VERSION}
cd ${OUTPUT_PATH}
COPYFILE_DISABLE=1 tar -jcf ${FILENAME} ${VERSION}
shasum -a 256 ${FILENAME}
ls -l ${FILENAME}

echo "Done"