//////////////////// ** Author: Jared Parkinson 
// Harrypotter.hpp// *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

class Harrypotter : public Creature
{
protected:
	int deathCount;
	virtual int atkDiceRoll(); //Roll Attack Dice
	virtual int defDiceRoll(); //Roll Defense Dice
public:
	Harrypotter(); //Constructor
	~Harrypotter(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action
	virtual int getStrength();
	virtual void setIsDead(bool state);
	virtual bool getIsDead();
};

#endif