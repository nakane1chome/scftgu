UNAME_S=${shell uname -s}
UNAME_A=${shell uname -m}
UNAME_O=${shell uname -o}
SYSTEM_ID=${UNAME_S}-${UNAME_O}

ifeq (${UNAME_O},Msys)
ARCH=
else
ARCH=-linux64
endif


SYSTEMC_TOP=${TOP_DIR}/install-${SYSTEM_ID}/systemc
INCLUDE_DIRS=${SYSTEMC_TOP}/include
LIB_DIRS=${SYSTEMC_TOP}/lib

ifeq (${UNAME_O},Msys)
#CXX=x86_64-w64-mingw32-g++
LD=c++
CXX=g++
#LD=g++
else
CXX=g++
LD=g++
endif

CPPFLAGS=${INCLUDE_DIRS:%=-I%}
CXXFLAGS= -O3 -DNDEBUG -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -std=gnu++14

LDFLAGS=  -O3 -DNDEBUG  ${LIB_DIRS:%=-L%}  -lsystemc 
EXE=
OBJ_DIR=obj.${UNAME_S}.${UNAME_A}
