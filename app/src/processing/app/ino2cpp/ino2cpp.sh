#!/bin/sh
#
# Convert Energia sketch files into buildable C/C++ files
#
#  Usage: ino2cpp [-o output] [-Dname=value] [-E] [-T tplt] sketch target
#
#  Note: ino2cpp can run without an existing installation of Energia
#
root="`dirname $0`"

## locate a java command
JAVA=java
for j in "$ENERGIA/java/bin/java" "`which java 2> /dev/null`" "$JAVA_HOME/bin/java"; do
    if [ -x "$j" -o -x "$j.exe" ]; then
        JAVA="$j"
        break
    fi
done

## run the ino2cpp preprocessor
$JAVA -jar "$root"/ino2cpp.jar -r "$root" -T $root/templates/Variables.mk.template "$@" 
