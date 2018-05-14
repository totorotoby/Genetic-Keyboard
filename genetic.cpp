/*Program to run genetic algorthim through*/

#include <stdlib.h>
#include "fitness.h"
using namespace std;
/*
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
*/

/* This function duplicates an existing keyboard to a new instance */
keyboard *duplicate_keyboard(keyboard *parent)
{
  keyboard *new_kb = new keyboard();
  for ( int i = 0; i < 32; i++)
    {
      new_kb->board[i] = parent->board[i];
    }
  return new_kb;
}

/* This function takes in a parent keyboard and returns a mutated copy  */
keyboard *mutate(keyboard *parent)
{
  keyboard *new_kb = duplicate_keyboard(parent);
  int rand_key1 = rand() % 32;
  int rand_key2 = rand() % 32;

  while ( rand_key1 == rand_key2 ) // Avoid duplicate index values
    rand_key2 = rand() % 32;

  // swap...
  new_kb->board[rand_key1] = parent->board[rand_key2];
  new_kb->board[rand_key2] = parent->board[rand_key1];

  return new_kb;
}

keyboard *breed(keyboard *keyboard1,keyboard *keyboard2){
  return keyboard1;
}

int main()
{
  return 0;
}
