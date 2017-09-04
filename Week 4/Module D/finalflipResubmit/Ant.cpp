//////////////////// ** Author: Jared Parkinson 
//     Ant.cpp    // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#include "Ant.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes movesMade and hasMoved
/*---------------------------------------------------------------------------------*/
Ant::Ant() {
	hasMoved = false;
	movesMade = 0;	
	icon = '*';
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
// Description: Free Memory
/*---------------------------------------------------------------------------------*/
Ant::~Ant() {}
/*---------------------------------------------------------------------------------*/
// Function: checkBreed
// Description: Bool return checking Breed
/*---------------------------------------------------------------------------------*/
bool Ant::checkBreed() {
	bool mustBreed = false;
	if (movesMade >= 3) mustBreed = true;
	return mustBreed;
}
/*---------------------------------------------------------------------------------*/
// Function: Breed
// Description: Returns Pointer to new Ant Object for Grid
/*---------------------------------------------------------------------------------*/
Critter* Ant::Breed() {	
	Critter* pointAnt;	
	pointAnt = new Ant();	
	clearMoves();
	return pointAnt;
}