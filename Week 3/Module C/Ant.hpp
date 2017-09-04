//////////////////// ** Author: Jared Parkinson 
//     Ant.hpp    // *** Date: 4/16/2016
//////////////////// **** Desc: modC

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

//Derived
class Ant: public Critter
{
private:
	int movesMade; //Ant Moves Made
	int antX; //Ant Object X Coord
	int antY; //Ant Object Y Coord
public:
	Ant(); //Create Ant Object		
	//Setter
	void clearMoves();
	void incMoves(); //Get Direction and return	
	void setAntX(int x); //Set Ant X
	void setAntY(int y); //Set Ant Y
	//Getter
	int getMoves(); //Get movesMade
	//Breed
	Ant* Breed();
};

#endif