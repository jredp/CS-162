//////////////////// ** Author: Jared Parkinson 
//    Grid.cpp    // *** Date: 4/1/2016
//////////////////// **** Desc: Module A Week 1

#include <iostream>
#include <random>
#include <memory>
#include "Grid.hpp"

using std::cout;

/*---------------------------------------------------------------------------------*/
// Description: Constructor - Creates Array, Initialize xSize/ySize	
/*---------------------------------------------------------------------------------*/
Grid::Grid(int xHeight, int yWidth) //10x10
{
	gridArray = createGridArray(xHeight, yWidth);
	gridXsize = xHeight;
	gridYsize = yWidth;
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
// Function: validMovement
// Description: Is the Critter move valid? Checks grid edges for valid move.
/*------------------------------------------------------------------------------*/
bool Grid::validMovement(int currentCritX, int currentCritY, int proposedDir) {	
	bool valid = true;
	//Later will need to pass Critter objects in array
	if (proposedDir == 1) {
		int propX = currentCritX; 		
		propX--;					
			if (propX < 1) valid = false; //Check Move Valid
	}
	else if (proposedDir == 2){
		int propY = currentCritY;
		propY++;
			if (propY > gridYsize) valid = false; //Check Move Valid
	}
	else if (proposedDir == 3){
		int propX = currentCritX;
		propX++;
			if (propX > gridXsize) valid = false; //Check Move Valid			
	}
	else if (proposedDir == 4){
		int propY = currentCritY;
		propY--;
			if (propY < 1) valid = false; //Check Move Valid
	}	
	return valid;
}

/*------------------------------------------------------------------------------*/
// Function: setStartCritterGrid
// Description: Initial random Critter Start Location
/*------------------------------------------------------------------------------*/
void Grid::setStartCritterGrid(Critter &critObj) {
	char c = critObj.getCritterIcon(); // Get Critter Icon	
	fillGrid(gridXsize, gridYsize); //Clear C from Grid
	critObj.randStartPosition(gridXsize, gridYsize);
	int posX = critObj.getXcoord();
	int posY = critObj.getYcoord();
	critObj.setCritXcoord(posX);	
	critObj.setCritYcoord(posY);
	gridArray[posX-1][posY-1] = c;	// Place Critter - Array offset	
}

/*------------------------------------------------------------------------------*/
// Function: placeCritterGrid
// Description: Places Critter Icon on Grid after valid move, or squashes Critter
// Does not fire if move invalid
/*------------------------------------------------------------------------------*/
void Grid::placeCritterGrid(Critter critObj, int x, int y) {
	char c = critObj.getCritterIcon(); //Get Critter Icon	
	fillGrid(gridXsize, gridYsize); //Clear C from Grid
	gridArray[x - 1][y - 1] = c;	//Place Critter - Array offset		
	critObj.incMoveCount(); //Increment Move Count
	printGrid(gridXsize, gridYsize);	
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
	char filler = '.'; // Char to set blanks (was 0)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			gridArray[i][j] = filler; // Init array to be -
		}
	}
}

/*------------------------------------------------------------------------------*/
// Function: printGrid
// Description: Prints out contents of the "Grid"
/*------------------------------------------------------------------------------*/
void Grid::printGrid(int row, int col) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			std::cout << gridArray[i][j] << " ";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

/*------------------------------------------------------------------------------*/
// Function: updateLocation
// Description: updates Critter Location 1 move at a time using random direction
// Pre-Conditions: x > 0, y > 0
/*------------------------------------------------------------------------------*/
void Grid::updateLocation(Critter &critObject)
{
	//Store Critter Location	
	int cLocationX = critObject.getXcoord();
	int cLocationY = critObject.getYcoord();	
	//bool squashed = critObject.getSquashed();

	//Do if Critter is on Grid
		while ((cLocationX >= 1 && cLocationX <= gridXsize) && (cLocationY >= 1 && cLocationY <= gridYsize) && critObject.getSquashed()==false) {
		//Get direction
		int direction = critObject.randMoveDirection();
		bool valid = validMovement(cLocationX, cLocationY, direction);

		if (valid == true) {
			if (direction == 1) {
				cLocationX--; //move 1 up = x-1
				critObject.setCritXcoord(cLocationX); //Set Crit Obj xLoc			
			}
			else if (direction == 2) {
				cLocationY++; //move 1 right = y+1
				critObject.setCritYcoord(cLocationY); //Set Crit Obj yLoc			
			}
			else if (direction == 3) {
				cLocationX++; //move 1 down = x+1			
				critObject.setCritXcoord(cLocationX); //Set Crit Obj xLoc			
			}
			else {
				cLocationY--; // Dir = 4 / Move 1 left = y-1
				critObject.setCritYcoord(cLocationY); //Set Crit Obj yLoc			
			}
			//Update Move Count, Place Critter
			critObject.incMoveCount(); //Increment Move Count
			placeCritterGrid(critObject, cLocationX, cLocationY);
		}
		else {
			critObject.setSquashed(true);
			critObject.incMoveCount(); //Increment Move Count
			int moves = critObject.getMoveCount(); //Get Move Count
			std::cout << "CRITTER SQUASHED! " << "         Move Count: " << moves << std::endl;
		}
		
	}
		
}