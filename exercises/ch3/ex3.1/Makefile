# Exercise to compile examples
# Using a common build setup for all exercises

TOP_DIR=../../../
include ${TOP_DIR}/common/vars.mak


TARGETS=hello_world${EXE} datatypes${EXE}

all  : ${TARGETS}

hello_world.cpp : ../../../examples/ch2/hello_world.cpp
	cp $< $@ 

datatypes.cpp : ../../../examples/ch3/datatypes.cpp
	cp $< $@ 

include ${TOP_DIR}/common/targets.mak
