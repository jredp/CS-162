//////////////////// ** Author: Jared Parkinson 
//  Creature.hpp  // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <random> //Randomizer
#include <memory> //Random Memory Engine Usage

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

class Creature 
{
protected:
	bool isDead;
	int strength; //"Hitpoints"	- 0 is death
	int armor; //Mitigated Damage (No damage to strength)	
	virtual int atkDiceRoll() = 0; //Pure Virtual Roll the Dice for Attack
	virtual int defDiceRoll() = 0; //Pure Virtual Roll the Dice for Defense
public:
	Creature(); //Constructor
	virtual ~Creature(); //Destructor	
	virtual int attack() = 0; //Pure Virtual Attack Action
	virtual void defend(int atk) = 0; //Pure Virtual Defend Action	
	virtual int getStrength() = 0;	
	virtual void setIsDead(bool state) = 0;
	virtual bool getIsDead() = 0;

};

#endif