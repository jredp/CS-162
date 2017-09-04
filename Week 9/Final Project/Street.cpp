//////////////////// ** Author: Jared Parkinson 
//   Street.cpp   // *** Date: 5/28/2016
//////////////////// **** Desc: Final

//**Normal Space (like Barbarian non-special)
#include "Street.hpp"

/*--------------------------------------------------*/
// Function: Constructor
/*--------------------------------------------------*/
Street::Street() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link
	playerHere = NULL; //Player Ptr
	//No Special Actions or Items for this space
}
/*--------------------------------------------------*/
// Function: Destructor
/*--------------------------------------------------*/
Street::~Street() {}
/*--------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*--------------------------------------------------*/
void Street::printSpaceDesc() {
	//Space Description
	std::cout << "\n***************************************************\n";
	std::cout << "STREET:\n";
	std::cout << "You are in a bustling thoroughway of people! Everyone\n";
	std::cout << "is wearing unusual clothing and walking quickly. You \n";
	std::cout << "must find the time Gems! You do not see any here! Move\n";
	std::cout << "on! Time is running out!\n";
	std::cout << "***************************************************\n";
}
/*--------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*--------------------------------------------------*/
void Street::Special() {
	printSpaceDesc();
	spaceOptions();
}
/*---------------------------------------------------------------------------------*/
// Function: spaceOptions
// Desc: Show Special Options
/*---------------------------------------------------------------------------------*/
void Street::spaceOptions() {
	std::cout << "(No special actions in this space.)\n";	
}