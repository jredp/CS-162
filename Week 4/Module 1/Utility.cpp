//////////////////// ** Author: Jared Parkinson 
//  Utility.cpp   // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#include "Utility.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*---------------------------------------------------------------------------------*/
Utility::Utility() {
	//Nothing Needed at the moment
}
/*---------------------------------------------------------------------------------*/
// Function: intChecker
// Description: Checks for INT input, else message.
/*---------------------------------------------------------------------------------*/
int Utility::intChecker() {	
	int intInput;
	std::cin >> intInput;

	//Valid number?
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');		
		std::cin >> intInput;
	}	
	return intInput;
}