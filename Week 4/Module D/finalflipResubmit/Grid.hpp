//////////////////// ** Author: Jared Parkinson 
//    Grid.hpp    // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#ifndef GRID_HPP
#define GRID_HPP

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include <unistd.h> //Linux Sleep
//#include <windows.h> //Windows Sleep

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
	bool edgeOffX(int propX); //Check Grid Edge X
	bool edgeOffY(int propY); //Check Grid Edge Y

	//NEW Functions-----------------------------------
	void DoodMoveAntInSlotX(int curX, int curY, int propX); //Doodlebug move into Ant
	void DoodMoveAntInSlotY(int curX, int curY, int propY); //Doodlebug move into Ant
	void MoveEmptySlotX(int curX, int curY, int propX); //Move into an Empty Slot	
	void MoveEmptySlotY(int curX, int curY, int propY); //Move into an Empty Slot
	void CannotMoveEdge(int curX, int curY); //Cannot move at edge actions
	void CannotMoveDoodle(int curX, int curY); //Cannot move at edge actions	
	//Moves
	void moveUpDown(int currentX, int currentY, int dir); //Move Up or Down X
	void moveLeftRight(int currentX, int currentY, int dir); //Move Left or Right Y	
	//NEW Functions-----------------------------------
	

public:
	Grid(int x, int y, int desiredAnts, int desiredDbugs, int desiredRuns);
	~Grid();
	Critter*** createGridArray(int xHeight, int yWidth); //Dynamic 2D array	
	void randStartPosition(int desiredCritters, int classType); //Generate Random Start Position and new Critter, place pointer in Grid	
	void cycleRuns(int desiredRuns); //Call Critter updateLocation and move if possible
};

#endif