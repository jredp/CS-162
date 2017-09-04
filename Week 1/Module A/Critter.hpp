//////////////////// ** Author: Jared Parkinson 
//   Critter.hpp  // *** Date: 4/1/2016
//////////////////// **** Desc: Module A Week 1

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <stdlib.h>
#include <time.h>

class Critter
{
private:
	int moveCount; //Moves Made
	char critterIcon; //Critter Display
	int critXcoord; //xCoord position
	int critYcoord; //yCoord position
	bool squashed; //Is it squashed?
public:
	Critter(); //Create Critter Object, Default Constructor	
	int randMoveDirection(); //Random direction to move. up,down,left,right
	bool validSize(int size);
	//Getters
	int getXcoord();
	int getYcoord();
	int getMoveCount();
	char getCritterIcon();
	bool getSquashed();
	//Setters
	void incMoveCount();
	void randStartPosition(int sizeX, int sizeY);
	void setCritXcoord(int x);
	void setCritYcoord(int y);
	void setSquashed(bool squashed);
};

#endif