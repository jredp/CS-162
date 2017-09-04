//////////////////// ** Author: Jared Parkinson 
//    Menu.hpp    // *** Date: 5/18/2016
//////////////////// **** Desc: Assignment 4

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
#include "Team.hpp"

class Menu
{
private:
	int choice; //Menu Choice
	/*---------NEW-----------*/
	int fighterAmount; //Desired Fighter Amount for each team		
	Creature *fighter1, *fighter2; //Fighter Pointers
	Team player1, player2; //Teams for Players 1&2	
	/*---------NEW-----------*/
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
	/*---------NEW-----------*/	
	void setFighterAmount(int amt); //Set Fighter Amount
	int getFighterAmount(); //Get Fighter Amount	
	void battle(); //Do Battle
	void winTeam(); //Show winning Team
	/*---------NEW-----------*/
};

#endif