//////////////////// ** Author: Jared Parkinson 
//    Fib.hpp     // *** Date: 6/2/2016
//////////////////// **** Desc: Mod 4  

#include "Fib.hpp"

/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
FibonacciNR::FibonacciNR() {}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
FibonacciNR::~FibonacciNR() {}
/*---------------------------------------------------------------------------------*/
// Function: FibNonRec
// Description: Fibonacci Non Recursive
/*---------------------------------------------------------------------------------*/
unsigned long long int FibonacciNR::Fibonacci(unsigned long long int passedN)
{
	unsigned long long int first = 0;
	unsigned long long int second = 1;
	unsigned long long int counter = 2;

	while (counter < passedN)
	{
		unsigned long long int temp = second;
		second = first + second;
		first = temp;
		++counter;
	}
	if (passedN == 0) {
		return 0;
	}
	else {
		return first + second;
	}
}
/*---------------------------------------------------------------------------------*/
// Function: PrintFibonacci
// Description: Fibonacci Non Recursive
/*---------------------------------------------------------------------------------*/
void FibonacciNR::PrintFibonacci(unsigned long long int printN){
	const unsigned long long int result = Fibonacci(printN);
	std::cout << printN << "th Fibonacci NonRec #:" << result << std::endl;
}


/*---------------------------------------------------------------------------------*/
// Function: Constructor
/*---------------------------------------------------------------------------------*/
FibonacciR::FibonacciR() {}
/*---------------------------------------------------------------------------------*/
// Function: Destructor
/*---------------------------------------------------------------------------------*/
FibonacciR::~FibonacciR() {}
/*---------------------------------------------------------------------------------*/
// Function: FibRec
// Description: Fibonacci Recursive
/*---------------------------------------------------------------------------------*/
unsigned long long int FibonacciR::Fibonacci(unsigned long long int passedN) {
	if (passedN == 0) {
		return 0;
	}
	else if (passedN == 1) {
		return 1;
	}
	return Fibonacci(passedN-1) + Fibonacci(passedN-2);
}
/*---------------------------------------------------------------------------------*/
// Function: PrintFibonacci
// Description: Fibonacci Recursive
/*---------------------------------------------------------------------------------*/
void FibonacciR::PrintFibonacci(unsigned long long int printN) {
	const unsigned long long int result = Fibonacci(printN);
	std::cout << printN << "th Fibonacci Rec #:" << result << std::endl;
}