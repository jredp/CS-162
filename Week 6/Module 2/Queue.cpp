//////////////////// ** Author: Jared Parkinson 
//   Queue.cpp    // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#include "Queue.hpp"

/*------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*------------------------------------------------------------*/
Queue::Queue() {
	front = NULL; //Set Front Null		
	back = NULL; //Set Back Null
}
/*------------------------------------------------------------*/
// Function: Destructor
// Description: Destructor
/*------------------------------------------------------------*/
Queue::~Queue() {
}
/*------------------------------------------------------------*/
// Function: add
// Description: Adds a Queuenode, sets top
/*------------------------------------------------------------*/
void Queue::add(char dataChar) {
	//Create new Queuenode struct object, place in back	
	if (queueEmptyChk()) {
		//If empty, make front/back point same Node
		front = new Queuenode(dataChar); //back will be NULL right now
		back = front; //Back now = Front
	}
	//If Queue has nodes, put a Node in back
	else {
		back->next = new Queuenode(dataChar); //New Node in Back
		back = back->next; //Set next Node
	}
}
/*------------------------------------------------------------*/
// Function: remove
// Description: Removes Queuenode, returns the char data
/*------------------------------------------------------------*/
char Queue::remove() {
	Queuenode *temp; //Temp Node Holder

	//Remove Queuenode	
	char tempNodeData = front->nodeData; //Temp Data Holder
	temp = front; //adjust top pointer	
	front = front->next; //Set front pointer to next node	
	delete temp; //remove node/data
	return tempNodeData; //return Char
}
/*------------------------------------------------------------*/
// Function: QueueEmptyChk
// Description: Checks if the Queue is empty
/*------------------------------------------------------------*/
bool Queue::queueEmptyChk() {
	//if (!front) return true;
	if (!front) return true;
	else return false;
}
/*------------------------------------------------------------*/
// Function: runQueue
// Description: Runs the Queue User entry, Validates input, 
//     Calls printQueue
/*------------------------------------------------------------*/
void Queue::runQueue() {
	//Queue User Input
	std::cout << "Please enter 1 char at a time, each followed by enter." << std::endl;
	std::cout << "If more than one char is entered, it only takes the 1st." << std::endl;
	std::cout << "Use period '.' to finish.\n" << std::endl;
	char inputChar;
	std::cin >> inputChar;
	//If valid Char
	while (inputChar != '.') {
		//If input Char is not a Char
		while (!std::cin) {
			std::cout << "Not a valid character! Try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> inputChar;
		}
		add(inputChar); //Add inputChar to Queuenode		
		std::cin.clear(); //Clear cin
		std::cin.ignore(256, '\n');
		std::cin >> inputChar;
	}
	std::cout << "Printing and removing the Queue." << std::endl;
	printRemoveQueue(); // Print and Remove Queue
}
/*------------------------------------------------------------*/
// Function: printQueue
// Description: Prints the Queue and Calls Remove as it prints
/*------------------------------------------------------------*/
void Queue::printRemoveQueue() {
	//Remove Queue/Print until empty
	while (!queueEmptyChk()) std::cout << remove() << " ";
	std::cout << "\nQueue is now empty.\n";
}