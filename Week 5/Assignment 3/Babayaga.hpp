//////////////////// ** Author: Jared Parkinson 
//  Babayaga.hpp  // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP

#include "Creature.hpp"

class Babayaga : public Creature
{
protected:
	virtual int atkDiceRoll(); //Roll Attack Dice
	virtual int defDiceRoll(); //Roll Defense Dice
public:
	Babayaga(); //Constructor
	~Babayaga(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action
	virtual int getStrength();
	virtual void setIsDead(bool state);
	virtual bool getIsDead();
};

#endif