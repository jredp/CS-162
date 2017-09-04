//////////////////// ** Author: Jared Parkinson 
//    Team.hpp    // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef TEAM_HPP
#define TEAM_HPP

#include "Creature.hpp"

class Team
{
private:	
	int fighterAmount; //Number of fighters
	Creature **fightArray; //Array of Fighters
	Creature *win1, *win2, *win3;	
	/*------------------------------------------------------------*/
	//Queue Lineup
	struct qLineupNode {
		Creature *fighterDataQ;
		qLineupNode *next;
		
		//Queue LineupNode Constructor
		qLineupNode(Creature *fighterDataIns, qLineupNode *nextIns = NULL) {
			fighterDataQ = fighterDataIns;
			next = nextIns;
		}
	};
	qLineupNode *frontLine; //Front of Lineup (Queue)
	qLineupNode *backLine; //Back of Lineup (Queue)
	/*------------------------------------------------------------*/
	//Stack Loser Pile
	struct sLoserPileNode {
		Creature *fighterDataS;
		sLoserPileNode *next;

		//Stack LoserNode Constructor
		sLoserPileNode(Creature *fighterDataIns, sLoserPileNode *nextIns) {
			fighterDataS = fighterDataIns;
			next = nextIns;
		}
	};
	sLoserPileNode *topLose; //Top of Loser Pile (Stack)
	sLoserPileNode *botLose; //Bottom of Loser Pile (Stack)
	/*------------------------------------------------------------*/
public:
	Team();
	~Team();
	void makeArray(int size); //Create new Array of size
	void insertArray(Creature *insert); //Insert Fighter in Array
	void sortTheArray(); //Sort the Array of Fighters
	void setWinners(); //Sets winners of this Team if called
	/*--------------------*/
	//Lineup (Queue)
	/*--------------------*/	
	void addLineupNode(Creature *add); //Add node with data of Creature*
	Creature* removeLineupNode(); //remove node from top of Queue FIFO	
	bool LineupEmptyChk(); //Checks for empty Lineup in Team (Queue)		
	/*--------------------*/
	//Loser Pile (Stack)
	/*--------------------*/
	void addLoserNode(Creature *add); //Add node with data of Creature
	Creature* removeLoserNode(); //remove node from top of stack	
	void printRemoveLoser(); //Prints LoserNode Stack and remove
	bool LoserNodeEmptyChk(); //Checks for empty Loser Pile
};

#endif
