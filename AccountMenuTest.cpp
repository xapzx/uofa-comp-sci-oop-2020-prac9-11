#include "Account.h"
#include <iostream>
#include <string>

int main()
{
	//Test menu method
	Account account("Test Test", "test", 1234);
	int option = account.menu();

	std::cout << option;

	return 0;
}