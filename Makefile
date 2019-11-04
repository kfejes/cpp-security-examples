CXX = clang++-10
OPTIMIZATION = -O0
CXXFLAGS = -std=c++17 -Wall -Wshadow -Wpedantic ${OPTIMIZATION}
ASAN = -fsanitize=address
UBSAN = -fsanitize=address
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
NANINDEX=NaNIndex
NANARRAY=NaNArray
NOEXCEPT=NoExcept
ITERATOR=IteratorInvalidation
ITERATORCOMP=IteratorComparison

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
	${CXX} ${OPTIONAL}.cpp -o ${APP}${OPTIONAL}.app ${CXXFLAGS} ${UBSAN} ${ASAN} ${OPTS}
pointer:
	${CXX} ${POINTER}.cpp -o ${APP}${POINTER}.app ${CXXFLAGS} ${ASAN} ${OPTS}
nanindex:
	${CXX} ${NANINDEX}.cpp -o ${APP}${NANINDEX}.app ${CXXFLAGS}
nanarray:
	${CXX} ${NANARRAY}.cpp -o ${APP}${NANARRAY}.app ${CXXFLAGS}
noexcept:
	${CXX} ${NOEXCEPT}.cpp -o ${APP}${NOEXCEPT}.app ${CXXFLAGS}
iteratorinvalidation:
	${CXX} ${ITERATOR}.cpp -o ${APP}${ITERATOR}.app ${CXXFLAGS}
iteratorcomparison:
	${CXX} ${ITERATORCOMP}.cpp -o ${APP}${ITERATORCOMP}.app ${CXXFLAGS}

all:
	make deadstore
	make stringviewUB
	make badmakereturn
	make badcopyofacevtor
	make optional
	make stringviewUAF
	make pointer
	make nanindex
	make nanarray
	make iteratorcomparison

clean:
	rm ${APP}/*.app
