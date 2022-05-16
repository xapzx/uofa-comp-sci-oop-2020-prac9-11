#ifndef TRANSACTION_H
#define	TRANSACTION_H
#include <string>
#include <iostream>
#include "Account.h"

class Transaction : public Account
{
public:
	Transaction(std::string fName, std::string uName, int pin);
	void pay(double amount);
	~Transaction();
};

#endif //TRANSACTION_H