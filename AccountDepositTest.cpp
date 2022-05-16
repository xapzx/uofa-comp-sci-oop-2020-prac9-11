#include "Account.h"
#include <iostream>
#include <iomanip>

int main()
{
	//Test account deposit method
	Account account("Test Test", "test", 1234);

	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Balance before deposit: $" << account.getBalance() << std::endl;
	account.deposit();
	std::cout << "Balance after deposit: $" << account.getBalance() << std::endl;
	return 0;
}