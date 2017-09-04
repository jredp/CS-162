//////////////////// ** Author: Jared Parkinson 
//    Grid.cpp    // *** Date: 4/10/2016
//////////////////// **** Desc: modB week2

#include <iostream>
#include "Grid.hpp"

/*---------------------------------------------------------------------------------*/
// Description: Constructor - Creates Array, Initializes Grid xSize/ySize	
/*---------------------------------------------------------------------------------*/
Grid::Grid(int xHeight, int yWidth, int desiredCritters, int desiredRuns) {
	gridOfCritters = createGridArray(xHeight, yWidth); //Create and NULL
	gridXsize = xHeight; //set Grid X
	gridYsize = yWidth; //set Grid Y	

	//Add Desired Critters
	randStartPosition(desiredCritters);
	//Make Desired Runs of Program
	cycleGrid(desiredRuns);
}

/*---------------------------------------------------------------------------------*/
// Description: Destructor - Clears Memory
/*---------------------------------------------------------------------------------*/
Grid::~Grid() {
	for (int i = 0; i < gridXsize; ++i)
	{
		for (int j = 0; j < gridYsize; ++j)
		{
			delete gridOfCritters[i][j];
		}
		delete [] gridOfCritters[i];
	}
	delete [] gridOfCritters;
}
/*------------------------------------------------------------------------------*/
// Function: createGridArray
// Description: Returns Pointer to new 2d array size [height x width]
// Pre-Conditions: x > 0, y > 0
/*------------------------------------------------------------------------------*/
Critter*** Grid::createGridArray(int xRows, int yCols) {
	//New Grid of pointers to Critters
	Critter*** tempGrid;
	tempGrid = new Critter**[xRows];
	for (int i = 0; i < xRows; ++i) {
		tempGrid[i] = new Critter*[yCols];
	}
	//Initialize Pointers to NULLS
	for (int i = 0; i < xRows; ++i) {
		for (int j = 0; j < yCols; ++j) {
			tempGrid[i][j] = NULL;
		}
	}
	return tempGrid; // Return the array
}
/*------------------------------------------------------------------------------*/
// Function: printGrid
// Description: Prints out contents of the "Grid"
/*------------------------------------------------------------------------------*/
void Grid::printGrid(int row, int col) {
	//Sleep by OS	
		//Windows
		//Sleep(400);
		//system("CLS");

	//Linux
		cout << "\033[2J\033[1;1H";
		unsigned int pause(50000);
		usleep(pause);

	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			//If slot == NULL, print .
			if (gridOfCritters[i][j] != NULL) {
				std::cout << "C" << " ";
			}
			//else print C (critter)
			else {
				std::cout << "." << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;	
}
/*---------------------------------------------------------------------------------*/
// Function: randStartPosition
// Description: Generates random start position
/*---------------------------------------------------------------------------------*/
void Grid::randStartPosition(int desiredCritters) {
	//Run this per desired critter
	for (int i = 0; i < desiredCritters; i++) {
		//Iterate through array
		bool critterPlaced = false;
		while (critterPlaced == false) {
			std::uniform_int_distribution<int> posX(1, gridXsize); //1-maxX
			std::uniform_int_distribution<int> posY(1, gridYsize); //1-maxY
			int randX = posX(engine);
			int randY = posY(engine);
			randX--; //Array Adjust
			randY--;
			if (gridOfCritters[randX][randY] == NULL) {
				gridOfCritters[randX][randY] = new Critter(); // Place new Critter adjust for Array
				critterPlaced = true;
			}
		}
	}
}
/*------------------------------------------------------------------------------*/
// Function: clearCritHasMoved
// Description: Clear the Critter Object hasMoved flag
/*------------------------------------------------------------------------------*/
void Grid::clearCritHasMoved() {
	for (int i = 0; i < gridXsize; i++) {
		for (int j = 0; j < gridYsize; j++) {
			if (gridOfCritters[i][j] != NULL) {
				gridOfCritters[i][j]->setHasMoved(false);
			}
		}
	}
}
/*------------------------------------------------------------------------------*/
// Function: callCritters
// Description: calls Critter Movement Function, updates if valid move
/*------------------------------------------------------------------------------*/
void Grid::cycleGrid(int desiredRuns) {
	int totalRuns = 0;
	//Run this until desired runs reached
	for (int b = 0; b < desiredRuns; b++) {
		//Cycle through array to check each slot
		for (int i = 0; i < gridXsize; i++) {
			for (int j = 0; j < gridYsize; j++) {
				//If array slot is not NULL and critter hasnt moved, call Critter move
				if (gridOfCritters[i][j] != NULL) {
					if (gridOfCritters[i][j]->getHasMoved() == false) {
						int move = gridOfCritters[i][j]->updateLocation(); //Call Critter Move Function												
						//X Axis							
						if ((move == 1) || (move == 3)) {
							moveXaxis(i, j, move);
						}
						//Y Axis							
						else if ((move == 2) || (move == 4)) {
							moveYaxis(i, j, move);
						}
						else {} //Do not move anywhere		
					}
				} //If slot == NULL, ignore
			} //col cycle
		} //row cycle		
		printGrid(gridXsize, gridYsize);
		clearCritHasMoved();
		totalRuns++;
		std::cout << "Moves Made: " << totalRuns << std::endl;
	} //Desired Runs	
}
/*------------------------------------------------------------------------------*/
// Functions: moveXaxis
// Description: moves the Critter up or down the x axis
/*------------------------------------------------------------------------------*/
void Grid::moveXaxis(int currentX, int currentY, int direction) {
	int proposedX = currentX;	
	if (direction == 1) {
		proposedX--; //move 1 up = x-1 / proposedX
		if ((proposedX >= 0) && (gridOfCritters[proposedX][currentY] == NULL)) {
			gridOfCritters[proposedX][currentY] = gridOfCritters[currentX][currentY]; //Set Critter to this slot		
			gridOfCritters[proposedX][currentY]->setHasMoved(true); //Set Critter hasMoved to true		
			gridOfCritters[currentX][currentY] = NULL; //Set old slot to NULL	
		}
	}
	//Direction 3	
	else if (direction == 3) {
		proposedX++; //move 1 down = x+1 / proposedX
		if ((proposedX < gridXsize) && (gridOfCritters[proposedX][currentY] == NULL)) {
			gridOfCritters[proposedX][currentY] = gridOfCritters[currentX][currentY]; //Set Critter to this slot		
			gridOfCritters[proposedX][currentY]->setHasMoved(true); //Set Critter hasMoved to true		
			gridOfCritters[currentX][currentY] = NULL; //Set old slot to NULL	
		}
	}
	else{}
}
/*------------------------------------------------------------------------------*/
// Functions: moveYaxis
// Description: moves the Critter left or right on the y axis
/*------------------------------------------------------------------------------*/
void Grid::moveYaxis(int currentX, int currentY, int direction) {
	int proposedY = currentY;
	if (direction == 2) {
		proposedY++; //move 1 right = y+1 / proposedY
		if ((proposedY < gridYsize) && (gridOfCritters[currentX][proposedY] == NULL)) {
			gridOfCritters[currentX][proposedY] = gridOfCritters[currentX][currentY]; //Set Critter to this slot
			gridOfCritters[currentX][proposedY]->setHasMoved(true); //Set Critter hasMoved to true
			gridOfCritters[currentX][currentY] = NULL; //Set old slot to NULL	
		}
	}
	//Direction 4
	else if (direction == 4) {
		proposedY--; //move 1 left = y-1 / proposedY
		if ((proposedY >= 0) && (gridOfCritters[currentX][proposedY] == NULL)) {
			gridOfCritters[currentX][proposedY] = gridOfCritters[currentX][currentY]; //Set Critter to this slot
			gridOfCritters[currentX][proposedY]->setHasMoved(true); //Set Critter hasMoved to true
			gridOfCritters[currentX][currentY] = NULL; //Set old slot to NULL	
		}
	}
	else{}
}