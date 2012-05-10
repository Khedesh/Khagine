# Name: Makefile
# Author: Khedesh
# At: 01/26/2012, 7:57 PM
# Description: This is Makefile for making khagine project, the simulation engine.
# Command 'make' makes objs in ./build then export a .a lib file in ./lib.
# You can build your tests by typing 'make test', and running by 'make run'

# variables
TOPDIR = .
PROJECT_NAME = khagine
VERSION = 0.0.3

lib: $(TOPDIR)/src/Makefile
	make -C $(TOPDIR)/src

test: $(TOPDIR)/test/Makefile
	make -C $(TOPDIR)/test

run:
	make run -C $(TOPDIR)/test

gz: ./src/ ./dgrm/ ./include/ ./Makefile ./test/
	tar -cf $(PROJECT_NAME)-$(VERSION).tar ../v$(VERSION)
	gzip $(PROJECT_NAME)-$(VERSION).tar

clean:
	make clean -C $(TOPDIR)/src
	make clean -C $(TOPDIR)/test
	rm -f $(PROJECT_NAME)-$(VERSION).tar.gz

.PHONY: lib test run gz clean
