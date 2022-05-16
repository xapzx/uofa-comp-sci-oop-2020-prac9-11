#include "Account.h"
#include <iostream>

int main()
{
	//Test to see account numbers are incremented when constructed
	Account *accounts[10];
	for(int i = 0; i < 10; i++)
	{
		accounts[i] = new Account("Test Test", "test", 1234);
	}

	for(int i = 0; i < 10; i++)
	{
		std::cout << accounts[i]->getAccNum() << std::endl;
	}

	return 0;
}