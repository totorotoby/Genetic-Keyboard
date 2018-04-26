/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "classes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int simple_index[18] = {0,1,2,11,12,13,22,23,24,7,8,9,18,19,20,29,30,31};


string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

int getFitness(string text, keyboard instance){

	int fitness = 0;
	for (int i = 0; i < content.length(); i++){
		int keyindex = getLocation(text[i], instance);
		key *keyloc = keyboard.board[i];

		if (inSimple(i))
			 
	}
}

int getLocation(char charcter, keyboard instance){
	key *keyloc

	for (int i = 0; i <= 31; i++){
		if (keyboard.board[i] == charcter)
			return i;
	}
}

int insimple(int i){

	for (int j =  0; j <= 18; j++){
		if (i == simple_index[j])
			return 1;
	}
}


int main(){

	string filename = "testfile";
	string text = readText(filename);
	cout << content << endl;

}