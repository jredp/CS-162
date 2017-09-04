//////////////////// ** Author: Jared Parkinson 
//   Afitch.hpp   // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef AFITCH_HPP
#define AFITCH_HPP

#include "Space.hpp"

class Afitch : public Space
{
public:
	Afitch(); //Constructor
	virtual ~Afitch(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action	
};

#endif