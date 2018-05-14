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
    
    //Get number of generations
    int gen;
    cout << "Enter number of generations: ";
    cin >> gen;
    cout << "\n";
    
    //Random Seed
    srand(time(NULL));
    int rnd, prev;
    
    //Pool for next generation
    keyboard *nextGen[100];
    
    for (int i = 0; i < gen; i++) {
        //Compute fitness for each keyboard and the overall avg fitness
        int avgfit = 0;
        for (int i = 0; i<100; i++) {
            pool[i]->setFitness(txt);
            avgfit += pool[i]->fitness;
        }
        avgfit /= 100;
        
        //Reset next generation
        int nextGenSize = 0;
        
        //Breed 100 new offspring
        while(nextGenSize != 100) {
            //Select 2 parents
            rnd = rand() % 100;
            prev = rnd;
            keyboard *p1 = pool[rnd];
            //Avoid picking same parent twice
            while(rnd == prev)
                rnd = rand() % 100;
            keyboard *p2 = pool[rnd];
            
            //Calculate crossover probability
            int c1 = p1->fitness / avgfit;
            int c2 = p2->fitness / avgfit;
            int pc = (c1 * c2) * 100;
            
            //Breeding calculation
            rnd = rand() % 100;
            if (rnd < pc) {
                //keyboard *offspring = breed(p1, p2);
                //nextGen[nextGenSize] = mutate(offspring);
                nextGenSize++;
                cout << nextGenSize << "\n";
            }
        }
        
        for (int i = 0; i<100; i++) {
            pool[i] = nextGen[i];
        }
    }
}
