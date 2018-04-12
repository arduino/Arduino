# Thread

It is simplest implementation iterative multithredaing for AVR8 microcontrollers.

Using
-----

See example for how to.

#### functions

`spawn(..)`	create new thread by function and stack resources

`yield()`	switch execution to next thread immediately

`hold()`	disable yield() and time division functionality

`schedule()`	enable yield() functionality only

`quantize()`	enable time division of the execution flows

`grab(..)`	implement mutual exclusion barrier lock

`loose(.)`	unlock barrier what has been locked by `grab(..)` call

#### constant

`MAIN`		pointer to dummy stack of the main root thread

#### variables

`therad`	dynamic pointer on the process stack structure
		what can be used for reentrant and identification

