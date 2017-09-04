//////////////////// ** Author: Jared Parkinson
//   Critter.cpp   // ** Date: 4/10/2016
//////////////////// ** Desc: modB week2

#include "Critter.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes data members
/*---------------------------------------------------------------------------------*/
Critter::Critter() {
	hasMoved = false;
}

//Getters
bool Critter::getHasMoved() {
	return hasMoved;
}
//Setters
void Critter::setHasMoved(bool moved) {
	hasMoved = moved;
}

//Movement
/*------------------------------------------------------------------------------*/
// Function: updateLocation
// Description: updates Critter Location 1 move at a time passing random direction
/*------------------------------------------------------------------------------*/
int Critter::updateLocation() {
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