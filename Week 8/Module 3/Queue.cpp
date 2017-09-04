//////////////////// ** Author: Jared Parkinson 
//   Queue.cpp    // *** Date: 5/25/2016
//////////////////// **** Desc: Mod 3

#include "Queue.hpp"

/*------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*------------------------------------------------------------*/
Queue::Queue() {	
	iteration = 0; //Init iter
	waitSum = 0; //Init wait
}
/*------------------------------------------------------------*/
// Function: Destructor
// Description: Destructor
/*------------------------------------------------------------*/
Queue::~Queue() {
	//Free Left Over Queue if not empty
	while (!queueEmptyChk()) {
		Queuenode.pop();
	}
}
/*------------------------------------------------------------*/
// Function: add
// Description: Adds a Queuenode, sets front
/*------------------------------------------------------------*/
void Queue::add(int nodesToAdd) {
	//Create new Queuenode struct object, place in back	
	for (int i = 0; i < nodesToAdd; i++) {
		//Insert node for each node to add
		Queuenode.push(iteration);		
	}
}
/*------------------------------------------------------------*/
// Function: remove
// Description: Removes Queuenode, returns the int data
/*------------------------------------------------------------*/
int Queue::remove() {
	int removed;
	removed = Queuenode.front();
	Queuenode.pop();
	return removed;
}
/*------------------------------------------------------------*/
// Function: QueueEmptyChk
// Description: Checks if the Queue is empty
/*------------------------------------------------------------*/
bool Queue::queueEmptyChk() {
	if (Queuenode.empty()) { 
		return true; 
	}
	else {
		return false;
	}
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