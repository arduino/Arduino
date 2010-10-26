#Test builder and runner make file
# each test needs make compiole, make upload, make getResult
#this also need to be done for the build for each environment

BOARD			?= atmega328
PORT			?= /dev/ttyUSB0
ARD_HOME		?= ../../../build/linux/work
ARD_BIN		?= /usr/bin
AVRDUDE_BIN	?= /usr/bin
AVRDUDE_CONF	?=/etc/avrdude.conf
LIB_DIRS  	=  $(ARD_HOME)/libraries/EEPROM $(ARD_HOME)/libraries/ArduinoTestSuite $(ARD_HOME)/libraries/Wire $(ARD_HOME)/libraries/Wire/utility

#SKETCH ?= 
#BUILD_DIR

PROGRAMMER ?= stk500v1
#PROGRAMMER ?= stk500v2

#include Makefile.master
include ../Makefile.master
