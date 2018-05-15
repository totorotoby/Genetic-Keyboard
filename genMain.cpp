/*Program to run genetic algorthim through*/
#include "mutbreed.cpp"
using namespace std;

int main() {
    
    //Initialize keyboard pool
    keyboard *pool[100];
    for (int i = 0; i<100; i++) {
        keyboard *toadd = new keyboard();
        pool[i] = toadd;
    }
    
    //Just using this file as a test
    string txt = readText("testfile.txt");
    
    //Get number of generations
    int gen;
    cout << "Enter number of generations: ";
    cin >> gen;
    
    //Random Seed
    srand(time(NULL));
    int rnd, prev;
    
    //Pool for next generation
    keyboard *nextGen[100];
    
    for (int i = 0; i < gen; i++) {
        //DEBUG FLAG
        cout << i << " generation\n";
        
        //Compute fitness for each keyboard and the overall avg fitness
        int avgfit = 0;
        for (int j = 0; j<100; j++) {
            pool[j]->setFitness(txt);
            //DEBUG FLAG
            //cout << j << " fitness: " << pool[j]->fitness << "\n";
            avgfit = avgfit + pool[j]->fitness;
        }
        avgfit = avgfit/100;
        //DEBUG FLAG
        cout << "avgfit: " << avgfit << "\n";
        
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
                keyboard *offspring = breed(p1, p2);
                nextGen[nextGenSize] = mutate(offspring);
                nextGenSize++;
                //DEBUG FLAG
                //cout << nextGenSize << " offspring\n";
            }
        }
        
        //Make new generation the parent pool
        for (int k = 0; k<100; k++) {
            pool[k] = nextGen[k];
        }
    }
}
