  //////////////////// ** Author: Jared Parkinson 
 //   ANT.hpp      // *** Date: 4/10/2016
//////////////////// **** Desc: Assignment 1

#ifndef ANT_HPP
#define ANT_HPP

#include <stdlib.h>
#include <time.h>

class Ant
{
private:
	int antXcoord; //xCoord position
	int antYcoord; //yCoord position	
	int antDirection; //Store Direction
	bool onBlack; //Store the square that Ant is on / set or not set
public:
	Ant(); //Create Ant Object, Default Constructor	
	//Getters
	int getXcoord();
	int getYcoord();
	int getAntDir(); //Get direction 1 up, 2 right, 3 down, 4 left
	bool getOnBlack();
	//Setters	
	void setAntXcoord(int x);
	void setAntYcoord(int y);
	void setOnBlack(bool square);
	void setAntDir(int dir);
    //Helper Function
	void randStartGenerate(int sizeX, int sizeY); //Choose random start position, set it
};

#endif