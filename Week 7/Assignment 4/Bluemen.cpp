//////////////////// ** Author: Jared Parkinson 
//  Bluemen.cpp  // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Bluemen.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Bluemen::Bluemen() {
	strength = 12, armor = 3, fixedHP = 12;
	isDead = false;
	//Atk 2d10
	atkDice = 2, atkDiceType = 10;
	//Def 3d6
	defDice = 3, defDiceType = 6;
	totalWins = 0;
	totalAttackDealt = 0;
	classType = "Blue Men";
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Bluemen::~Bluemen() {}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Bluemen::attack() {
	int atkRoll = atkDiceRoll();
	totalAttackDealt += atkRoll;
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Bluemen::defend(int attack) {			
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense		
	//Defend First
	int atkAfterDef = (attack - defRoll);	
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative		
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);		
		if (damaged <= 0) { //Check for death
			setIsDead(true); //Set Death
			std::cout << "\n**************************\n" << "Blue Men have DIED! Name: "
				<< fighterID << "\n**************************\n";
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
	//Special!! *Mob - Take damage taken/4
	if ((atkAfterArmor > 4) && (defDice != 0) && (isDead == false)) {
		int divide = atkAfterArmor / 4;
		std::cout << "Blue Men used *Mob!" << std::endl;				
		defDice -= divide;		
		if (defDice < 0) defDice = 0;
		std::cout << "Blue Men # Dice after removal: " << defDice << std::endl;
	}
}