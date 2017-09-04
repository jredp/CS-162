//////////////////// ** Author: Jared Parkinson 
//    Team.cpp    // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Team.hpp"

/*------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*------------------------------------------------------------*/
Team::Team() {
	//Lineup Init
	frontLine = NULL;
	backLine = NULL;
	//Loser Pile Init
	topLose = NULL;
	botLose = NULL;
}
/*------------------------------------------------------------*/
// Function: Destructor
/*------------------------------------------------------------*/
Team::~Team(){
	//If Lineup not empty, free it
	while (!LineupEmptyChk()) {		
		Creature *freeLineCreature = removeLineupNode();
		delete freeLineCreature;
		freeLineCreature = NULL;
	}
	//If Loser Pile not empty, free it
	while (!LoserNodeEmptyChk()) {		
		Creature *freeLoseCreature = removeLoserNode();
		delete freeLoseCreature;
		freeLoseCreature = NULL;
	}
	//Free fightArray
	delete [] fightArray;
}
/*------------------------------------------------------------*/
// Function: makeArray
// Description: Creates an array of Creature pointers of size
/*------------------------------------------------------------*/
void Team::makeArray(int size) {
	fighterAmount = size;
	
	fightArray = new Creature*[fighterAmount]; //New array of size
	for (int arraySlot = 0; arraySlot < fighterAmount; ++arraySlot) {
		fightArray[arraySlot] = NULL;	//Set Item Pointers to NULL
	}
}
/*------------------------------------------------------------*/
// Function: insertArray
// Description: Insert a Fighter into an empty array slot
/*------------------------------------------------------------*/
void Team::insertArray(Creature *insert) {
	//Find NULL slot and insert Creatures
	for (int arraySlot = 0; arraySlot < fighterAmount; ++arraySlot) {
		if (fightArray[arraySlot] == NULL) {
			fightArray[arraySlot] = insert;
			break;
		}
	}
}
/*------------------------------------------------------------*/
// Function: sortTheArray
// Description: Sorts in Descending order by Wins and then Score
/*------------------------------------------------------------*/
void Team::sortTheArray() {
	int tempWinsI, tempWinsJ;
	int tempScoreI, tempScoreJ;		
	Creature *tempFighter = NULL;

	//Sort array on Wins and Score
		for (int i = 0; i < fighterAmount-1; i++) {
			for (int j = 0; j < fighterAmount-1; j++) {
				//Set Array Slot comparisons
				tempWinsI = fightArray[j + 1]->getWins();
				tempWinsJ = fightArray[j]->getWins();
				//Sort Desc by Wins
				if (tempWinsI > tempWinsJ) {
					tempFighter = fightArray[j + 1]; //Ahead slot copied
					fightArray[j + 1] = fightArray[j]; //j written over i
					fightArray[j] = tempFighter;
					tempFighter = NULL;
				}
				//Sort if wins matching				
				if (tempWinsJ == tempWinsI) {					
					tempScoreI = fightArray[j + 1]->getFighterScore();
					tempScoreJ = fightArray[j]->getFighterScore();					
					//Swap after comparing scores
					if (tempScoreI > tempScoreJ) {
						tempFighter = fightArray[j+1];
						fightArray[j + 1] = fightArray[j];
						fightArray[j] = tempFighter;
						tempFighter = NULL;
					}
				}			
		}
	}
}
/*------------------------------------------------------------*/
/* LINEUP (QUEUE)*/
/*------------------------------------------------------------*/
// Function: addLineupNode
// Description: Adds a LineupNode, sets top
/*------------------------------------------------------------*/
void Team::addLineupNode(Creature *addCreature) {
	//Create new Queuenode struct object, place in back	
	if (LineupEmptyChk()) {
		//If empty, make front/back point same Node
		frontLine = new qLineupNode(addCreature); //backLine will be NULL right now (NEXT?)
		backLine = frontLine; //Back now = Front
	}
	//If Queue has nodes, put a Node in back
	else {
		backLine->next = new qLineupNode(addCreature); //New Node in Back
		backLine = backLine->next; //Set next Node
	}	
}
/*------------------------------------------------------------*/
// Function: removeLineupNode
// Description: Remove LineupNode from front, returns data
/*------------------------------------------------------------*/
Creature* Team::removeLineupNode() {
	qLineupNode *temp; //Temp Node Holder

	//Remove LineupNode
	Creature *tempNodeData = frontLine->fighterDataQ; //Temp Data(creature ptr) Holder
	frontLine->fighterDataQ = NULL; //Free pointer
	temp = frontLine; //adjust top pointer	
	frontLine = frontLine->next; //Set front pointer to next node	
	delete temp; //remove node/data
	return tempNodeData; //return Creature Pointer	
}
/*------------------------------------------------------------*/
// Function: LineupEmptyChk
// Description: Checks for empty Lineup in Team (Queue)
/*------------------------------------------------------------*/
bool Team::LineupEmptyChk() {	
	if (!frontLine) return true;
	else return false;
}
/*------------------------------------------------------------*/
// Function: setWinners
// Description: Sets the winners from the sorted array
/*------------------------------------------------------------*/
void Team::setWinners() {
	//Sort array
	sortTheArray();

	//Fighter ordered Print	
	std::cout << "\n-----------Winning Team Sorted--------------\n";
	for (int i = 0; i < fighterAmount; i++) {
		std::cout << "Type: " << fightArray[i]->getClassType() << "   Name: " << fightArray[i]->getFighterID() 
			<< "   Wins: " << fightArray[i]->getWins() << "   Score: " 
			<< fightArray[i]->getFighterScore() << std::endl;
	}

	//Scoring
	std::string win1Typ, win2Typ, win3Typ;
	std::string win1ID, win2ID, win3ID;
	int win1Wins, win2Wins, win3Wins;
	int win1Score, win2Score, win3Score;
	
	//Set and Print
	std::cout << "\n-----------Top 3 Winners--------------\n";
	//1st Place
	win1 = fightArray[0];
	win1ID = win1->getFighterID(); win1Typ = win1->getClassType();
	win1Wins = win1->getWins();
	win1Score = win1->getFighterScore();
	std::cout << "1st Place - Type: " << win1Typ << "    Name: " << win1ID << "    Wins: " 		
		<< win1Wins << "     Score: " << win1Score << std::endl;
	//2nd Place
	win2 = fightArray[1];
	win2ID = win2->getFighterID(); win2Typ = win2->getClassType();
	win2Wins = win2->getWins();
	win2Score = win2->getFighterScore();
	std::cout << "2nd Place - Type: " << win2Typ << "    Name: " << win2ID << "    Wins: "
		<< win2Wins << "     Score: " << win2Score << std::endl;
	//3rd Place
	win3 = fightArray[2];
	win3ID = win3->getFighterID(); win3Typ = win3->getClassType();
	win3Wins = win3->getWins();
	win3Score = win3->getFighterScore();
	std::cout << "3rd Place - Type: " << win3Typ << "    Name: " << win3ID << "    Wins: "
		<< win3Wins << "     Score: " << win3Score << std::endl;
}
/*------------------------------------------------------------*/
/* LOSER PILE (STACK)*/
/*------------------------------------------------------------*/
// Function: addLoserNode
// Description: Adds a LoserNode, sets top
/*------------------------------------------------------------*/
void Team::addLoserNode(Creature *addCreature) {	
	topLose = new sLoserPileNode(addCreature, topLose);
}
/*------------------------------------------------------------*/
// Function: removeLoserNode
// Description: Removes Loser Node, returns the pointer
/*------------------------------------------------------------*/
Creature* Team::removeLoserNode() {
	sLoserPileNode *temp; //Temp Node Holder

	//Remove Stacknode	
	Creature *tempNodeData = topLose->fighterDataS; //Temp Data(creature) Holder
	topLose->fighterDataS = NULL; //Free pointer
	temp = topLose; //adjust top pointer
	topLose = topLose->next; //Set next node
	delete temp; //remove node/data	
	return tempNodeData; //return Creature
}
/*------------------------------------------------------------*/
// Function: LoserNodeEmptyChk
// Description: Checks if the Stack is empty
/*------------------------------------------------------------*/
bool Team::LoserNodeEmptyChk() {
	if (!topLose) return true;
	else return false;
}
/*------------------------------------------------------------*/
// Function: printStack
// Description: Prints the Stack and Calls Remove as it prints
/*------------------------------------------------------------*/
void Team::printRemoveLoser() {
	//Remove Loser Node/Print until empty
	std::cout << "\n-----------Loser Pile--------------\n";
	while (!LoserNodeEmptyChk()) {		
		Creature *temp = removeLoserNode();
		std::cout << "Fighter Class: " << temp->getClassType() <<
			"     Fighter ID: " << temp->getFighterID() 
			<< "     Fighter Wins: " << temp->getWins() << "\n";
		delete temp; //Free pointer & Creature object
	}	
}