//////////////////// ** Author: Jared Parkinson 
//  Medusa.hpp // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#ifndef Medusa_HPP
#define Medusa_HPP

#include "Creature.hpp"

class Medusa : public Creature
{
protected:
	virtual int atkDiceRoll(); //Roll Attack Dice
	virtual int defDiceRoll(); //Roll Defense Dice
public:
	Medusa(); //Constructor
	~Medusa(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action
	virtual int getStrength();
	virtual void setIsDead(bool state);
	virtual bool getIsDead();
};

#endif