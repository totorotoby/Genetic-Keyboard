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
int cgetDistance(char ch, finger fing, keyboard instance);
int getFingerNum(int index);
void incrFingCount(int FingNum);
int getFingCount(int FingNum);
int getStr(int FingNum);
void disttoAdj(key *curNode, dijk_pair vertices[6]);
int findIndexinverts(key *node);
int dijkDone(dijk_pair vertices[6]);
finger *getFinger(int index, hands *ihands);

int simple_index[18] = {0,1,2,11,12,13,22,23,24,7,8,18,19,29,30};
int basic_index[8] = {11,12,13,14,17,18,19,20};
int pressarray[8] = {0};
int strarray[8] = {50, 30, 15, 5, 5, 15, 30, 50};