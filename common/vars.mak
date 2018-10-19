ARCH=linux64
SYSTEMC_TOP=${TOP_DIR}/install/systemc
INCLUDE_DIRS=${SYSTEMC_TOP}/include
LIB_DIRS=${SYSTEMC_TOP}/lib-${ARCH}

CXX=g++
LD=g++
CPPFLAGS=${INCLUDE_DIRS:%=-I%}
CXXFLAGS=--std=c++03
LDFLAGS=${LIB_DIRS:%=-L%} -lsystemc
EXE=
OBJ_DIR=obj.Linux.x86_64
