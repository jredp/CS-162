//////////////////// ** Author: Jared Parkinson
//   Critter.cpp   // ** Date: 4/28/2016
//////////////////// ** Desc: modD

#include "Critter.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes data members
/*---------------------------------------------------------------------------------*/
Critter::Critter() {
	hasMoved = false;
	icon = 'C';
}
/*---------------------------------------------------------------------------------*/
// Function: Virtual Destructor
// Description: Virtual Destructor
/*---------------------------------------------------------------------------------*/
Critter::~Critter() {
	//Deleted!
}
//Action
/*---------------------------------------------------------------------------------*/
// Function: Breed
// Description: Base Breed function (not in use), instantly breeds
/*---------------------------------------------------------------------------------*/
Critter* Critter::Breed() {	
	Critter* newCrit;	
	newCrit = new Critter();
	clearMoves();	
	return newCrit;
}
/*---------------------------------------------------------------------------------*/
// Function: Eat
// Description: Base Eat function (not in use)
/*---------------------------------------------------------------------------------*/
void Critter::Eat() {
	setMovesNoEat(0); //Reset to 0 moves without eating
}
/*------------------------------------------------------------------------------*/
// Function: updateLocation
// Description: updates Critter Location 1 move at a time passing random direction
/*------------------------------------------------------------------------------*/
int Critter::move() {
	int direction = randMoveDirection();
	return direction;
}
/*---------------------------------------------------------------------------------*/
// Function: randMoveDirection
// Description: Generates random direction as int 1-4. Possible: Up, Down, Left, Right
/*---------------------------------------------------------------------------------*/
int Critter::randMoveDirection() {
	std::uniform_int_distribution<> direction(1, 4);
	auto returnDir = direction(engine);
	return returnDir;
}


//Setter
/*---------------------------------------------------------------------------------*/
// Function: clearMoves
// Description: Sets the moves to 0
/*---------------------------------------------------------------------------------*/
void Critter::clearMoves() {
	movesMade = 0;
}
/*---------------------------------------------------------------------------------*/
// Function: setHasMoved
// Description: Sets the hasMoved bool
/*---------------------------------------------------------------------------------*/
void Critter::setHasMoved(bool moved) {
	hasMoved = moved;
}
/*---------------------------------------------------------------------------------*/
// Function: setMovesNoEat
// Description: Set moves without eating
/*---------------------------------------------------------------------------------*/
void Critter::setMovesNoEat(int movNoEat) {
	movesNoEat = movNoEat;
}
/*---------------------------------------------------------------------------------*/
// Function: incMoves
// Description: Increments the movesMade
/*---------------------------------------------------------------------------------*/
void Critter::incMoves() {
	movesMade++; //Increment movesMade
}
/*---------------------------------------------------------------------------------*/
// Function: incMovNoEat
// Description: Increments the moves made without eating
/*---------------------------------------------------------------------------------*/
void Critter::incMovNoEat() {
	movesNoEat++; //Increment movesMade
}


//Getter
/*---------------------------------------------------------------------------------*/
// Function: getMoves
// Description: Gets the movesMade
/*---------------------------------------------------------------------------------*/
int Critter::getMoves() {
	return movesMade;
}
/*---------------------------------------------------------------------------------*/
// Function: getIcon
// Description: Gets the movesMade
/*---------------------------------------------------------------------------------*/
char Critter::getIcon() {
	return icon;
}
/*---------------------------------------------------------------------------------*/
// Function: getHasMoved
// Description: Gets hasMoved
/*---------------------------------------------------------------------------------*/
bool Critter::getHasMoved() {
	return hasMoved;
}