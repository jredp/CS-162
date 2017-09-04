//////////////////// ** Author: Jared Parkinson 
//    Main.cpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#include <iostream>
#include "Menu.hpp"

int main()
{
	//Initialization
	Recur recurA; //Game Object
	Menu menu1(&recurA); //New Menu, pass Game Object
	menu1.mainMenu(); //Start Menu System

	//system("PAUSE");

	return 0;
}