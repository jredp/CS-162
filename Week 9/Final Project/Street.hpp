//////////////////// ** Author: Jared Parkinson 
//   Street.hpp   // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef STREET_HPP
#define STREET_HPP

#include "Space.hpp"

class Street : public Space
{
public:	
	Street(); //Constructor
	virtual ~Street(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action	
};

#endif