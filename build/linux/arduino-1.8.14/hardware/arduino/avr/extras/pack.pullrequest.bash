#!/bin/bash -ex

#  pack.*.bash - Bash script to help packaging avr core releases.
#  Copyright (c) 2015 Arduino LLC.  All right reserved.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

PR_NUMBER=$1
BUILD_NUMBER=$2
VERSION=`grep version= platform.txt | sed 's/version=//g'`

PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`
FILENAME=package_avr-b${BUILD_NUMBER}.tar.bz2

rm -f $FILENAME

# Change name in platform.txt
sed -i "s/name=.*/name=SAMD Pull request #${PR_NUMBER} (Build ${BUILD_NUMBER})/" platform.txt

cd ..
tar --transform "s|$FOLDERNAME|avr-PR${PR_NUMBER}_b${BUILD_NUMBER}|g"  --exclude=extras/** --exclude=.git* --exclude=.idea -cjf $FILENAME $FOLDERNAME
cd -

mv ../$FILENAME .

CHKSUM=`sha256sum $FILENAME | awk '{ print $1 }'`
SIZE=`wc -c $FILENAME | awk '{ print $1 }'`

cat extras/package_index.json.PR.template |
sed s/%%PR_NUMBER%%/${PR_NUMBER}/ |
sed s/%%BUILD_NUMBER%%/${BUILD_NUMBER}/ |
sed s/%%VERSION%%/${VERSION}-build-${BUILD_NUMBER}/ |
sed s/%%FILENAME%%/${FILENAME}/ |
sed s/%%CHECKSUM%%/${CHKSUM}/ |
sed s/%%SIZE%%/${SIZE}/ > package_avr-b${BUILD_NUMBER}_index.json

