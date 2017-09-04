//////////////////// ** Author: Jared Parkinson 
//    Menu.cpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#include "Menu.hpp"
#include "Recur.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes Menu
/*---------------------------------------------------------------------------------*/
Menu::Menu(Recur* recura) {
	choice = 0; //Menu User Input	
	problist = recura; //Setup Clean ShopList
}
/*---------------------------------------------------------------------------------*/
// Function: getInput
// Description: Get Menu Input / Validate Input is Int
/*---------------------------------------------------------------------------------*/
int Menu::getInput() {
	choice = 0; //Reset Choice
	int input;
	std::cin >> input;

	//Valid number?
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');		
		std::cin >> input;
	}
	choice = input; //Set Choice
	return choice;
}
/*---------------------------------------------------------------------------------*/
// Function: showMainMenu
// Description: Show the Main Menu
/*---------------------------------------------------------------------------------*/
void Menu::showMainMenu() {
	std::cout << "-----MAIN MENU-----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Play A Game\n";
	std::cout << "2. Exit Program\n";
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: showGameMenu
// Description: Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showGameMenu() {
	std::cout << "-----GAME MENU-----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Play Game 1: Reverse String\n";
	std::cout << "2. Play Game 2: Calculate Sum\n";
	std::cout << "3. Play Game 3: Triangle Number\n";
	std::cout << "4. Back to Main\n";
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: mainMenu
// Description: Main Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::mainMenu() {
	do {
		showMainMenu();
		switch (getInput()) {
		case 1:
			clearScreen();
			std::cout << "Let's Play!\n\n";
			gameMenu();
			break;
		case 2:
			clearScreen();
			std::cout << "Exiting Program...\n\n";
			break;
		default:
			clearScreen();
			std::cout << "Invalid Menu Choice. Try again.\n\n";
			break;
		}
	} while (choice != 2);
}
/*---------------------------------------------------------------------------------*/
// Function: gameMenu
// Description: Game Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::gameMenu() {
	std::string aStr; //String Game 1
	int intGame3; //Int Game 3

	do {		
		showGameMenu();
		switch (getInput()) {			
		case 1:
			//Play Game 1: Reverse String
			clearScreen();
			std::cout << "Enter a string:\n\n";	
			std::cin.ignore(256, '\n');
			std::getline(std::cin, aStr); //Intake String			
			problist->reverseString(aStr); //Call Game Function
			break;
		case 2:
			//Play Game 2: Calculate Sum
			clearScreen();						
			std::cout << "Enter any # of ints to sum them. Follow each with Enter:\n";
			std::cout << "To finish entering, enter any negative int.\n\n";			
			std::cout << "\nThe sum is: " << problist->calcSum(problist->getProb2Arr(), 0) << std::endl;
			break;
		case 3:			
			//Play Game 3: Triangle Number
			clearScreen();
			std::cout << "Enter N rows to find the Triangle Number:\n\n";		
			intGame3 = getInput(); //Intake String
			std::cout << problist->triangleNum(intGame3) << std::endl; //Play Game 3
			break;
		case 4:
			clearScreen();
			std::cout << "Back to Main\n\n";
			break;
		default:
			clearScreen();
			std::cout << "\nInvalid Menu Choice! Try again.\n\n";
			break;
		}
	} while (choice != 4);
}
/*---------------------------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen on Windows and Linux OS
/*---------------------------------------------------------------------------------*/
void Menu::clearScreen() {
	
	//Windows
	//Sleep(400);
	//system("CLS");

	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen
	//unsigned int pause(70000);
	//usleep(pause);
}