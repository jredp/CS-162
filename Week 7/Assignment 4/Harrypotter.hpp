//////////////////// ** Author: Jared Parkinson 
// Harrypotter.hpp// *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class Harrypotter : public Creature
{
protected:
	int deathCount;	
public:
	Harrypotter(); //Constructor
	~Harrypotter(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action	
};

#endif