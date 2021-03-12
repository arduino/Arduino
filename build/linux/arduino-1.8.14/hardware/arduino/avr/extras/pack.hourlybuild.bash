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

BUILD_NUMBER=$1
CURR_TIME=`date "+%Y-%m-%d %H:%M"`
CURR_TIME_SED=`date "+%Y\\-%m\\-%d %H:%M"`
VERSION=9.9.9-Hourly

PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`
FILENAME=package_avr-hourly-b${BUILD_NUMBER}.tar.bz2

rm -f $FILENAME

# Change name in platform.txt
sed -i "s/name=.*/name=SAMD Hourly Build ${BUILD_NUMBER} (${CURR_TIME})/" platform.txt

cd ..
tar --transform "s|$FOLDERNAME|avr-hourly_b${BUILD_NUMBER}|g"  --exclude=extras/** --exclude=.git* --exclude=.idea -cjf $FILENAME $FOLDERNAME
cd -

mv ../$FILENAME .

CHKSUM=`sha256sum $FILENAME | awk '{ print $1 }'`
SIZE=`wc -c $FILENAME | awk '{ print $1 }'`

cat extras/package_index.json.Hourly.template |
sed "s/%%BUILD_NUMBER%%/${BUILD_NUMBER}/" |
sed "s/%%CURR_TIME%%/${CURR_TIME_SED}/" |
sed "s/%%VERSION%%/${VERSION}/" |
sed "s/%%FILENAME%%/${FILENAME}/" |
sed "s/%%CHECKSUM%%/${CHKSUM}/" |
sed "s/%%SIZE%%/${SIZE}/" > package_avr-hourly-build_index.json

