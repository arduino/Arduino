# arduino-linux-setup.sh : A simple Arduino setup script for Linux systems
# Copyright (C) 2015 Arduino Srl
#
# Author : Arturo Rinaldi
# E-mail : arturo@arduino.org
# Project URL : https://github.com/artynet/arduino-linux-setup
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Release v8 changelog :
#
#   + rules are now created in /tmp folder
#
# Release v7 changelog :
#
#	+ Adding project URL
#	+ minor bugfixing
#
# Release v6 changelog :
#
#	+ removing sudocheck function and control
#
# Release v5 changelog :
#
#	+ adding UDEV rule for stm32 DFU mode
#
# Release v4 changelog :
#
#	+ The rules are generated in a temporary folder
#
#	+ the user should run it without sudo while having its permissions
#
# Release v3 changelog :
#
#	+ The most common linux distros are now fully supported
#
#	+ now the script checks for SUDO permissions
#

#! /bin/bash

# if [[ $EUID != 0 ]] ; then
#   echo This must be run as root!
#   exit 1
# fi

refreshudev () {

    echo ""
    echo "Restarting udev"
    echo ""

    sudo service udev restart
    sudo udevadm control --reload-rules
    sudo udevadm trigger

}

groupsfunc () {

    echo ""
    echo "******* Add User to dialout,tty, uucp, plugdev groups *******"
    echo ""

    sudo usermod -a -G tty $1
    sudo usermod -a -G dialout $1
    sudo usermod -a -G uucp $1
    sudo groupadd plugdev
    sudo usermod -a -G plugdev $1

}

acmrules () {

    echo ""
    echo "# Setting serial port rules"
    echo ""

cat <<EOF
"KERNEL="ttyUSB[0-9]*", TAG+="udev-acl", TAG+="uaccess", OWNER="$1"
"KERNEL="ttyACM[0-9]*", TAG+="udev-acl", TAG+="uaccess", OWNER="$1"
EOF

}

openocdrules () {

    echo ""
    echo "# Adding Arduino M0/M0 Pro, Primo UDEV Rules for CMSIS-DAP port"
    echo ""

cat <<EOF
ACTION!="add|change", GOTO="openocd_rules_end"
SUBSYSTEM!="usb|tty|hidraw", GOTO="openocd_rules_end"

#Please keep this list sorted by VID:PID

#CMSIS-DAP compatible adapters
ATTRS{product}=="*CMSIS-DAP*", MODE="664", GROUP="plugdev"

LABEL="openocd_rules_end"
EOF

}

avrisprules () {

    echo ""
    echo "# Adding AVRisp UDEV rules"
    echo ""

cat <<EOF
SUBSYSTEM!="usb_device", ACTION!="add", GOTO="avrisp_end"
# Atmel Corp. JTAG ICE mkII
ATTR{idVendor}=="03eb", ATTRS{idProduct}=="2103", MODE="660", GROUP="dialout"
# Atmel Corp. AVRISP mkII
ATTR{idVendor}=="03eb", ATTRS{idProduct}=="2104", MODE="660", GROUP="dialout"
# Atmel Corp. Dragon
ATTR{idVendor}=="03eb", ATTRS{idProduct}=="2107", MODE="660", GROUP="dialout"

LABEL="avrisp_end"
EOF

}

dfustm32rules () {

    echo ""
    echo "# Adding STM32 bootloader mode UDEV rules"
    echo ""

cat <<EOF
# Example udev rules (usually placed in /etc/udev/rules.d)
# Makes STM32 DfuSe device writeable for the "plugdev" group

ACTION=="add", SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="df11", MODE="664", GROUP="plugdev", TAG+="uaccess"
EOF

}

dfuarduino101rules (){

    echo ""
    echo "# Arduino 101 in DFU Mode"
    echo ""

cat <<EOF
SUBSYSTEM=="tty", ENV{ID_REVISION}=="8087", ENV{ID_MODEL_ID}=="0ab6", MODE="0666", ENV{ID_MM_DEVICE_IGNORE}="1", ENV{ID_MM_CANDIDATE}="0"
SUBSYSTEM=="usb", ATTR{idVendor}=="8087", ATTR{idProduct}=="0aba", MODE="0666", ENV{ID_MM_DEVICE_IGNORE}="1"
EOF

}

removemm () {

    echo ""
    echo "******* Removing modem manager *******"
    echo ""

    if [ -f /etc/lsb-release -a ! -f /etc/SuSE-release ] || [ -f /etc/debian_version ] || [ -f /etc/linuxmint/info ]
    then
        #Only for Ubuntu/Mint/Debian
        sudo apt-get -y remove modemmanager
    elif [ -f /etc/SuSE-release ]
    then
        #Only for Suse
        sudo zypper remove modemmanager
    elif [ -f /etc/fedora-release ] || [ -f /etc/redhat-release ]
    then
        #Only for Red Hat/Fedora/CentOS
        sudo yum remove modemmanager
    else
        echo ""
        echo "Your system is not supported, please take care of it with your package manager"
        echo ""
    fi

}


if [ "$1" = "" ]
then
    echo ""
    echo "Run the script with command ./arduino-linux-setup.sh \$USER"
    echo ""
else

    [ `whoami` != $1 ] && echo "" && echo "The user name is not the right one, please double-check it !" && echo "" && exit 1

    groupsfunc $1

    removemm

    acmrules $1 > /tmp/90-extraacl.rules

    openocdrules > /tmp/98-openocd.rules

    avrisprules > /tmp/avrisp.rules

    dfustm32rules > /tmp/40-dfuse.rules

    dfuarduino101rules > /tmp/99-arduino-101.rules

    sudo mv /tmp/*.rules /etc/udev/rules.d/

    refreshudev

    echo ""
    echo "*********** Please Reboot your system ************"
    echo ""
fi
