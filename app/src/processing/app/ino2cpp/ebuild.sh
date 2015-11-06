#!/bin/sh
#
#  Command-line build of an Energia MT sketch
#
#  Usage: ebuild [-e energia_root] [-t target] sketch-dir build-dir [ppopts...]
#
#    where,
#      -e energia_root - installation directory of Energia MT.  If not 
#                        specified, uses the directory containing the directory
#                        containing this script; i.e., `dirname $0`/..
#                        Note: a complete installation of Energia is required
#                        in order to build an executable.
#      -t target       - target; e.g., cc3200emt:RedBearLab_CC3200.  If not
#                        specified, uses cc3200emt:CC3200_LAUNCHXL
#      sketch_dir      - directory containing the sketch to build
#      build_dir       - output directory for the build of the sketch
#      ppopts          - Energia MT preprocessor (ino2cpp) options; e.g., 
#                          -Dsketchbook.path=...
#                          -Dbuild.drvlib={true|false}
#
#  Note: A complete installation of Energia is REQUIRED in order for the build
#        to work.  Energia contains numerous makefiles, all of which are 
#        required to complete the build.
#
#  Examples
#   1. Build a sketch for the cc3200emt:CC3200_LAUNCHXL
#
#           ebuild.ksh mysketch mybuild
#
#    2. Using example from a contributed library installed in, say, 
#       $ZUMOCC3200, build in the local directory ./foo
#
#           ebuild.ksh -t cc3200emt:RedBearLab_CC3200 \
#                      $ZUMOCC3200/examples/AssistedDrive ./foo \
#                     -Dsketchbook.path=../$ZUMOCC3200
#

pname="$0"
mydir="`dirname $pname`"

# someday this will be inside Energia
INO2CPP="$mydir"
ENERGIA="`cd $mydir/..; /bin/pwd`"

usage="usage: $0 [-e energia_root] [-t target] sketch-dir build-dir [ino2cpp_options ...]"

## parse command line options
target="cc3200emt:CC3200_LAUNCHXL"
while getopts e:t: c ; do
    case $c in
        e )  ENERGIA="$OPTARG" ;;
        t )  target="$OPTARG" ;;
        \?)  echo "$usage"
                exit 1;;
    esac
done
shift `expr $OPTIND - 1`

## validate command line options
if [ $# -lt 2 ]; then
    echo $usage
    exit 1
fi

sketch=$1
build=$2
shift 2

## locate a java command
JAVA=java
for j in "$ENERGIA/java/bin/java" "`which java 2> /dev/null`" "$JAVA_HOME/bin/java"; do
    if [ -x "$j" -o -x "$j.exe" ]; then
        JAVA="$j"
        break
    fi
done

## locate a make command
MAKE=make
for m in $ENERGIA/tools/common/bin/make "`which make 2> /dev/null`"; do
    if [ -x "$m" -o -x "$m.exe" ]; then
        MAKE="$m"
        break
    fi
done

## check that ENERGIA is in fact an Energia installation
if [ ! -r "$ENERGIA/hardware/common/Makefile" ]; then
    echo "$pname: error: '$ENERGIA/hardware/common/Makefile' does not exist; '$ENERGIA' doesn't seem to be an installation of Energia." 2>&1
    exit 1
fi

## run the Energia Wiring preprocessor
echo processing $sketch [$target] ...
$JAVA -jar $INO2CPP/ino2cpp.jar -o $build -T $INO2CPP/templates/Variables.mk.template -r $ENERGIA $* $sketch $target
if [ "$?" != "0" ]; then
    echo "$pname: error: Energia ino2cpp preprocessor failed." 2>&1
    exit 1
fi

## compile!
$MAKE -C $build -f "$ENERGIA/hardware/common/Makefile"
