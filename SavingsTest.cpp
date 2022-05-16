#include <iostream>
#include "Savings.h"
#include "Account.h"

int main()
{
	int numOfTests = 0;
	int pass = 0;

	//applyInterest test
	{
		Savings savings("Test Test", "test", 1234);
		savings.setBalance(1000);
		savings.applyInterest();

		if(savings.getBalance() == 1020)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: applyInterest(), Positive\n";
		}
		numOfTests++;
	}

	{
		Savings savings("Test Test", "test", 1234);
		savings.setBalance(-1000);
		savings.applyInterest();

		if(savings.getBalance() == -1000)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: applyInterest(), Negative\n";
		}
		numOfTests++;
	}

	{
		Savings savings("Test Test", "test", 1234);
		savings.setBalance(0);
		savings.applyInterest();

		if(savings.getBalance() == 0)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: applyInterest(), Zero\n";
		}
		numOfTests++;
	}

	//Print results
	std::cout << "Tests Passed: " << pass << "\n" << "Total Tests: " << numOfTests << "\n";
	return 0;
}