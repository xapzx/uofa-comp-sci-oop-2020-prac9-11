#include <iostream>
#include "Account.h"

int main()
{
	//Test changePin method
	Account account("Test Test", "test", 1234);
	account.changePin();
	std::cout << account.getPin();
	return 0;
}