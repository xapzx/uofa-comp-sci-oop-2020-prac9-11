#include <string>
#include "Savings.h"
#include "Account.h"
#include <iostream>
#include <string>

//Savings Contructor
Savings::Savings(std::string fName, std::string uName, int pin): Account(fName, uName, pin)
{
	//2% Interest Rate
	interest = 0.02;
}

//Apply interest to balance
void Savings::applyInterest()
{
	//Add 2% Interest if balance more than $0
	if(balance > 0)
	{
		balance = balance + balance*interest;	
	}
}

//Deposit method and save transaction+interest to statement
void Savings::deposit()
{
	double dep = -1.0;
	//Catch negative deposit input
	while(dep < 0)
	{
		double temp;
		std::cout << "Enter deposit amount: $";
		//If a valid double is entered, get amount set to input
		if(std::cin >> temp)
		{
			dep = temp;
		}
		else
		{
			std::cout << "Invalid Input, Try Again.\n";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		//If deposit amount less than 0
		if(dep < 0)
		{
			std::cout << "Invalid Deposit Amount.\n";	
		}
	}
	balance += dep;
	//Save transaction to statement
	std::string text = "Deposit\t\t$"+std::to_string(dep)+"\t\t$"+std::to_string(balance)+"\t\t";
	applyInterest();
	text += "$"+std::to_string(balance)+"\n";
	statement.push_back(text);
	statementCount++;
}

//Print bank statement with interest
void Savings::printStatement()
{
	std::cout << "Account Number: " << getAccNum() << std::endl;
	std::cout << "Starting Balance $0\n";
	std::cout << "------------------------------------------------------------------------------------\n";
	std::cout << "Action\t\tAmount\t\t\tBalance\t\t\tBalance + Interest\n";
	std::cout << "------------------------------------------------------------------------------------\n";
	for(int i = 0; i < statementCount; i++)
	{
		std::cout << statement[i];
	}
	std::cout << "------------------------------------------------------------------------------------\n";
	std::cout << "Closing Balance $" << getBalance() << std::endl;
}

//Savings object destructor
Savings::~Savings()
{

}
