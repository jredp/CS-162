//////////////////// ** Author: Jared Parkinson 
//   Critter.hpp  // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <random> //Randomizer
#include <memory> //For Random Memory Engine

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

//Base Class
class Critter
{
protected:
	bool hasMoved; //Critter Has Moved Already	
	int movesMade;	
	char icon;	
	int movesNoEat;

public:	
	Critter(); //Create Critter Objects, Constructor	
	virtual ~Critter(); //Object Destructor

	//Getters
	bool getHasMoved();
	int getMoves(); //Get movesMade
	virtual char getIcon(); //Gets Icon

	//Setters
	void setHasMoved(bool moved);
	void setMovesNoEat(int movesNoEat);	
	void clearMoves();
	void incMoves(); //Increment moves made	
	void incMovNoEat(); //Get Direction and return	

	//Actions
	virtual Critter* Breed(); //Base Class Breed action - Pure Virtual
	virtual void Eat(); //Pure virtual, only Doodlebug needs this
	int move(); //Get Direction and return
	int randMoveDirection(); //Get Random Direction
};

#endif