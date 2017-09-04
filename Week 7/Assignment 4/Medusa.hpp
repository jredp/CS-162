//////////////////// ** Author: Jared Parkinson 
//   Medusa.hpp   // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef Medusa_HPP
#define Medusa_HPP

#include "Creature.hpp"

class Medusa : public Creature
{
public:
	Medusa(); //Constructor
	~Medusa(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action	
};

#endif