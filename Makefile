all: genMain

genMain: genMain.cpp fitness.h fitness.cpp fitness.h mutbreed.cpp
	g++ -std=c++11 -o genMain genMain.cpp

fitness: fitness.cpp fitness.h
	g++ -g -std=c++11 -o fitness fitness.cpp
