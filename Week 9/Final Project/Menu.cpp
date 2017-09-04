//////////////////// ** Author: Jared Parkinson 
//    Menu.cpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#include "Menu.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes Menu
/*---------------------------------------------------------------------------------*/
Menu::Menu()
{
	choice = 0; //Menu User Input	
	worldMap = new Map(); //Dynamic Map Pointer	
	gameComplete = false; //Set bool
	timeLimitMet = false; //Set Time Bool
	moveSpace = NULL; //Temp Space
	start = time(NULL); //Start Clock
	maxSeconds = 420; //Max Time Limit (7 mins)
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
// Description: Object destructor
/*---------------------------------------------------------------------------------*/
Menu::~Menu() {
	delete worldMap; //Free Map	
	moveSpace = NULL;
}
/*---------------------------------------------------------------------------------*/
// Function: getInput
// Description: Get Menu Input / Validate Input is Int
/*---------------------------------------------------------------------------------*/
int Menu::getInput() {
	choice = 0; //Reset Choice
	int input; //input holder	
	std::cin >> input;

	//Check Valid #
	while (!std::cin) {
		std::cout << "\nNot a valid number! \nChoose again: ";
		std::cin.clear();
		std::cin.ignore(2, '\n');
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
	std::cout << "------------------------------------\n";
	std::cout << "-----< A 'Knight' in New York >-----\n";
	std::cout << "------------------------------------\n";	
	std::cout << "Choose from the following:\n";
	std::cout << "1. Play the Game! \n";
	std::cout << "2. Exit Program\n";
	std::cout << "\n**(You have 7 mins to complete the game!)\n";
	std::cout << "Enter Choice: ";	
}
/*---------------------------------------------------------------------------------*/
// Function: showGameMenu
// Description: Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showGameMenu() {	
	double timer =  (maxSeconds - (time(NULL) - start));
	std::cout << "\n----------------------\n";
	std::cout << "You have [ " << timer << " ] seconds left!\n";
	std::cout << "Choose a direction: \n";
	std::cout << "1. Travel North\n";
	std::cout << "2. Travel South\n";
	std::cout << "3. Travel East\n";
	std::cout << "4. Travel West\n";
	std::cout << "5. ? Check Inventory\n";
	std::cout << "6. ? HELP Menu\n";
	std::cout << "----------------------\n";
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
			gameMenu();
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
	} while ((choice != 2));
}
/*---------------------------------------------------------------------------------*/
// Function: gameMenu
// Description: Direction Travel Work
/*---------------------------------------------------------------------------------*/
void Menu::gameMenu() {	
	printIntro(); //Print Game Begin	
	std::cout << "\nYou have regained consciousness...";
	worldMap->getCurSpace()->Special(); //Show first space
	//Direction Travel
	do {		
		double timer = (time(NULL) - start); //Timer
		if (timer >= maxSeconds) timeLimitMet = true; //Check Time
		showGameMenu();				
		switch (getInput()) {
		case 1: //North	
			clearScreen();	
			spaceMoveAction('N');			
			break;
		case 2: //South
			clearScreen();	
			spaceMoveAction('S');			
			break;
		case 3: //East
			clearScreen();			
			spaceMoveAction('E');			
			break;
		case 4: //West
			clearScreen();
			spaceMoveAction('W');			
			break;
		case 5: //Check Pack			
			clearScreen();
			worldMap->getCurSpace()->printSpaceDesc();
			worldMap->getPlayer()->usePack()->checkPackInv();			
			break;
		case 6: //Player Help
			clearScreen();
			printHelp();
			worldMap->getCurSpace()->printSpaceDesc();
			break;
		default:			
			std::cout << "\nInvalid Menu Choice! Try again.\n\n";
			break;
		}		
	} while ((worldMap->getPlayer()->getGameWinScene() != true) && (timeLimitMet != true));
	//Check Win
	if (worldMap->getPlayer()->getGameWinScene() == true) {
		worldMap->morphToFinalSpace(); //Final Add-Remove: Time Portal
	}
	//Final Screen
	finalPrint(); //Show Final Screen
	choice = 2; //Quit Main Menu
}
/*---------------------------------------------------------------------------------*/
// Function: spaceMoveAction
// Description: Do Space Actions per Direction
/*---------------------------------------------------------------------------------*/
void Menu::spaceMoveAction(char dir) {
	//Assign Space from direction
	moveSpace = worldMap->getDirSpace(dir);

	//Check For Space exist
	if (moveSpace == NULL) {
		std::cout << "\nCannot move that direction! Try again\n";
	}
	else if (moveSpace != NULL) {
		std::cout << "Moving..." << std::endl;
		worldMap->getCurSpace()->setPlayerLeave(); //Clear Player Space		
		worldMap->setCurSpace(moveSpace); //Set currentSpace		
		Player* tempPlayer = worldMap->getPlayer(); //Get Player
		worldMap->getCurSpace()->setPlayerHere(tempPlayer); //Set Player				
		moveSpace->Special(); //Call Special
	}
}
/*---------------------------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen Linux OS
/*---------------------------------------------------------------------------------*/
void Menu::clearScreen() {
	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen	
}
/*---------------------------------------------------------------------------------*/
// Function: printHelp
// Description: Print the help Screen
/*---------------------------------------------------------------------------------*/
void Menu::printHelp() {
	std::cout << "********************************************";
	std::cout << "\n***********     PLAYER HELP     ***********\n";	
	std::cout << "To win this game, you must do the following: \n";
	std::cout << "1. Pickup Red, Blue, and Green Time Gems.\n";	
	std::cout << "2. Pickup your lost Sword.\n";	
	std::cout << "3. Go to Park, place 3 gems(may be 2 trips, full pack).\n";
	std::cout << "4. Go to Park, activate monument with Sword in inv\n";
	std::cout << "*******************************************\n";
	std::cout << "...\n";
}
/*---------------------------------------------------------------------------------*/
// Function: printIntro
// Description: Print the game intro
/*---------------------------------------------------------------------------------*/
void Menu::printIntro() {	
	std::cout << "--------------------------------------------------------\n";
	std::cout << "You are a Lone Knight for a fallen Kingdom that has been\n";
	std::cout << "thrust forward in time by the Dread Mage Nefarious! You\n";
	std::cout << "must travel back to your own time to defeat Nefarious!\n";
	std::cout << "You have fallen from the sky and landed in a random place.\n";
	std::cout << "Collect your gear/the time Gems/and do the Park Action!\n";
	std::cout << " *The #6 Help Menu shows you what to do to win! Now Go!\n";
	std::cout << " *Game Map is randomly generated each play.\n";	
	std::cout << "--------------------------------------------------------\n";
}
/*---------------------------------------------------------------------------------*/
// Function: finalPrint
// Description: Print the final Screen, differs if timeLimit hit
/*---------------------------------------------------------------------------------*/
void Menu::finalPrint() {
	//Print the final Screen
	if (worldMap->getPlayer()->getGameWinScene() == true) { //Game has been beaten
		std::cout << "\n|||||||||||||||||||||||||||||" << std::endl;
		std::cout << "||| PLAYER WINS THE GAME! |||" << std::endl;
		std::cout << "|||||||||||||||||||||||||||||" << std::endl;		
	}
	else if (timeLimitMet) { //Time Limit has been met
		std::cout << "\n||||||||||||||||||||||" << std::endl;
		std::cout << "|||   TIME IS UP!  |||" << std::endl;
		std::cout << "||||||||||||||||||||||" << std::endl;
		
	}
}
