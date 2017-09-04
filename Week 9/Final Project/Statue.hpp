//////////////////// ** Author: Jared Parkinson 
//  Statue.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef STATUE_HPP
#define STATUE_HPP

#include "Space.hpp"

class Statue : public Space
{	
public:
	Statue(); //Constructor
	virtual ~Statue(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action	
};

#endif