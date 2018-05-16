/* Where all functions are that calculate fitness
and functions that deal with the text we will be using*/

#include "fitness.h"
using namespace std;
//ALGORTHIM FOR FINDING FITNESS FOR A SINGLE KEYBOARD
//*******************************************************************************************************************
//*******************************************************************************************************************


void keyboard::setFitness(std::string text){


	//this->printBoard();

	//cout<<"\n\n"<<endl;
	int fit = 0;
	hands *iHands = new hands(this);
	for (int i = 0; i < text.length(); i++){

		if(text[i] == '\n')
			continue;

		int strPenalty = 0;
		int repPenalty = 0;
		int handPenalty = 0;
		int distance = 0;


		int keyindex = getLocation(text[i], this);
		int fingNum = getFingerNum(keyindex);

		delayCheck(iHands, this);

		if (inbasic(keyindex)){
		
			//ignore distance
			//add finger rep penalty
			
			
			repPenalty = getFingCount(fingNum);
			strPenalty = getStr(fingNum);
			handPenalty = getHandpen(fingNum);

		}

		else if (insimple(keyindex)){
		
			
			distance = sgetDistance(text[i], this);
			repPenalty = getFingCount(fingNum);
			strPenalty = getStr(fingNum);
			handPenalty = getHandpen(fingNum);
		}
		//complex case
		else{

			//cout << "charcter in complex case: " << text[i] << endl;
			//add distance to new key more complicated
			//finding finger
			delayReset(fingNum);
			//finding distance depending on graph we are dealing with
			
			if (fingNum != 8){
				if (fingNum == 4){
					distance  = cgetDistance(text[i], iHands -> l_index, this);
					iHands -> l_index.curPosition = &this->board[keyindex];
				}
				else{
					distance  = cgetDistance(text[i], iHands -> r_index, this);
					iHands -> r_index.curPosition = &this->board[keyindex];
				}
			}
			else
				distance  = cgetDistance(text[i], iHands -> r_pinky, this);


			//add finger penalty
			repPenalty = getFingCount(fingNum);
			//add str penalty
			strPenalty = getStr(fingNum);
			//add hand pen
			handPenalty = getHandpen(fingNum);

		}
		fit += distance + strPenalty + repPenalty + handPenalty;
	}

	resetGlobals();

	fitness = fit;
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

void resetGlobals(){

	lastHand = 0;
	currHand = 0;
	handPen = 0;
	prevFingNum = -1;
	indexDelay[0] = 0;
	indexDelay[1] = 0;
}


void delayCheck(hands *iHands, keyboard *instance){

	if (iHands -> l_index.curPosition != &instance->board[14])
		indexDelay[0]++;

	if (iHands -> r_index.curPosition != &instance->board[17])
		indexDelay[1]++;

	if (indexDelay[0] > 3){
		iHands -> r_index.curPosition = &instance->board[14];
		indexDelay[0] = 0;
	}

	if (indexDelay[1] > 3){
		iHands -> l_index.curPosition = &instance->board[17];
		indexDelay[1] = 0;
	}
}

void delayReset(int fingNum){

	if (fingNum == 4){
		indexDelay[0] = 0;
	}
	if (fingNum == 5){
		indexDelay[1] = 0;
	}
}



int insimple(int i){

	for (int j =  0; j <= 9; j++){
		if (i == simple_index[j])
			return 1;
	}
	return 0;
}

int inbasic(int i){
	for (int j =  0; j <= 7; j++){
		if (i == basic_index[j])
			return 1;
	}
	return 0;
}


int sgetDistance(char ch, keyboard *instance){

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


void incrFingCount(int FingNum){
pressarray[FingNum] +=	pressarray[FingNum]/4;
}

int getFingCount(int FingNum){
	if (prevFingNum == FingNum)
		incrFingCount(FingNum);
	else
		pressarray[FingNum] = 0;

	prevFingNum = FingNum;

	return pressarray[FingNum];
}

int getStr(int FingNum){
	return strarray[FingNum - 1];
}

int getHandpen(int fingNum){

	lastHand = currHand;


	if (fingNum < 5)
		currHand = -1;

	if (fingNum >= 5)
		currHand = 1;


	if (currHand == lastHand && (currHand != 0))
		handPen += 3;

	if (currHand != lastHand)
		handPen = 0;

	return handPen;
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

	return vertices;

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
void disttoAdj(key *current, int adjIndex, dijk_pair *vertices){

	int distToCur;
	int newDist = 1000;
	int vertIndex;

	//finding distance to current node, that new distance will be added to.
	for (int i = 0; i < 6 ; i++){
		if (current == vertices[i].vertex)
			distToCur = vertices[i].distto;
	}
	
	
	newDist = distToCur + current->adjdist[adjIndex];



	vertIndex = findIndexinverts(current->adjList[adjIndex], vertices);


	if (newDist < vertices[vertIndex].distto){
		vertices[vertIndex].distto = newDist;
	}
}

// ch is the key we want to move to, finger is where finger is currently placed
int cgetDistance(char ch, finger fing, keyboard *instance){


	
	////==========================================================================================
	//setting up array to keep track of distances
	dijk_pair *vertices;
	int vertdestindex;
	


	//sets the array of keys that we have to check before dikjstras is done
	vertices = setCheckArray(fing, instance);


	//==========================================================================================
	//finding where in array our destination is based on ch
	
	for (int k = 0; k < 6 ; k++){
	  //cout << vertices[k].vertex->charcter << endl;
	  if ( ch == vertices[k].vertex->charcter && vertices[k].vertex != NULL){
			vertdestindex = k;
		break;
	  }
	}
	//cout << "vertdestindex is: " << vertdestindex << endl;

	//==========================================================================================


	key *current = fing.curPosition;

	//cout << current->charcter<< endl;

	int sourceindex = findIndexinverts(current, vertices);
	
	vertices[sourceindex].distto = 0;

	getAdjdistances(current, vertices);
	for (int j = 0 ; j < 2 ; j++){
		for (int i = 0 ; i < 5 ; i++){
			if (current->adjList[i] != NULL){
				current = current -> adjList[i];
				
				getAdjdistances(current, vertices);
			}
		}
	}
	
	//	printShortestDist(current, vertices);
	int toreturn = vertices[vertdestindex].distto;
	freeArray(vertices);
	return  toreturn;

}


void printShortestDist(key *current, dijk_pair *vertices){

	cout << "we are at key: " << current->charcter << endl;

	for (int i = 0 ; i < 6 ; i++){
	  if (vertices[i].vertex != NULL)
	    cout << "distance to charcter " << vertices[i].vertex->charcter << " is " << vertices[i].distto << endl;
	}

}

void getAdjdistances(key *current, dijk_pair *vertices){

	for (int i = 0 ; i < 5 ; i++){
		if (current->adjList[i] != NULL){
			disttoAdj(current, i, vertices);
		}
	}
}


void freeArray(dijk_pair *vertices){
	free(vertices);
}


//*******************************************************************************************************************
//*******************************************************************************************************************
/*
int main(){

  string text = readText("testfile.txt");
  
  keyboard *instance = new keyboard();
  instance->setFitness(text);

}
*/
