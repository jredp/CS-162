//////////////////// ** Author: Jared Parkinson 
//  Harrypotter.cpp // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Harrypotter.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Harrypotter::Harrypotter() {
	strength = 10, armor = 0, fixedHP = 10;
	deathCount = 0;
	isDead = false;
	//Atk 2d6
	atkDice = 2, atkDiceType = 6;
	//Def 2d6
	defDice = 2, defDiceType = 6;
	totalWins = 0;
	totalAttackDealt = 0;
	classType = "Harry Potter";
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Harrypotter::~Harrypotter() {}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Harrypotter::attack() {
	int atkRoll = atkDiceRoll();
	totalAttackDealt += atkRoll;
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Harrypotter::defend(int attack) {		
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
			if (deathCount == 1) {
				setIsDead(true); //Set Death
				std::cout << "\n*****************************\n" << "Harry Potter is FINALLY DEAD! Name: "
					<< fighterID << "\n*****************************\n";
				strength = 0; //Set STR to 0
			}
			else {				
				strength = 10; //reset Strength to 10 (additional life of 10)
				std::cout << "Harry Potter has died!\n" << "Harry Potter used *Hogwarts and recovered to 10 strength!\n";
				deathCount++;
			}			
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}