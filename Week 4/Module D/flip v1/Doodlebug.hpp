//////////////////// ** Author: Jared Parkinson 
//  Doodlebug.hpp // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

//Derived -- Public allows Data member access
class Doodlebug : public Critter
{
private:	
	bool starved; //Is it starved?	

public:
	Doodlebug(); //Create DBug Object	

	//Getter
	bool getStarved(); //Get starved

	//Action
	virtual Critter* Breed();
	virtual void Eat();
	void Starve();	
};

#endif