//////////////////// ** Author: Jared Parkinson 
//  Bluemen.hpp // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef Bluemen_HPP
#define Bluemen_HPP

#include "Creature.hpp"

class Bluemen : public Creature
{
public:
	Bluemen(); //Constructor
	~Bluemen(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action	
};

#endif