all: genMain

genMain: genMain.cpp fitness.h
	g++ -std=c++11 -o genMain genMain.cpp
