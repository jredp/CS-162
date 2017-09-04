//////////////////// ** Author: Jared Parkinson 
//    Medusa.cpp  // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Medusa.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Medusa::Medusa() {
	strength = 8, armor = 3, fixedHP = 8;
	isDead = false;
	//Atk 2d6
	atkDice = 2, atkDiceType = 6;
	//Def 1d6
	defDice = 1, defDiceType = 6;
	totalWins = 0;
	totalAttackDealt = 0;
	classType = "Medusa";
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Medusa::~Medusa() {}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Medusa::attack() {
	int atkRoll = atkDiceRoll();
	totalAttackDealt += atkRoll;
	//Special *Glare
	if (atkRoll == 12) { 
		//Max out attk > any creature str/def/arm
		atkRoll = 66;
		std::cout << "*Medusa used *Glare for instant death!\n";
	} 
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Medusa::defend(int attack) {
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
			std::cout << "\n**************************\n" << "Medusa is DEAD! Name: "
				<< fighterID << "\n**************************\n";
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}