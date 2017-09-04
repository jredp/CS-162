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
// Function: Breed
// Description: Returns Pointer to new Ant Object for Grid
/*---------------------------------------------------------------------------------*/
Critter* Ant::Breed() {	
	Critter* pointAnt;	
	if (movesMade >= 3) {
		pointAnt = new Ant();	
		clearMoves();
	}
	//Else set previous slot to NULL
	else {
		pointAnt = NULL;
		//setMoves(movesMade+1); 
	}
	return pointAnt;
}