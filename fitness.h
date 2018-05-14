#include "classes.cpp"
#include <string>
#include <fstream>
#include <sstream>




string readText(string Filename);
int getFitness(string text, keyboard instance);
int getLocation(char charcter, keyboard *instance);
int insimple(int i);
int inbasic(int i);
int sgetDistance(char ch, keyboard *instance);
int cgetDistance(char ch, finger fing, keyboard *instance);
int getFingerNum(int index);
void incrFingCount(int FingNum);
int getFingCount(int FingNum);
int getStr(int FingNum);
int getHandpen(int fingNum);
void disttoAdj(key *curNode, dijk_pair vertices[6]);
int findIndexinverts(key *node);
int dijkDone(dijk_pair vertices[6]);
finger getFinger(int index, hands *ihands);
void printShortestDist(key *current, dijk_pair *vertices);
void getAdjdistances(key *current, dijk_pair *vertices);
void resetGlobals();
void delayCheck(hands *iHands, keyboard *instance);
void delayReset(int fingNum);


string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

int simple_index[] = {0,1,2,22,23,24,7,8,29, 30};
int basic_index[] = {11,12,13,14,17,18,19,20};
int pressarray[] = {0};
int strarray[] = {30, 20, 15, 5, 5, 15, 20, 30};
int lastHand = 0;
int currHand = 0;
int handPen = 0;
int prevFingNum = 0;
int indexDelay[] = {0,0};
