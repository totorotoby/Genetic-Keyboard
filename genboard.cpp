/*Program to run genetic algorthim through*/

#include "fitness.cpp"
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
    keyboard *pool[100];
    for (int i = 0; i<100; i++) {
        keyboard *toadd = new keyboard();
        pool[i] = toadd;
    }
    
    //Just using this file as a test
    string txt = readText("small-wordlist.txt");
    //Compute fitness for each keyboard and the overall avg fitness
    int avgfit = 0;
    for (int i = 0; i<100; i++) {
        pool[i]->setFitness(txt);
        avgfit += pool[i]->fitness;
    }
    avgfit /= 100;
}
