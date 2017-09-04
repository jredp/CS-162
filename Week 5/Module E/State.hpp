//////////////////// ** Author: Jared Parkinson 
//    State.hpp   // *** Date: 5/3/2016
//////////////////// **** Desc: Mod E

#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <unistd.h> //Linux
#include <random> //Randomizer
#include <memory> //Random Memory Engine Usage

static std::random_device rd; /* http://www.cplusplus.com/reference/random/random_device/operator()/ */
static std::mt19937 engine(rd()); /* http://www.cplusplus.com/reference/random/mt19937/ */

class State 
{
private:			
	State *nextState; //Pointer to next state in list
	char direction1, direction2, direction3, direction4; //1=North, 2=East, 3=South, 4=West
	int NorLightNumVeh, EasLightNumVeh, SouLightNumVeh, WesLightNumVeh;
	int arrivN, arrivS, arrivE, arrivW;
	int depN, depS, depE, depW;

public:
	State(char light1, char light2); //Constructor
	~State(); //Destructor
	void setGreenTraffic(); //Sets the Traffic Flow

	//Getters
	State* getNextState(); //Gets next State
	int getNumVehArrive(char dir);
	int getNumVehDepart(char dir);
	int getNorLightNumVeh(); //Get North Light Num Veh
	int getSouLightNumVeh(); //Get South Light Num Veh
	int getEasLightNumVeh(); //Get East Light Num Veh
	int getWesLightNumVeh(); //Get West Light Num Veh
	//Setters		
	void setNextStateNode(State &nexState);
	int nrOfVehiclesArrive(); //Random
	int nrOfVehiclesDepart(); //Random
	void setNorLightNumVeh(int numVeh); //Set North Light Num Veh
	void setSouLightNumVeh(int numVeh); //Set South Light Num Veh
	void setEasLightNumVeh(int numVeh); //Set East Light Num Veh
	void setWesLightNumVeh(int numVeh); //Set West Light Num Veh
	void printLanes(); //Print the Lanes
	void clearScreen(); //Clear the screen
};

#endif