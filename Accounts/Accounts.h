/*///////////////////////////////////////
Автор - Алла Садовець                  //
Банківські рахунки                     //
Файл - header з прототипами класів     //
*////////////////////////////////////////

#pragma once

#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <time.h>
#include <iostream>
#include <string>

class account{
private:
	unsigned int accountNumber;
	std::string bankName;

	double interest;
protected:
	double accountBalance;

public:
	account(unsigned int accountNo = 0, std::string bankN = "", double balance = 0, double interesto = 0);
	unsigned int getAccountNumber();
	void setAccountNumber(unsigned int accNo);
	std::string getBankName();
	void setBankName(std::string name);
	double getAccountBalance();
	void setAccountBalance(double balance);
	void withdraw(double sum);
	void deposit(double sum);
	double balanceInDays(int days);
	double getInterest();
	void setInterest(double interest);
	void printData();
	friend account operator+(account &, double);
	~account();
};

class depositAccount :public account
{
private:
	tm openingDate; // will be set as a current date after the account is created
	unsigned int periodOfValidity; //in days

public:
	depositAccount(unsigned int accountNo = 0, std::string bankN = "", double balance = 0, double interesto = 0, unsigned int periodVal = 0);
	unsigned int getPeriodOfValidity();
	void setPeriodOfValidity(unsigned int days);
	std::string getOpeningDate();
	void setOpeningDate(tm newDate);
	void printData();
	~depositAccount();
};


class checkingAccount :public account
{
private:
	tm lastTransationDate; // will be set as a current date after new transaction takes place

public:
	checkingAccount(unsigned int accountNo = 0, std::string bankN = "", double balance = 0, double interesto = 0);
	std::string  getLastTransationDate();
	void setLastTransationDate(tm newDate);
	void printData();
	~checkingAccount();

};
#endif