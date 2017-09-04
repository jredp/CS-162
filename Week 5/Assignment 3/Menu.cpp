//////////////////// ** Author: Jared Parkinson 
//    Menu.cpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#include "Menu.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes Menu
/*---------------------------------------------------------------------------------*/
Menu::Menu() 
{
		choice = 0; //Menu User Input	
		finishRun = false; //Mark run finish
		attacker = NULL; //Init NULL
		defender = NULL; //Init NULL
		//Init Empty pointers for potential fighters
		ptrBaba1 = NULL, ptrBarb1 = NULL, ptrBlue1 = NULL, ptrMedu1 = NULL, ptrHarr1 = NULL;
		ptrBaba2 = NULL, ptrBarb2 = NULL, ptrBlue2 = NULL, ptrMedu2 = NULL, ptrHarr2 = NULL;
}
Menu::~Menu()
{
	//Free memory only if used
	if (ptrBaba1 != NULL) delete ptrBaba1; if (ptrBaba2 != NULL) delete ptrBaba2;
	if (ptrBarb1 != NULL) delete ptrBarb1;	if (ptrBarb2 != NULL) delete ptrBarb2;
	if (ptrBlue1 != NULL) delete ptrBlue1; if (ptrBlue2 != NULL) delete ptrBlue2;
	if (ptrMedu1 != NULL) delete ptrMedu1; if (ptrMedu2 != NULL) delete ptrMedu2;
	if (ptrHarr1 != NULL) delete ptrHarr1; if (ptrHarr2 != NULL) delete ptrHarr2;
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
	std::cout << "\n-----MAIN MENU-----\n";
	std::cout << "Choose from the following options:\n";
	std::cout << "1. Fight!! \n";
	std::cout << "2. Exit Program\n";
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: showGameMenu1
// Description: Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showGameMenu1() {	
	std::cout << "-----ATTACK MENU-----\n";
	std::cout << "Choose starting ATTACKER Fighter 1!:\n";		
	std::cout << "1. Baba Yaga\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n";
	std::cout << "6. Back to Main\n";	
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: showGameMenu2
// Description: Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showGameMenu2() {
	std::cout << "-----DEFEND MENU-----\n";
	std::cout << "Choose starting DEFENDER! Figher 2:\n";
	std::cout << "1. Baba Yaga\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n";
	std::cout << "6. Back to Main\n";	
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: mainMenu
// Description: Main Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::mainMenu() {	
	showMainMenu();
	do {
		switch (getInput()) {
		case 1:
			clearScreen();
			std::cout << "\nLETS FIGHT!\n\n";
			gameMenu1();
			break;
		case 2:
			clearScreen();
			std::cout << "Exiting Program...\n\n";
			break;
		default:
			clearScreen();
			std::cout << "Invalid Menu Choice. Try again.\n\n";
			showMainMenu();
			break;
		}	
	} while ((choice != 2) && (finishRun == false));
}
/*---------------------------------------------------------------------------------*/
// Function: gameMenu1 Attack
// Description: Attack Game Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::gameMenu1() {
	do {
		showGameMenu1();
		switch (getInput()) {
		case 1: //Baba Yaga			
			clearScreen();			
			std::cout << "\nBaba Yaga is the Attacker!\n\n";			
			if (ptrBaba1 == NULL)ptrBaba1 = new Babayaga; //NEW with leak check
			attacker = ptrBaba1;
			attackCheck();
			break;
		case 2: //Barbarian			
			clearScreen();			
			std::cout << "\nBarbarian is the Attacker!\n\n";			
			if (ptrBarb1 == NULL)ptrBarb1 = new Barbarian; //NEW with leak check
			attacker = ptrBarb1;
			attackCheck();
			break;
		case 3: //Blue Men			
			clearScreen();
			std::cout << "\nBlue Men are the Attackers!\n\n";
			if (ptrBlue1 == NULL)ptrBlue1 = new Bluemen; //NEW with leak check
			attacker = ptrBlue1;
			attackCheck();
			break;
		case 4: //Medusa			
			clearScreen();
			std::cout << "\nMedusa is the Attacker!\n\n";
			if (ptrMedu1 == NULL)ptrMedu1 = new Medusa; //NEW with leak check
			attacker = ptrMedu1;
			attackCheck();
			break;
		case 5: //Harry Potter			
			clearScreen();
			std::cout << "\nHarry Potter is the Attacker!\n\n";
			if (ptrHarr1 == NULL)ptrHarr1 = new Harrypotter; //NEW with leak check
			attacker = ptrHarr1;
			attackCheck();
			break;
		case 6:
			clearScreen();
			std::cout << "\nBack to Main Menu...\n";
			break;
		default:
			clearScreen();
			std::cout << "\nInvalid Menu Choice! Try again.\n\n";
			break;
		}
	} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) && (finishRun == false));	
	clearChoice();
}
/*---------------------------------------------------------------------------------*/
// Function: gameMenu2 Defend
// Description: Defend Game Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::gameMenu2() {	
	do {	
		showGameMenu2();	
		switch (getInput()) {
		case 1:
			//Baba Yaga
			clearScreen();
			std::cout << "\nBaba Yaga is the Defender!\n";		
			if (ptrBaba2 == NULL)ptrBaba2 = new Babayaga; //NEW with leak check
			defender = ptrBaba2;
			defendCheck();			
			break;
		case 2:
			//Barbarian
			clearScreen();
			std::cout << "\nBarbarian is the Defender!\n";			
			if (ptrBarb2 == NULL)ptrBarb2 = new Barbarian; //NEW with leak check
			defender = ptrBarb2;		
			defendCheck();			
			break;
		case 3:
			//Blue Men
			clearScreen();
			std::cout << "\nBlue Men are the Defenders!\n";		
			if (ptrBlue2 == NULL)ptrBlue2 = new Bluemen; //NEW with leak check
			defender = ptrBlue2;
			defendCheck();			
			break;
		case 4:
			//Medusa	
			clearScreen();
			std::cout << "\nMedusa is the Defender!\n";	
			if (ptrMedu2 == NULL)ptrMedu2 = new Medusa; //NEW with leak check
			defender = ptrMedu2;
			defendCheck();			
			break;
		case 5:
			//Harry Potter	
			clearScreen();
			std::cout << "\nHarry Potter is the Defender!\n";					
			if (ptrHarr2 == NULL)ptrHarr2 = new Harrypotter; //NEW with leak check
			defender = ptrHarr2;
			defendCheck();				
			break;
		case 6:
			clearScreen();
			std::cout << "\nBack to Main\n\n";			
			break;
		default:
			clearScreen();			
			std::cout << "\nInvalid Menu Choice! Try again.\n\n";
			break;
		}
	} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) && (finishRun == false));	
	choice = 2; finishRun = true;
}
/*---------------------------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen on Windows and Linux OS
/*---------------------------------------------------------------------------------*/
void Menu::clearScreen() {

	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen
	//unsigned int pause(70000);
	//usleep(pause);
}
/*---------------------------------------------------------------------------------*/
// Function: clearChoice
// Description: Clears the last user Choice
/*---------------------------------------------------------------------------------*/
void Menu::clearChoice() {
	choice = 0;
}
/*---------------------------------------------------------------------------------*/
// Function: attackCheck
// Description: Checks for dead character
/*---------------------------------------------------------------------------------*/
void Menu::attackCheck() {
	//Checking death removed temporarily due to Forum stating 1 round
	gameMenu2(); //Choose Fighter 2
}
/*---------------------------------------------------------------------------------*/
// Function: defendCheck
// Description: Checks for dead character or attacking self
/*---------------------------------------------------------------------------------*/
void Menu::defendCheck() {	
	//Checking death removed temporarily due to Forum stating 1 round
	battle(); //Start Battle
}
/*---------------------------------------------------------------------------------*/
// Function: battle
// Description: Battle it out between the two characters
/*---------------------------------------------------------------------------------*/
void Menu::battle() {
	Creature *tempAtker = attacker; //Temp Swap Atk
	Creature *tempDfder = defender; //Temp Swap Def

	//While attacker or Defender are not dead
	while ((tempAtker->getIsDead() != true) && (tempDfder->getIsDead() != true)) {		
		std::cout << "\n-----------\n" << " Attacking!\n" << "-----------\n";
		int attackAmt = tempAtker->attack();
		std::cout << "Attack Roll: " << attackAmt << std::endl;
		std::cout << "\n-----------\n" << " Defending!\n" << "-----------\n";
		std::cout << "Strength before Attack: " << tempDfder->getStrength() << std::endl;
		tempDfder->defend(attackAmt);
		std::cout << "Final Str after Defend: " << tempDfder->getStrength() << std::endl;

		//Repeat with Swapped Pointers
		Creature *swap = NULL;
		swap = tempAtker;
		tempAtker = tempDfder;
		tempDfder = swap;	
	}	
}