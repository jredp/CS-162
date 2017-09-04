//////////////////// ** Author: Jared Parkinson 
//  Barbarian.hpp // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature
{
public:
	Barbarian(); //Constructor
	~Barbarian(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action	
};

#endif