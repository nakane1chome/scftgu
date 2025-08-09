__MKDIR_OBJ=-mkdir ${OBJ_DIR} 2> /dev/null


${OBJ_DIR}/%.o : %.cpp
	${__MKDIR_OBJ}
	${CXX} -c -o $@ ${CXXFLAGS} ${CPPFLAGS} $< -MMD 

%${EXE} : ${OBJ_DIR}/%.o
	${LD} -o $@   ${LDFLAGS} ${OBJ_FILES} $^


clean :
	rm -rf ${OBJ_DIR}
	rm -f ${TARGETS}

.SUFFIXES:
