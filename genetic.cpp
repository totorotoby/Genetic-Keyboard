/*Program to run genetic algorthim through*/


#include "fitness.h"
using namespace std;

string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

keyboard *genNewPool(){

	keyboard *pool = new keyboard[1000];
	for (int i = 0; i<1000 ; i++){
		keyboard *toadd = new keyboard();
		pool[i] = toadd;
	}
	return pool;
}

void rankBoards(keyboard *pool, string[5] texts){
	for (int i = 0; i<1000 ; i++){
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

