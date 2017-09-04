//////////////////// ** Author: Jared Parkinson 
//  Statue.cpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Statue.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Statue::Statue() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link	
	playerHere = NULL; //Player in Space
	specialComplete = false;

	//Item: Sword
	std::string tempName = "Sword";
	item = new Item(tempName);
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Statue::~Statue() {}
/*---------------------------------------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*---------------------------------------------------------------------------------*/
void Statue::printSpaceDesc() {
	//Description based on Special
	if (specialComplete == false) {
		std::cout << "\n***************************************************\n";
		std::cout << "STATUE: (Sword)\n";
		std::cout << "You have arrived at some sort of large Worship Statue. It \n";
		std::cout << "appears to be a False God your Bishop has spoken about!\n";
		std::cout << "You see a faint glimmer atop the False God. You enter and\n";
		std::cout << "climb to the top of the statue to find your Sword!\n";		
		std::cout << "***************************************************\n";
	}
	else {
		std::cout << "\n***************************************************\n";
		std::cout << "STATUE: (Sword)\n";
		std::cout << "You have already picked up your Sword.\n";
		std::cout << "No time to waste! Move on!\n";
		std::cout << "***************************************************\n";
	}
}
/*---------------------------------------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*---------------------------------------------------------------------------------*/
void Statue::Special() {
	printSpaceDesc();
	if (specialComplete == false) {
		int choice;
		bool pickedUp; //Pickup Success!
		Knapsack* tempPack = playerHere->usePack();
		spaceOptions();
		do {
			switch (choice = spaceInput()) {
			case 1:
				//Pickup Item if pack not full
				pickedUp = tempPack->addPack(item);
				if (pickedUp) {
					std::cout << "\n**You pick up your Sword!.**\n";
					specialComplete = true;
					item = NULL; //No item in space
				}
				break;
			case 2:
				std::cout << "\nYou decide to leave. What direction?";
				break;
			default:
				std::cout << "Invalid Menu Choice. Try again.\n\n";
				break;
			}
		} while ((choice != 1) && (choice != 2));
		std::cin.clear(); //Clear cin state
		std::cin.ignore(2, '\n'); //Clear Buffer
	}
}
/*---------------------------------------------------------------------------------*/
// Function: spaceOptions
// Desc: Show Special Options
/*---------------------------------------------------------------------------------*/
void Statue::spaceOptions() {
	std::cout << "1. Pick up your Sword!\n";
	std::cout << "2. Leave Area.\n";
	std::cout << "Enter Choice: ";
}