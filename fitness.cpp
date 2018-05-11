/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "fitness.h"
/*

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
			finger *fing = getFinger(fingNum, ihands);
			//finding distance depending on graph we are dealing with
			distance  = cgetDistance(text[i], fing, instance);
			//add finger penalty
			repPenalty = getFingCount(fingNum);
			//add str penalty
			strPenalty = getStr(fingNum);
		}
	}
}
*/

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

	if (index%11 == 0)
		return 1;
	if (index%11 == 1)
		return 2;
	if (index%11 == 2)
		return 3;
	if (index%11 == 3 || index%11 == 4)
		return 4;
	if (index%11 == 5 || index%11 == 6)
		return 5;
	if (index%11 == 7)
		return 6;
	if (index%11 == 8)
		return 7;
	if (index%11 == 9 || index%11 == 10)
		return 8;
	return 0;
}

finger getFinger(int fing_num, hands *ihands){
	if (fing_num == 4)
		return ihands -> l_index;
	if (fing_num == 5)
		return ihands -> r_index;
	if (fing_num == 8)
		return ihands -> r_pinky;
}



void incrFingCount(int FingNum){
pressarray[FingNum] += 5;
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

dijk_pair *setCheckArray(finger fing, keyboard *instance){

	dijk_pair* vertices = (dijk_pair*) malloc(6 * sizeof(dijk_pair));

	if (fing.name == 4){
		vertices[0].vertex = &instance -> board[3];
		vertices[1].vertex = &instance -> board[4];
		vertices[2].vertex = &instance -> board[14];
		vertices[3].vertex = &instance -> board[15];
		vertices[4].vertex = &instance -> board[25];
		vertices[5].vertex = &instance -> board[26];

		vertices[0].distto = 1000;
		vertices[1].distto = 1000;
		vertices[2].distto = 1000;
		vertices[3].distto = 1000;
		vertices[4].distto = 1000;
		vertices[5].distto = 1000;

	}

	if (fing.name == 5){
		vertices[0].vertex = &instance -> board[5];
		vertices[1].vertex = &instance -> board[6];
		vertices[2].vertex = &instance -> board[16];
		vertices[3].vertex = &instance -> board[17];
		vertices[4].vertex = &instance -> board[27];
		vertices[5].vertex = &instance -> board[28];

		vertices[0].distto = 1000;
		vertices[1].distto = 1000;
		vertices[2].distto = 1000;
		vertices[3].distto = 1000;
		vertices[4].distto = 1000;
		vertices[5].distto = 1000;

	}

	if (fing.name == 8){
		vertices[0].vertex = &instance -> board[9];
		vertices[1].vertex = &instance -> board[10];
		vertices[2].vertex = &instance -> board[20];
		vertices[3].vertex = &instance -> board[21];
		vertices[4].vertex = &instance -> board[31];
		vertices[5].vertex = NULL;

		vertices[0].distto = 1000;
		vertices[1].distto = 1000;
		vertices[2].distto = 1000;
		vertices[3].distto = 1000;
		vertices[4].distto = 1000;
		vertices[5].distto = 1000;

	}


}


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


int findIndexinverts(key *node, dijk_pair vertices[6]){
	//find keyindex in vertices
		for (int i = 0; i < 6 ; i++){
			if ( node == vertices[i].vertex){
				return i;
			}
		}
		return 0;
}


//finds all distances from current not to its neighbors
void disttoAdj(key *curNode, dijk_pair vertices[6]){

	int distToCur;
	int newDist = 1000;
	int vertIndex;

	//finding distance to current node, that new distance will be added to.
	for (int i = 0; i < 6 ; i++){
		if (curNode == vertices[i].vertex)
			distToCur = vertices[i].distto;
	}

	for (int j = 0; j < 5 ; j++){

		//proposed new distance
		if (curNode->adjdist[j] != 1000){

		newDist = distToCur + curNode->adjdist[j];
		vertIndex = findIndexinverts(curNode->adjList[j], vertices);

	}

		// set new distance if newDist is less then vertices[vertIndex].distto
		if (newDist < vertices[vertIndex].distto)
			vertices[vertIndex].distto = newDist;
	}
}

// ch is the key we want to move to, finger is where finger is currently placed
int cgetDistance(char ch, finger fing, keyboard *instance){

	////==========================================================================================
	//setting up array to keep track of distances
	dijk_pair *vertices;
	int vertdestindex;


	vertices = setCheckArray(fing, instance);


	//==========================================================================================
	//finding where in array our destination is based on ch
	
	for (int k = 0; k < 5 ; k++){
		if ( ch == vertices[k].vertex->charcter)
			vertdestindex = k;
	}
	cout << vertdestindex << endl;
}
	//==========================================================================================

		/*

	key *current = fing->curPosition;
	int sourceindex = findIndexinverts(current);
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


}
*/
//*******************************************************************************************************************
//*******************************************************************************************************************



int main(){

	string filename = "testfile";
	string text = readText(filename);
	

	keyboard *keyboard_inst = new keyboard();

	//cout << keyboard_inst -> board[17].adjList[0]->charcter << endl;
	//cout << keyboard_inst -> board[17].adjList[1]->charcter << endl;

	hands *hand_inst = new hands(keyboard_inst);

	int index = getLocation(text[0], keyboard_inst);
	int finger_number = getFingerNum(index);
	finger fing = getFinger(finger_number, hand_inst);
	int distance = cgetDistance(text[0], fing, keyboard_inst);

	//cout << distance << endl;

}