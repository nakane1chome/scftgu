UNAME_S=${shell uname -s}
UNAME_A=${shell uname -m}

ifeq (${UNAME_S},MINGW64_NT-10.0)
ARCH=mingw64
else
ARCH=linux64
endif


SYSTEMC_TOP=${TOP_DIR}/install/systemc
INCLUDE_DIRS=${SYSTEMC_TOP}/include
LIB_DIRS=${SYSTEMC_TOP}/lib-${ARCH}

ifeq (${UNAME_S},MINGW64_NT-10.0)
CXX=x86_64-w64-mingw32-g++
LD=x86_64-w64-mingw32-g++
else
CXX=g++
LD=g++
endif

CPPFLAGS=${INCLUDE_DIRS:%=-I%}
CXXFLAGS=--std=c++03 -O2
LDFLAGS=${LIB_DIRS:%=-L%} -lsystemc
EXE=
OBJ_DIR=obj.${UNAME_S}.${UNAME_A}
