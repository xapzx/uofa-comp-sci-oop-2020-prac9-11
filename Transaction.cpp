#include "Account.h"
#include "Transaction.h"
#include <string>
#include <iostream>

//Transaction constructor
Transaction::Transaction(std::string fName, std::string uName, int pin): Account(fName, uName, pin)
{

}

//Payment method and save to statement
void Transaction::pay(double amount)
{
	balance -= amount;
	statement.push_back("Payment\t\t$"+std::to_string(amount)+"\t\t$"+std::to_string(balance)+"\n");
	statementCount++;
}

//Transaction Destructor
Transaction::~Transaction()
{
	
}