//////////////////// ** Author: Jared Parkinson 
//   Queue.cpp    // *** Date: 5/23/2016
//////////////////// **** Desc: Mod F

#include "Queue.hpp"

/*------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*------------------------------------------------------------*/
Queue::Queue() {
	front = NULL; //Set Front Null		
	back = NULL; //Set Back Null
	iteration = 0; //Init iter
	waitSum = 0; //Init wait
}
/*------------------------------------------------------------*/
// Function: Destructor
// Description: Destructor
/*------------------------------------------------------------*/
Queue::~Queue() {
	//Free Left Over Queue
	while (!queueEmptyChk()) {
		Queuenode *temp;

		temp = front; //adjust top pointer
		front = front->next; //Set front pointer to next node
		delete temp; //remove node/data		
		temp = NULL;
	}
}
/*------------------------------------------------------------*/
// Function: add
// Description: Adds a Queuenode, sets front
/*------------------------------------------------------------*/
void Queue::add(int nodesToAdd) {
	//Create new Queuenode struct object, place in back	
	for (int i = 0; i < nodesToAdd; i++) {
		if (queueEmptyChk()) {
			//If empty, make front/back point same Node
			front = new Queuenode(iteration); //back will be NULL right now
			back = front; //Back now = Front
		}
		//If Queue has nodes, put a Node in back
		else {
			back->next = new Queuenode(iteration); //New Node in Back
			back = back->next; //Set next Node
		}
	}
}
/*------------------------------------------------------------*/
// Function: remove
// Description: Removes Queuenode, returns the int data
/*------------------------------------------------------------*/
int Queue::remove() {
	Queuenode *temp; //Temp Node Holder

	//Remove Queuenode	
	int tempNodeData = front->timeStamp; //Temp Data Holder
	temp = front; //adjust top pointer	
	front = front->next; //Set front pointer to next node	
	delete temp; //remove node/data
	temp = NULL;
	return tempNodeData; //return Char
}
/*------------------------------------------------------------*/
// Function: QueueEmptyChk
// Description: Checks if the Queue is empty
/*------------------------------------------------------------*/
bool Queue::queueEmptyChk() {	
	if (!front) return true;
	else return false;
}
/*------------------------------------------------------------*/
// Function: setIteration
// Description: Sets the iteration
/*------------------------------------------------------------*/
void Queue::setIteration(int setIter) {
	iteration = setIter;
}
/*------------------------------------------------------------*/
// Function: setWaitSum
// Description: Sets the Wait Sum
/*------------------------------------------------------------*/
void Queue::setWaitSum(int setSum) {
	waitSum += setSum;
}
/*------------------------------------------------------------*/
// Function: getWaitSum
// Description: Gets the Wait Sum for Calc
/*------------------------------------------------------------*/
int Queue::getWaitSum() {
	return waitSum;
}