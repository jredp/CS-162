//////////////////// ** Author: Jared Parkinson 
//   Menu.cpp     // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#include "Menu.hpp"

/*-------------------------------------------------------------*/
// Function: Constructor
/*-------------------------------------------------------------*/
Menu::Menu() {
	choice = 0;
	stackDemo = NULL;
	queueDemo = NULL;	
}
/*-------------------------------------------------------------*/
// Function: Destructor
/*-------------------------------------------------------------*/
Menu::~Menu() {
	//Check for Demo usage, delete as necessary
	if (stackDemo != NULL) delete stackDemo;
	if (queueDemo != NULL) delete queueDemo;
}
/*-------------------------------------------------------------*/
// Function: getInput - Simple User Input Validator
// Description: Get Menu Input / Validate Input is Int
/*-------------------------------------------------------------*/
int Menu::getInput() {
	int choice = 0; //Reset Choice
	int input; //User Input
	std::cin >> input; 

	//Check for Valid Input
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}
	choice = input; //Set Choice
	return choice;
}
/*-------------------------------------------------------------*/
// Function: showSimpleMenu
// Description: Show the Simple Main Menu
/*-------------------------------------------------------------*/
void Menu::showSimpleMenu() {
	std::cout << "\n----- STACK / QUEUE -----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Run Stack Program \n";
	std::cout << "2. Run Queue Program \n";
	std::cout << "3. Exit Program \n";
	std::cout << "Enter Choice: ";
}
/*-------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen on Windows and Linux OS
/*-------------------------------------------------------------*/
void Menu::clearScreen() {
	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen	
}
/*-------------------------------------------------------------*/
// Function: runNodeDemo
// Description: Responsible for running Queue or Stack programs
/*-------------------------------------------------------------*/
void Menu::runNodeDemo() {
	do {
		switch (choice = getInput()) {
		case 1:
			//Stack Demo Program
			clearScreen();
			stackDemo = new Stack;
			stackDemo->runStack();
			choice = 3; //Leave Program
			break;
		case 2:
			//Queue Demo Program
			clearScreen();
			queueDemo = new Queue;
			queueDemo->runQueue();
			choice = 3; //Leave Program
			break;
		case 3:
			//Exit
			clearScreen();
			std::cout << "Exiting program... \n";
			break;
		default:
			//Check Input
			clearScreen();
			std::cout << "Invalid Menu Choice. Try again.\n\n";
			break;
		}
	} while (choice != 3);
}