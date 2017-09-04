//////////////////// ** Author: Jared Parkinson 
//     Ant.hpp    // *** Date: 4/28/2016
//////////////////// **** Desc: modD

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

//Derived -- Public allows Data member access
class Ant : public Critter
{
private:	
	//None needed
public:
	Ant(); //Create Ant Object				
	~Ant(); //Destructor
	virtual Critter* Breed(); //Breed Class Specifc
	virtual bool checkBreed(); //Check for breed
};

#endif