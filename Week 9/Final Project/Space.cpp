//////////////////// ** Author: Jared Parkinson 
//   Space.cpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Space.hpp"

/*--------------------------------------------------*/
// Function: Constructor
/*--------------------------------------------------*/
Space::Space() {}
/*--------------------------------------------------*/
// Function: Destructor
/*--------------------------------------------------*/
Space::~Space() {}
/*--------------------------------------------------*/
// Function: getSpaceN
// Description: Gets space N
/*--------------------------------------------------*/
Space* Space::getSpaceN() {
	return N;
}
/*--------------------------------------------------*/
// Function: getSpaceS
// Description: Gets space S
/*--------------------------------------------------*/
Space* Space::getSpaceS() {
	return S;
}
/*--------------------------------------------------*/
// Function: getSpaceE
// Description: Gets space E
/*--------------------------------------------------*/
Space* Space::getSpaceE() {
	return E;
}
/*--------------------------------------------------*/
// Function: getSpaceW
// Description: Gets space W
/*--------------------------------------------------*/
Space* Space::getSpaceW() {
	return W;
}
/*--------------------------------------------------*/
// Function: spaceInput
// Desc: Input for Space Actions
/*--------------------------------------------------*/
int Space::spaceInput() {
	int input; //input holder
	std::cin >> input;

	//Check Valid #
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear();
		std::cin.ignore(2, '\n');
		std::cin >> input;
	}
	return input;
}
/*--------------------------------------------------*/
// Function: setSpace
// Description: Sets space of passed Direction
/*--------------------------------------------------*/
void Space::setSpace(char dir, Space* passed) {	
	if (dir == 'N') {
		N = passed;
	}
	else if (dir == 'E') {
		E = passed;
	}
	else if (dir == 'S') {
		S = passed;
	}
	else if (dir == 'W') {
		W = passed;
	}
}
/*--------------------------------------------------*/
// Function: setPlayerHere
// Description: Sets the Player in this space
/*--------------------------------------------------*/
void Space::setPlayerHere(Player* playPtr) {
	playerHere = playPtr;
}
/*--------------------------------------------------*/
// Function: setPlayerLeave
// Description: The player has left, NULL the pointer
/*--------------------------------------------------*/
void Space::setPlayerLeave() {
	playerHere = NULL;
}