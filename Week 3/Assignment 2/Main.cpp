//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 4/20/2016
//////////////////// **** Desc: Assignment 2

#include <iostream>
#include "Menu.hpp"

int main() 
{
	//Initialization
	List lista; //Fresh List
	Menu menu1(&lista); //New Menu, pass List
	menu1.mainMenu(); //Start Menu System
	
	//system("PAUSE");

	return 0;
}