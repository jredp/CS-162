//////////////////// ** Author: Jared Parkinson 
//    Menu.cpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#include "Menu.hpp"
#include "List.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes Menu
/*---------------------------------------------------------------------------------*/
Menu::Menu(List* lista) {
	choice = 0; //Menu User Input	
	shoplist = lista; //Setup Clean ShopList
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
		//std::cin.ignore();
		std::cin >> input;
	}
	choice = input; //Set Choice
	return choice;
}
/*---------------------------------------------------------------------------------*/
// Function: showMainMenu, showGameMenu
// Description: Show the Main Menu, Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showMainMenu() {
	std::cout << "-----MAIN MENU-----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Go Shopping\n";
	std::cout << "2. Leave Store\n";
	std::cout << "Enter Choice: ";
}
void Menu::showGameMenu() {
	std::cout << "-----GAME MENU-----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Display Items in Cart List\n";
	std::cout << "2. Add Item\n";
	std::cout << "3. Remove Item\n";
	std::cout << "4. Back to Main Menu\n";
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
				std::cout << "Let's SHOP!\n\n";				
				gameMenu();
				break;
			case 2:
				clearScreen();
				std::cout << "Quitting...\n";				
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
	do {
//		clearScreen();
		showGameMenu();
		switch (getInput()) {
			case 1:
				//display list
				std::cout << "\nDisplaying List\n";
				clearScreen();
				//Display Shop list
				shoplist->printList();
				break;
			case 2:
				//AddItem
				clearScreen();
				//Cout Add Item Requests
				addItemQuest();				
				break;
			case 3:
				//DeleteItem
				clearScreen();
				//Cout Delete Item Requests
				delItemQuest();
				std::cout << "\nDeleting Item\n";
				break;
			case 4:
				//MainMenu
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
	//Sleep by OS	
		//Windows
		//Sleep(400);
		//system("CLS");

		//Linux
		std::cout << "\033[2J\033[1;1H"; //Clears Screen
		unsigned int pause(70000);
		usleep(pause);
}
/*---------------------------------------------------------------------------------*/
// Function: addItemQuest
// Description: Questions for adding new item
/*---------------------------------------------------------------------------------*/
void Menu::addItemQuest() {
	//Init Input Vars
	string itemNam;
	string unitTyp;
	int buyAmt;
	double unitPric;

	std::cout << "-----Add a New Item to List-----\n";
	std::cout << "Name of the item you want (Letters & spaces) *25 max chars:\n";	
	//std::cin.ignore(500, '\n'); //Clear Space for cin	
	std::cin.ignore();
	std::getline (std::cin, itemNam); //getline gets spaces
	//std::getline(std::cin, 25); //getline gets spaces
	std::cout << "\nUnit type of the item (IE: can, box, pounds, ounces) *10 max chars:\n";	
	std::getline(std::cin, unitTyp); //getline gets spaces	
	std::cout << "\nNumber of the item to buy (Whole Num only):\n";
	std::cin >> buyAmt;
	std::cout << "\nCost of item per unit:\n";
	std::cin >> unitPric;
	std::cout << "\nAttempting Add Item..........\n";
	shoplist->addToList(itemNam, unitTyp, buyAmt, unitPric); //Add new item to list
}
/*---------------------------------------------------------------------------------*/
// Function: delItemQuest
// Description: Questions for deleting new item
/*---------------------------------------------------------------------------------*/
void Menu::delItemQuest() {
	string itemNam;
	std::cout << "-----Delete an Item from List-----\n";
	std::cout << "Please type the name of the item you want to remove (letters & spaces allowed):\n";
	std::cin.ignore(500, '\n'); //Clear Space for cin	
	//std::cin.ignore();
	std::getline(std::cin, itemNam); //getline gets spaces	
	shoplist->delFromList(itemNam); //Run Deletion Function, pass name
}