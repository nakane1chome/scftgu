# Exercise to compile examples
# Using a common build setup for all exercises

TOP_DIR=../../
include ${TOP_DIR}/common/vars.mak


TARGETS=\
	simple_spawn${EXE} 


all  : ${TARGETS}

simple_spawn.cpp : ${TOP_DIR}/examples/ch7/simple_spawn.cpp
	cp $< $@ 

simple_spawn${EXE} : ${OBJ_DIR}/simple_spawn.o


include ${TOP_DIR}/common/targets.mak
