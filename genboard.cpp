/*Program to run genetic algorthim through*/

#include <iostream>
#include <vector>
#include "fitness.h"
using namespace std;

/** This function is overloading the readText() function in fitness.h and throwing an error
string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

keyboard *genNewPool(){

	keyboard *pool = new *keyboard[100];
	for (int i = 0; i<100 ; i++){
		keyboard *toadd = new keyboard();
		pool[i] = toadd;
	}
	return pool;
}

//This function is also generating a few errors
void rankBoards(keyboard *pool, string[5] texts){
	for (int i = 0; i<100 ; i++){
		int total = 0;
		for (int j = 0 ; j < 5 ; j++){

			hands *hand_inst = new hands(keyboard_inst);
			int fitness = getFitness(text[j], pool[i], hand_inst);
			total += fitness;
		}
		total = total/5;
		pool[i].fitness = total;
	}
}
*/

int main() {
    
    //Initialize keyboard pool
    vector<keyboard*> pool;
    for (int i = 0; i<100; i++) {
        keyboard *toadd = new keyboard();
        pool.push_back(toadd);
    }
    
    //Just using this file as a test
    string txt = readText("small-wordlist.txt");
    //Compute fitness for each keyboard and the overall avg fitness
    int avgfit = 0;
    for (int i = 0; i<100; i++) {
        //hands *hand_inst = new hands(keyboard_inst);
        //int currentFit = getFitness(txt, pool.at(i), hand_inst);
        avgfit += currentFit;
        pool.at(i)->fitness = currentFit;
    }
}
