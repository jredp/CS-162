//////////////////// ** Author: Jared Parkinson 
//   Stack.cpp    // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#include "Stack.hpp"

/*------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*------------------------------------------------------------*/
Stack::Stack() {
	top = NULL; //Set Top Null		
}
/*------------------------------------------------------------*/
// Function: Destructor
// Description: Destructor
/*------------------------------------------------------------*/
Stack::~Stack() {
}
/*------------------------------------------------------------*/
// Function: add
// Description: Adds a Stacknode, sets top
/*------------------------------------------------------------*/
void Stack::add(char dataChar) {
	//Create new Stacknode struct object
	top = new Stacknode(dataChar, top);	
}
/*------------------------------------------------------------*/
// Function: remove
// Description: Removes Stacknode, returns the char data
/*------------------------------------------------------------*/
char Stack::remove() {
	Stacknode *temp; //Temp Node Holder

	//Remove Stacknode	
	char tempNodeData = top->nodeData; //Temp Data Holder
	temp = top; //adjust top pointer
	top = top->next; //Set next node
	delete temp; //remove node/data
	return tempNodeData; //return Char		
}
/*------------------------------------------------------------*/
// Function: stackEmptyChk
// Description: Checks if the Stack is empty
/*------------------------------------------------------------*/
bool Stack::stackEmptyChk() {	
	if (!top) return true;
	else return false;
}
/*------------------------------------------------------------*/
// Function: runStack
// Description: Runs the Stack User entry, Validates input, 
//     Calls printStack
/*------------------------------------------------------------*/
void Stack::runStack() {
	//Stack User Input
	std::cout << "Please enter 1 char at a time, each followed by enter." << std::endl;
	std::cout << "**If more than 1 at a time is input, it takes the 1st." << std::endl;
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
		add(inputChar); //Add inputChar to Stacknode	
		std::cin.clear(); //Clear cin
		std::cin.ignore(256, '\n');
		std::cin >> inputChar;
	}
			std::cout << "Printing and removing the Stack." << std::endl;
			printRemoveStack(); // Print and Remove Stack
}
/*------------------------------------------------------------*/
// Function: printStack
// Description: Prints the Stack and Calls Remove as it prints
/*------------------------------------------------------------*/
void Stack::printRemoveStack() {	
	//Remove Stack/Print until empty
	while (!stackEmptyChk()) std::cout << remove() << " ";
	std::cout << "Stack is empty.\n";
}