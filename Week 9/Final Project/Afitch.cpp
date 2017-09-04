//////////////////// ** Author: Jared Parkinson 
//   Afitch.cpp   // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Afitch.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
Afitch::Afitch() {
	N = NULL; //North Link
	S = NULL; //South Link
	E = NULL; //East Link
	W = NULL; //West Link	
	playerHere = NULL; //Player in Space
	specialComplete = false;
	
	//Item: Blue Time Gem
	std::string tempName = "BlueGem";
	item = new Item(tempName);
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
Afitch::~Afitch() {}
/*---------------------------------------------------------------------------------*/
// Function: printSpaceDesc
// Desc: Prints the Space Description to the screen
/*---------------------------------------------------------------------------------*/
void Afitch::printSpaceDesc() {
	//Description based on Special
	if (specialComplete == false) {
		std::cout << "\n***************************************************\n";
		std::cout << "Abercrombie and Fitch: (Blue Gem)\n";
		std::cout << "You see a large banner with a half-naked person somehow\n";
		std::cout << "being displayed on the front! How can this be?!? Many \n";
		std::cout << "pretty short-haired people stare at you as you enter.\n";
		std::cout << "There seems to be some shiny blue object in the entrance.\n";
		std::cout << "Should you look at it? Hurry! Time is of the essence!\n";
		std::cout << "\n***************************************************\n";
	}
	else {
		std::cout << "\n***************************************************\n";
		std::cout << "Abercrombie and Fitch: (Blue Gem)\n";
		std::cout << "You have already picked up the Blue Gem.\n";
		std::cout << "No time to waste! Move on!\n";
		std::cout << "***************************************************\n";
	}	
}
/*---------------------------------------------------------------------------------*/
// Function: Special
// Desc: Does Special Actions / Prints if none
/*---------------------------------------------------------------------------------*/
void Afitch::Special() {
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
					std::cout << "\n**You pick up the Blue Gem!**\n";
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
void Afitch::spaceOptions() {
	std::cout << "1. Pick up Blue Gem!\n";
	std::cout << "2. Leave Area.\n";
	std::cout << "Enter Choice: ";
}