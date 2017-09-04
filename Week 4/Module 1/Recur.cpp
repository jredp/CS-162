//////////////////// ** Author: Jared Parkinson 
//   Recur.cpp    // *** Date: 4/26/2016
//////////////////// **** Desc: Module 1

#include "Recur.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
// Description: Default Constructor
/*---------------------------------------------------------------------------------*/
Recur::Recur() {
	//Game 1
	prob1Str = ""; //Empty String
	
	//Game 2
	prob2arr = NULL; //NULL Pointer to Array
	
	//Game 3
	prob3Rows = 0; //Init Int
	

}
/*---------------------------------------------------------------------------------*/
// Function: reverseString
// Description: Game 1 - Reverses any string entered by user
// Requirements: Any input
/*---------------------------------------------------------------------------------*/
void Recur::reverseString(std::string inStr) {
	int strSize = inStr.length(); //Get String Length
	//If size of String is only 1 or 0
	if (strSize <= 1) {
		std::cout << inStr << std::endl;
	}	
	else {
		std::cout << inStr[strSize-1]; //Print with offset		
		//Cut String down: 0 slot to size-1 slot as the end
		std::string recStr = inStr.substr(0, strSize - 1); 
		//Recursive call
		reverseString(recStr);
	}
}

/*---------------------------------------------------------------------------------*/
// Function: calcSum
// Description: Game 2 - Sums all integers entered by user up to exit
// Requirements: Enter Only integers
/*---------------------------------------------------------------------------------*/
int Recur::calcSum(int *arr, int elem) {	
	int input = utilA.intChecker(); //Get Input	

	//Base Case if negative #, exit
	if (input < 0) {
		return 0;
	}
	else {
		//Base Case: If array is empty, add one
		if (arr == NULL) {
			arr = new int[1];
			arr[elem] = input;
		}		
		int newSize = (elem + 1);
		int *tempArray = new int[newSize]; //New array of +1 size
		
		//Iterate through slots to copy
		for (int slot = 0; slot < elem; slot++) {
			tempArray[slot] = arr[slot]; //Copy current array slot		
		}
		tempArray[newSize] = input; //Set new int to last slot
		prob2arr = tempArray;
		return (input + calcSum(prob2arr, newSize));
	}	
}
/*---------------------------------------------------------------------------------*/
// Function: getProb2Arr
// Description: Game 2 - Gets the Private Data Member Array for game 2
/*---------------------------------------------------------------------------------*/
int* Recur::getProb2Arr() {
	return prob2arr;
}

/*---------------------------------------------------------------------------------*/
// Function: triangleNum
// Description: Determine how many pins it would take to make N rows
// Requirements: Enter a single Int
//
// 2 = 2 + 1
// 3 = 3 + (2 + 1)
// 4 = 4 + (3 + 2 + 1)
// = n + (summation of n-1)
/*---------------------------------------------------------------------------------*/
int Recur::triangleNum(int rowN) {
	if (rowN == 0) {
		return 0; //0 Pins for 0 Rows
	}	
	else {		
		prob3Rows = (rowN - 1);		
		return (rowN + triangleNum(prob3Rows)); //currentRowN + previous rowSum 
	}	
}