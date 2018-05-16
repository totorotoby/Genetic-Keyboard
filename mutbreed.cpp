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

  // traverse the child keyboard to find collisions
  char collisions[32] = {0};
  char all[32] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o',
		  'p', ' ', 'a', 's', 'd', 'f', 'g', 'h', 'j','k', 'l', ';', '"',
		  'z', 'x', 'c', 'v','b','n','m','<','>','?'};
  int index = 0;
  for (int i = 0; i < 32; i++)
    {
      for (int j = i + 1; j < 32; j++)
      {
        if ( child_kb->board[i].charcter == child_kb->board[j].charcter && i != j )
        {
	  //printf("Collsion found %c at %d\n", child_kb->board[i].charcter, i);
          collisions[index++]=child_kb->board[i].charcter;
          child_kb->board[i].charcter = '!';
	  break;
        }
      }
    }

  // Subtract duplicates from all possible characters
  for (int dup_index = 0; dup_index < 32; dup_index++) // for each char in collisions
    {
      for (int all_index = 0; all_index < 32; all_index++) // remove the collisions from all
	{
	  if (collisions[dup_index] == all[all_index])
	    {
	      all[all_index] = '!';
	      break;
	    }
	}
    }

  // Subtract current child_kb from all in order to leave just
  // the characters that can be added to the child_kb in order to
  // avoid all duplicates
  for (int child_index = 0; child_index < 32; child_index++)
    {
      if (child_kb->board[child_index].charcter == '!') // Skip '!' in child_kb
	  continue;
      for (int all_index = 0; all_index < 32; all_index++)
	{
	  if (child_kb->board[child_index].charcter == all[all_index])
	    {
	      all[all_index] = '!';
	      break;
	    }
	}
    }
  
  // shuffle the non_collisions array
  std::random_shuffle(&all[0],&all[31]);
  
  // Add non_collisions back into the child keyboard
  for (int i = 0; i < 32; i++)
    {
      if (child_kb->board[i].charcter == '!')
	{
	  // Add the next non '!' character that is not a duplicate to child_kb
	  for (int all_index = 0; all_index < 32; all_index++)
	    {
	      if (all[all_index] == '!')
		continue;
	      
	      child_kb->board[i].charcter = all[all_index];
	      all[all_index] = '!';
	      break;
	    }
	}
    }
  return child_kb;
}
