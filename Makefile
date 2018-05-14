all: fitness genetic genboard


fitness: fitness.cpp fitness.h
	g++ -std=c++11 -o fitness fitness.cpp

genboard: genboard.cpp fitness.h
	g++ -std=c++11 -o genboard genboard.cpp

genetic: genetic.cpp fitness.h
	g++ -std=c++11 -o genetic genetic.cpp
