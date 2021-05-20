# Top Level Makefile for Circular Buffer Data Structure Library

all:
	(cd lib/Dynamic; make all)
	(cd lib/Static; make all)
clean:
	(cd lib/Dynamic; make clean)
	(cd lib/Static; make clean)
static:
	(cd lib/Static; make all)
dynamic:
	(cd lib/Dynamic; make all)
