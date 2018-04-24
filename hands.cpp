/* The fitness function that will evaluate how fit a keyboard is */




// a class for fingers. We can store:
// (1)there position (what key they are on)
// (2)There strength
// (3)Times it has been used
// more...
class finger{

	public:
		key curPosition;
		int str;
		int pressCount = 0;


	void setPos(key pos){
		curPosition = pos;
	}
	void keyTouch(){
		pressCount++;
	}

};

//all types of fingers inherate the finger class, and have different strengths. 
//(This is kinda bulky, but I don't know any other way to do it)
//Once we have a keyboard object we can make 2 of each call set position on each of them
// to the starting "asdfjkl;" position, and then start typing

class pinky : public finger{

	public:
		pinky()
};
pinky::pinky(){
	str = 1; 
}
class ring : public finger{
	public:
		ring()
};
ring::ring(){
	str = 2; 
}
class middle : public finger{
	public:
		middle()
};
middle::middle(){
	str = 4;
}
class index : public finger{
	public:
		index()
};
index::index(){
	str = 4;
}



//class that has all of the fingers
class hands{

	pinky rp;
	pinky lp;
	ring rr;
	ring lr;
	middle rm;
	middle lm;
	index ri;
	index li;


	// The constructor of hands requires a keyboard, to set positions on.
	hands(keyboard instance){

		//set position of finger by taking instance of keyboard object, getting board and then finding
		//spot in array.
		rp.setPos(instance.board[20])
		lp.setPos(instance.board[11])
		rr.setPos(instance.board[19])
		lr.setPos(instance.board[12])
		rm.setPos(instance.board[18])
		lm.setPos(instance.board[13])
		ri.setPos(instance.board[17])
		li.setPos(instance.board[14])
	}
};


