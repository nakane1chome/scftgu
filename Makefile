SYSTEMC_SRC=systemc
INSTALL_DIR=install-${SYSTEM_ID}
SYSTEMC_INSTALL=${INSTALL_DIR}/systemc
SYSTEMC_INSTALL_ABS=${CURDIR}/${INSTALL_DIR}/systemc
SYSTEMC_LIB=${SYSTEMC_SRC}/src/sysc/.libs/libsystemc.so
SYSTEM_ID=${shell uname -s}-${shell uname -p}
BUILD_DIR=build-${SYSTEM_ID}

install : ${SYSTEMC_INSTALL}/include/systemc.h 

build : ${SYSTEMC_LIB}

ifeq (${shell uname -o},Msys)
CMAKE_GENERATOR="Unix Makefiles"
else
CMAKE_GENERATOR="Unix Makefiles"
endif

configure : build/Makefile

${BUILD_DIR}/Makefile :
	if [ ! -d ${BUILD_DIR} ] ; then mkdir ${BUILD_DIR}; fi
	if [ ! -d ${INSTALL_DIR}/systemc ] ; then mkdir -p ${INSTALL_DIR}/systemc; fi
	cd ${BUILD_DIR}; cmake \
			-G ${CMAKE_GENERATOR}  \
			-D CMAKE_INSTALL_PREFIX=../${SYSTEMC_INSTALL} \
			-D BUILD_SHARED_LIBS=OFF \
			-D CMAKE_CXX_STANDARD=14 \
			../systemc/

clean :
	rm -rf ${BUILD_DIR}
	rm -rf ${INSTALL_DIR}/systemc
	find  ${SYSTEMC_SRC} -type d -name ".deps" | xargs rm -rf

uninstall :
	rm -rf ${SYSTEMC_INSTALL}

${SYSTEMC_INSTALL}/include/systemc.h  : ${SYSTEMC_LIB}
	if [ ! -d ${SYSTEMC_INSTALL} ] ; then mkdir ${SYSTEMC_INSTALL} ; fi
	cd ${BUILD_DIR}; ${MAKE} install prefix=$(shell readlink -f ${SYSTEMC_INSTALL})

${SYSTEMC_LIB} : ${BUILD_DIR}/Makefile
	cd ${BUILD_DIR}; ${MAKE}

ifeq (${shell uname -o},Msys)
CFG_FLAGS= --host=x86_64-w64-mingw32
endif
