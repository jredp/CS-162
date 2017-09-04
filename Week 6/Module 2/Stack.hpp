//////////////////// ** Author: Jared Parkinson 
//   Stack.hpp    // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

//LIFO - First in Last Out
class Stack 
{
private:		
	struct Stacknode	
	{
		char nodeData; //Node Count helper
		Stacknode *next; //Next pointer
		//Stacknode Constructor
		Stacknode(char nodeDataIns, Stacknode *nextIns) {			
			nodeData = nodeDataIns;
			next = nextIns;						
		}
	};		
	Stacknode *top; //Top of Stack		
	void add(char add); //Add node with data of char		
	char remove(); //remove node from top of Stack FILO	
	bool stackEmptyChk(); //Checks for empty stack
	void printRemoveStack(); //Prints Stack and removes items	

public:
	Stack(); //Constructor	
	~Stack(); //Destructor	
	void runStack(); //Run the Stack program for input	
	
};

#endif
