all: lib/tink.runtime.wiring.lib

lib/tink.runtime.wiring.lib: lib
	$(MAKE) -f makefile

lib:
	$(MKDIR) $@

clean:: .local-clean

.local-clean:
	$(RMDIR) lib
