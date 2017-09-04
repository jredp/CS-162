//////////////////// ** Author: Jared Parkinson 
//    State.hpp   // *** Date: 5/25/2016
//////////////////// **** Desc: Mod 3

#ifndef STATE_HPP
#define STATE_HPP

#include "Queue.hpp"
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
	Queue *lane1, *lane2; //Queue pointers	
	int iteration; //Iteration	

public:
	State(char light1, char light2); //Constructor
	~State(); //Destructor
	void setGreenTraffic(int timeStampIns);

	//Getters
	State* getNextState();
	int getNumVehArrive(char dir);
	int getNumVehDepart(char dir);
	int getNorLightNumVeh(); //Get North Light Num Veh
	int getSouLightNumVeh(); //Get South Light Num Veh
	int getEasLightNumVeh(); //Get East Light Num Veh
	int getWesLightNumVeh(); //Get West Light Num Veh
	int getWaitSumLane1(); //Get the WaitSum of lane1 queue
	int getWaitSumLane2(); //Get the WaitSum of lane1 queue
	//Setters		
	void setNextStateNode(State &nexState);
	void nrOfVehiclesArrive(); //Random
	void nrOfVehiclesDepart(); //Random
	void setNorLightNumVeh(int numVeh); //Set North Light Num Veh
	void setSouLightNumVeh(int numVeh); //Set South Light Num Veh
	void setEasLightNumVeh(int numVeh); //Set East Light Num Veh
	void setWesLightNumVeh(int numVeh); //Set West Light Num Veh
	void printLanes();
	void clearScreen();
};

#endif