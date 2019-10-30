CXX = clang++-10
OPTIMIZATION = -O3
CXXFLAGS = -std=c++17 -Wall -Wshadow -Wpedantic ${OPTIMIZATION}

DEADSTORE=DeadStoreRemoval
STRINGVIEWUB=StringViewUB

deadstore:
	${CXX} ${DEADSTORE}.cpp -o ${DEADSTORE}.app ${CXXFLAGS}
stringviewUB:
	${CXX} ${STRINGVIEWUB}.cpp -o ${STRINGVIEWUB}.app ${CXXFLAGS}

all:
	deadstore
	stringviewUB

clean:
	rm *.app
