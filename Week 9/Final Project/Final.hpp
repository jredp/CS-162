//////////////////// ** Author: Jared Parkinson 
//   Final.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef FINAL_HPP
#define FINAL_HPP

#include "Space.hpp"

class Final : public Space
{
public:
	Final(); //Constructor
	virtual ~Final(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action
};

#endif