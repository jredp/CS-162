//////////////////// ** Author: Jared Parkinson 
//     Ant.cpp    // *** Date: 4/16/2016
//////////////////// **** Desc: modC

#include "Ant.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes movesMade and hasMoved
/*---------------------------------------------------------------------------------*/
Ant::Ant() {
	hasMoved = false;
	movesMade = 0;
}
/*---------------------------------------------------------------------------------*/
// Function: Breed
// Description: Returns Pointer to new Ant Object for Grid
/*---------------------------------------------------------------------------------*/
Ant* Ant::Breed() {	
	incMoves();
	Ant* newAnt;
	//If 3 moves made, Breed new Ant in previous slot
	if (movesMade >= 3) {		
		newAnt = new Ant();
		clearMoves();
	}
	//Else set previous slot to NULL
	else {
		newAnt = NULL;
		//setMoves(movesMade+1); 
	}
	return newAnt;
}

//Setters
void Ant::clearMoves() {
	movesMade = 0;
}
void Ant::incMoves() {
	movesMade++; //Increment movesMade
}
void Ant::setAntX(int x) {
	antX = x;
}
void Ant::setAntY(int y) {
	antY = y;
}
//Getters
int Ant::getMoves() {
	int totalMoves = movesMade;
	return totalMoves;
}