/*Program to run genetic algorthim through*/
#include "mutbreed.cpp"
using namespace std;
#include <vector>



//comparator for to keyboards fitnesses
int keyboardComp(const keyboard *a, const keyboard *b)
{
    int toreturn = a->fitness > b->fitness;
    return toreturn;
}
/*void printBest(keyboard *bestOverGen[], int gen, int keyNum){

    std::vector <keyboard> myvector;
    myvector.insert(myvector.begin(), bestOverGen, bestOverGen+gen);
    std::sort(myvector, myvector + gen, keyboardComp);

    for (int i = 0 ; i < keyNum ; i++){
        cout << "keyboard: " << i <<endl;
        cout<< "generation: " << myvector.at(i)->generation << endl;
        cout << "fitness: " << myvector.at(i)->fitness << endl; 
        cout << "Display: " << endl;
        myvector.at(i)->printBoard();
        cout << "\n\n";
    }
}
*/

int main(int argc, char **argv) {
    
    //Initialize keyboard pool
    keyboard *pool[100];
    for (int i = 0; i<100; i++) {
        keyboard *toadd = new keyboard();
        pool[i] = toadd;
    }
    
    //Just using this file as a test
    if (argc < 2)
      {
	printf("Usage: ./genMain <language_file.txt>\n");
	exit(2);
      }

    int print_out = 0;
    // Get printout flag
    if (argc == 3)
      print_out = 1;
    
    string txt = readText(argv[1]);
    
    //Get number of generations
    int gen;
    cout << "Enter number of generations: ";
    cin >> gen;

    //Number of keyboard you want printed
    int keyNum;
    //cout << "Enter number of keyboards Displayed: ";
    //cin >> keyNum;
    
    //Random Seed
    srand(time(NULL));
    int rnd, prev;
    
    //Pool for next generation
    keyboard *nextGen[100];
    keyboard *bestOverGen[gen];
    int bestCount;
    
    for (int i = 0; i < gen; i++) {
        //DEBUG FLAG
      cout << "Generation " << i;

      keyboard *min_kb;
      int min_fit = 999999999;
      
        //Compute fitness for each keyboard and the overall avg fitness
        int avgfit = 0;
        for (int j = 0; j<100; j++) {
            pool[j]->setFitness(txt);
	    if (pool[j]->fitness < min_fit)
	      {
		min_kb = pool[j];
        min_kb->generation = i;
		min_fit = pool[j]->fitness;
	      }
	    
            //DEBUG FLAG
            //cout << j << " fitness: " << pool[j]->fitness << "\n";
            avgfit = avgfit + pool[j]->fitness;
        }
        avgfit = avgfit/100;
        //DEBUG FLAG
        cout << ": avgfit = " << avgfit << "\n";

	if (print_out)
	  {
	    cout << "Best keyboard: fitness = " << min_fit << endl;
	    min_kb->printBoard();
	    printf("\n");
	  }	  
        
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
            int c1 = avgfit / p1->fitness;
            int c2 = avgfit / p2->fitness;
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

    //printBest(bestOverGen, gen, keyNum);

}
