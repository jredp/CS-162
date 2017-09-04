  //////////////////// ** Author: Jared Parkinson 
 //    Grid.cpp    // *** Date: 4/10/2016
//////////////////// **** Desc: Assignment 1

#include <iostream>
#include <random>
#include <memory>
#include "Grid.hpp"

using std::cout;

/*---------------------------------------------------------------------------------*/
// Description: Constructor - Creates Array, Initialize xSize/ySize	
/*---------------------------------------------------------------------------------*/
Grid::Grid(int xHeight, int yWidth, int desiredRuns) {
	gridArray = createGridArray(xHeight, yWidth);
	gridXsize = xHeight;
	gridYsize = yWidth;
	desiredMoves = desiredRuns; //Set program run length
	fillGrid(xHeight, yWidth); //Fill it with White Squares
}
/*---------------------------------------------------------------------------------*/
// Description: Destructor - Clears Memory
/*---------------------------------------------------------------------------------*/
Grid::~Grid() {
	for (int i = 0; i<gridXsize; i++)
		delete [] gridArray[i]; // Delete each element of Array
	delete [] gridArray; // Delete the array
}
/*------------------------------------------------------------------------------*/
// Function: setRandStartAntGrid
// Description: Initial random Ant Start Location
/*------------------------------------------------------------------------------*/
void Grid::setRandStartAntGrid(Ant &antObj) {
	char ant = '*'; // Get Ant Icon	
	antObj.randStartGenerate(gridXsize, gridYsize);
	int posX = antObj.getXcoord();
	int posY = antObj.getYcoord();
	antObj.setAntXcoord(posX);
	antObj.setAntYcoord(posY);	
	gridArray[posX-1][posY-1] = ant;	// Place Ant - Array offset	
}
/*------------------------------------------------------------------------------*/
// Function: setUserStartAntGrid
// Description: Initial random Ant Start Location
/*------------------------------------------------------------------------------*/
void Grid::setUserStartAntGrid(Ant &antObj, int desiredX, int desiredY) {
	char ant = '*'; // Get Ant Icon		
	int posX = desiredX;
	int posY = desiredY;
	antObj.setAntXcoord(posX);
	antObj.setAntYcoord(posY);
	gridArray[posX - 1][posY - 1] = ant;	// Place Ant - Array offset	
}
/*------------------------------------------------------------------------------*/
// Function: getChar
// Description: gets square at this location.
// Usage: can get ahead square
/*------------------------------------------------------------------------------*/
char Grid::getChar(int x, int y) {
	int setX = x;
	int setY = y;
	setX--;
	setY--;
	char returnChar = gridArray[setX][setY];
	return returnChar;
}
/*------------------------------------------------------------------------------*/
// Function: placeAntGrid
// Description: Places Ant on Grid
// Does not fire if move invalid
/*------------------------------------------------------------------------------*/
void Grid::placeAntGrid(int x, int y) {
	char ant = '*';
	int setX = x;
	int setY = y;
	setX--;
	setY--;
	gridArray[setX][setY] = ant;	//Place Ant - Array offset		
}
/*------------------------------------------------------------------------------*/
// Function: updPrevGridSquare
// Description: updates previous square to set # or white .
/*------------------------------------------------------------------------------*/
void Grid::updPrevGridSquare(bool onBlack, int x, int y) {
	char black = '#';
	char white = '.';
	int antX = x;
	int antY = y;
	antX--;
	antY--;
    if (onBlack == true) {
		gridArray[antX][antY] = white;
    }	
	else {
		gridArray[antX][antY] = black;
	}
}
/*------------------------------------------------------------------------------*/
// Function: createGridArray
// Description: Returns Pointer to new 2d array size [height x width]
// Pre-Conditions: x > 0, y > 0
/*------------------------------------------------------------------------------*/
char** Grid::createGridArray(int xHeight, int yWidth) {
	char **tempGrid;
	tempGrid = new char*[xHeight]; // Create y Cols		
	for (int i = 0; i < xHeight; i++) {
		tempGrid[i] = new char[yWidth]; // Create x Rows in y Cols				
	}	
	return tempGrid; // Return the array
}
/*------------------------------------------------------------------------------*/
// Function: fillGrid
// Description: Fills grid with x's
// Parameters: Rows, Columns
/*------------------------------------------------------------------------------*/
void Grid::fillGrid(int row, int col)	{
	char filler = '.'; // Char to set blanks (White Squares)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			gridArray[i][j] = filler; // Init array to be
		}
	}
}
/*------------------------------------------------------------------------------*/
// Function: printGrid
// Description: Prints out contents of the "Grid"
/*------------------------------------------------------------------------------*/
void Grid::printGrid(int row, int col) {
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			std::cout << gridArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
    //Clear screen
	unsigned int pause(5000);
	cout << "\033[2J\033[1;1H";
	usleep(pause);	     
}
/*------------------------------------------------------------------------------*/
// Function: turnAnt()
// Description: sets direction based on char ahead Ant is moving to
//              Also updates onBlack of antObj
/*------------------------------------------------------------------------------*/
void Grid::turnAnt(Ant &antObj, char passed) {
	//Turn Right
	if (passed == '#') {
		int dir = antObj.getAntDir();
		antObj.setOnBlack(true); //update onBlack to Black
		if (dir == 4) antObj.setAntDir(1); //Fix when on 4
		else {
			int dirPlus = dir;
			dirPlus++; //Turn Right
			antObj.setAntDir(dirPlus);
		}
	}
	//Turn Left
	else {
		int dir = antObj.getAntDir();
		antObj.setOnBlack(false); //update onBlack to White
		if (dir == 1) antObj.setAntDir(4); //Fix when on 1
		else {
			int dirPlus = dir;
			dirPlus--; //Turn Left
			antObj.setAntDir(dirPlus);
		}
	}
}
/*------------------------------------------------------------------------------*/
// Function: makeMoves
// Description: updates Ant Location 1 move at a time using random direction
// Pre-Conditions: x > 0, y > 0
/*------------------------------------------------------------------------------*/
void Grid::makeMoves(Ant &antObject)
{
	//While desiredMoves not met, do below
	for (int movesMade = 0; movesMade < desiredMoves; movesMade++) {
		int antLocX = antObject.getXcoord();//Store Ant Location
		int antLocY = antObject.getYcoord();
		int curAntDirection = antObject.getAntDir();//Store Ant Direction		
		moveAntNoEdge(antObject, antLocX, antLocY, curAntDirection);		
		printGrid(gridXsize, gridYsize); //Print each moveMade
		int runs = movesMade;
		runs++; //Increment Runs
		std::cout << "Runs: " << runs << std::endl;
	}
}
/*------------------------------------------------------------------------------*/
// Function: moveAntNoEdge
// Description: Moves Ant 1 space if not on edge
/*------------------------------------------------------------------------------*/
void Grid::moveAntNoEdge(Ant &antObj, int antX, int antY, int direc) {
	int antXprop = antX;
	int antYprop = antY;	
	char forwardChar;
	bool onBlack = antObj.getOnBlack();
    /*-------------X Axis--------------*/
    if (direc == 1) {        	
        antXprop--; //move temp 1 up = x-1
		if (antXprop < 1) antXprop = gridXsize; //If ant going off grid		
		else{} //else leave as is
		forwardChar = getChar(antXprop, antY); //Store char at proposed location		
		updPrevGridSquare(onBlack, antX, antY); //Update previous grid char		
        placeAntGrid(antXprop, antY);//place ant new loc
		    antObj.setAntXcoord(antXprop); //Set ant X location				
		turnAnt(antObj, forwardChar); //turn ant based on forwardChar stored / update onBlack bool
	}
	else if (direc == 3) {
		antXprop++; //move 1 down = x+1	
		if (antXprop > gridXsize) antXprop = 1;
		forwardChar = getChar(antXprop, antY); //Store char at proposed location		
		updPrevGridSquare(onBlack, antX, antY); //Update previous grid char		
		placeAntGrid(antXprop, antY);//place ant new loc
		antObj.setAntXcoord(antXprop); //Set ant X location				
		turnAnt(antObj, forwardChar); //turn ant based on forwardChar stored / update onBlack bool
	}
	/*-------------Y Axis--------------*/
	else if (direc == 2) {
		antYprop++; //move 1 right = y+1
		if (antYprop > gridYsize) antYprop = 1;
		forwardChar = getChar(antX, antYprop); //Store char at proposed location		
		updPrevGridSquare(onBlack, antX, antY); //Update previous grid char		
		placeAntGrid(antX, antYprop);//place ant new loc
		antObj.setAntYcoord(antYprop); //Set ant X location				
		turnAnt(antObj, forwardChar); //turn ant based on forwardChar stored / update onBlack bool
	}	
	else {
		antYprop--; // Dir = 4 / Move 1 left = y-1
		if (antYprop < 1) antYprop = gridYsize; //If ant going off grid		
		else{} //else leave as is
		forwardChar = getChar(antX, antYprop); //Store char at proposed location		
		updPrevGridSquare(onBlack, antX, antY); //Update previous grid char		
		placeAntGrid(antX, antYprop);//place ant new loc
		antObj.setAntYcoord(antYprop); //Set ant X location				
		turnAnt(antObj, forwardChar); //turn ant based on forwardChar stored / update onBlack bool
	}	
}