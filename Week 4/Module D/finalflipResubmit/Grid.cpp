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
	delete gridOfCritters[x][y]; //Kill this Critter slot
	gridOfCritters[x][y] = NULL; //Free Pointer	
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
						/*-------------------------MOVE FUNC--------------------------------*/
						int move = gridOfCritters[i][j]->move(); //Call Critter Move Function
						/*-------------------------MOVE FUNC--------------------------------*/
						if (move == 1) moveUpDown(i, j, 1); //X Axis
						else if (move == 2) moveLeftRight(i, j, 2); //Y Axis
						else if (move == 3) moveUpDown(i, j, 3); //X Axis
						else moveLeftRight(i, j, 4); //Y Axis - Direction 4												
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
// Functions: edgeCheckX 
// Description: Check for Grid Edge X Axis
/*------------------------------------------------------------------------------*/
bool Grid::edgeOffX(int propX) {
	bool edgeOff = false;
	if (propX < 0) edgeOff = true;
	else if (propX >= gridXsize) edgeOff = true;
	return edgeOff;
}
/*------------------------------------------------------------------------------*/
// Functions: edgeCheckY
// Description: Check for Grid Edge Y Axis
/*------------------------------------------------------------------------------*/
bool Grid::edgeOffY(int propY) {
	bool edgeOff = false;
	if (propY < 0) edgeOff = true;
	else if (propY >= gridYsize) edgeOff = true;
	return edgeOff;
}
/*------------------------------------------------------------------------------*/
// Functions: DoodMoveAntInSlotX
// Description: Doodlebug moves into an Ant slot X Axis
/*------------------------------------------------------------------------------*/
void Grid::DoodMoveAntInSlotX(int curX, int curY, int propX) {
	//Copy Pointer
	delete gridOfCritters[propX][curY]; //Kill Ant
	gridOfCritters[propX][curY] = gridOfCritters[curX][curY]; //Overwrite Slot (EAT)
	gridOfCritters[curX][curY] = NULL; //Free Old Pointer
	//Check Breed
	if (gridOfCritters[propX][curY]->checkBreed() == true){		
		gridOfCritters[curX][curY] = gridOfCritters[propX][curY]->Breed(); //Breed
	}	
	gridOfCritters[propX][curY]->setHasMoved(true); //Set Critter hasMoved to true					
	gridOfCritters[propX][curY]->incMoves(); //Increase moves made
	gridOfCritters[propX][curY]->Eat(); //Mark eaten, reset moves, no starve check					
}
/*------------------------------------------------------------------------------*/
// Functions: DoodMoveAntInSlotY
// Description: Doodlebug moves into an Ant slot Y Axis
/*------------------------------------------------------------------------------*/
void Grid::DoodMoveAntInSlotY(int curX, int curY, int propY) {
	//Copy Pointer
	delete gridOfCritters[curX][propY]; //Kill Ant
	gridOfCritters[curX][propY] = gridOfCritters[curX][curY]; //Copy Pointer at this slot
	gridOfCritters[curX][curY] = NULL; //Free Old Pointer
	//Check Breed
	if (gridOfCritters[curX][propY]->checkBreed() == true) {		
		gridOfCritters[curX][curY] = gridOfCritters[curX][propY]->Breed(); //Breed
	}	
	gridOfCritters[curX][propY]->setHasMoved(true); //Set Critter hasMoved to true					
	gridOfCritters[curX][propY]->incMoves(); //Increase moves made
	gridOfCritters[curX][propY]->Eat(); //Mark eaten, reset moves, no starve check
}
/*------------------------------------------------------------------------------*/
// Functions: MoveEmptySlotX
// Description: Move into Empty Slot X Axis
/*------------------------------------------------------------------------------*/
void Grid::MoveEmptySlotX(int curX, int curY, int propX) {
	Doodlebug *propDB;		
	//Copy Pointer
	gridOfCritters[propX][curY] = gridOfCritters[curX][curY]; //Copy Pointer at this slot
	gridOfCritters[curX][curY] = NULL; //Free old Pointer
	//Check Breed
	if (gridOfCritters[propX][curY]->checkBreed() == true) {		
		gridOfCritters[curX][curY] = gridOfCritters[propX][curY]->Breed(); //Breed
	}
	gridOfCritters[propX][curY]->setHasMoved(true); //Set Critter hasMoved to true
	gridOfCritters[propX][curY]->incMoves(); //Increase moves made
	if (gridOfCritters[propX][curY]->getIcon() == '#') {		
		gridOfCritters[propX][curY]->incMovNoEat(); //Increase moves w/o eating
		propDB = static_cast<Doodlebug *>(gridOfCritters[propX][curY]); //Static Cast to use Starve	
		propDB->Starve(); //Set Starved
		if (propDB->getStarved()) clearStarved(propX, curY), starveCount++; //Kill starved
	}	
	propDB = NULL; //Null Temp Pointer		
}
/*------------------------------------------------------------------------------*/
// Functions: MoveEmptySlotY
// Description: Move into Empty Slot Y Axis
/*------------------------------------------------------------------------------*/
void Grid::MoveEmptySlotY(int curX, int curY, int propY) {
	Doodlebug *propDB;	
	//Copy Pointer
	gridOfCritters[curX][propY] = gridOfCritters[curX][curY]; //Copy Pointer to this slot	
	gridOfCritters[curX][curY] = NULL; //Null last Critter Pointer
	//Check Breed
	if (gridOfCritters[curX][propY]->checkBreed() == true) {		
		gridOfCritters[curX][curY] = gridOfCritters[curX][propY]->Breed(); //Breed
	}
	gridOfCritters[curX][propY]->setHasMoved(true); //Set Critter hasMoved to true
	gridOfCritters[curX][propY]->incMoves(); //Increase moves made
	if (gridOfCritters[curX][propY]->getIcon() == '#') {			
		gridOfCritters[curX][propY]->incMovNoEat();
		propDB = static_cast<Doodlebug *>(gridOfCritters[curX][propY]); //Static Cast use Starve
		propDB->Starve(); //Set Starved
		if (propDB->getStarved()) clearStarved(curX, propY), starveCount++; //Kill starved
	}	
	propDB = NULL; //Null Temp Pointer
}
/*------------------------------------------------------------------------------*/
// Functions: CannotMoveEdge
// Description: If Critter cannot move over Edge
/*------------------------------------------------------------------------------*/
void Grid::CannotMoveEdge(int curX, int curY) {
	Doodlebug *curDB; //Doodlebug Pointers for Static Cast
	curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve
	
	gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move		
	if (gridOfCritters[curX][curY]->getIcon() == '#') {		
		gridOfCritters[curX][curY]->incMovNoEat(); //Increase moves w/o eating
		curDB->Starve(); //Set Starved
		if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill starved
	}	
	curDB = NULL; //NULL temp pointer
}
/*------------------------------------------------------------------------------*/
// Functions: CannotMoveDoodle
// Description: If Critter cannot move over Doodlebug
/*------------------------------------------------------------------------------*/
void Grid::CannotMoveDoodle(int curX, int curY) {
	Doodlebug *curDB; //Doodlebug Pointers for Static Cast
	curDB = static_cast<Doodlebug *>(gridOfCritters[curX][curY]); //Static Cast use Starve

	gridOfCritters[curX][curY]->incMoves(); //Increase moves made even though didn't move
	gridOfCritters[curX][curY]->incMovNoEat(); //Increase moves w/o eating
	curDB->Starve(); //Set Starve
	if (curDB->getStarved()) clearStarved(curX, curY), starveCount++; //Kill Starve
	curDB = NULL; //NULL temp pointer
}
/*------------------------------------------------------------------------------*/
// Functions: moveUpDown
// Description: moves the Critter up or down the x axis
/*------------------------------------------------------------------------------*/
void Grid::moveUpDown(int curX, int curY, int dir) {
	int propX = 0; //Init propX
	if (dir == 1) propX = (curX-1); //move 1 up = x-1
	else if (dir == 3) propX = (curX+1); //move 1 Down = x+1
	
	if (edgeOffX(propX)==false) { //If move is on Grid
		if (gridOfCritters[propX][curY] != NULL) { //Proposed slot has Critter			
			if (gridOfCritters[curX][curY]->getIcon() == '#') { //If slot is Doodlebug
				//If Next Slot Ant, eat it
				if (gridOfCritters[propX][curY]->getIcon() == '*') DoodMoveAntInSlotX(curX, curY, propX); //Predator Actions				
				else CannotMoveDoodle(curX, curY); //Else Next slot is Doodlebug, cycle
			}
			//Else cur slot is Ant, can't move, tick moves
			else gridOfCritters[curX][curY]->incMoves();
		}
		//Else if slot empty (NULL), simply move there		
		else MoveEmptySlotX(curX, curY, propX);
	}
	//Cannot move off Grid, no breed
	else CannotMoveEdge(curX, curY);
}

