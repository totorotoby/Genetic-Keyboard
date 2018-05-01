/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "fitness.h"

int simple_index[18] = {0,1,2,11,12,13,22,23,24,7,8,18,19,29,30};
int basic_index[8] = {11,12,13,14,17,18,19,20}


string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

/*int getFitness(string text, keyboard *instance){

	int fitness = 0;
	for (int i = 0; i < text.length(); i++){
		int keyindex = getLocation(text[i], instance);
		
		if (inbasic(i)){
		
		//ignore distance
		//add finger rep penalty
		//str pentaly

		}

		if (insimple(i)){

		//add distance
		int distance = sgetDistance(text[i], keyboard *instance);
		//add finger penalty
		//add str penalty

		}
		//complex case
		else{

		}
	}
}*/

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


int main(){

	string filename = "testfile";
	string text = readText(filename);

	keyboard* instance = new keyboard();

	



	int distance = sgetDistance(text[1],instance);

	cout << distance << endl;

}