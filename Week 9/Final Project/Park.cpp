//////////////////// ** Author: Jared Parkinson 
//   Park.cpp     // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Park.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Park::Park() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link	
	playerHere = NULL; //Player in Space	
	//Special
	specialComplete = false;	
	haveSword = false; //Set equipment bool
	totalGems = 0; //Set Gems
	//Item Names
	gem1 = "BlueGem"; gem2 = "RedGem"; 
	gem3 = "GreenGem"; sword = "Sword";
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Park::~Park() {}
/*---------------------------------------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*---------------------------------------------------------------------------------*/
void Park::printSpaceDesc() {
	//Description based on Special
	std::cout << "\n***************************************************\n";
	std::cout << "PARK:\n";
	std::cout << "You walk into a  some sort of Faire area. There seems to\n";
	std::cout << "be a monument in the middle of the open. As you \n";
	std::cout << "walk towards it you can hear the faint hum of the same\n";
	std::cout << "spell that sent you here! There is a glowing sphere\n";
	std::cout << "that you feel must be the way back! There are 3 empty\n";
	std::cout << "slots that look like Gems. Hurry! Place them/find them!\n";
	std::cout << "\n***************************************************\n";		
}
/*---------------------------------------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*---------------------------------------------------------------------------------*/
void Park::Special() {		
	printSpaceDesc();
	if (specialComplete == false) {
		int choice, dep1, dep2, dep3;
		Knapsack* tempPack = playerHere->usePack();
		spaceOptions();
		do {
			switch (choice = spaceInput()) {
			case 1:
				//Remove Gems From Pack				
				std::cout << "\n<------------>\n";
				dep1 = tempPack->removeItem(gem1); dep2 = tempPack->removeItem(gem2);
				dep3 = tempPack->removeItem(gem3);				
				totalGems += (dep1 + dep2 + dep3); //Total Gems				
				std::cout << "\n**Depositing Gems.**\n";
				std::cout << "**You have deposited " << totalGems
					<< " total gems.\n (Need 3 for option #2.)\n";
				std::cout << "<------------>\n";
				std::cout << "\nThe monument pushes you away in a direction...\n";
				break;
			case 2:
				//Activate Monument				
				haveSword = tempPack->searchPack(sword); //Check for Sword
				if ((haveSword) && (totalGems == 3)) {					
					//Game Win Start					
					playerHere->setGameWin(true);					
					specialComplete = true; //Special Complete			
				}
				else {
					std::cout << "<------------>\n";
					std::cout << "You need 3 gems and your Sword!\n";
					std::cout << "*Gems: " << totalGems;
					if (!haveSword) std::cout << " *Missing Sword!\n";
					else std::cout << " *Have your Sword!\n";
					std::cout << "<------------>\n";
				}
				std::cout << "\nThe monument pushes you away in a direction...\n";
				break;
			case 3:
				//Leave
				std::cout << "\nYou decide to leave. What direction?...";
				break;
			default:
				std::cout << "Invalid Menu Choice. Try again.\n\n";
				break;
			}
		} while ((choice != 1) && (choice != 2) && (choice != 3) && (playerHere->getGameWinScene() != true));
		std::cin.clear(); //Clear cin state
		std::cin.ignore(2, '\n'); //Clear Buffer
	}
}
/*---------------------------------------------------------------------------------*/
// Function: spaceOptions
// Desc: Show Special Options
/*---------------------------------------------------------------------------------*/
void Park::spaceOptions() {
	std::cout << "1. Place Gems!\n";
	std::cout << "2. Activate Monument!\n";
	std::cout << "3. Leave Area.\n";
	std::cout << "Enter Choice: ";
}