#include "classes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



string readText(string Filename);
int getFitness(string text, keyboard instance);
int getLocation(char charcter, keyboard instance);
int insimple(int i);
int sgetDistance(char ch, keyboard *instance);