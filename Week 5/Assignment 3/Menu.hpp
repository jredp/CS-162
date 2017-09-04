//////////////////// ** Author: Jared Parkinson 
//    Menu.hpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#ifndef MENU_HPP
#define MENU_HPP

#include <unistd.h> //Linux

#include <sstream>
#include <iostream>

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Babayaga.hpp"
#include "Bluemen.hpp"
#include "Medusa.hpp"
#include "Harrypotter.hpp"

class Menu
{
private:
	int choice; //Menu Choice
	bool finishRun;
	Creature *attacker; //Attacker Pointer
	Creature *defender; //Defender Pointer
	Barbarian *ptrBarb1, *ptrBarb2; //Atk Def Pointers
	Babayaga *ptrBaba1, *ptrBaba2; //Atk Def Pointers
	Bluemen *ptrBlue1, *ptrBlue2; //Atk Def Pointers
	Medusa *ptrMedu1, *ptrMedu2; //Atk Def Pointers
	Harrypotter *ptrHarr1, *ptrHarr2; //Atk Def Pointers
	
public:
	Menu();
	~Menu();	
	int getInput(); //Get Menu Choice
	void mainMenu(); //Check Options
	void gameMenu1(); //Check Options
	void gameMenu2(); //Check Options
	void showMainMenu(); //Display Main Menu	
	void showGameMenu1(); //Display Game Menu 1 Attacker
	void showGameMenu2(); //Display Game Menu 2 Defender
	void clearChoice(); //Clear the last user choice
	void clearScreen(); //Clear the screen	
	void attackCheck(); //Check for Dead
	void defendCheck(); //Check for Attack/Defend
	void battle(); //Do Battle
};

#endif