#ifndef SAVINGS_H
#define SAVINGS_H
#include "Account.h"
#include <string>
#include <iostream>

class Savings: public Account
{
private:
	double interest;

public:
	Savings(std::string fName, std::string uName, int pin);
	void applyInterest();
	void deposit();
	~Savings();
	void printStatement();
};


#endif //SAVINGS_H