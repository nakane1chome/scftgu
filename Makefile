SYSTEMC_SRC=systemc
SYSTEMC_INSTALL=install/systemc
SYSTEMC_LIB=${SYSTEMC_SRC}/src/sysc/.libs/libsystemc.so

install : ${SYSTEMC_INSTALL}/include/systemc.h 

build : ${SYSTEMC_LIB}

configure : ${SYSTEMC_SRC}/Makefile

${SYSTEMC_INSTALL}/include/systemc.h  : ${SYSTEMC_LIB}
	-mkdir ${SYSTEMC_INSTALL}
	cd ${SYSTEMC_SRC}; ${MAKE} install prefix=$(shell readlink -f ${SYSTEMC_INSTALL})

${SYSTEMC_LIB} : ${SYSTEMC_SRC}/Makefile
	cd ${SYSTEMC_SRC}; ${MAKE}

${SYSTEMC_SRC}/Makefile :
	cd ${SYSTEMC_SRC}; ./configure CXXFLAGS=-std=c++03
