//////////////////// ** Author: Jared Parkinson 
//    Menu.hpp    // *** Date: 5/28/2016
//////////////////// **** Desc: Final

#ifndef MENU_HPP
#define MENU_HPP

#include <unistd.h> //Linux
#include <time.h>
#include <iostream>

#include "Map.hpp"

class Menu
{
private:
	time_t start; //Starting Clock
	double maxSeconds; //Time Limit
	int choice; //Menu Choice	
	bool gameComplete; //Game Complete Bool
	bool timeLimitMet; //Time Limit bool
	Map* worldMap; //Map pointer	
	Space* moveSpace; //Space for Movement
	
public:
	Menu(); //Constructor
	~Menu(); //Destructor	
	void mainMenu(); //Check Options
	void gameMenu(); //Check Options	
	void showMainMenu(); //Display Main Menu	
	void showGameMenu(); //Display Game Menu
	void clearScreen(); //Clear the screen	
	int getInput(); //Get Menu Choice / TIME LIMIT
	void setGameComplete(bool set); //Set the bool of gameComplete
	void spaceMoveAction(char dir); //Do Space Move Actions per Direction	
	void printHelp(); //Print Player Help
	void printIntro(); //Print Game Intro
	void finalPrint(); //Show Final Screen
};

#endif
