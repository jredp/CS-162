//////////////////// ** Author: Jared Parkinson 
//   Critter.hpp  // *** Date: 4/10/2016
//////////////////// **** Desc: modB week2

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <random> //Randomizer
#include <memory> //For Random Memory Engine

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

class Critter
{
private:
	bool hasMoved; //Critter Has Moved Already	
public:
	Critter(); //Create Critter Objects, Constructor	

	//Getters
	bool getHasMoved();
	//Setters
	void setHasMoved(bool moved);	
	//Move
	int updateLocation(); //Get Direction and return
	int randMoveDirection(); //Get Random Direction
};

#endif