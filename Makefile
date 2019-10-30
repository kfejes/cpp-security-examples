CXX = clang++-10
OPTIMIZATION = -O3
CXXFLAGS = -std=c++17 -Wall -Wshadow -Wpedantic ${OPTIMIZATION}

DEADSTORE=DeadStoreRemoval
STRINGVIEWUB=StringViewUB
BADMAKERETURN=BadMakeReturn
BADCOPYVECTOR=BadCopyOfAVector

deadstore:
	${CXX} ${DEADSTORE}.cpp -o ${DEADSTORE}.app ${CXXFLAGS}
stringviewUB:
	${CXX} ${STRINGVIEWUB}.cpp -o ${STRINGVIEWUB}.app ${CXXFLAGS}
badmakereturn:
	${CXX} ${BADMAKERETURN}.cpp -o ${BADMAKERETURN}.app ${CXXFLAGS}
badcopyofacevtor:
	${CXX} ${BADCOPYVECTOR}.cpp -o ${BADCOPYVECTOR}.app ${CXXFLAGS}

all:
	deadstore
	stringviewUB
	badmakereturn
	badcopyofacevtor

clean:
	rm *.app
