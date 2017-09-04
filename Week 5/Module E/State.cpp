//////////////////// ** Author: Jared Parkinson 
//    State.cpp   // *** Date: 5/3/2016
//////////////////// **** Desc: Mod E

#include "State.hpp"

State::State(char light1, char light2) {
	direction1 = light1; //North	
	direction3 = light1; //South
	direction2 = light2; //East
	direction4 = light2; //West
	
	nextState = NULL;
	NorLightNumVeh = 0, EasLightNumVeh = 0;
	SouLightNumVeh = 0, WesLightNumVeh = 0;
	arrivN = 0, arrivS = 0, arrivE = 0, arrivW = 0;
	depN = 0, depS = 0, depE = 0, depW = 0;
}
State::~State() {
	nextState = NULL;
}
/*---------------------------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen on Windows and Linux OS
/*---------------------------------------------------------------------------------*/
void State::clearScreen() {
	
	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen
	//unsigned int pause(70000);
	//usleep(pause);
}
/*---------------------------------------------------------------------------------*/
// Function: printLanes
// Description: Prints the lane information
/*---------------------------------------------------------------------------------*/
void State::printLanes() {
	clearScreen();
	std::cout << "----------------------------------" << std::endl;
	//Green NS
	if (direction1 == 'G') {
		std::cout << "*** STATE 1 ***" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "North Lane: GREEN" << std::endl;
		std::cout << "North Lane Arriving Vehicles: " << arrivN << std::endl;
		std::cout << "North Lane Departing Vehicles: " << depN << std::endl;
		std::cout << "N Lane Current Veh After Departures: " << NorLightNumVeh << std::endl;
		std::cout << "\nSouth Lane: GREEN" << std::endl;
		std::cout << "South Lane Arriving Vehicles: " << arrivS << std::endl;
		std::cout << "South Lane Departing Vehicles: " << depS << std::endl;
		std::cout << "S Lane Current Veh After Departures: " << SouLightNumVeh << std::endl;
		std::cout << "\nNo activity East or West" << std::endl;
	}
	//Green EW
	else if (direction2 == 'G') {
		std::cout << "*** STATE 3 ***" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "East Lane: GREEN" << std::endl;
		std::cout << "East Lane Arriving Vehicles: " << arrivE << std::endl;
		std::cout << "East Lane Departing Vehicles: " << depE << std::endl;
		std::cout << "E Lane Current Veh After Departures: " << EasLightNumVeh << std::endl;
		std::cout << "\nWest Lane: GREEN" << std::endl;
		std::cout << "West Lane Arriving Vehicles: " << arrivW << std::endl;
		std::cout << "West Lane Departing Vehicles: " << depW << std::endl;
		std::cout << "W Lane Current Veh After Departures: " << WesLightNumVeh << std::endl;
		std::cout << "\nNo activity North or South" << std::endl;
	}
	//Yellow NS
	if (direction1 == 'Y') {
		std::cout << "*** STATE 2 ***" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "North Lane: YELLOW" << std::endl;
		std::cout << "North Lane Arriving Vehicles: " << arrivN << std::endl;
		std::cout << "North Lane Departing Vehicles: " << depN << std::endl;
		std::cout << "N Lane Current Veh After Departures: " << NorLightNumVeh << std::endl;
		std::cout << "\nSouth Lane: YELLOW" << std::endl;
		std::cout << "South Lane Arriving Vehicles: " << arrivS << std::endl;
		std::cout << "South Lane Departing Vehicles: " << depS << std::endl;
		std::cout << "S Lane Current Veh After Departures: " << SouLightNumVeh << std::endl;
		std::cout << "\nNo activity requested on YELLOW" << std::endl;
	}	
	//Yellow EW
	else if (direction2 == 'Y') {
		std::cout << "*** STATE 4 ***" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "East Lane: YELLOW" << std::endl;
		std::cout << "East Lane Arriving Vehicles: " << arrivE << std::endl;
		std::cout << "East Lane Departing Vehicles: " << depE << std::endl;
		std::cout << "E Lane Current Veh After Departures: " << EasLightNumVeh << std::endl;
		std::cout << "\nWest Lane: YELLOW" << std::endl;
		std::cout << "West Lane Arriving Vehicles: " << arrivW << std::endl;
		std::cout << "West Lane Departing Vehicles: " << depW << std::endl;
		std::cout << "W Lane Current Veh After Departures: " << WesLightNumVeh << std::endl;
		std::cout << "\nNo activity requested on YELLOW" << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	unsigned int pause(1600000); //Screen Pause
	usleep(pause); //Call Pause
	clearScreen(); //Clear Screen
}

//Getters
/*---------------------------------------------------------------------------------*/
// Function: getNextState
// Description: Gets the next state Node
/*---------------------------------------------------------------------------------*/
State* State::getNextState() {
	return nextState;
}
/*---------------------------------------------------------------------------------*/
// Function: getNorLightNumVeh
// Description: Gets the North Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
int State::getNorLightNumVeh() {
	return NorLightNumVeh;
}
/*---------------------------------------------------------------------------------*/
// Function: getSouLightNumVeh
// Description: Gets the South Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
int State::getSouLightNumVeh() {
	return SouLightNumVeh;
}
/*---------------------------------------------------------------------------------*/
// Function: getEasLightNumVeh
// Description: Gets the East Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
int State::getEasLightNumVeh() {
	return EasLightNumVeh;
}
/*---------------------------------------------------------------------------------*/
// Function: getWesLightNumVeh
// Description: Gets the West Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
int State::getWesLightNumVeh() {
	return WesLightNumVeh;
}
int State::getNumVehArrive(char dir) {
	if (dir == 'N') return arrivN;
	else if (dir == 'E') return arrivE;
	else if (dir == 'S') return arrivS;
	else return arrivW;
}
int State::getNumVehDepart(char dir) {
	if (dir == 'N') return depN;
	else if (dir == 'E') return depE;
	else if (dir == 'S') return depS;
	else return depW;
}
//Setters
/*---------------------------------------------------------------------------------*/
// Function: setNextStateNode
// Description: Sets the next state Node
/*---------------------------------------------------------------------------------*/
void State::setNextStateNode(State &nexStateNode) {
	nextState = &nexStateNode;
}
/*---------------------------------------------------------------------------------*/
// Function: setNorLightNumVeh
// Description: Sets the North Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
void State::setNorLightNumVeh(int numN) {
	NorLightNumVeh = numN;
}
/*---------------------------------------------------------------------------------*/
// Function: setSouLightNumVeh
// Description: Sets the South Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
void State::setSouLightNumVeh(int numS) {
	SouLightNumVeh = numS;
}
/*---------------------------------------------------------------------------------*/
// Function: setEasLightNumVeh
// Description: Sets the East Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
void State::setEasLightNumVeh(int numE) {
	EasLightNumVeh = numE;
}
/*---------------------------------------------------------------------------------*/
// Function: setWestLightNumVeh
// Description: Sets the West Light Number of Vehicles
/*---------------------------------------------------------------------------------*/
void State::setWesLightNumVeh(int numW) {
	WesLightNumVeh = numW;
}
/*---------------------------------------------------------------------------------*/
// Function: setGreenTraffic
// Description: Sets the amount of Traffic with Uniform and Normal Distribution
/*---------------------------------------------------------------------------------*/
void State::setGreenTraffic() {
	if (direction1 == 'G') { //Both dir1 and dir3 G
		//North Lane
		arrivN = nrOfVehiclesArrive(); //Uniform Distribution #
		depN = nrOfVehiclesDepart(); //Normal Distribution #
		int atNLight = (NorLightNumVeh + (arrivN-depN));
		if (atNLight < 0) atNLight = 0; //Check for Negative Cars
		setNorLightNumVeh(atNLight);
		//South Lane
		arrivS = nrOfVehiclesArrive(); //Uniform Distribution #
		depS = nrOfVehiclesDepart(); //Normal Distribution #
		int atSLight = (SouLightNumVeh + (arrivS-depS));
		if (atSLight < 0) atSLight = 0; //Check for Negative Cars
		setSouLightNumVeh(atSLight);
	}
	else if (direction2 == 'G') { //Both dir2 and dir4 G
		//East Lane
		arrivE = nrOfVehiclesArrive(); //Uniform Distribution #
		depE = nrOfVehiclesDepart(); //Normal Distribution #
		int atELight = (EasLightNumVeh + (arrivE - depE));
		if (atELight < 0) atELight = 0; //Check for Negative Cars
		setEasLightNumVeh(atELight);
		//West Lane
		arrivW = nrOfVehiclesArrive(); //Uniform Distribution #
		depW = nrOfVehiclesDepart(); //Normal Distribution #
		int atWLight = (WesLightNumVeh + (arrivW - depW));		
		if (atWLight < 0) atWLight = 0; //Check for Negative Cars
		setWesLightNumVeh(atWLight);
	}	
}
/*---------------------------------------------------------------------------------*/
// Function: nrOfVehiclesDepart
// Description: Uniform Distribution singular "roll"
/*---------------------------------------------------------------------------------*/
int State::nrOfVehiclesDepart() {
	std::uniform_int_distribution<> diceRoll(4, 8);
	auto singleRoll = diceRoll(engine);	
	return singleRoll;	
}
/*---------------------------------------------------------------------------------*/
// Function: nrOfVehiclesDepart
// Description: Normal Distribution double "roll"
/*---------------------------------------------------------------------------------*/
int State::nrOfVehiclesArrive() {
	int total = 0;
	//Random for 2 "dice"
	for (int i = 0; i < 2; i++) {
		std::uniform_int_distribution<> diceRoll(2, 4);
		auto singleRoll = diceRoll(engine);
		total += singleRoll;
	}
	return total;
}

