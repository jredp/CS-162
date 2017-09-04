//////////////////// ** Author: Jared Parkinson 
//    Grid.hpp    // *** Date: 4/1/2016
//////////////////// **** Desc: Module A Week 1

#ifndef GRID_HPP
#define GRID_HPP

#include "Critter.hpp"

class Grid
{
private:
	int gridXsize; //Grid row size
	int gridYsize; //Grid col size	
	char **gridArray; //Grid
	void printGrid(int x, int y); //Print Grid
	void placeCritterGrid(Critter critObj, int x, int y); //Critter Movement
	bool validMovement(int critCurrentX, int critCurrentY, int direction); //Is the move valid?

public:
	Grid(int x, int y);
	~Grid();	
	char** createGridArray(int xHeight, int yWidth); //Dynamic 2D array					
	void setStartCritterGrid(Critter &critObj);
	void updateLocation(Critter &critObj); //Move critter 1 space, update critter, clean critter	
	void fillGrid(int x, int y); //fill the Grid with movement spaces					
};

#endif
