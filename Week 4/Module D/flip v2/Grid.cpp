//////////////////// ** Author: Jared Parkinson 
//    Grid.cpp    // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#include <iostream>
#include "Grid.hpp"

/*---------------------------------------------------------------------------------*/
// Description: Constructor - Creates Array, Initializes Grid xSize/ySize	
/*---------------------------------------------------------------------------------*/
Grid::Grid(int xHeight, int yWidth, int desiredAnts, int desiredDbugs, int desiredRuns) {
	gridOfCritters = createGridArray(xHeight, yWidth); //Create and NULL
	gridXsize = xHeight; //set Grid X
	gridYsize = yWidth; //set Grid Y	
	starveCount = 0;

	//Add Desired Critters
	randStartPosition(desiredAnts, 1); //Ants
	randStartPosition(desiredDbugs, 2); //Dbugs

	//Make Desired Runs of Program
	cycleRuns(desiredRuns);
}

/*---------------------------------------------------------------------------------*/
// Description: Destructor - Clears Memory
/*---------------------------------------------------------------------------------*/
Grid::~Grid() {
	for (int i = 0; i < gridXsize; ++i) {
		for (int j = 0; j < gridYsize; ++j) {
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
	std::cout << "\033[2J\033[1;1H";
	unsigned int pause(310000);
	usleep(pause);

	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {			
			if (gridOfCritters[i][j] != NULL) {				
				char curIcon = gridOfCritters[i][j]->getIcon();
				std::cout << curIcon << " ";				
			}
			//else print .
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
void Grid::randStartPosition(int desiredAmt, int classType) {	
	//Run this per desired critter
	for (int i = 0; i < desiredAmt; i++) {
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
				//classType: 1=Ant 2=Doodlebug
				if (classType == 1) gridOfCritters[randX][randY] = new Ant(); // Place new Ant adjust for Array
				if (classType == 2) gridOfCritters[randX][randY] = new Doodlebug(); // Place new Dbug adjust for Array
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
// Function: clearStarved
// Description: Clear the starved critter
/*------------------------------------------------------------------------------*/
void Grid::clearStarved(int x, int y) {	
	gridOfCritters[x][y] = NULL; //Kill this Critter slot	
}
/*------------------------------------------------------------------------------*/
// Function: checkGridFull
// Description: Check if the Grid is full of Critters
/*------------------------------------------------------------------------------*/
bool Grid::checkGridFull() {
	bool isFull = false;
	int gridCount = 0;
	int gridSize = gridXsize*gridYsize;
	for (int i = 0; i < gridXsize; i++) {
		for (int j = 0; j < gridYsize; j++) {
			if (gridOfCritters[i][j] != NULL) {
				gridCount++;
			}
		}
	}
	if (gridCount == gridSize) {
		isFull = true;
		std::cout << "The Grid is full! No more moves can be made." << std::endl;
	}
	return isFull;
}
/*------------------------------------------------------------------------------*/
// Function: cycleRuns
// Description: calls Critter Movement Function, updates if valid move
/*------------------------------------------------------------------------------*/
void Grid::cycleRuns(int desiredRuns) {
	int totalRuns = 0;
	//Run this until desired runs reached
	for (int b = 0; (b < desiredRuns) && (checkGridFull() == false); b++) {		
		for (int i = 0; i < gridXsize; i++) { //Cycle through array to check each slot
			for (int j = 0; j < gridYsize; j++) { //If slot !NULL
				if (gridOfCritters[i][j] != NULL) {
					if (gridOfCritters[i][j]->getHasMoved() == false) { //Check Moved
						int move = gridOfCritters[i][j]->move(); //Call Critter Move Function						
						if (move == 1) moveUp(i,j); //X Axis
						else if (move == 2) moveRight(i, j); //Y Axis
						else if (move == 3) moveDown(i, j); //X Axis						
						else moveLeft(i, j); //Y Axis - Direction 4						
					}
				} //If slot == NULL, ignore
			} //col cycle
		} //row cycle			
		clearCritHasMoved();
		printGrid(gridXsize, gridYsize);		
		totalRuns++;
		std::cout << "Runs Made: " << totalRuns << std::endl;
		std::cout << "Starve Count this run: " << starveCount << std::endl;
		starveCount = 0; //reset starve count
	} //Desired Runs	
}
/*------------------------------------------------------------------------------*/
// Functions: moveUp
// Description: moves the Critter up or down the x axis
/*------------------------------------------------------------------------------*/
void Grid::moveUp(int curX, int curY) {
	int propX = (curX-1); //move 1 up = x-1		
	Doodlebug *curDB, *propDB; //Doodlebug Pointers for Static Cast
		
	if (propX >= 0) { //If move is on Grid		
		if (gridOfCritters[propX][curY] != NULL) { //Proposed slot has Critter			
			if (gridOfCritters[curX][curY]->getIcon() == '#') { //If slot is Doodlebug
				curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve				
				if (gridOfCritters[propX][curY]->getIcon() == '*') { //If Next Slot Ant, eat it
					gridOfCritters[propX][curY] = gridOfCritters[curX][curY]; //Overwrite Slot
					gridOfCritters[curX][curY] = gridOfCritters[propX][curY]->Breed(); //Check Breed
					gridOfCritters[curX][curY] = NULL; //Null out prev slot
					gridOfCritters[propX][curY]->setHasMoved(true); //Set Critter hasMoved to true					
					gridOfCritters[propX][curY]->incMoves(); //Increase moves made
					gridOfCritters[propX][curY]->Eat(); //Mark eaten, reset moves, no starve check					
				}				
				else { //Else Next slot is Doodlebug //Do nothing
					gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move
					curDB->incMovNoEat(); //Increase moves w/o eating
					curDB->Starve(); //Set Starve
					if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill Starve
				}
			}			
			else gridOfCritters[curX][curY]->incMoves(); //Else cur slot is Ant, can't move
		}		
		else { //Else if slot empty (NULL), simply move there
			gridOfCritters[propX][curY] = gridOfCritters[curX][curY]; //Copy Pointer to this slot	
			gridOfCritters[curX][curY] = gridOfCritters[propX][curY]->Breed(); //Breed check current square
			gridOfCritters[propX][curY]->setHasMoved(true); //Set Critter hasMoved to true
			gridOfCritters[propX][curY]->incMoves(); //Increase moves made
			if (gridOfCritters[propX][curY]->getIcon() == '#') {
				propDB = static_cast<Doodlebug *>(gridOfCritters[propX][curY]); //Static Cast to use Starve
				propDB->incMovNoEat(); //Increase moves w/o eating
				propDB->Starve(); //Set Starved
				if (propDB->getStarved()) clearStarved(propX, curY), starveCount++; //Kill starved
			}
		}
	}	
	else { //Cannot move off Grid, no breed
		gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move		
		if (gridOfCritters[curX][curY]->getIcon() == '#') {
			curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve
			curDB->incMovNoEat(); //Increase moves w/o eating
			curDB->Starve(); //Set Starved
			if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill starved
		}
	}
}
/*------------------------------------------------------------------------------*/
// Functions: moveDown
// Description: moves the Critter up or down the x axis
/*------------------------------------------------------------------------------*/
void Grid::moveDown(int curX, int curY) {
	int propX = (curX + 1); //move 1 Down = x+1		
	Doodlebug *curDB, *propDB; //Doodlebug Pointers for Static Cast
	
	if (propX < gridXsize) { //If move is on Grid
		if (gridOfCritters[propX][curY] != NULL) { //Proposed slot has a Critter
			if (gridOfCritters[curX][curY]->getIcon() == '#') { //If slot is Doodlebug
				curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast to use Starve				
				if (gridOfCritters[propX][curY]->getIcon() == '*') { //Next Slot Ant, eat it
					gridOfCritters[propX][curY] = gridOfCritters[curX][curY]; //Overwrite Slot
					gridOfCritters[curX][curY] = gridOfCritters[propX][curY]->Breed(); //Check Breed
					gridOfCritters[curX][curY] = NULL; //Null out prev slot
					gridOfCritters[propX][curY]->setHasMoved(true); //Set Critter hasMoved to true					
					gridOfCritters[propX][curY]->incMoves(); //Increase moves made
					gridOfCritters[propX][curY]->Eat(); //Mark eaten, reset moves, no starve check					
				}				
				else { //Else Next slot is Doodlebug //Do nothing
					gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move
					curDB->incMovNoEat(); //Increase moves w/o eating
					curDB->Starve(); //Set Starve
					if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill Starved
				}
			}
			else gridOfCritters[curX][curY]->incMoves(); //Else cur slot is Ant, can't move
		}		
		else { //Else if slot empty (NULL), simply move
			gridOfCritters[propX][curY] = gridOfCritters[curX][curY]; //Copy Pointer to this slot	
			gridOfCritters[curX][curY] = gridOfCritters[propX][curY]->Breed(); //Breed check current square
			gridOfCritters[propX][curY]->setHasMoved(true); //Set Critter hasMoved to true
			gridOfCritters[propX][curY]->incMoves(); //Increase moves made
			if (gridOfCritters[propX][curY]->getIcon() == '#') {
				propDB = static_cast<Doodlebug *>(gridOfCritters[propX][curY]); //Static Cast use Starve
				propDB->incMovNoEat(); //Increase moves w/o eating
				propDB->Starve(); //Set Starved
				if (propDB->getStarved()) clearStarved(propX, curY), starveCount++; //Kill starved
			}
		}
	}	
	else { //Cannot move off Grid, no breed
		gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move		
		if (gridOfCritters[curX][curY]->getIcon() == '#') {
			curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve
			curDB->incMovNoEat(); //Increase moves w/o eating
			curDB->Starve(); //Set Starved
			if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill starved
		}
	}
}

/*------------------------------------------------------------------------------*/
// Functions: moveLeft
// Description: moves the Critter left on Y axis
/*------------------------------------------------------------------------------*/
void Grid::moveLeft(int curX, int curY) {	
	int propY = (curY - 1); //move 1 Left = y-1		
	Doodlebug *curDB, *propDB; //Doodlebug Pointers for Static Cast

	if (propY >= 0) { //If move is on Grid
		if (gridOfCritters[curX][propY] != NULL) { //Proposed slot has a Critter
			if (gridOfCritters[curX][curY]->getIcon() == '#') { //If slot is Doodlebug
				curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast to use Starve				
				if (gridOfCritters[curX][propY]->getIcon() == '*') { //Next Slot Ant, eat it
					gridOfCritters[curX][propY] = gridOfCritters[curX][curY]; //Overwrite Slot
					gridOfCritters[curX][curY] = gridOfCritters[curX][propY]->Breed(); //Check Breed
					gridOfCritters[curX][curY] = NULL; //Null out prev slot
					gridOfCritters[curX][propY]->setHasMoved(true); //Set Critter hasMoved to true					
					gridOfCritters[curX][propY]->incMoves(); //Increase moves made
					gridOfCritters[curX][propY]->Eat(); //Mark eaten, reset moves, no starve check					
				}
				else { //Else Next slot is Doodlebug //Do nothing
					gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move
					gridOfCritters[curX][curY]->incMovNoEat(); //Increase moves w/o eating
					curDB->Starve(); //Set Starve
					if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill Starved
				}
			}
			else gridOfCritters[curX][curY]->incMoves(); //Else cur slot is Ant, can't move
		}
		else { //Else if slot empty (NULL), simply move
			gridOfCritters[curX][propY] = gridOfCritters[curX][curY]; //Copy Pointer to this slot	
			gridOfCritters[curX][curY] = gridOfCritters[curX][propY]->Breed(); //Breed check current square
			gridOfCritters[curX][propY]->setHasMoved(true); //Set Critter hasMoved to true
			gridOfCritters[curX][propY]->incMoves(); //Increase moves made
			if (gridOfCritters[curX][propY]->getIcon() == '#') {
				propDB = static_cast<Doodlebug *>(gridOfCritters[curX][propY]); //Static Cast use Starve
				gridOfCritters[curX][propY]->incMovNoEat();
				propDB->Starve(); //Set Starved
				if (propDB->getStarved()) clearStarved(curX, propY), starveCount++; //Kill starved
			}
		}
	}
	else { //Cannot move off Grid, no breed
		gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move		
		if (gridOfCritters[curX][curY]->getIcon() == '#') {
			curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve
			curDB->incMovNoEat(); //Increase moves w/o eating
			curDB->Starve(); //Set Starved
			if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill starved
		}
	}
}
/*------------------------------------------------------------------------------*/
// Functions: moveRight
// Description: moves the Critter left on Y axis
/*------------------------------------------------------------------------------*/
void Grid::moveRight(int curX, int curY) {	
	int propY = (curY + 1); //move 1 Right = y+1		
	Doodlebug *curDB, *propDB; //Doodlebug Pointers for Static Cast

	if (propY < gridXsize) { //If move is on Grid
		if (gridOfCritters[curX][propY] != NULL) { //Proposed slot has a Critter
			if (gridOfCritters[curX][curY]->getIcon() == '#') { //If slot is Doodlebug
				curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast to use Starve				
				if (gridOfCritters[curX][propY]->getIcon() == '*') { //Next Slot Ant, eat it
					gridOfCritters[curX][propY] = gridOfCritters[curX][curY]; //Overwrite Slot
					gridOfCritters[curX][curY] = gridOfCritters[curX][propY]->Breed(); //Check Breed
					gridOfCritters[curX][curY] = NULL; //Null out prev slot
					gridOfCritters[curX][propY]->setHasMoved(true); //Set Critter hasMoved to true					
					gridOfCritters[curX][propY]->incMoves(); //Increase moves made
					gridOfCritters[curX][propY]->Eat(); //Mark eaten, reset moves, no starve check					
				}
				else { //Else Next slot is Doodlebug //Do nothing
					gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move
					curDB->incMovNoEat(); //Increase moves w/o eating
					curDB->Starve(); //Set Starve
					if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill Starved
				}
			}
			else gridOfCritters[curX][curY]->incMoves(); //Else cur slot is Ant, can't move
		}
		else { //Else if slot empty (NULL), simply move
			gridOfCritters[curX][propY] = gridOfCritters[curX][curY]; //Copy Pointer to this slot	
			gridOfCritters[curX][curY] = gridOfCritters[curX][propY]->Breed(); //Breed check current square
			gridOfCritters[curX][propY]->setHasMoved(true); //Set Critter hasMoved to true
			gridOfCritters[curX][propY]->incMoves(); //Increase moves made
			if (gridOfCritters[curX][propY]->getIcon() == '#') {
				propDB = static_cast<Doodlebug *>(gridOfCritters[curX][propY]); //Static Cast use Starve
				propDB->incMovNoEat(); //Increase moves w/o eating
				propDB->Starve(); //Set Starved
				if (propDB->getStarved()) clearStarved(curX, propY), starveCount++; //Kill starved
			}
		}
	}
	else { //Cannot move off Grid, no breed
		gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move		
		if (gridOfCritters[curX][curY]->getIcon() == '#') {
			curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve
			curDB->incMovNoEat(); //Increase moves w/o eating
			curDB->Starve(); //Set Starved
			if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill starved
		}
	}
}