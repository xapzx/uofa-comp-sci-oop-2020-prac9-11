#include "Account.h"
#include <iostream>
#include <iomanip>

int main()
{
	//Test account withdraw method
	Account account("Test Test", "test", 1234);
	account.setBalance(1000);
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Balance before withdrawal: $" << account.getBalance() << std::endl;
	account.withdraw();
	std::cout << "Balance after withdrawal: $" << account.getBalance() << std::endl;
	return 0;
}