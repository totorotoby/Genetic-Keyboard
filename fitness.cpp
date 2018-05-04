/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "fitness.h"

// Just to read textfile in as string
string readText(string filename){

	std::ifstream ifs(filename);
	std::stringstream file;
	file << ifs.rdbuf();
	return file.str();	

}

//ALGORTHIM FOR FINDING FITNESS FOR A SINGLE KEYBOARD
//*******************************************************************************************************************
//*******************************************************************************************************************


int getFitness(string text, keyboard *instance, hands *iHands){

	int fitness = 0;
	for (int i = 0; i < text.length(); i++){
		int strPenalty;
		int distance;
		int repPenalty;
		int keyindex = getLocation(text[i], instance);
		int fingNum = getFingerNum(keyindex);

		if (inbasic(i)){
		
			//ignore distance
			//add finger rep penalty
			repPenalty = getFingCount(fingNum);
			//str pentaly
			strPenalty = getStr(fingNum);
		}

		if (insimple(i)){
		
			//add distance
			distance = sgetDistance(text[i], instance);
			//add finger penalty
			repPenalty = getFingCount(fingNum);
			//add str penalty
			strPenalty = getStr(fingNum);
		}
		//complex case
		else{
			//add distance to new key more complicated
			//finding finger
			finger *fing = getFinger(int fingNum, ihands);
			//finding distance depending on graph we are dealing with
			distance  = cgetDistance(text[i], fing, instance);
			//add finger penalty
			repPenalty = getFingCount(fingNum);
			//add str penalty
			strPenalty = getStr(fingNum);
		}
	}
}


//HELPERS TO FIND EVERYTHING WE NEED FOR A SINGLE CHARCTER MINUS DIJKSTRAS
//*******************************************************************************************************************
//*******************************************************************************************************************


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

finger *getFinger(int index, hands *ihands){
	if (index = 4)
		return ihands.l_index;
	if (index = 5)
		return ihands.r_index;
	if (index = 8)
		return ihands.r_pinky;
	else
		return NULL;
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





//EVERYTHING FOR DIJKSTRAS
//*******************************************************************************************************************
//*******************************************************************************************************************





int dijkDone(dijk_pair vertices[6]){

	int count = 0;
	for (int i = 0; i < 6 ; i++){
		if (vertices[i].distto < 1000)
			count++;
	}

	if (count == 6)
		return 1;

	return 0;
}


int findIndexinverts(key *node){
	//find keyindex in vertices
		for (int i = 0; i < 6 ; i++){
			if ( &node == vertices[i].vertex){
				return i;
			}
		}
}



void disttoAdj(key *curNode, dijk_pair vertices[6]){


	//finding distance to current node, that new distance will be added to.
	for (int i = 0; i < 6 ; i++){
		if (&curNode == vertices[i].vertex)
			int distToCur = vertices[i].distto;
	}

	key *neighbors[5] = curNode.adjList;

	for (int j = 0; j < 5 ; j++){

		//proposed new distance
		int newDist = distToCur + neighbors[i].adjdist;

		int vertIndex = findIndexinverts(neighbors[i])


		// set new distance if newDist is less then vertices[vertIndex].distto
		if (newDist < vertices[vertIndex].distto)
			vertices[vertIndex].distto = newDist;
	}
}

// ch is the key we want to move to, finger is where finger is currently placed
int cgetDistance(char ch, finger *fing, keyboard *instance){

	////==========================================================================================
	//setting up array to keep track of distances

	dijk_pair vertices[6];

	if (fing->name == 1){
		vertices[0].vertex = instance.board[3];
		vertices[1].vertex = instance.board[4];
		vertices[2].vertex = instance.board[14];
		vertices[3].vertex = instance.board[15];
		vertices[4].vertex = instance.board[25];
		vertices[5].vertex = instance.board[26];

		vertices[0].distto = 1000;
		vertices[1].distto = 1000;
		vertices[2].distto = 1000;
		vertices[3].distto = 1000;
		vertices[4].distto = 1000;
		vertices[5].distto = 1000;

	}

	if (fing->name == 2){
		vertices[0].vertex = instance.board[5];
		vertices[1].vertex = instance.board[6];
		vertices[2].vertex = instance.board[16];
		vertices[3].vertex = instance.board[17];
		vertices[4].vertex = instance.board[27];
		vertices[5].vertex = instance.board[28];

		vertices[0].distto = 1000;
		vertices[1].distto = 1000;
		vertices[2].distto = 1000;
		vertices[3].distto = 1000;
		vertices[4].distto = 1000;
		vertices[5].distto = 1000;

	}

	if (fing->name == 2){
		vertices[0].vertex = instance.board[9];
		vertices[1].vertex = instance.board[10];
		vertices[2].vertex = instance.board[20];
		vertices[3].vertex = instance.board[21];
		vertices[4].vertex = instance.board[31];
		vertices[5].vertex = NULL;

		vertices[0].distto = 1000;
		vertices[1].distto = 1000;
		vertices[2].distto = 1000;
		vertices[3].distto = 1000;
		vertices[4].distto = 1000;
		vertices[5].distto = 1000;

	}

	//==========================================================================================
	//finding where in array our destination is based on ch
	
		for (int k = 0; i < 6 ; k++){
			if ( ch == vertices[k].vertex.charcter){
				int destindex = k;
			}
		}
	//==========================================================================================



	key *current = fing->curPosition;
	int indexcur = findIndexinverts(current);
	vertices[indexcur].distto = 0;

	while (!dijkDone(vertices)){

		for (int i = 0; i < 5 ; i++){
			if (current.adjList[i] != NULL){
				disttoAdj(current.adjList[i], vertices)
			}
		}
	}
	
}

return vertices[k].distto;


//*******************************************************************************************************************
//*******************************************************************************************************************







int main(){

	string filename = "testfile";
	string text = readText(filename);

	keyboard* keyboard_inst = new keyboard();
	hands *hand_inst = new hands(instance);

	int distance = sgetDistance(text[1],instance);

	cout << distance << endl;

}