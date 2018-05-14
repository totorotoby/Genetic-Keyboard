all: fitness genetic genboard mutbreed


fitness: fitness.cpp fitness.h
	g++ -std=c++11 -o fitness fitness.cpp

genMain: genMain.cpp fitness.h
	g++ -std=c++11 -o genMain genMain.cpp

mutbreed: mutbreed.cpp fitness.h
	g++ -std=c++11 -o mutbreed mutbreed.cpp
