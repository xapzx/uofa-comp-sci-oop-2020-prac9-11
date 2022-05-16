#include <iostream>
#include <iomanip>
#include <string>
#include "Bank.h"
#include "Account.h"	
#include "Savings.h"
#include "Transaction.h"
#include <limits>

void pressAnyKey();

int main()
{
	//Instantiate a Bank Object
	Bank bank = Bank();
	
	//Initialise array of accounts pointers, maximum of 10 accounts
	Account *accounts[10];
	Transaction *transaction[10];
	Savings *savings[10];
	//Keep track of number of accounts created
	int accountsCount = 0;

	//Set floats/doubles to print with 2 decimal points
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "WELCOME TO THE BANK\n";
	while(true)
	{
		start:
		//Call menu function and assign the return value to a variable
		int option = bank.menu();
		//Conditions for Bank Menu Options
		if(option == 1)
		{
			//Enter details to create an account
			std::string firstName;
			std::string lastName;
			std::string fName;
			std::string uName;
			int pin;
			int temp;

			std::cout << "Enter your First Name: ";
			std::cin >> firstName;
			std::cout << "Enter your Last Name: ";
			std::cin >> lastName;
			std::cout << "Enter Username: ";
			std::cin >> uName;
			std::cout << "Enter Pincode: ";

			//Check for valid integer input. If its not an integer input, clear cin and restart loop
			if(std::cin >> temp)
			{
				pin = temp;
			}
			else
			{
				std::cout << "Invalid PIN Input, Try Again.\n";
				std::cin.clear();
				pressAnyKey();
				continue;
			}
			//Append first/lastname to create fullname
			fName.append(firstName);
			fName.append(" ");
			fName.append(lastName);
			//Instantiate an account object and dynamically allocate memory to the heap
			Account *acc = new Account(fName, uName, pin);
			//Add the account object to accounts pointer array
			accounts[accountsCount] = acc;
			accountsCount++;
			//Successfull account creation
			std::cout << "Account successfully created. Please log in.\n";
		}
		//Log in bank account
		else if(option == 2)
		{
			std::string uName;
			int pin;
			int logInIndex; //To keep track of who is logged in
			bool log = false;

			//While Username and passward is incorrect keep looping
			while(log == false)
			{
				int temp;
				std::cout << "Enter Username: ";
				std::cin >> uName;
				std::cout << "Enter Pincode: ";
				//Check for valid integer input
				if(std::cin >> temp)
				{
					pin = temp;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore();
					int option;
					std::cout << "Invalid PIN Input, Try Again.\n";
					std::cout << "1) Try Again\n";
					std::cout << "2) Back to Menu\n";
					std::cout << "Enter Option: ";
					std::cin >> option;
					//Try log in again
					if(option == 1)
					{
						continue;
					}
					// Go to start label (bank menu)
					else
					{
						goto start;
					}
				}
				//Accounts array iteration to check user/pass
				for(int i = 0; i < accountsCount; i++)
				{
					if(accounts[i]->logIn(uName, pin) == true)
					{
						log = true;
						//To access account at this index in account array
						logInIndex = i;
					}
				}
				//Unsuccessful login message
				if(log == false)
				{
					std::cout << "Login Unsuccessful, Try Again.\n";
				}	
			}
			//Correct user/pass is entered
			std::cout << "Login Successful.\n";
			std::cout << "Press Enter to Continue";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

			//Variable to hold account menu option 
			int accOption;
			bool loop = true;
			//Account main menu
			while(loop == true)
			{
				//Log In successful, show user account's menu. Accessed by logInIndex
				accounts[logInIndex]->menuPrint();
				accOption = accounts[logInIndex]->menu();
				Savings *saveAcc;
				Transaction *transAcc;
				bool settingLoop = true;
				switch (accOption)
				{
					//View accounts option
					case 1:
						//Print Account Holder's Name
						std::cout << "Account Holder's Name: " << accounts[logInIndex]->getName() << std::endl;
						//Conditions to only show avaliable accounts
						//View both accounts
						if(accounts[logInIndex]->getNoSavings() == 1 && accounts[logInIndex]->getNoTrans() == 1)
						{
							std::cout << "Transaction Account Number: " << transaction[logInIndex]->getAccNum() << std::endl;
							std::cout << "Balance: $" << transaction[logInIndex]->getBalance() << std::endl << std::endl;
							std::cout << "Savings Account Number: " << savings[logInIndex]->getAccNum() << std::endl;
							std::cout << "Balance: $" << savings[logInIndex]->getBalance() << std::endl;
						}
						//View Savings Account only
						else if(accounts[logInIndex]->getNoSavings() == 1 && accounts[logInIndex]->getNoTrans() == 0)
						{
							std::cout << "Savings Account Number: " << savings[logInIndex]->getAccNum() << std::endl;
							std::cout << "Balance: $" << savings[logInIndex]->getBalance() << std::endl;
						}
						//View Only Transaction account
						else if(accounts[logInIndex]->getNoSavings() == 0 && accounts[logInIndex]->getNoTrans() == 1)
						{
							std::cout << "Transaction Account Number: " << transaction[logInIndex]->getAccNum() << std::endl;
							std::cout << "Balance: $" << transaction[logInIndex]->getBalance() << std::endl;
						}
						//No account avaliable
						else
						{
							std::cout << "No accounts have been opened. Please open an account\n";
						}
						pressAnyKey();
						break;
					//Transfer funds between accounts
					case 2:
						int transferOp;
						double transferAmount;
						//Unable to transfer with only one account opened
						if(accounts[logInIndex]->getNoSavings() == 0 || accounts[logInIndex]->getNoTrans() == 0)
						{
							std::cout << "You do not have enough accounts opened to make a transfer.\n";
						}
						//Ask for transfer option and amount
						else
						{
							//Transfer menu option
							while(true)
							{
								int temp;
								std::cout << "Select Transfer Options:\n";
								std::cout << "\t1) Transaction to Savings\n";
								std::cout << "\t2) Savings to Transaction\n";
								std::cout << "\t3) Exit\n";
								std::cout << "Enter Option: ";
								//Check for valid integer input
								if(std::cin >> temp)
								{
									transferOp = temp;
									break;
								}
								else
								{
									std::cout << "Invalid Input, Try Again.\n";
									std::cin.clear();
									pressAnyKey();
									continue;
								}
							}
							
							//Option 1 and 2, ask for amount input
							if(transferOp == 1 || transferOp == 2)
							{
								while(true)
								{
									double temp;
									std::cout << "Enter Transfer Amount: $";
									//Check for valid integer input
									if(std::cin >> temp)
									{
										transferAmount = temp;
										break;
									}
									else
									{
										std::cout << "Invalid Input, Try Again.\n";
										std::cin.clear();
										pressAnyKey();
										continue;
									}
								}
								//Conditions to check if there is sufficient balance to transfer
								//Also conditions for which accounts to transfer to/from
								//Transfer from Transaction to savings
								if(transferOp == 1 && transferAmount <= transaction[logInIndex]->getBalance())
								{
									transaction[logInIndex]->transferFrom(transferAmount);
									savings[logInIndex]->transferTo(transferAmount);
									std::cout << "Successfully Transferred.\n";
								}
								//Insufficient funds in transaction account
								else if(transferOp == 1 && transferAmount > transaction[logInIndex]->getBalance())
								{
									std::cout << "Insufficient Funds.\n";
								}
								//Transfer from savings to transaction
								else if(transferOp == 2 && transferAmount <= savings[logInIndex]->getBalance())
								{
									savings[logInIndex]->transferFrom(transferAmount);
									transaction[logInIndex]->transferTo(transferAmount);
									std::cout << "Successfully Transferred.\n";
								}
								//Insufficient funds in savings account
								else if(transferOp == 2 && transferAmount > savings[logInIndex]->getBalance())
								{
									std::cout << "Insufficient Funds.\n";
								}
							}
							//Exit transfer menu
							else if(transferOp == 3)
							{
								break;
							}
							else
							{
								std::cout << "Invalid Input.\n";
							}
						}
						pressAnyKey();
						break;
					//Deposit function
					case 3: 
						int depAcc;
						while(true)
						{
							int temp;
							//Which accounts to deposit to
							std::cout << "Which account would you like to deposit in?\n";
							std::cout << "\t1) Savings\n";
							std::cout << "\t2) Transaction\n";
							std::cout << "\t3) Exit\n";
							std::cout << "Enter Option: ";
							//Check for valid integer input
							if(std::cin >> temp)
							{
								depAcc = temp;
								break;
							}
							else
							{
								std::cout << "Invalid Input, Try Again.\n";
								std::cin.clear();
								pressAnyKey();
								continue;
							}
						}

						//Check account avaliability
						if(accounts[logInIndex]->getNoSavings() == 0 && depAcc == 1)
						{
							std::cout << "You don't have a Savings Account.\n";
						}
						else if(accounts[logInIndex]->getNoTrans() == 0 && depAcc == 2)
						{
							std::cout << "You don't have a Transaction Account.\n";
						}
						//Deposit to Savings
						else if(depAcc == 1)
						{
							savings[logInIndex]->deposit();
							std::cout << "Successfully deposited to Savings Account.\n";
						}
						//Deposit to transaction
						else if(depAcc == 2)
						{
							transaction[logInIndex]->deposit();
							std::cout << "Successfully deposited to Transaction Account.\n";
						}
						//Exit menu
						else if(depAcc == 3)
						{
							break;
						}
						//Invalid input
						else
						{
							std::cout << "Invalid Input.\n";
						}
						pressAnyKey();
						break;
					//Withdraw function
					case 4:
						double withdraw;
						int wAcc;
						while(true)
						{
							int temp;
							//Which accounts to withdraw from
							std::cout << "Which account would you like to withdraw from?\n";
							std::cout << "\t1) Savings\n";
							std::cout << "\t2) Transaction\n";
							std::cout << "\t3) Exit\n";
							std::cout << "Enter Option: ";
							//Check for valid integer input
							if(std::cin >> temp)
							{
								wAcc = temp;
								break;
							}
							else
							{
								std::cout << "Invalid Input, Try Again.\n";
								std::cin.clear();
								pressAnyKey();
								continue;
							}
						}
						//Conditions to check for available accounts/balance
						if(accounts[logInIndex]->getNoSavings() == 0 && wAcc == 1)
						{
							std::cout << "You don't have a Savings Account.\n";
						}
						else if(accounts[logInIndex]->getNoTrans() == 0 && wAcc == 2)
						{
							std::cout << "You don't have a Transaction Account.\n";
						}
						else if(wAcc == 1 && savings[logInIndex]->getBalance() == 0)
						{
							std::cout << "You have Insufficient Funds to withdraw.\n";
						}
						else if(wAcc == 2 && transaction[logInIndex]->getBalance() == 0)
						{
							std::cout << "You have Insufficient Funds to withdraw.\n";
						}
						//withdraw from Savings
						else if(wAcc == 1)
						{
							savings[logInIndex]->withdraw();
							std::cout << "Successfully withdrew from Savings Account.\n";
						}
						//withdraw from transaction
						else if(wAcc == 2)
						{
							transaction[logInIndex]->withdraw();
							std::cout << "Successfully withdrew from Transaction Account.\n";
						}
						//Exit menu
						else if(wAcc == 3)
						{
							break;
						}
						//Invalid input
						else
						{
							std::cout << "Invalid Input.\n";
						}
						pressAnyKey();
						break;

					//Make Payment from Transaction account
					case 5:
						//If a transaction account has not been opened
						if(accounts[logInIndex]->getNoTrans() == 0)
						{
							std::cout << "You do not have a Transaction Account.\n";
						}
						//No balance in account
						else if(transaction[logInIndex]->getBalance() <= 0)
						{
							std::cout << "You have Insufficient Funds to make a payment.\n";
						}
						//Ask for payment input then subtract from balance
						else
						{
							double payment;
							//Keeps looping until valid input is entered (payment amount <= balance is valid)
							while(true)
							{
								std::cout << "Transaction Account Number: " << transaction[logInIndex]->getAccNum() << std::endl;
								std::cout << "Balance: $" << transaction[logInIndex]->getBalance() << std::endl;
								std::cout << "Enter payment amount: $";
								std::cin >> payment;
								if(payment > transaction[logInIndex]->getBalance())
								{
									std::cout << "You have Insufficient Funds.\n";
									pressAnyKey();
									continue;
								}
								break;
							}
							//Payment successful, show balance
							transaction[logInIndex]->pay(payment);
							std::cout << "Payment Succesful!\n";
							std::cout << "Transaction Account Number: " << transaction[logInIndex]->getAccNum() << std::endl;
							std::cout << "Balance: $" << transaction[logInIndex]->getBalance() << std::endl;
						}
						pressAnyKey();
						break;
					//View Statement
					case 6:
						while(true)
						{
							//Choice of which account to view or exit
							int statementOp;
							int temp;
							std::cout << "Select Account to View Statement:\n";
							std::cout << "\t1) Savings Account\n";
							std::cout << "\t2) Transaction Account\n";
							std::cout << "\t3) Exit\n";
							std::cout << "Enter Option: ";
							//Check for valid integer input
							if(std::cin >> temp)
							{
								statementOp = temp;
							}
							else
							{
								std::cout << "Invalid Input, Try Again.\n";
								std::cin.clear();
								pressAnyKey();
								continue;
							}
							//Conditions to check avaliable accounts
							//If avaliable print statement or print message
							if(statementOp == 1 && accounts[logInIndex]->getNoSavings() == 0)
							{
								std::cout << "You do not have a Savings Account.\n";
								pressAnyKey();
							}
							else if(statementOp == 2 && accounts[logInIndex]->getNoTrans() == 0)
							{
								std::cout << "You do not have a Transaction Account.\n";
								pressAnyKey();
							}
							else if(statementOp == 1)
							{
								std::cout << "Account Holder's Name: " << accounts[logInIndex]->getName() << std::endl;
								savings[logInIndex]->printStatement();
								pressAnyKey();
							}
							else if(statementOp == 2)
							{
								std::cout << "Account Holder's Name: " << accounts[logInIndex]->getName() << std::endl;
								transaction[logInIndex]->printStatement();
								pressAnyKey();
							}
							else if(statementOp == 3)
							{
								break;
							}
							else
							{
								std::cout << "Invalid Input\n";
								pressAnyKey();
							}
						}
						break;
					//Open Transaction account
					case 7:
						//Condition to only allow opening 1 transaction account
						if(accounts[logInIndex]->getNoTrans() == 1)
						{
							std::cout << "You already have a Transaction account.\n";
							pressAnyKey();
							break;
						}
						transAcc = new Transaction(accounts[logInIndex]->getName(), accounts[logInIndex]->getUserName(), accounts[logInIndex]->getPin()); 
						transaction[logInIndex] = transAcc;
						accounts[logInIndex]->incTransAcc();
						std::cout << "Successfully opened a Transaction Account.\n";
						pressAnyKey();
						break;
					//Open savings account
					case 8:
						//Condition to only allow opening 1 savings account
						if(accounts[logInIndex]->getNoSavings() == 1)
							{
								std::cout << "You already have a Savings account.\n";
								pressAnyKey();
								break;
							}
						saveAcc = new Savings(accounts[logInIndex]->getName(), accounts[logInIndex]->getUserName(), accounts[logInIndex]->getPin()); 
						savings[logInIndex] = saveAcc;
						accounts[logInIndex]->incSavingsAcc();
						std::cout << "Successfully opened a Savings Account.\n";
						pressAnyKey();
						break;
					//Account Settings
					case 9:
						int settingOp;
						while(settingLoop == true)
						{
							int temp;
							std::cout << "Account Settings\n";
							std::cout << "\t1) Change Name\n";
							std::cout << "\t2) Change Pincode\n";
							std::cout << "\t3) Exit Settings\n";	
							std::cout << "Enter Option: ";
							//Check for valid integer input
							if(std::cin >> temp)
							{
								settingOp = temp;
							}
							else
							{
								std::cout << "Invalid Input, Try Again.\n";
								std::cin.clear();
								pressAnyKey();
								continue;
							}

							//Setting options conditions
							if(settingOp == 1)
							{	
								//Change Name
								accounts[logInIndex]->changeNamePrint();
								accounts[logInIndex]->changeName();
								std::cout << "Successfully changed Name.\n";
								pressAnyKey();
							}
							else if(settingOp == 2)
							{
								//Change Pincode
								accounts[logInIndex]->changePinPrint();
								accounts[logInIndex]->changePin();
								std::cout << "Successfully changed PIN Code.\n";
								pressAnyKey();
							}
							//Exit Settings
							else if(settingOp == 3)
							{
								settingLoop = false;
							}
							//Invalid Input
							else
							{
								std::cout << "Invalid Input.\n";
								pressAnyKey();
							}		
						}
						break;
					//Exit account menu/logout
					case 10:
						loop = false;
						break;
				}
			}
		}	
		else if(option == 3)
		{
			//Exit program
			std::cout << "Exiting Program\n";
			break;
		}
		else
		{
			//Catch Invalid Input
			std::cout << "Invalid Input, Try Again.\n";
		}
	}
	return 0;
}

//Pauses and waits for 'enter' to continue running
void pressAnyKey()
{
	std::cout << "Press Enter to Continue";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
