/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "classes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

int main(){

	string filename = "testfile";
	string content = readText(filename);
	cout << content << endl;


}