//////////////////// ** Author: Jared Parkinson 
//  Barbarian.cpp // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Barbarian.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Barbarian::Barbarian() {
	strength = 12, armor = 0, fixedHP = 12;
	isDead = false;	
	//Atk 2d6
	atkDice = 2, atkDiceType = 6;
	//Def 2d6
	defDice = 2, defDiceType = 6;
	totalWins = 0;
	totalAttackDealt = 0;
	classType = "Barbarian";
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Barbarian::~Barbarian() {}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Barbarian::attack() {	
	int atkRoll = atkDiceRoll();
	totalAttackDealt += atkRoll;
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Barbarian::defend(int attack) {
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense	
	//Defend First
	int atkAfterDef = (attack - defRoll);
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);
		//Check for death
		if (damaged <= 0) {
			setIsDead(true); //Set Death
			std::cout << "\n**************************\n" << "Barbarian has DIED! Name: "
				<< fighterID << "\n**************************\n";			
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}