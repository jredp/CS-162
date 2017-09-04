  //////////////////// ** Author: Jared Parkinson 
 //    Grid.hpp    // *** Date: 4/10/2016
//////////////////// **** Desc: Module A Week 1

#ifndef GRID_HPP
#define GRID_HPP

#include <string>
#include <unistd.h>
#include "Ant.hpp"

class Grid
{
private:
	int gridXsize; //Grid row size
	int gridYsize; //Grid col size
	int desiredMoves; //User Defined	
	char **gridArray; //2D char array
	void printGrid(int x, int y); //Print Grid
	void fillGrid(int x, int y); //fill the Grid with blank squares
	void placeAntGrid(int x, int y); //Ant Movement	
	void moveAntNoEdge(Ant &antObj, int antX, int antY, int direc); //Move Ant, edge doesn't matter	
	void updPrevGridSquare(bool onBlack, int antX, int antY); //Update previous grid square
	char getChar(int x, int y); //get Char at this location
	void turnAnt(Ant &antObj, char passedChar); //Turn ant based on Char passed

public:
	Grid(int x, int y, int desiredRuns);
	~Grid();
	char** createGridArray(int xHeight, int yWidth); //Dynamic 2D array    
    //Setter
    void setUserStartAntGrid(Ant &antObj, int chosenX, int chosenY);
	void setRandStartAntGrid(Ant &antObj);
    //Helper
	void makeMoves(Ant &antObj); //Move Ant 1 space, update Ant location, direction		
};

#endif
