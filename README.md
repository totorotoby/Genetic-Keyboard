# Genetic Keyboard (genBoard)
#### This program generates the most optimal keyboard using a genetic algorithm
#### Final Project for CS241, Systems Programming
#### Group Members: Dorian Levine, Marouane Abra, Toby Harvey and Steven Abreu

Keyboard object has attributes:

key board[32]     //which is a array of keys, where board[i] is the ith key on the board, where the numbering is in Keyboard Diagram.jpg
int fitness      // which is the fitness of the keyboard

Key objects have attributes:

char charcter    //the charcter on that particular key of that particular keyboard
key *adjList[5]     // an array of pointers that point to each of the adjacent keys ot this particular key.
int adjdist[5]     // adjdist[i] gives the distance from this particular key to the key pointed to by adjList[i].



keyboard objects also have the function:

 setFitness(string text, keyboard *instance, hands *hand_instance)

text is the string that we are assessing the fitness on. So a book or something along those lines.
instance is the pointer to the keyboard instance that we are trying to find the fitness of.
hands_instance is a object to keep track of positions on for index fingers (If you are not Toby don't worry about this).

set fitness just turns instance.fitness to a integer that is not 0.