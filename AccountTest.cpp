#include "Account.h"
#include "Savings.h"
#include <iostream>

int main()
{
	int numOfTests = 0;
	int pass = 0;

	//getBalance/setBalance tests
	{
		Account account("Test Test", "test", 1234);
		account.setBalance(100);
		if(account.getBalance() == 100)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account getBalance()/setBalance(), positive\n";
		}
		numOfTests++;
	}

	{
		Account account("Test Test", "test", 1234);
		account.setBalance(-100);
		if(account.getBalance() == -100)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account getBalance()/setBalance(), negative\n";
		}
		numOfTests++;
	}	

	{
		Account account("Test Test", "test", 1234);
		account.setBalance(0);
		if(account.getBalance() == 0)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account getBalance()/setBalance(), zero\n";
		}
		numOfTests++;
	}

	{
		Account account("Test Test", "test", 1234);
		account.setBalance(100.25);
		if(account.getBalance() == 100.25)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account getBalance()/setBalance(), positive float\n";
		}
		numOfTests++;
	}

	{
		Account account("Test Test", "test", 1234);
		account.setBalance(-100.25);
		if(account.getBalance() == -100.25)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: account getBalance()/setBalance(), negative float\n";
		}
		numOfTests++;
	}

	//getAccNum tests
	{
		Account account("Test Test", "test", 1234);
		
		if(account.getAccNum() == 10000005)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getAccNum()\n";
		}
		numOfTests++;
	}

	//getName tests
	{
		Account account("Test Test", "test", 1234);

		if(account.getName() == "Test Test")
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getName(), Full Name\n";
		}
		numOfTests++;
	}

	//getUserName test
	{
		Account account("Test Test", "test", 1234);

		if(account.getUserName() == "test")
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getUserName()\n";
		}
		numOfTests++;
	}

	//changeUserName test
	{	
		Account account("Test Test", "test", 1234);
		account.changeUserName("newtest");

		if(account.getUserName() == "newtest")
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: changeUserName()\n";
		}
		numOfTests++;
	}

	//logIn test
	{	
		Account account("Test Test", "test", 1234);

		if(account.logIn("test", 1234) == true)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: logIn()\n";
		}
		numOfTests++;
	}	

	//getPin test
	{	
		Account account("Test Test", "test", 1234);

		if(account.getPin() == 1234)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getPin(), 4 digits\n";
		}
		numOfTests++;
	}	

	{	
		Account account("Test Test", "test", 1);

		if(account.getPin() == 1)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getPin(), 1 digit\n";
		}
		numOfTests++;
	}	

	//getNoSavings Test
	{	
		Account account("Test Test", "test", 1234);

		if(account.getNoSavings() == 0)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getNoSavings()\n";
		}
		numOfTests++;
	}	

	//getNoTrans Test
	{	
		Account account("Test Test", "test", 1234);

		if(account.getNoTrans() == 0)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: getNoTrans()\n";
		}
		numOfTests++;
	}	

	//incSavingsAcc Test
	{	
		Account account("Test Test", "test", 1234);
		account.incSavingsAcc();

		if(account.getNoSavings() == 1)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: incSavingsAcc()\n";
		}
		numOfTests++;
	}	

	//incTranssAcc Test
	{	
		Account account("Test Test", "test", 1234);
		account.incTransAcc();

		if(account.getNoTrans() == 1)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: incTransAcc()\n";
		}
		numOfTests++;
	}	

	//transferTo Test
	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(100);
		account.transferTo(50);

		if(account.getBalance() == 150)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferTo(), positive balance/transfer: integers\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(100);
		account.transferTo(10.50);

		if(account.getBalance() == 110.5)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferTo(), positive transfer: float, balance: int\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(-100);
		account.transferTo(50);

		if(account.getBalance() == -50)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferTo(), negative balance;positive transfer: integer\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(-100);
		account.transferTo(50.50);

		if(account.getBalance() == -49.5)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferTo(), negative balance: integer; positive transfer:float\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(100.50);
		account.transferTo(50.50);

		if(account.getBalance() == 151)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferTo(), positive balance/transfer:float\n";
		}
		numOfTests++;
	}

	//transferFrom Test
	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(100);
		account.transferFrom(50);

		if(account.getBalance() == 50)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferFrom(), positive balance/transfer: integers\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(100);
		account.transferFrom(10.50);

		if(account.getBalance() == 89.5)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferFrom(), positive transfer: float, balance: int\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(-100);
		account.transferFrom(50);

		if(account.getBalance() == -150)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferFrom(), negative balance;positive transfer: integer\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(-100);
		account.transferFrom(50.50);

		if(account.getBalance() == -150.5)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferFrom(), negative balance: integer; positive transfer:float\n";
		}
		numOfTests++;
	}

	{	
		Account account("Test Test", "test", 1234);
		account.setBalance(100.50);
		account.transferFrom(50.50);

		if(account.getBalance() == 50)
		{
			pass++;
		}
		else
		{
			std::cout << "Failed: transferFrom(), positive balance/transfer:float\n";
		}
		numOfTests++;
	}

	//Print results
	std::cout << "Tests Passed: " << pass << "\n" << "Total Tests: " << numOfTests << "\n";
	return 0;
}