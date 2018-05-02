/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "fitness.h"


string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

int getFitness(string text, keyboard *instance){

	int fitness = 0;
	for (int i = 0; i < text.length(); i++){
		int keyindex = getLocation(text[i], instance);
		int fingNum = getFingerNum(keyindex);
		if (inbasic(i)){
		
			//ignore distance
			//add finger rep penalty
			int repPenalty = getFingCount(fingNum);
			//str pentaly
			int strPenalty = getStr(fingNum);
		}

		if (insimple(i)){
		
			//add distance
			int distance = sgetDistance(text[i], keyboard *instance);
			//add finger penalty
			int repPenalty = getFingCount(fingNum);
			//add str penalty
			int strPenalty = getStr(fingNum);
		}
		//complex case
		else{
			//add distance to new key more complicated

			//add finger penalty
			int repPenalty = getFingCount(fingNum);
			//add str penalty
			int strPenalty = getStr(fingNum);
		}
	}
}

int getLocation(char charcter, keyboard *instance){


	for (int i = 0; i <= 31; i++){
		if (instance->board[i].charcter == charcter)
			return i;
	}
	return -1;
}

int insimple(int i){

	for (int j =  0; j <= 18; j++){
		if (i == simple_index[j])
			return 1;
	}
	return 0;
}

int inbasic(int i){
	for (int j =  0; j <= 8; j++){
		if (i == basic_index[j])
			return 1;
	}
	return 0;
}


int sgetDistance(char ch, keyboard *instance){

	cout << ch << endl;
	for (int i = 0; i < sizeof(instance->board)/sizeof(instance->board[0]); i++){
		
		for (int j = 0; j < sizeof(instance->board[i].adjList)/sizeof(instance->board[i].adjList[0]); j++){

			if (instance->board[i].adjList[j] != NULL){

			key *adlist = instance->board[i].adjList[j];
			
				if (adlist->charcter == ch){
					return instance->board[i].adjdist[j];
				}
			}
		}
	}
	return -1;
}

int cgetDistance(char ch, finger fing, keyboard instance){



}

int getFingerNum(int index){

	if (i%11 == 0)
		return 1;
	if (i%11 == 1)
		return 2;
	if (i%11 == 2)
		return 3;
	if (i%11 == 3 || i%11 == 4)
		return 4;
	if (i%11 == 5 || i%11 == 6)
		return 5;
	if (i%11 == 7)
		return 6;
	if (i%11 == 8)
		return 7;
	if (i%11 == 9 || i%11 == 10)
		return 8;
}

void incrFingCount(int FingNum){
pressarray[FingNum] =+ 5;
}

int getFingCount(int FingNum){
	return pressarray[FingNum];
}

int getStr(int FingNum){
	return strarray[FingNum];
}



int main(){

	string filename = "testfile";
	string text = readText(filename);

	keyboard* keyboard_inst = new keyboard();
	hands *hand_inst = new hands(instance);

	int distance = sgetDistance(text[1],instance);

	cout << distance << endl;

}