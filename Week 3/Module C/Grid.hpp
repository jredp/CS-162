//////////////////// ** Author: Jared Parkinson 
//    Grid.hpp    // *** Date: 4/16/2016
//////////////////// **** Desc: modC

#ifndef GRID_HPP
#define GRID_HPP

#include "Critter.hpp"
#include "Ant.hpp"
#include <unistd.h> //Linux Sleep
//#include <windows.h> //Windows Sleep

class Grid {
private:
	int gridXsize; //Grid row size
	int gridYsize; //Grid col size	
	Ant ***gridOfCritters; // Grid made up of Pointers to Critters	
	void printGrid(int x, int y); //Print Grid
	void clearCritHasMoved(); //Clear hasMoved flag on all Critters after a desired run	
	bool checkGridFull();
	void moveXaxis(int currentX, int currentY, int direction); //X Axis    	
	void moveYaxis(int currentX, int currentY, int direction); //Y Axis

public:
	Grid(int x, int y, int desiredCritters, int desiredRuns);
	~Grid();
	Ant*** createGridArray(int xHeight, int yWidth); //Dynamic 2D array	
	void randStartPosition(int desiredCritters); //Generate Random Start Position and new Critter, place pointer in Grid	
	void cycleRuns(int desiredRuns); //Call Critter updateLocation and move if possible
};

#endif