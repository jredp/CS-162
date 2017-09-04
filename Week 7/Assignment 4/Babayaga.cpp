//////////////////// ** Author: Jared Parkinson 
//  Babayaga.cpp  // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Babayaga.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Babayaga::Babayaga() {
	strength = 12, armor = 3, fixedHP = 12;
	isDead = false;	
	totalWins = 0;
	totalAttackDealt = 0;
	classType = "Baba Yaga";
	//Atk 2d6
	atkDice = 2, atkDiceType = 6;
	//Def 1d10
	defDice = 1, defDiceType = 10;
	//*Soul
	soulUseCount = 0;		
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Babayaga::~Babayaga() {}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Babayaga::attack() {	
	int atkRoll = atkDiceRoll();
	totalAttackDealt += atkRoll;
	int soulReport = (atkRoll / 3);

	//Special *Soul
	if ((soulReport > 0) && (soulUseCount < 4))	{
		//Report Life Stolen
		std::cout << "*Soul used by Baba Yaga!" << std::endl;
		std::cout << "*Soul uses (up to 3): " << soulUseCount << std::endl;
		strength += (atkRoll / 3); //1/3 dmg to her str
		soulUseCount++; //Increment Soul Use		
	}	
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Babayaga::defend(int attack) {
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
			std::cout << "\n**************************\n" << "Baba Yaga has DIED! Name: " 
				<< fighterID << "\n**************************\n";
			
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}