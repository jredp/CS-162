//////////////////// ** Author: Jared Parkinson
//   Critter.cpp   // ** Date: 11/23/2015
//////////////////// ** Desc: Week 1 - critter.cpp

#include "Critter.hpp"
#include <random> //Randomizer
#include <memory> //For Random Memory Engine

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes data members
/*---------------------------------------------------------------------------------*/
Critter::Critter()
{
	Critter::critXcoord = 0; //Default to position 1
	Critter::critYcoord = 0; //Default to position 1
	Critter::moveCount = 0; //Set to 0 moves on creation
	Critter::critterIcon = 'C';
	Critter::squashed = false;
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

/*------------------------------------------------------------------------------*/
// Function: gridSize
// Description: Is the Grid Size valid?
/*------------------------------------------------------------------------------*/
bool Critter::validSize(int size) {
	bool valid = true;
	if (size < 1) valid = false;
	return valid;
}

//Getters
/*---------------------------------------------------------------------------------*/
// Function: getXcoord
// Description: Adjusts for 0 array start
/*---------------------------------------------------------------------------------*/
int Critter::getXcoord() {	
	return critXcoord;
}

/*---------------------------------------------------------------------------------*/
// Function: getYcoord
// Description: Adjusts for 0 array start
/*---------------------------------------------------------------------------------*/
int Critter::getYcoord() {	
	return critYcoord;
}
int Critter::getMoveCount() {
	return moveCount;
}
char Critter::getCritterIcon() {
	return critterIcon;
}
bool Critter::getSquashed() {
	return squashed;
}

//Setters
void Critter::incMoveCount() {
	moveCount++;
}
void Critter::setCritXcoord(int xCo){
	int xTemp = xCo; //Adjust for Array
	critXcoord = xTemp;
}
void Critter::setCritYcoord(int yCo){
	int yTemp = yCo;
	critYcoord = yTemp;
}
void Critter::setSquashed(bool squashState) {
	squashed = squashState;
}

/*---------------------------------------------------------------------------------*/
// Function: randStartPosition
// Description: Generates random start position
/*---------------------------------------------------------------------------------*/
void Critter::randStartPosition(int xSize, int ySize) {
	std::uniform_int_distribution<int> posX(1, xSize);
	std::uniform_int_distribution<int> posY(1, ySize);
	int positX = posX(engine);
	int positY = posY(engine);
	setCritXcoord(positX);
	setCritYcoord(positY);
}