//////////////////// ** Author: Jared Parkinson 
//    Menu.cpp    // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

#include "Menu.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor - Initializes Menu
/*---------------------------------------------------------------------------------*/
Menu::Menu() 
{
		choice = 0; //Menu User Input	
		fighter1 = NULL; //Init NULL
		fighter2 = NULL; //Init NULL		
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
// Description: Object destructor
/*---------------------------------------------------------------------------------*/
Menu::~Menu() {}
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
	std::cout << "1. Tournament Battle! \n";
	std::cout << "2. Exit Program\n";
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: showGameMenu1
// Description: Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showGameMenu1() {	
	std::cout << "-----Player 1 MENU-----\n";
	std::cout << "Choose starting Lineup for Player 1:\n";
	std::cout << "1. Baba Yaga\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n";	
	std::cout << "Enter Choice: ";
}
/*---------------------------------------------------------------------------------*/
// Function: showGameMenu2
// Description: Show the Game Menu
/*---------------------------------------------------------------------------------*/
void Menu::showGameMenu2() {
	std::cout << "-----Player 2 MENU-----\n";
	std::cout << "Choose starting Lineup for Player 2:\n";
	std::cout << "1. Baba Yaga\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n";	
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
	} while ((choice != 2));
}
/*---------------------------------------------------------------------------------*/
// Function: gameMenu1 Attack
// Description: Attack Game Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::gameMenu1() {	
	int player1picked = 0; //Player Pick Count		
	std::string fighterName; //Fighter Name
	
	//User Input Fighter Amount / make arrays
	do {
		std::cout << "Enter # of Fighters desired each team:\n";
		std::cout << "(MUST be 3 or greater):\n\n";
		setFighterAmount(getInput()); //Get amount of Fighters
	} while ((choice < 3));	
	int choicesLeft = getFighterAmount(); //Choices Left
	player1.makeArray(getFighterAmount()); //Make P1array of this size
	player2.makeArray(getFighterAmount()); //Make P2array of this size

	//Choose Fighters
	do {
		showGameMenu1();
		switch (getInput()) {
		case 1: //Baba Yaga			
			clearScreen();
			std::cout << "Baba Yaga has been chosen!\n\n";			
			fighter1 = new Babayaga; //Dynamic Derived Class			
			break;
		case 2: //Barbarian			
			clearScreen();
			std::cout << "Barbarian has been chosen!\n\n";
			fighter1 = new Barbarian; //Dynamic Derived Class
			break;
		case 3: //Blue Men			
			clearScreen();
			std::cout << "Blue Men have been chosen!\n\n";
			fighter1 = new Bluemen; //Dynamic Derived Class
			break;
		case 4: //Medusa			
			clearScreen();
			std::cout << "Medusa has been chosen!\n\n";
			fighter1 = new Medusa; //Dynamic Derived Class
			break;
		case 5: //Harry Potter			
			clearScreen();
			std::cout << "Harry Potter has been chosen!\n\n";
			fighter1 = new Harrypotter; //Dynamic Derived Class
			break;		
		default:
			clearScreen();
			std::cout << "\nInvalid Menu Choice! Try again.\n\n";
			break;
		}
		fighter1->setFighterID(); //Set Name ID
		player1.addLineupNode(fighter1); //New Node with creature added
		player1.insertArray(fighter1); //Insert fighter into array
		fighter1 = NULL; //Clear Pointer
		player1picked++, choicesLeft--; //Increment picked / Decrement Choices			
		if (choicesLeft>0) std::cout << "Player 1 choices left: " << choicesLeft << std::endl;
	} while (player1picked != getFighterAmount());
		
	clearChoice();
	gameMenu2(); //Player 2 Menu
}
/*---------------------------------------------------------------------------------*/
// Function: gameMenu2 Defend
// Description: Defend Game Menu Options
/*---------------------------------------------------------------------------------*/
void Menu::gameMenu2() {	
	int player2picked = 0; //Player Pick Count
	int choicesLeft = (getFighterAmount());
	clearScreen();
	do {		
		showGameMenu2();
		switch (getInput()) {
		case 1: //Baba Yaga			
			clearScreen();
			std::cout << "Baba Yaga has been chosen!\n";
			fighter2 = new Babayaga; //Dynamic Derived Class			
			break;
		case 2:	//Barbarian
			clearScreen();
			std::cout << "Barbarian has been chosen!\n";
			fighter2 = new Barbarian; //Dynamic Derived Class
			break;
		case 3: //Blue Men			
			clearScreen();
			std::cout << "Blue Men have been chosen!\n";
			fighter2 = new Bluemen; //Dynamic Derived Class
			break;
		case 4: //Medusa				
			clearScreen();
			std::cout << "Medusa has been chosen!\n";
			fighter2 = new Medusa; //Dynamic Derived Class
			break;
		case 5: //Harry Potter				
			clearScreen();
			std::cout << "Harry Potter has been chosen!\n";
			fighter2 = new Harrypotter; //Dynamic Derived Class			
			break;		
		default:
			clearScreen();
			std::cout << "\nInvalid Menu Choice! Try again.\n\n";
			break;
		}
		fighter2->setFighterID(); //Get Name
		player2.addLineupNode(fighter2); //New Node with creature added	
		player2.insertArray(fighter2); //Insert fighter into array
		fighter2 = NULL; //Clear Pointer
		player2picked++, choicesLeft--; //Increment picked / Decrement Choices			
		if (choicesLeft>0) std::cout << "Player 2 choices left: " << choicesLeft << std::endl;
	} while (player2picked != getFighterAmount());		
	
	battle(); //Start the battle	
	choice = 2; 	
}
/*---------------------------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen on Windows and Linux OS
/*---------------------------------------------------------------------------------*/
void Menu::clearScreen() {
	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen	
}
/*---------------------------------------------------------------------------------*/
// Function: clearChoice
// Description: Clears the last user Choice
/*---------------------------------------------------------------------------------*/
void Menu::clearChoice() {
	choice = 0;
}
/*---------------------------------------------------------------------------------*/
// Function: battle
// Description: Battle it out between the two characters
/*---------------------------------------------------------------------------------*/
void Menu::battle() {
	while ((!player1.LineupEmptyChk()) && (!player2.LineupEmptyChk())) {
		fighter1 = player1.removeLineupNode(); //Removed P1 Front Node
		fighter2 = player2.removeLineupNode(); //Removed P2 Front Node
		Creature *tempAtker = fighter1, *tempDfder = fighter2; //Temp Swap Fighters

		//While Fighters not dead, battle back and forth
		std::cout << "\n---Fight Round---\n";		
		while ((tempAtker->getIsDead() != true) && (tempDfder->getIsDead() != true)) {
			int attackAmt = tempAtker->attack(); //Get Attack Amt
			tempDfder->defend(attackAmt); //Get Defend Amt			
			Creature *swap = NULL; //Repeat with Swapped Pointers
			swap = tempAtker, tempAtker = tempDfder, tempDfder = swap;
		}
		tempAtker = NULL, tempDfder = NULL; //Free temp ptrs

		//Fighter Shuffling Lineup or Loser Pile
		if (fighter1->getIsDead() != true) { //Fighter 1 Alive
			std::cout << "\n***Winner - Type: " << fighter1->getClassType() << "    Name: "
				<< fighter1->getFighterID() << "    Wins: " << fighter1->getWins() << 
				"    Score: " << fighter1->getFighterScore() << std::endl;
			player1.addLineupNode(fighter1); //put F1 back of P1 Lineup
			fighter1->restoreHP(); //Restore some HP
			fighter1->incWins(); //Increase wins by 1
			player2.addLoserNode(fighter2); //put F2 in LoserPile of P2						
		}
		else {
			std::cout << "\n***Winner - Type: " << fighter2->getClassType() << "    Name: "
				<< fighter2->getFighterID() << "    Wins: " << fighter2->getWins() <<
				"    Score: " << fighter2->getFighterScore() << std::endl;
			player2.addLineupNode(fighter2); //put F2 back of P2 Lineup
			fighter1->restoreHP(); //Restore some HP
			fighter2->incWins(); //Increase wins by 1
			player1.addLoserNode(fighter1); //put F1 in LoserPile of P1			
		}
		fighter1 = NULL, fighter2 = NULL; //Free temp ptrs		
	}
	winTeam(); //Show the winning credits
}
/*---------------------------------------------------------------------------------*/
// Function: winTeam
// Description: Show the winning printout
/*---------------------------------------------------------------------------------*/
void Menu::winTeam() {
	//Final Team Empty Check, print winning team
	if (player1.LineupEmptyChk()) { //Lineup is empty P1
		std::cout << "\n||||||||||||||||||||||" << std::endl;
		std::cout << "||| PLAYER 2 WINS! |||" << std::endl;
		std::cout << "||||||||||||||||||||||" << std::endl;
		player2.setWinners(); //Set winners from P2
		player1.printRemoveLoser();	//Print and remove Loser Pile P2	
	}	
	else if (player2.LineupEmptyChk()) { //Lineup is empty P2
		std::cout << "\n||||||||||||||||||||||" << std::endl;
		std::cout << "||| PLAYER 1 WINS! |||" << std::endl;
		std::cout << "||||||||||||||||||||||" << std::endl;
		player1.setWinners(); //Set winners from P1
		player2.printRemoveLoser(); //Print and remove Loser Pile P2
	}	
}
/*---------------------------------------------------------------------------------*/
// Function: getFighterAmt
// Description: Get the Fighter Amount
/*---------------------------------------------------------------------------------*/
int Menu::getFighterAmount() {
	return fighterAmount;
}
/*---------------------------------------------------------------------------------*/
// Function: setFighterAmt
// Description: Set the Fighter Amount
/*---------------------------------------------------------------------------------*/
void Menu::setFighterAmount(int amt) {
	fighterAmount = amt;
}