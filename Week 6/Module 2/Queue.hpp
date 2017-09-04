//////////////////// ** Author: Jared Parkinson 
//   Queue.hpp    // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

//FIFO - First In First Out
class Queue
{
private:	
	struct Queuenode
	{
		char nodeData; //Node Count helper		
		Queuenode *next; //Next pointer
		//Queuenode Constructor
		Queuenode(char nodeDataIns, Queuenode *nextIns = NULL) {
			nodeData = nodeDataIns;
			next = nextIns;
		}
	};
	Queuenode *front; //front of Queue
	Queuenode *back; //front of Queue
	int numQueue; //Number of Queued items
	void add(char add); //Add node with data of char	
	char remove(); //remove node from top of Queue FIFO
	void printRemoveQueue(); //Prints Queue and removes items
	bool queueEmptyChk(); //Checks for empty Queue	

public:
	Queue(); //Constructor
	~Queue(); //Destructor		
	void runQueue(); //Run the Queue program for input	
};

#endif
