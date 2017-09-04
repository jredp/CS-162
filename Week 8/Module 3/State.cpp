//////////////////// ** Author: Jared Parkinson 
//    State.cpp   // *** Date: 5/25/2016
//////////////////// **** Desc: Mod 3

#include "State.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Sets Data members for lanes, directions and Queues
/*---------------------------------------------------------------------------------*/
State::State(char light1, char light2) {
	//State Dirs
	direction1 = light1; //North
	direction3 = light1; //South
	direction2 = light2; //East
	direction4 = light2; //West
		
	NorLightNumVeh = 0, EasLightNumVeh = 0;
	SouLightNumVeh = 0, WesLightNumVeh = 0;
	arrivN = 0, arrivS = 0, arrivE = 0, arrivW = 0;
	depN = 0, depS = 0, depE = 0, depW = 0;

	//Queue
	if ((direction1 == 'G') || (direction2 == 'G')) {
		lane1 = new Queue;
		lane2 = new Queue;
	}
	else {
		lane1 = NULL;
		lane2 = NULL;
	}
}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
State::~State() {	
	//Free Memory
	if (lane1) {
		delete lane1;
	}
	if (lane2) {
		delete lane2;
	}
}
/*---------------------------------------------------------------------------------*/
// Function: clearScreen
// Description: Clears Screen on Windows and Linux OS
/*---------------------------------------------------------------------------------*/
void State::clearScreen() {
	//Linux
	std::cout << "\033[2J\033[1;1H"; //Clears Screen	
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
	//Yelow
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
/*---------------------------------------------------------------------------------*/
// Function: getNumVehArrive
// Description: Gets the Num Vehicles arriving based on Lane
/*---------------------------------------------------------------------------------*/
int State::getNumVehArrive(char dir) {
	if (dir == 'N') return arrivN;
	else if (dir == 'E') return arrivE;
	else if (dir == 'S') return arrivS;
	else return arrivW;
}
/*---------------------------------------------------------------------------------*/
// Function: getNumVehDepart
// Description: Gets the Num Vehicles departing based on Lane
/*---------------------------------------------------------------------------------*/
int State::getNumVehDepart(char dir) {
	if (dir == 'N') return depN;
	else if (dir == 'E') return depE;
	else if (dir == 'S') return depS;
	else return depW;
}
/*---------------------------------------------------------------------------------*/
// Function: getWaitSumLane1
// Description: Gets the wait sum for this queue Lane
/*---------------------------------------------------------------------------------*/
int State::getWaitSumLane1() {
	int waitSumTemp = lane1->getWaitSum();
	return waitSumTemp;
}
/*---------------------------------------------------------------------------------*/
// Function: getWaitSumLane2
// Description: Gets the wait sum for this queue Lane
/*---------------------------------------------------------------------------------*/
int State::getWaitSumLane2() {
	int waitSumTemp = lane2->getWaitSum();
	return waitSumTemp;
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
void State::setGreenTraffic(int timeStampIns) {
	iteration = timeStampIns; //Set the iteration
	nrOfVehiclesArrive(); //Uniform Distribution #
	nrOfVehiclesDepart(); //Normal Distribution #	
}
/*---------------------------------------------------------------------------------*/
// Function: nrOfVehiclesDepart
// Description: Uniform Distribution singular "roll"
/*---------------------------------------------------------------------------------*/
void State::nrOfVehiclesDepart() {
	std::uniform_int_distribution<> diceRoll(4, 8);
	auto lane1Roll = diceRoll(engine);
	auto lane2Roll = diceRoll(engine);
	int atNLight, atSLight, atELight, atWLight;

	if (direction1 == 'G') { //Both North and South Lanes
		/*---------North Car Totals------------*/
		depN = lane1Roll;
		if (depN > NorLightNumVeh) depN = NorLightNumVeh; //If depart > existing cars
		atNLight = (NorLightNumVeh + (arrivN - depN)); //Calc atNLight
		setNorLightNumVeh(atNLight); //Set At North Light
		//Remove N Cars		
		for (int i = 0; i < depN; i++) {
			int timeUnitRemoved = lane1->remove(); //Remove 1 car node			
			lane1->setWaitSum(iteration - timeUnitRemoved); //Sum of wait time (Light Changes)
		}
		/*---------South Car Totals------------*/
		depS = lane2Roll;
		if (depS > SouLightNumVeh) depS = SouLightNumVeh; //If depart > existing cars
		atSLight = (SouLightNumVeh + (arrivS - depS)); //Calc atSLight
		setSouLightNumVeh(atSLight); //Set At South Light
		//Remove S Cars		
		for (int i = 0; i < depS; i++) {
			int timeUnitRemoved = lane2->remove(); //Remove 1 car node			
			lane2->setWaitSum(iteration - timeUnitRemoved); //Sum of wait time (Light Changes)
		}
	}
	else if (direction2 == 'G') { //Both East and West Lanes
		/*---------East Car Totals------------*/
		depE = lane1Roll;
		if (depE > EasLightNumVeh) depE = EasLightNumVeh; //If depart > existing cars
		atELight = (EasLightNumVeh + (arrivE - depE)); //Calc atELight
		setEasLightNumVeh(atELight); //Set At East Light
		//Remove E Cars		
		for (int i = 0; i < depE; i++) {
			int timeUnitRemoved = lane1->remove(); //Remove 1 car node			
			lane1->setWaitSum(iteration - timeUnitRemoved); //Sum of wait time (Light Changes)
		}
		/*---------West Car Totals------------*/
		depW = lane2Roll;
		if (depW > WesLightNumVeh) depW = WesLightNumVeh; //If depart > existing cars
		atWLight = (WesLightNumVeh + (arrivW - depW)); //Calc atWLight
		setWesLightNumVeh(atWLight); //Set At West Light
		//Remove W Cars		
		for (int i = 0; i < depW; i++) {
			int timeUnitRemoved = lane2->remove(); //Remove 1 car node			
			lane2->setWaitSum(iteration - timeUnitRemoved); //Sum of wait time (Light Changes)
		}
	}
}
/*---------------------------------------------------------------------------------*/
// Function: nrOfVehiclesArrive
// Description: Normal Distribution double "roll"
/*---------------------------------------------------------------------------------*/
void State::nrOfVehiclesArrive() {
	int total1 = 0, total2 = 0;
	//Random for 2 "dice"
	for (int i = 0; i < 2; i++) {
		std::uniform_int_distribution<> diceRoll(2, 4);
		auto lane1Roll = diceRoll(engine);
		auto lane2Roll = diceRoll(engine);
		total1 += lane1Roll; total2 += lane2Roll;
	}
	//Both North and South Lanes
	if (direction1 == 'G') {
		//North
		arrivN = total1;
		lane1->setIteration(iteration); //Update Iteration on Queue Object
		lane1->add(arrivN); //Add generated number of Cars
		//South
		arrivS = total2;
		lane2->setIteration(iteration); //Update Iteration on Queue Object
		lane2->add(arrivS); //Add generated number of Cars
	}
	//Both East and West Lanes
	else if (direction2 == 'G') {
		//East
		arrivE = total1;
		lane1->setIteration(iteration); //Update Iteration on Queue Object
		lane1->add(arrivE); //Add generated number of Cars
		//West
		arrivW = total2;
		lane2->setIteration(iteration); //Update Iteration on Queue Object
		lane2->add(arrivW); //Add generated number of Cars
	}
}