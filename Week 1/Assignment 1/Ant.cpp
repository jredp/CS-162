  //////////////////// ** Author: Jared Parkinson
 //   Ant.cpp      // ** Date: 4/10/2016
//////////////////// ** Desc: Assignment 1

#include "Ant.hpp"
#include <random> //Randomizer
#include <memory> //For Random Memory Engine

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes data members
/*---------------------------------------------------------------------------------*/
Ant::Ant()
{
	Ant::antXcoord = 1; //Default to position 1
	Ant::antYcoord = 1; //Default to position 1	
	Ant::antDirection = 4; //Set Direction to Face Left by default
	Ant::onBlack = false; //Ant starts on White
}

//Getters
int Ant::getXcoord() {
	return antXcoord;
}
int Ant::getYcoord() {
	return antYcoord;
}
int Ant::getAntDir() {
	return antDirection;
}
bool Ant::getOnBlack() {
	return onBlack;
}
//Setters
void Ant::setAntXcoord(int xCo) {
	antXcoord = xCo; //Adjust for Array
	//antXcoord = xTemp;
}
void Ant::setAntYcoord(int yCo){
	antYcoord = yCo;
	//antYcoord = yTemp;
}
void Ant::setOnBlack(bool square){
	onBlack = square;
}
void Ant::setAntDir(int dir){
	antDirection = dir;
}

/*---------------------------------------------------------------------------------*/
// Function: randStartPosition
// Description: Generates random start position for Ant
// Prereq: taken care of with validation
/*---------------------------------------------------------------------------------*/
void Ant::randStartGenerate(int xSize, int ySize) {
	std::uniform_int_distribution<int> posX(1, xSize); //Between 1 and MaxX
	std::uniform_int_distribution<int> posY(1, ySize); //Between 1 and MaxY
	int positX = posX(engine);
	int positY = posY(engine);
	setAntXcoord(positX); //Set position
	setAntYcoord(positY);
}