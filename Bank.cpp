#include <iostream>
#include <string>
#include "Bank.h"

//Bank object Constructor
Bank::Bank()
{

}

//Bank menu prompt
int Bank::menu()
{
	restart:
	int option;
	int temp;
	std::cout << "=====MAIN MENU=====\n";
	std::cout << "1) Create an account.\n";
	std::cout << "2) Log In\n";
	std::cout << "3) Exit\n";
	std::cout << "Enter Option: ";
	//If a valid integer is entered, get PIN to input
	if(std::cin >> temp)
	{
		option = temp;
		return option;
	}
	//If input is not a valid integer, clear cin error then go to start of loop
	else
	{
		std::cout << "Invalid Input, Try Again.\n";
		std::cin.clear();
		std::cin.ignore();
		goto restart;
	}
}

//Bank destructor
Bank::~Bank()
{
	
}