//////////////////// ** Author: Jared Parkinson 
//  Babayaga.cpp  // *** Date: 5/3/2016
//////////////////// **** Desc: Assignment 3

#include "Babayaga.hpp"
#include <iostream>

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Str, Armor, isDead bool
/*---------------------------------------------------------------------------------*/
Babayaga::Babayaga() {
	strength = 12;
	armor = 3;	
	isDead = false;
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Babayaga::~Babayaga() {}
/*---------------------------------------------------------------------------------*/
// Function: atkDiceRoll
// Description: Roll # of Dice and Size for a Total Attack (Class Specific)
/*---------------------------------------------------------------------------------*/
int Babayaga::atkDiceRoll() {
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
int Babayaga::defDiceRoll() {
	//Dice 1d10, total after applied damage
	int diceAmt = 1, diceType = 10, total = 0;

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
int Babayaga::attack() {	
	int atkRoll = atkDiceRoll();
	int soulReport = (atkRoll / 3);

	//Special *Soul
	if (soulReport > 0)	{
		//Report Life Stolen
		std::cout << "\n*Soul used by Baba Yaga!" << std::endl;
		std::cout << "Baba Yaga strength before steal: " << strength << std::endl;
		std::cout << "Baba Yaga stole strength amount: " << soulReport << std::endl;
		strength += (atkRoll / 3); //1/3 dmg to her str
		std::cout << "Baba Yaga strength after steal: " << strength << std::endl;
	}	
	return atkRoll;
}
/*---------------------------------------------------------------------------------*/
// Function: defend
// Description: Defend against incoming INT Attack
/*---------------------------------------------------------------------------------*/
void Babayaga::defend(int attack) {
	//Incoming Attack
	std::cout << "Incoming Attack against Baba: " << attack << std::endl;
	//Roll Defense
	int defRoll = defDiceRoll(); //Roll for defense	
	std::cout << "Baba Defense roll: " << defRoll << std::endl;	
	//Defend First
	int atkAfterDef = (attack - defRoll);
	std::cout << "Baba Attack After Defend: " << atkAfterDef << std::endl;
	//Armor Second
	int atkAfterArmor = (atkAfterDef - armor); //Left over attack after armor removed, can be negative
	std::cout << "Baba Attack After Armor: " << atkAfterArmor << std::endl;
	
	//If damage is less than Defended/Armor amt
	if (atkAfterArmor <= 0) std::cout << "\nZero Damage Dealt to Baba." << std::endl;
	//If damage surpasses Defense and Armor
	if (atkAfterArmor > 0) {
		int damaged = (strength - atkAfterArmor);
		//Check for death
		if (damaged <= 0) {
			setIsDead(true); //Set Death
			std::cout << "\n*******************\n" << "Baba Yaga has DIED!\n" << "*******************\n";
			strength = 0; //Set STR to 0
		}
		else strength = damaged; //Set Strength to damaged amount
	}
}
//Setters
/*---------------------------------------------------------------------------------*/
// Function: setIsDead
// Description: Set the Dead Bool
/*---------------------------------------------------------------------------------*/
void Babayaga::setIsDead(bool state) {
	isDead = state;
}
//Getters
/*---------------------------------------------------------------------------------*/
// Function: getStrength
// Description: Get the Current Strength
/*---------------------------------------------------------------------------------*/
int Babayaga::getStrength() {
	int curStr = strength;
	return curStr;
}
/*---------------------------------------------------------------------------------*/
// Function: getIsDead
// Description: Get the Dead Bool
/*---------------------------------------------------------------------------------*/
bool Babayaga::getIsDead() {
	return isDead;
}