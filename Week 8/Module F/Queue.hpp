//////////////////// ** Author: Jared Parkinson 
//   Queue.hpp    // *** Date: 5/23/2016
//////////////////// **** Desc: Mod F

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

//FIFO - First In First Out
class Queue
{
private:
	struct Queuenode
	{
		int timeStamp; //Node Data - int timeStamp	
		Queuenode *next; //Next pointer
		//Queuenode Constructor
		Queuenode(int timeStampIns, Queuenode *nextIns = NULL) {
			timeStamp = timeStampIns;
			next = nextIns;
		}
	};
	Queuenode *front; //front of Queue
	Queuenode *back; //front of Queue	
	bool queueEmptyChk(); //Checks for empty Queue	
	int iteration; //Iteration of a single light change
	int waitSum; //Sum of Time Waiting each lane

public:
	Queue(); //Constructor
	~Queue(); //Destructor			
	void add(int nodesToAdd); //Add node with data of char	
	int remove(); //remove node from top of Queue FIFO
	void setIteration(int iteration); //Sets the iteration timeStamp we are on
	void setWaitSum(int setWait); //Sets the Wait Sum of this Lane
	int getWaitSum(); //Gets the Wait Sum
};

#endif
