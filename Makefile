CXX = clang++-10
OPTIMIZATION = -O3
CXXFLAGS = -std=c++17 -Wall -Wshadow -Wpedantic ${OPTIMIZATION}
ASAN = -fsanitize=address
ASANOPTS = ASAN_OPTIONS=detect_leaks=1
OPTS = ; ${ASANOPTS}

APP=bin/

DEADSTORE=DeadStoreRemoval
STRINGVIEWUB=StringViewUB
BADMAKERETURN=BadMakeReturn
BADCOPYVECTOR=BadCopyOfAVector
OPTIONAL=OptionalUB
POINTER=PointerIsNotDeAllocated
STRINGVIEWUAF=StringViewUAF

deadstore:
	${CXX} ${DEADSTORE}.cpp -o ${APP}${DEADSTORE}.app ${CXXFLAGS}
stringviewUB:
	${CXX} ${STRINGVIEWUB}.cpp -o ${APP}${STRINGVIEWUB}.app ${CXXFLAGS}
stringviewUAF:
	${CXX} ${STRINGVIEWUAF}.cpp -o ${APP}${STRINGVIEWUAF}.app ${CXXFLAGS}	
badmakereturn:
	${CXX} ${BADMAKERETURN}.cpp -o ${APP}${BADMAKERETURN}.app ${CXXFLAGS}
badcopyofacevtor:
	${CXX} ${BADCOPYVECTOR}.cpp -o ${APP}${BADCOPYVECTOR}.app ${CXXFLAGS}
optional:
	${CXX} ${OPTIONAL}.cpp -o ${APP}${OPTIONAL}.app ${CXXFLAGS} ${ASAN} ${OPTS}
pointer:
	${CXX} ${POINTER}.cpp -o ${APP}${POINTER}.app ${CXXFLAGS} ${ASAN} ${OPTS}

all:
	make deadstore
	make stringviewUB
	make badmakereturn
	make badcopyofacevtor
	make optional
	make stringviewUAF

clean:
	rm ${APP}/*.app
