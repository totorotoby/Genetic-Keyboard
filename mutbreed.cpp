#include "fitness.cpp"
using namespace std;

/* This function duplicates an existing keyboard to a new instance */
keyboard *duplicate_keyboard(keyboard *parent)
{
  keyboard *new_kb = new keyboard();
  for ( int i = 0; i < 32; i++)
    {
      new_kb->board[i].charcter = parent->board[i].charcter;
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
  new_kb->board[rand_key1].charcter = parent->board[rand_key2].charcter;
  new_kb->board[rand_key2].charcter = parent->board[rand_key1].charcter;

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
 *       keeping track of a running list of duplicated keys                          *
 *  Set every collisions to NULL                                                     * 
 *  Randomly fill in the NULL keys with missing keys from the running list           *
 *  return child keyboard                                                            *
 *                                                                                   *
 * Keyboard graph representation:                                                    *
 * Each Letter represents a graph                                                    *
 * Each Node represents the index from the board array                               *
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
  keyboard *child_kb = new keyboard();
  // Add graphs A, C, E and G of parent 1 to child keyboard
  // A
  child_kb->board[0].charcter = keyboard1->board[0].charcter;
  child_kb->board[11].charcter = keyboard1->board[11].charcter;
  child_kb->board[22].charcter = keyboard1->board[22].charcter;

  // C
  child_kb->board[2].charcter = keyboard1->board[2].charcter;
  child_kb->board[13].charcter = keyboard1->board[13].charcter;
  child_kb->board[23].charcter = keyboard1->board[23].charcter;
  child_kb->board[24].charcter = keyboard1->board[24].charcter;

  // E
  child_kb->board[5].charcter = keyboard1->board[5].charcter;
  child_kb->board[6].charcter = keyboard1->board[6].charcter;
  child_kb->board[16].charcter = keyboard1->board[16].charcter;
  child_kb->board[17].charcter = keyboard1->board[17].charcter;
  child_kb->board[27].charcter = keyboard1->board[28].charcter;
  child_kb->board[28].charcter = keyboard1->board[27].charcter;

  // G
  child_kb->board[8].charcter = keyboard1->board[8].charcter;
  child_kb->board[19].charcter = keyboard1->board[19].charcter;
  child_kb->board[30].charcter = keyboard1->board[30].charcter;

  // Add graphs B, D, F and H of parent 2 to child keyboard
  // B
  child_kb->board[1].charcter = keyboard2->board[1].charcter;
  child_kb->board[12].charcter = keyboard2->board[12].charcter;

  // D
  child_kb->board[3].charcter = keyboard2->board[3].charcter;
  child_kb->board[4].charcter = keyboard2->board[4].charcter;
  child_kb->board[14].charcter = keyboard2->board[14].charcter;
  child_kb->board[15].charcter = keyboard2->board[15].charcter;
  child_kb->board[25].charcter = keyboard2->board[25].charcter;
  child_kb->board[26].charcter = keyboard2->board[26].charcter;

  // F
  child_kb->board[7].charcter = keyboard2->board[7].charcter;
  child_kb->board[18].charcter = keyboard2->board[18].charcter;
  child_kb->board[29].charcter = keyboard2->board[29].charcter;

  // H
  child_kb->board[9].charcter = keyboard2->board[9].charcter;
  child_kb->board[10].charcter = keyboard2->board[10].charcter;
  child_kb->board[20].charcter = keyboard2->board[20].charcter;
  child_kb->board[21].charcter = keyboard2->board[21].charcter;
  child_kb->board[31].charcter = keyboard2->board[31].charcter;

  cout << "\n\n" << endl;

  child_kb->printBoard();

  cout << "\n\n" << endl;

  // traverse the child keyboard to find collisions
  char collisions[32] = {'0'};
  int index = 0;
  for (int i = 0; i < 32; i++)
    {
      for (int j = i + 1; j < 32; j++)
      {
        if ( child_kb->board[i].charcter == child_kb->board[j].charcter && i != j )
        {
          collisions[index++]=child_kb->board[i].charcter;
          child_kb->board[i].charcter = '!';
        }
      }
    }

    child_kb->printBoard();

    cout << "\n\n" << endl;
    
  // randomly fill in the NULL keys with collisions
  std::random_shuffle(&collisions[0],&collisions[index]);

  /*
  cout << "collisions: " << endl;
  for (int i = 0 ; i < 32 ; i++)
    cout << collisions[i] << endl;
  */

  int counter = 0; // keep track of elements in collisions
  while ( counter < index )
  {
      for ( int i = 0; i < 32; i++)
      {
        if ( child_kb->board[i].charcter == '!' )
        {
          child_kb->board[i].charcter = collisions[counter];
          counter++;
          break;
        }
      }
  }
  return child_kb;
}

int main(){

  keyboard *newinst1 = new keyboard();
  keyboard *newinst2 = new keyboard();
  cout << "newinst1: " << endl;
  newinst1->printBoard();
   cout << "newinst2: " << endl;
  newinst2->printBoard();
  keyboard *child = breed(newinst1,newinst2);

  cout << "child: " << endl;
  child->printBoard();

  keyboard *mutate1 = mutate(newinst1);

  cout << "\n\n" << endl;
  cout << "newinst1: " << endl;
  newinst1->printBoard();

  cout << "\n\n" << endl;
  mutate1->printBoard();



}




