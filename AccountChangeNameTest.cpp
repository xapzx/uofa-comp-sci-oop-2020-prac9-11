#include "Account.h"
#include <iostream>
#include <string>

int main()
{
	//Test change name method
	Account account("Test Test", "test", 1234);
	account.changeName();

	std::cout << account.getName() << std::endl;

	return 0;
}