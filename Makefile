default: all

Bank.o: Bank.cpp Bank.h
	clang++ -c Bank.cpp

Account.o: Account.cpp Account.h
	clang++ -c Account.cpp

Savings.o: Account.h Savings.cpp Savings.h
	clang++ -c Account.cpp Savings.cpp

Transaction.o: Account.h Savings.h Transaction.cpp Transaction.h
	clang++ -c Account.cpp Savings.cpp Transaction.cpp

main.o: Account.h Savings.h Transaction.h main.cpp
	clang++ -c Account.cpp Savings.cpp Transaction.cpp main.cpp

all: Bank.o Account.o Savings.o Transaction.o main.o
	clang++ Bank.o Account.o Savings.o Transaction.o main.o -o main

clean:
	rm Bank.o Account.o Savings.o Transaction.o main.o main 

cleantest:
	rm a.out
