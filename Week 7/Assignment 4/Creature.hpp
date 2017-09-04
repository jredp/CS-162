//////////////////// ** Author: Jared Parkinson 
//  Creature.hpp  // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>
#include <random> //Randomizer
#include <memory> //Random Memory Engine Usage

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

class Creature 
{
protected:	
	/*---------NEW-----------*/
	int totalWins; //Track Creature Wins
	int totalAttackDealt; //Track Attack Roll Dished Out
	int fixedHP; // fixed max HP number	
	std::string classType; //Name or ID of Fighter
	std::string fighterID; //Name or ID of Fighter	
	/*---------NEW-----------*/
	bool isDead;
	int strength; //"Hitpoints"	- 0 is death
	int armor; //Mitigated Damage (No damage to strength)	
	int atkDice, defDice; //Attack Dice and Defend Dice Amount of Dice
	int atkDiceType, defDiceType; //Attack Dice and Defend Dice Type of Dice (e.g. 6, 10)
	int atkDiceRoll(); //Virtual Roll the Dice for Attack
	int defDiceRoll(); //Virtual Roll the Dice for Defense
public:
	Creature(); //Constructor
	virtual ~Creature(); //Destructor	
	virtual int attack() = 0; //Pure Virtual Attack Action
	virtual void defend(int atk) = 0; //Pure Virtual Defend Action	
	virtual int getStrength();	//Get Strength of Creature
	virtual void setIsDead(bool state); //Set isDead bool
	virtual bool getIsDead(); //Get isDead bool
	/*---------NEW-----------*/
	void setFighterID(); //Set Fighter Name or ID
	std::string getFighterID();
	void incWins(); //Increase wins by 1
	int getWins(); //Get number of wins	
	int getFighterScore(); //Get Fighter Score
	std::string getClassType(); //Get the Class Type
	void restoreHP(); //Restore lost health each round	
	/*---------NEW-----------*/
};

#endif