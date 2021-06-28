# Exercise to compile examples
# Using a common build setup for all exercises

TOP_DIR=../../
include ${TOP_DIR}/common/vars.mak


TARGETS=\
	basic_process_ex${EXE} \
	ex4.2_basic_process_ex${EXE} \
	ex4.3_basic_process_ex${EXE} \
	ex4.4_basic_process_ex${EXE} \
	ex4.5_counter${EXE}


all  : ${TARGETS}

basic_process_ex.hpp : ${TOP_DIR}/examples/ch4/basic_process_ex.hpp
	cp $< $@ 

basic_process_ex.cpp : ${TOP_DIR}/examples/ch4/basic_process_ex.cpp
	cp $< $@ 

basic_process_ex${EXE} : basic_process_ex.hpp basic_process_ex.cpp


include ${TOP_DIR}/common/targets.mak
