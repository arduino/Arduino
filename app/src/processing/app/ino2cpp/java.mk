# JDK specifies the JDK used to build the ino2cpp classes
JDK ?= $(TOOLS)/vendors/oracle/jdk/jdk1.6.0_37/Linux

# JVM_TARGET specifies the JVM version "targeted" by javac
JVM_TARGET ?= 1.6

# JVM<target>_BOOTCLASSES specifies a target-specific rt.jar to build against
#
#  We must explicitly compile against the specified target's JVM boot classes:
#      By default, The Java 2 SDK's javac will  compile against its own
#      bootstrap classes, so we need to tell javac to compile against the 
#      target bootstrap classes instead. We do this with -bootclasspath and
#      -extdirs. Failing to do this might allow compilation against a Java 2
#      Platform API that would not be present on the specified VM and fail
#      at runtime. 
#

# set default for 1.5
JVM1.5_BOOTCLASSES ?= $(TOOLS)/vendors/oracle/jdk/1.5.0_22/Linux/jre/lib/rt.jar
# set default for 1.6
JVM1.6_BOOTCLASSES ?= $(TOOLS)/vendors/oracle/jdk/jdk1.6.0_37/Linux/jre/lib/rt.jar

# check that the required variables are defined and reference existing files
ifndef JVM$(JVM_TARGET)_BOOTCLASSES
    $(error JVM$(JVM_TARGET)_BOOTCLASSES must be defined to point to a $(JVM_TARGET) Java Runtime Environment's rt.jar)
endif

ifeq (,$(wildcard $(JDK)))
    $(error JDK (= '$(JDK)') must be set to the installation dirctory of a Java JDK)
endif
ifeq (,$(wildcard $(JVM$(JVM_TARGET)_BOOTCLASSES)))
    $(error JVM$(JVM_TARGET)_BOOTCLASSES (= '$(JVM$(JVM_TARGET)_BOOTCLASSES)') must be defined to point to a $(JVM_TARGET) Java Runtime Environment's rt.jar)
endif

#
# CLASSTOP - directory containing class files (not including the package name)
# CLASSDIR - the full directory where class files are written
#
CLASSTOP   = .java/classes
CLASSDIR   = $(CLASSTOP)/.

ifeq (,$(wildcard $(CLASSTOP)))
    $(shell mkdir -p $(CLASSTOP))
endif
