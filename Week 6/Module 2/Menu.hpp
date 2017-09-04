//////////////////// ** Author: Jared Parkinson 
//   Menu.hpp     // *** Date: 5/11/2016
//////////////////// **** Desc: Mod 2

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"

class Menu
{
private:
	int choice;
	Stack *stackDemo;
	Queue *queueDemo;

public:
	Menu(); //Constructor
	~Menu(); //Desrcutor
	int getInput(); //Gets user input
	void showSimpleMenu(); //Shows Simple Menu
	void clearScreen(); //Clears Screen
	void runNodeDemo(); //Runs Stack or Queue program
};

#endif