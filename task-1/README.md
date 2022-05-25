This is Task 01 of the Eudyptula Challenge
------------------------------------------

Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!"  Be sure to make
the module be able to be unloaded as well.

The Makefile should build the kernel module against the source for the
currently running kernel, or, use an environment variable to specify
what kernel tree to build it against.
