//////////////////// ** Author: Jared Parkinson 
//  Barbarian.hpp // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature
{
protected:	
	virtual int atkDiceRoll(); //Roll Attack Dice
	virtual int defDiceRoll(); //Roll Defense Dice
public:
	Barbarian(); //Constructor
	~Barbarian(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action
	virtual int getStrength();
	virtual void setIsDead(bool state);
	virtual bool getIsDead();
};

#endif