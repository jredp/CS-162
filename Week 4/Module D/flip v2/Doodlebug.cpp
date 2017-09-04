//////////////////// ** Author: Jared Parkinson 
//  Doodlebug.cpp // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#include "Doodlebug.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes movesMade and hasMoved
/*---------------------------------------------------------------------------------*/
Doodlebug::Doodlebug() {
	hasMoved = false; //set Has Moved
	starved = false;	
	movesMade = 0; //Set moves made
	movesNoEat = 0; //Set moves made without eating
	icon = '#'; //Set Icon
}
/*---------------------------------------------------------------------------------*/
// Function: Breed
// Description: Returns Pointer to new Doodlebug Object for Grid
/*---------------------------------------------------------------------------------*/
Critter* Doodlebug::Breed() {	
	Critter* newDoodlebug;
	//If 8 moves made, Breed new Doodlebug in previous slot
	if (movesMade >= 8) {
		newDoodlebug = new Doodlebug();
		clearMoves();
	}
	//Else set previous slot to NULL
	else {
		newDoodlebug = NULL;		
	}
	return newDoodlebug;
}
/*---------------------------------------------------------------------------------*/
// Function: getStarved
// Description: Gets starved
/*---------------------------------------------------------------------------------*/
bool Doodlebug::getStarved() {
	return starved;
}
/*---------------------------------------------------------------------------------*/
// Function: Eat
// Description: Sets hasEaten
/*---------------------------------------------------------------------------------*/
void Doodlebug::Eat() {	
	movesNoEat = 0;
}

/*---------------------------------------------------------------------------------*/
// Function: Starve
// Description: Sets Starve
/*---------------------------------------------------------------------------------*/
void Doodlebug::Starve() {
	if (movesNoEat >=3) starved = true;
}