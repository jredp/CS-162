//////////////////// ** Author: Jared Parkinson 
//    Menu.hpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#ifndef MENU_HPP
#define MENU_HPP

#include <unistd.h> //Linux Sleep
//#include <windows.h> //Windows Sleep
#include "List.hpp"

class Menu
{
private:
	int choice; //Menu Choice
	List* shoplist; //Clean Shop List
public:
	Menu(List* lista); //No Default
	int getInput(); //Get Menu Choice
	void mainMenu(); //Check Options
	void gameMenu(); //Check Options
	void showMainMenu(); //Display Main Menu	
	void showGameMenu(); //Display Game Menu
	void clearScreen(); //Clear the screen
	void addItemQuest(); //Add Item to List Questions
	void delItemQuest(); //Del Item from List Question
};

#endif