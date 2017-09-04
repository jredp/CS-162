//////////////////// ** Author: Jared Parkinson 
//  Coffee.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "Space.hpp"

class Coffee : public Space
{
public:
	Coffee(); //Constructor
	virtual ~Coffee(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action	
};

#endif