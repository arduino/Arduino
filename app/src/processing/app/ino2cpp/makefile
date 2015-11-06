include java.mk

CLASSES := $(patsubst %.java,%,$(wildcard *.java))

JARFILE = ino2cpp.jar
ZIPFILE = $(CURDIR)/exports/ino2cpp.zip

# prerequisite packages from Energia
APP = ../../../../../app
CORE = ../../../../../core

JCPATH  := .:$(APP)/src:$(CORE)/src:$(APP)/lib/jna.jar:$(APP)/lib/RXTXcomm.jar
JCOPTS  := -Xlint

all: $(JARFILE) $(ZIPFILE)

#
#  Rules for building class files and jars ...
#

# create a disribution that includes command line tools
$(ZIPFILE): $(JARFILE) templates/ ino2cpp.sh ebuild.sh
	@echo making distribution $@ ...
	mkdir -p $(@D)
	cd ..; zip -r $@ $(patsubst %,ino2cpp/%,$^)

# create self-contained executable jar
$(JARFILE): $(patsubst %,$(CLASSDIR)/%.class,$(CLASSES))
	@echo making $@ ...
	@rm -f $@
	"$(JDK)/bin/jar" cfe $@ processing.app.ino2cpp.Main -C $(CLASSTOP) ./

# rule to build class files
$(CLASSDIR)/%.class:%.java
	@echo javac $< ...
	"$(JDK)/bin/javac" -target $(JVM_TARGET) -bootclasspath "$(JVM$(JVM_TARGET)_BOOTCLASSES)" $(JCOPTS) -classpath "$(JCPATH)" -d $(CLASSTOP) $<

# clean up our build artifacts
clean:
	rm -rf $(CLASSTOP) exports
	rm -f $(JARFILE)

