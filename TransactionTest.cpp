#include <iostream>
#include "Account.h"
#include "Transaction.h"

int main()
{
	int numOfTests = 0;
	int pass = 0;

	//pay() test
	{
		Transaction transaction("Test Test", "test", 1234);
		transaction.setBalance(100);
		transaction.pay(10);
		if(transaction.getBalance() == 90)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account pay(whole number), positive\n";
		}
		numOfTests++;
	}

	{
		Transaction transaction("Test Test", "test", 1234);
		transaction.setBalance(100);
		transaction.pay(10.50);
		if(transaction.getBalance() == 89.50)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account pay(decimal), positive\n";
		}
		numOfTests++;
	}

	{
		Transaction transaction("Test Test", "test", 1234);
		transaction.setBalance(-100);
		transaction.pay(10);
		if(transaction.getBalance() == -110)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account pay(whole number), negative\n";
		}
		numOfTests++;
	}

	{
		Transaction transaction("Test Test", "test", 1234);
		transaction.setBalance(-100);
		transaction.pay(10.50);
		if(transaction.getBalance() == -110.50)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account pay(decimal), negative\n";
		}
		numOfTests++;
	}
	//Print results
	std::cout << "Tests Passed: " << pass << "\n" << "Total Tests: " << numOfTests << "\n";
	return 0;
}