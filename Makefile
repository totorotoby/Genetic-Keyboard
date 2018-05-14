


fitness: fitness.cpp fitness.h
	g++ -std=c++11 -o fitness fitness.cpp

genboard: genboard.cpp fitness.h
	g++ -std=c++11 -o genboard genboard.cpp
