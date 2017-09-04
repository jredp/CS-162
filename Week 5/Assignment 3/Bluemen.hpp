//////////////////// ** Author: Jared Parkinson 
//  Bluemen.hpp // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#ifndef Bluemen_HPP
#define Bluemen_HPP

#include "Creature.hpp"

class Bluemen : public Creature
{
protected:
	int defDice;
	virtual int atkDiceRoll(); //Roll Attack Dice
	virtual int defDiceRoll(); //Roll Defense Dice
public:
	Bluemen(); //Constructor
	~Bluemen(); //Destructor		
	virtual int attack(); //Attack Action
	virtual void defend(int atk); //Defend Action
	virtual int getStrength();
	virtual void setIsDead(bool state);
	virtual bool getIsDead();
};

#endif