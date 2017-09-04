//////////////////// ** Author: Jared Parkinson 
//  Harrypotter.cpp // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#include "Harrypotter.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Harrypotter::Harrypotter() {
	strength = 10;
	armor = 0;
	deathCount = 0;
	isDead = false;
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Harrypotter::~Harrypotter() {}
/*---------------------------------------------------------------------------------*/
// Function: atkDiceRoll
// Description: Roll # of Dice and Size for a Total Attack (Class Specific)
/*---------------------------------------------------------------------------------*/
int Harrypotter::atkDiceRoll() {
	//Dice 2d6, total damage dealing
	int diceAmt = 2, diceType = 6, total = 0;

	//Random roll for each Die
	for (int i = 0; i < diceAmt; i++) {
		std::uniform_int_distribution<> diceRoll(0, diceType);
		auto singleRoll = diceRoll(engine);
		total += singleRoll;
	}
	return total;
}
/*---------------------------------------------------------------------------------*/
// Function: defDiceRoll
// Description: Roll # of Dice and Size for a Total Defense (Class Specific)
/*---------------------------------------------------------------------------------*/
int Harrypotter::defDiceRoll() {
	//Dice 2d6, total after applied damage
	int diceAmt = 2, diceType = 6, total = 0;

	//Random roll for each Die
	for (int i = 0; i < diceAmt; i++) {
		std::uniform_int_distribution<> diceRoll(0, diceType);
		auto singleRoll = diceRoll(engine);
		total += singleRoll;
	}
	return total;
}
/*---------------------------------------------------------------------------------*/
// Function: attack
// Description: Returns an Attack Roll
/*---------------------------------------------------------------------------------*/
int Harrypotter::attack() {
	int atkRoll = atkDiceRoll();
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Harrypotter::defend(int attack) {

	//Incoming Attack
	std::cout << "Incoming Attack against Harry P: " << attack << std::endl;
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense	
	std::cout << "Harry P Defense roll: " << defRoll << std::endl;
	//Defend First
	int atkAfterDef = (attack - defRoll);
	std::cout << "Attack After Harry P Defend: " << atkAfterDef << std::endl;
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative
	std::cout << "Attack After Harry P Armor: " << atkAfterArmor << std::endl;

	//If damage is less than Defended/Armor amt
	if (atkAfterArmor <= 0) std::cout << "\nZero Damage Dealt to Harry P." << std::endl;
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);
		//Check for death
		if (damaged <= 0) {
			if (deathCount == 1) {
				setIsDead(true); //Set Death
				std::cout << "\n*******************\n" << "Harry Potter is FINALLY DEAD!\n" << "*******************\n";
				strength = 0; //Set STR to 0
			}
			else {
				//Per TA Diana Bacon Post on forum, Harry gets reset to 10hp on DeathX
				strength = 10; //reset Strength to 10 (additional life of 10)
				std::cout << "\nHarry Potter has died!\n" << "Harry Potter used *Hogwarts and recovered to 10 strength!\n";
				deathCount++;
			}			
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}
//Setters
/*---------------------------------------------------------------------------------*/
// Function: setIsDead
// Description: Set the Dead Bool
/*---------------------------------------------------------------------------------*/
void Harrypotter::setIsDead(bool state) {
	isDead = state;
}
//Getters
/*---------------------------------------------------------------------------------*/
// Function: getStrength
// Description: Get the Current Strength
/*---------------------------------------------------------------------------------*/
int Harrypotter::getStrength() {
	int curStr = strength;
	return curStr;
}
/*---------------------------------------------------------------------------------*/
// Function: getIsDead
// Description: Get the Dead Bool
/*---------------------------------------------------------------------------------*/
bool Harrypotter::getIsDead() {
	return isDead;
}