/*------------------------------------------------------------------------------*/
// Functions: moveLeftRight
// Description: moves the Critter left on Y axis
/*------------------------------------------------------------------------------*/
void Grid::moveLeftRight(int curX, int curY, int dir) {	
	int propY = 0; //Init propY
	if (dir == 4) propY = (curY - 1); //move 1 Left = y-1
	else if (dir == 2) propY = (curY + 1); //move 1 Right = y+1
	
	if (edgeOffY(propY) == false) { //If move is on Grid
		if (gridOfCritters[curX][propY] != NULL) { //Proposed slot has a Critter
			if (gridOfCritters[curX][curY]->getIcon() == '#') { //If current slot is Doodlebug
				//If Next Slot Ant, eat it
				if (gridOfCritters[curX][propY]->getIcon() == '*') DoodMoveAntInSlotY(curX, curY, propY); //Predator Actions
				else CannotMoveDoodle(curX, curY); //Else Next slot is Doodlebug, cycle
			}
			//Else cur slot is Ant, can't move, tick moves
			else gridOfCritters[curX][curY]->incMoves();
		}
		//Else if slot empty (NULL), simply move there		
		else MoveEmptySlotY(curX, curY, propY);
	}
	//Cannot move off Grid, no breed
	else CannotMoveEdge(curX, curY);
}