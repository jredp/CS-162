#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;

#include "Grid.hpp"

int main()
{
	//Initialization
	Critter CritterA;
	int xSize; // User input Grid X Size
	int ySize; // User input Grid Y Size	

/*--------------------------------*/

	//Ask for Grid Size
	std::cout << "Please enter the Grid Size." << std::endl;
	std::cout << "Enter the number of Rows (Height)" << std::endl;
	std::cin >> xSize;
		//X Size Catch
		while (CritterA.validSize(xSize) == false) {
			std::cout << "You must choose a size of 1 or higher." << std::endl;
			std::cout << "Enter the number of Rows (Height)" << std::endl;
			std::cin >> xSize;
		}
	std::cout << "Enter the number of Columns (Width)" << std::endl;
	std::cin >> ySize;
		//Y Size Catch
		while (CritterA.validSize(xSize) == false) {
			std::cout << "You must choose a size of 1 or higher." << std::endl;
			std::cout << "Enter the number of Columns (Width)" << std::endl;
			std::cin >> ySize;
		}

	//Create Grid Object
	Grid GridA(xSize, ySize);
	//Random Critter Start
	GridA.setStartCritterGrid(CritterA);		
	//Update Critter Location - Makes Moves
	GridA.updateLocation(CritterA);

	return 0;
}