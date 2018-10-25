SYSTEMC_SRC=systemc
SYSTEMC_INSTALL=install/systemc
SYSTEMC_LIB=${SYSTEMC_SRC}/src/sysc/.libs/libsystemc.so

install : ${SYSTEMC_INSTALL}/include/systemc.h 

build : ${SYSTEMC_LIB}

configure : ${SYSTEMC_SRC}/Makefile

clean :
	find  ${SYSTEMC_SRC} -type d -name ".deps" | xargs rm -rf
	-${MAKE} -k -C ${SYSTEMC_SRC} clean
	rm -f ${SYSTEMC_SRC}/Makefile

uninstall :
	rm -rf ${SYSTEMC_INSTALL}

${SYSTEMC_INSTALL}/include/systemc.h  : ${SYSTEMC_LIB}
	-mkdir ${SYSTEMC_INSTALL}
	cd ${SYSTEMC_SRC}; ${MAKE} install prefix=$(shell readlink -f ${SYSTEMC_INSTALL})

${SYSTEMC_LIB} : ${SYSTEMC_SRC}/Makefile
	cd ${SYSTEMC_SRC}; ${MAKE}

ifeq (${shell uname -s},MINGW64_NT-10.0)
CFG_FLAGS= --host=x86_64-w64-mingw32
endif

${SYSTEMC_SRC}/Makefile :
	cd ${SYSTEMC_SRC}; ./configure CXXFLAGS=-std=c++03 ${CFG_FLAGS}
