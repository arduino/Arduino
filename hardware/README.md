### Cores have been moved
Originally, the main Arduino repository contained Arduino
platforms/cores in this directory. Since then, these have been moved to
their own repositories instead (see commit 2e98854 and d6b40d0).

The official Arduino cores can now be found here:
 - https://github.com/arduino/ArduinoCore-avr
 - https://github.com/arduino/ArduinoCore-sam
 - https://github.com/arduino/ArduinoCore-samd

##### Migrating commits
If you need to move commits and/or pull requests over from this
repository into the separate core repositories, an approach to handle
that mostly automatically is suggested below. These are for the avr
core, but with some changes, it should apply to sam as well.

	# Start out in the Arduino repo, by rebasing your branch on top of the
	# last commit that still contained the avr core. This makes sure that
	# any conflicts are resolved before transferring the commits, since git
	# am is not so helpful with conflicts.
	git checkout my-branch
	git rebase -i 950d88dcbe7b9b2d348fb25b5ffcd0c6d2d30b97

	# Then, generate patch files for all of your commits, into the patches
	# directory.
	git format-patch -o patches 950d88dcbe7b9b2d348fb25b5ffcd0c6d2d30b97

	# These steps are optional, but if your commits contain changes to other
	# files than the avr core, this re-applies your commits with only the
	# avr core changes, and regenerates the patches
	git checkout -b tmp-branch 950d88dcbe7b9b2d348fb25b5ffcd0c6d2d30b97
	git am --include 'hardware/arduino/avr/*' patches/*
	rm -rf patches/
	git format-patch -o patches 950d88dcbe7b9b2d348fb25b5ffcd0c6d2d30b97

	# Then, in the ArduinoCore-avr repo, create a new branch on the commit
	# matching the Arduino repo.
	git checkout -b my-branch b7c607663fecc232e598f2c0acf419ceb0b7078c

	# Apply our previously generated patches (update the path to point to
	# wherever you generated the patches previously). -p4 tells git am to
	# strip the a/hardware/arduino/avr part of the paths before applying.
	git am -p4  /path/to/patches/*

	# Finally, rebase on top of master
	git rebase origin/master
