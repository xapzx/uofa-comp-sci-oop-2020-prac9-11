#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>

class Account
{
//Variables
protected:	//Needs to be accessed by child classes
	double balance; 
	std::vector<std::string> statement;
	int statementCount;

private:
	std::string fullName;
	std::string userName;
	int uniqueAccNum;
	static int currentAccNum;
	int pincode;
	int noOfSavings; 
	int noOfTransaction;

public:
	//Methods
	Account(std::string fName, std::string uName, int pin);
	void menuPrint();
	int menu();
	bool logIn(std::string uName, int pin);
	bool logOut();
	void deposit();
	void withdraw();
	double getBalance();
	int getAccNum();
	std::string getName();
	std::string getUserName();
	void changeNamePrint();
	void changeName();
	void changeUserName(std::string uName);
	void changePinPrint();
	void changePin();
	int getPin();
	int getNoSavings();
	int getNoTrans();
	void incSavingsAcc();
	void incTransAcc();
	void setBalance(double amount);
	void transferTo(double amount);
	void transferFrom(double amount);
	void printStatement();
	~Account();
};
#endif //ACCOUNT_H