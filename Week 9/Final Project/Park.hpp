//////////////////// ** Author: Jared Parkinson 
//   Park.hpp     // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef PARK_HPP
#define PARK_HPP

#include "Space.hpp"

class Park : public Space
{
private:
	int totalGems;
	bool haveSword;
	std::string gem1, gem2, gem3, sword;
public:
	Park(); //Constructor
	virtual ~Park(); //Destructor	
	virtual void Special(); //Special Action
	virtual void printSpaceDesc(); //Print Space Description	
	virtual void spaceOptions(); //Space Menu for item/action	
};

#endif