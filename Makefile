CXX = clang++-10
OPTIMIZATION = -O3
CXXFLAGS = -std=c++17 -Wall -Wshadow -Wpedantic ${OPTIMIZATION}
SAN= -fsanitize=memory

DEADSTORE=DeadStoreRemoval
STRINGVIEWUB=StringViewUB
BADMAKERETURN=BadMakeReturn
BADCOPYVECTOR=BadCopyOfAVector
OPTIONAL=OptionalUB

deadstore:
	${CXX} ${DEADSTORE}.cpp -o ${DEADSTORE}.app ${CXXFLAGS}
stringviewUB:
	${CXX} ${STRINGVIEWUB}.cpp -o ${STRINGVIEWUB}.app ${CXXFLAGS}
badmakereturn:
	${CXX} ${BADMAKERETURN}.cpp -o ${BADMAKERETURN}.app ${CXXFLAGS}
badcopyofacevtor:
	${CXX} ${BADCOPYVECTOR}.cpp -o ${BADCOPYVECTOR}.app ${CXXFLAGS}
optional:
	${CXX} ${OPTIONAL}.cpp -o ${OPTIONAL}.app ${CXXFLAGS} ${SAN}

all:
	deadstore
	stringviewUB
	badmakereturn
	badcopyofacevtor
	optional

clean:
	rm *.app
