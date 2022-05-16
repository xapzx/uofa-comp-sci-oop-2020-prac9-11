#include "Account.h"
#include <iostream>
#include <string>
#include <iomanip>

int Account::currentAccNum = 10000000;

//Account Constructor
Account::Account(std::string fName, std::string uName, int pin)
{
	fullName = fName;
	userName = uName;
	pincode = pin;
	balance = 0.0;
	uniqueAccNum = currentAccNum;
	currentAccNum++;
	noOfSavings = 0;
	noOfTransaction = 0;
	statementCount = 0;
}

//Print Account menu
void Account::menuPrint()
{
	std::cout << "=====ACCOUNT MENU=====\n";
	std::cout << "1) View Accounts\n";
	std::cout << "2) Transfer\n";
	std::cout << "3) Deposit\n";
	std::cout << "4) Withdraw\n";
	std::cout << "5) Make Payment\n";
	std::cout << "6) View Statement\n";
	std::cout << "7) Open Transaction Account\n";
	std::cout << "8) Open Savings Accounts\n";
	std::cout << "9) Settings\n";
	std::cout << "10) Log Out\n";
	std::cout << "Enter Option: ";
}

//Account menu input
int Account::menu()
{
	int option;

	while(true)
	{
		int temp;
		//Check for valid integer input
		if(std::cin >> temp)
		{
			option = temp;
			break;
		}
		else
		{
			std::cout << "Invalid Input, Try Again.\n";
			std::cin.clear();
			std::cin.ignore();
			menuPrint();
			continue;
		}
	}
	return option;
}

//Log in info checker
bool Account::logIn(std::string uName, int pin)
{
	//Check User/pass combo
	if(uName == userName && pin == pincode)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Deposit Method
void Account::deposit()
{
	std::cout << std::setprecision(2) << std::fixed;
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
		//If deposit less than 0
		if(dep < 0)
		{
			std::cout << "Invalid Deposit Amount.\n";	
		}
	}
	balance += dep;
	//Save transaction to statement
	statement.push_back("Deposit\t\t$"+std::to_string(dep)+"\t\t$"+std::to_string(balance)+"\n");
	statementCount++;
}

//Withdraw Method
void Account::withdraw()
{
	double wAmount;
	while(true)
	{
		double temp;
		//Ask for withdraw amount
		std::cout << "Balance: $" << getBalance() << std::endl;
		std::cout << "Enter withdraw amount $";
		//If a valid double is entered, get amount set to input
		if(std::cin >> temp)
		{
			wAmount = temp;
		}
		else
		{
			std::cout << "Invalid Input, Try Again.\n";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		//If withdraw amount is larger than balance, show message
		if(wAmount > balance)
		{
			std::cout << "Insufficient funds. Try Again.\n";
		}
		//If withdraw amount less than 0, show message
		else if(wAmount < 0)
		{
			std::cout << "Invalid Input.\n";
		}
		else
		{
			break;
		}
	}
	balance -= wAmount;
	statement.push_back("Withdraw\t$"+std::to_string(wAmount)+"\t\t$"+std::to_string(balance)+"\n");
	statementCount++;
}

//Set Balance
void Account::setBalance(double amount)
{
	balance += amount;
}

//Get Balance
double Account::getBalance()
{
	return balance;
}

//Get Account Number
int Account::getAccNum()
{
	return uniqueAccNum;
}

//Get Full Name
std::string Account::getName()
{
	return fullName;
}

//Get Username
std::string Account::getUserName()
{
	return userName;
}

//Change name prompt
void Account::changeNamePrint()
{
	std::cout << "Enter New Full Name: ";
}

//Change Name method
void Account::changeName()
{
	std::string first;
	std::string last;
	std::cin >> first;
	std::cin >> last;
	//Append first and last name to create full name with space, then change name
	std::string fName;
	fName.append(first);
	fName.append(" ");
	fName.append(last);
	fullName = fName;
}

//Change Username method
void Account::changeUserName(std::string uName)
{
	userName = uName;
}

// Change PIN prompt
void Account::changePinPrint()
{
	std::cout << "Enter new Pincode: ";
}

//Change PIN method
void Account::changePin()
{
	int newPin;

	std::cin >> newPin;
	pincode = newPin;
}

//Get PIN
int Account::getPin()
{
	return pincode;
}

//Get number of savings account opened
int Account::getNoSavings()
{
	return noOfSavings;
}

//Get number of transaction account opened
int Account::getNoTrans()
{
	return noOfTransaction;
}

//Increment Number of Savings Account Created
void Account::incSavingsAcc()
{
	noOfSavings++;
}

//Increment Number of Transaction Account Created
void Account::incTransAcc()
{
	noOfTransaction++;
}

//Transfer to this account method
void Account::transferTo(double amount)
{
	balance += amount;
	statement.push_back("Transfer In\t$"+std::to_string(amount)+"\t\t$"+std::to_string(balance)+"\n");
	statementCount++;
}

//Transfer from this account method
void Account::transferFrom(double amount)
{
	balance -= amount;
	statement.push_back("Transfer Out\t$"+std::to_string(amount)+"\t\t$"+std::to_string(balance)+"\n");
	statementCount++;
}

//Print Bank Statement
void Account::printStatement()
{
		std::cout << "Account Number: " << getAccNum() << std::endl;
		std::cout << "Starting Balance $0\n";
		std::cout << "-----------------------------------------------------\n";
		std::cout << "Action\t\tAmount\t\t\tBalance\n";
		std::cout << "-----------------------------------------------------\n";
		for(int i = 0; i < statementCount; i++)
		{
			std::cout << statement[i];
		}
		std::cout << "-----------------------------------------------------\n";
		std::cout << "Closing Balance $" << getBalance() << std::endl;
}

//Account Destructor
Account::~Account()
{

}