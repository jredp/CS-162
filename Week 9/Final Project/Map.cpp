//////////////////// ** Author: Jared Parkinson 
//    Map.cpp     // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Map.hpp"

/*------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Generates Map on Creation
/*------------------------------------------------------------------------------*/
Map::Map() {
	player = new Player(); //Dynamic Player
	//Spaces
	noSpecS=0; //Generic Spaces 0 - Up to 10	
	A=B=C=P=S=0; //Spec Spaces 0 - 1 each
	//Generate Empty Map
	mapArray = createMapArray();	
	//Random Generate Spaces in Array
	randSpaceGenerate();
	//Create Spaces Linked Structure via Array slots
	makeLinkedStruc();
	//Set Player Starting space
	curSpace = mapArray[2][2];
	//Set Player in Space
	curSpace->setPlayerHere(player);
}
/*------------------------------------------------------------------------------*/
// Function: Destructor
// Description: Frees Map
/*------------------------------------------------------------------------------*/
Map::~Map() {	
	//Free Space Memory
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			delete mapArray[i][j];
		}
		delete [] mapArray[i];
	}
	delete [] mapArray;	
	//Free Player
	delete player;	
}
/*------------------------------------------------------------------------------*/
// Function: createMapArray
// Description: Generates a 3x5 map of Space Pointers
/*------------------------------------------------------------------------------*/
Space*** Map::createMapArray() {
	//New Map Grid of pointers to Spaces
	Space*** tempMap;
	tempMap = new Space**[3];
	for (int i = 0; i < 3; ++i) {
		tempMap[i] = new Space*[5];
	}
	//Initialize Pointers to NULLS
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			tempMap[i][j] = NULL;
		}
	}
	return tempMap; // Return the array
}
/*---------------------------------------------------------------------------------*/
// Function: randSpaceGenerate
// Description: Generates random space up to certain amount
/*---------------------------------------------------------------------------------*/
void Map::randSpaceGenerate() {
	//Generate Random Spaces in Array
	int totalSpaces = 15;
	for (int i = 0; i < totalSpaces; i++) {
		//Iterate through array
		bool spacePlaced = false;
		while (spacePlaced == false) {
			std::uniform_int_distribution<int> posX(1, 3); //Gen Random X
			std::uniform_int_distribution<int> posY(1, 5); //Gen Random Y
			int rX = posX(engine); //Set Position Int
			int rY = posY(engine);
			rX--; //Array Adjust
			rY--;
			if (mapArray[rX][rY] == NULL) {
				//Street non-special spaces
				if (noSpecS < 10) {
					mapArray[rX][rY] = new Street(); // Dynamic Street
					noSpecS++;
				}
				//Special Spaces Assignment
				else if (A < 1) mapArray[rX][rY] = new Afitch(), A++;
				else if (B < 1) mapArray[rX][rY] = new Borders(), B++;
				else if (C < 1) mapArray[rX][rY] = new Coffee(), C++;
				else if (P < 1) mapArray[rX][rY] = new Park(), P++;
				else if (S < 1) mapArray[rX][rY] = new Statue(), S++;				
				spacePlaced = true; //1 space placed of 15
			}
		}
	}
}
/*------------------------------------------------------------*/
// Function: makeLinkedStruc
// Description: Generates a Linked Structure using N,S,E,W ptrs
/*------------------------------------------------------------*/
void Map::makeLinkedStruc() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			//Row 1: i == 0 Linked Structure Direction Assignment
			if (i == 0) {
				if (j == 0) {					
					mapArray[i][j]->setSpace('S', mapArray[i+1][j]);
					mapArray[i][j]->setSpace('E', mapArray[i][j+1]);										
				}
				else if ((j > 0) && (j < 4)) {
					mapArray[i][j]->setSpace('S', mapArray[i+1][j]);
					mapArray[i][j]->setSpace('E', mapArray[i][j+1]);					
					mapArray[i][j]->setSpace('W', mapArray[i][j-1]);
				}
				else if (j == 4) {
					mapArray[i][j]->setSpace('S', mapArray[i+1][j]);
					mapArray[i][j]->setSpace('W', mapArray[i][j-1]);
				}
			}
			//Row 2: i == 1 Linked Structure Direction Assignment
			if (i == 1) {
				if (j == 0) {
					mapArray[i][j]->setSpace('N', mapArray[i-1][j]);
					mapArray[i][j]->setSpace('E', mapArray[i][j+1]);
					mapArray[i][j]->setSpace('S', mapArray[i+1][j]);
				}
				else if ((j > 0) && (j < 4)) {
					mapArray[i][j]->setSpace('N', mapArray[i-1][j]);
					mapArray[i][j]->setSpace('E', mapArray[i][j+1]);
					mapArray[i][j]->setSpace('S', mapArray[i+1][j]);
					mapArray[i][j]->setSpace('W', mapArray[i][j-1]);
				}
				else if (j == 4) {
					mapArray[i][j]->setSpace('N', mapArray[i-1][j]);
					mapArray[i][j]->setSpace('S', mapArray[i+1][j]);
					mapArray[i][j]->setSpace('W', mapArray[i][j-1]);
				}
			}
			//Row 3: i == 2 Linked Structure Direction Assignment
			if (i == 2) {
				if (j == 0) {
					mapArray[i][j]->setSpace('N', mapArray[i-1][j]);
					mapArray[i][j]->setSpace('E', mapArray[i][j+1]);					
				}
				else if ((j > 0) && (j < 4)) {
					mapArray[i][j]->setSpace('N', mapArray[i-1][j]);
					mapArray[i][j]->setSpace('E', mapArray[i][j+1]);					
					mapArray[i][j]->setSpace('W', mapArray[i][j-1]);
				}
				else if (j == 4) {
					mapArray[i][j]->setSpace('N', mapArray[i-1][j]);
					mapArray[i][j]->setSpace('W', mapArray[i][j-1]);
				}
			}
		}
	}
}
/*------------------------------------------------------------*/
// Function: morphToFinalSpace
// Description: Morph Current Space to Final Space
/*------------------------------------------------------------*/
void Map::morphToFinalSpace() {
	//Save Space
	Space* oldSpace = curSpace;
	//Morph the space after you leave but before you come back	
	finalSpace = new Final();
	//Add final Space in place of Park
	addLinkSpace(finalSpace);
	//Remove the Park
	remvLinkSpace(oldSpace);
	//Player Work	
	finalSpace->setPlayerHere(player); //Add Player Final
	//Final Call
	finalSpace->Special();
}
/*------------------------------------------------------------*/
// Function: addLinkSpace
// Description: Add Space in current location
/*------------------------------------------------------------*/
void Map::addLinkSpace(Space* add) {
	Space* cSpace = curSpace;
	Space* workSpace = NULL;
	//if cur N != NULL
	workSpace = cSpace->getSpaceN();
	if (workSpace) workSpace->setSpace('N', add);
	//if cur S != NULL
	workSpace = cSpace->getSpaceS();
	if (workSpace) workSpace->setSpace('S', add);
	//if cur E != NULL
	workSpace = cSpace->getSpaceE();
	if (workSpace) workSpace->setSpace('E', add);
	//if cur W != NULL
	workSpace = cSpace->getSpaceW();
	if (workSpace) workSpace->setSpace('W', add);

	//Reset Current Space
	curSpace = add;
}
/*------------------------------------------------------------*/
// Function: remvLinkSpace
// Description: Remove Linked Space
/*------------------------------------------------------------*/
void Map::remvLinkSpace(Space* remove) {		
	remove->setPlayerLeave(); //Clear player Park
	
	//Unlink all Directions of remove Space	
	if (remove->getSpaceN() != NULL) remove->setSpace('N', NULL);	
	if (remove->getSpaceS() != NULL) remove->setSpace('S', NULL);
	if (remove->getSpaceE() != NULL) remove->setSpace('E', NULL);
	if (remove->getSpaceW() != NULL) remove->setSpace('W', NULL);
	//NULL and SWAP array slot
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (mapArray[i][j] == remove) {
				mapArray[i][j] = NULL; //Clear Array Slot
				mapArray[i][j] = finalSpace; //Swap Space in
			}
		}
	}
	//Remove Linked Space
	delete remove;
}
/*------------------------------------------------------------*/
// Function: getDirSpace
// Description: Get the Space on the map
/*------------------------------------------------------------*/
Space* Map::getDirSpace(char dir) {
	Space* tempSpace = NULL; //Temp Holder	
	if (dir == 'N') {
		tempSpace = curSpace->getSpaceN();
	}
	else if (dir == 'E') {
		tempSpace = curSpace->getSpaceE();
	}
	else if (dir == 'S') {
		tempSpace = curSpace->getSpaceS();
	}
	else if (dir == 'W') {
		tempSpace = curSpace->getSpaceW();
	}
	return tempSpace;
}
/*------------------------------------------------------------*/
// Function: getPlayer
// Description: Get the Player
/*------------------------------------------------------------*/
Player* Map::getPlayer() {
	return player;
}
/*------------------------------------------------------------*/
// Function: getCurrentSpace
// Description: Get the current Space we are in
/*------------------------------------------------------------*/
Space* Map::getCurSpace() {
	return curSpace;
}
/*------------------------------------------------------------*/
// Function: setCurrentSpace
// Description: Set the current Space Player is in
/*------------------------------------------------------------*/
void Map::setCurSpace(Space* setSpace) {
	curSpace = setSpace;
}