//////////////////// ** Author: Jared Parkinson 
//  Babayaga.hpp  // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP

#include "Creature.hpp"

class Babayaga : public Creature
{
private:
	int soulUseCount;
public:
	Babayaga(); //Constructor
	~Babayaga(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action	
};

#endif