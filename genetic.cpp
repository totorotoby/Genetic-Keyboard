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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  This function takes in two keyboards and breeds them returning a child keyboard  *
 *                                                                                   *
 *  Breeding Algorithm: (See graph below for reference)                              *
 *                                                                                   * 
 *  Add graphs A, C, E and G of parent 1 to child keyboard                           *
 *  Add graphs B, D, F and H of parent 2 to child keyboard                           *
 *  Traverse the child keyboard to find collisions                                   *
 *       keeping track of a running list of non repeated keys                        *
 *  Set collisions to NULL                                                           * 
 *  Randomly fill in the NULL keys with missing keys from the running list           *
 *  return child keyboard                                                            *
 *                                                                                   *
 * Keyboard graph representation:                                                    *
 * Each Letter represents the graph                                                  *
 * Each Node represents the index on the board array                                 *
 *                                                                                   *
 *                                                                                   * 
 *                                                                                   *
 * A     B     C          D        E         F      G        H                       *
 * 0     1     2        3 - 4     5 - 6      7      8      9 - 10                    *
 * |     |     |        | X |     | X |      |      |      | X |                     *
 * 11    12    13      14 - 15   16 - 17    18     19     20 - 21                    *
 * |           / \      | X |     | X |      |      |      \   /                     *
 * 22         23 24    25 - 26   27 - 28    29     30        31                      *
 *                                                                                   *
 *                                                                                   *
 *                                                                                   *
 *                                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
keyboard *breed(keyboard *keyboard1,keyboard *keyboard2){
  
  return keyboard1;
}

int main()
{
  return 0;
}
