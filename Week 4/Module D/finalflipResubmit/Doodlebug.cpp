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
// Function: Destructor
// Description: Destructor
/*---------------------------------------------------------------------------------*/
Doodlebug::~Doodlebug(){}
/*---------------------------------------------------------------------------------*/
// Function: checkBreed
// Description: Bool return checking Breed
/*---------------------------------------------------------------------------------*/
bool Doodlebug::checkBreed() {
	bool mustBreed = false;
	if (movesMade >= 8) mustBreed = true;
	return mustBreed;
}
/*---------------------------------------------------------------------------------*/
// Function: Breed
// Description: Returns Pointer to new Doodlebug Object for Grid
/*---------------------------------------------------------------------------------*/
Critter* Doodlebug::Breed() {		
	Critter* newDoodlebug = new Doodlebug();
	clearMoves();	
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