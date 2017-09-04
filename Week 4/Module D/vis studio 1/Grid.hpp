//////////////////// ** Author: Jared Parkinson 
//    Grid.hpp    // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#ifndef GRID_HPP
#define GRID_HPP

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

//#include <unistd.h> //Linux Sleep
#include <windows.h> //Windows Sleep

class Grid {
private:
	int gridXsize; //Grid row size
	int gridYsize; //Grid col size	
	Critter ***gridOfCritters; // Grid made up of Pointers to Critters	
	int starveCount; //Count of Staves this round
	void printGrid(int x, int y); //Print Grid
	void clearCritHasMoved(); //Clear hasMoved flag on all Critters after a desired run		
	void clearStarved(int x, int y); //Clear starved
	bool checkGridFull(); //Check if Grid is full	
	//Moves
	void moveUp(int currentX, int currentY); //Move Up X Axis -1
	void moveDown(int currentX, int currentY); //Move Down X Axis +1	
	void moveLeft(int currentX, int currentY); //Move Left Y Axis -1
	void moveRight(int currentX, int currentY); //Move Right Y Axis +1

public:
	Grid(int x, int y, int desiredAnts, int desiredDbugs, int desiredRuns);
	~Grid();
	Critter*** createGridArray(int xHeight, int yWidth); //Dynamic 2D array	
	void randStartPosition(int desiredCritters, int classType); //Generate Random Start Position and new Critter, place pointer in Grid	
	void cycleRuns(int desiredRuns); //Call Critter updateLocation and move if possible
};

#endif