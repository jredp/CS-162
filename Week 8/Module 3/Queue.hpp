//////////////////// ** Author: Jared Parkinson 
//   Queue.hpp    // *** Date: 5/25/2016
//////////////////// **** Desc: Mod 3

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>

//FIFO - First In First Out
class Queue
{
private:
	std::queue<int> Queuenode;	
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