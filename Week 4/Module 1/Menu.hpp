//////////////////// ** Author: Jared Parkinson 
//    Menu.hpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#ifndef MENU_HPP
#define MENU_HPP

#include <unistd.h> //Linux
//#include <windows.h> //Windows
#include "Recur.hpp"
#include <sstream>

class Menu
{
private:
	int choice; //Menu Choice
	Recur* problist; //Clean Shop List
public:
	Menu(Recur* recura); //No Default
	int getInput(); //Get Menu Choice
	void mainMenu(); //Check Options
	void gameMenu(); //Check Options
	void showMainMenu(); //Display Main Menu	
	void showGameMenu(); //Display Game Menu
	void clearScreen(); //Clear the screen	
};

#endif