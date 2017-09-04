//////////////////// ** Author: Jared Parkinson 
//    Grid.hpp    // *** Date: 4/10/2016
//////////////////// **** Desc: modB week2

#ifndef GRID_HPP
#define GRID_HPP

#include "Critter.hpp"
#include <unistd.h> //Linux Sleep
//#include <windows.h> //Windows Sleep

class Grid {
private:
	int gridXsize; //Grid row size
	int gridYsize; //Grid col size	
	Critter ***gridOfCritters; // Grid made up of Pointers to Critters
	void printGrid(int x, int y); //Print Grid
	void clearCritHasMoved(); //Clear hasMoved flag on all Critters after a desired run

	//Move Functions	
	void moveXaxis(int currentX, int currentY, int direction); //Move Up - X Axis    	
	void moveYaxis(int currentX, int currentY, int direction); //Move Up - X Axis

public:
	Grid(int x, int y, int desiredCritters, int desiredRuns);
	~Grid();
	Critter*** createGridArray(int xHeight, int yWidth); //Dynamic 2D array	
	void randStartPosition(int desiredCritters); //Generate Random Start Position and new Critter, place pointer in Grid	
	void cycleGrid(int desiredRuns); //Call Critter updateLocation and move if possible
};

#endif