//////////////////// ** Author: Jared Parkinson 
//  Borders.hpp   // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef BORDERS_HPP
#define BORDERS_HPP

#include "Space.hpp"

class Borders : public Space
{
public:
	Borders(); //Constructor
	virtual ~Borders(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action	
};

#endif