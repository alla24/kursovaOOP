/*///////////////////////////////////////
Автор - Алла Садовець                  //
Банківські рахунки                     //
Файл з реалізацією класів              //
*////////////////////////////////////////

#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>
#include "Accounts.h"

using namespace std;

account::account(unsigned int accountNo, std::string bankN, double balance, double interesto)
	{
	accountNumber = accountNo;
	bankName = bankN;
	accountBalance=balance;
	interest=interesto;
	cout << "Створено новий рахунок (базовий) No " << accountNumber << endl;
	}
unsigned int account::getAccountNumber()
{
	return accountNumber;
}
void account::setAccountNumber(unsigned int accNo)
{
	accountNumber = accNo;
}
std::string account::getBankName()
{
	return bankName;
}
void account::setBankName(std::string name)
{
	bankName = name;
}
double account::getAccountBalance()
{
	return accountBalance;
}
void account::setAccountBalance(double balance)
{
	if (balance >= 0)		accountBalance = balance;
	else		cout << "Недопустиме значення" << endl;
}
void account::withdraw(double sum)
{
	if (sum <= accountBalance)		accountBalance -= sum;
	else		cout << "Недопустиме значення" << endl;

}
void account::deposit(double sum)
{
	if (sum >= 0)		accountBalance += sum;
	else		cout << "Недопустиме значення" << endl;
}
double account::balanceInDays(int days)
{
	if (days >= 0){
		double futureBalance;
		futureBalance = accountBalance*(pow((1 + interest / 365), days));
		return futureBalance;
	}
	else
	{
		cout << "Недопустиме значення" << endl;
		return 0;
	}

}
double account::getInterest()
{
	return interest;
};
void account::setInterest(double interesto)
{
	interest = interesto;
};
void account::printData()
{
	cout << "---Iнформацiя про рахунок №" << getAccountNumber() << "---" << endl;
	cout << "Вiдкритий у банку:  " << getBankName() << endl;
	cout << "Поточний баланс:  " << getAccountBalance() << endl;
	cout << "Вiдсоткова ставка:  " << ((getInterest()) * 100) << "%" << endl;
}

account::~account()
{
	cout << "Базовий рахунок №" << accountNumber << " знищено." << endl;
};

account operator+(account &a, double b)
{
	a.deposit(b);
	return a;
}

depositAccount::depositAccount(unsigned int accountNo, std::string bankN, double balance, double interesto, unsigned int periodVal) : account(accountNo, bankN, balance, interesto), openingDate()
	{
	//openingDate will be set as a current date after the account is created
	//char temp[26]; 
	time_t rawtime;
	time(&rawtime); // Get current time as integer.

	localtime_s(&openingDate, &rawtime); // Convert to local time.

	periodOfValidity=periodVal; //in days
	cout << "Створено новий рахунок (депозитний) No " << getAccountNumber() << endl;
	}

unsigned int depositAccount::getPeriodOfValidity()
{
	return periodOfValidity;
}
void depositAccount::setPeriodOfValidity(unsigned int days)
{
	periodOfValidity=days;
};
std::string depositAccount::getOpeningDate()
{
	char temp[26];
	asctime_s(temp, 26, &openingDate);
	return temp;
}
void depositAccount::setOpeningDate(tm newDate)
{
	openingDate = newDate;
}
void depositAccount::printData()
{
	cout << "---Iнформацiя про рахунок №" << getAccountNumber() << "---" << endl;
	cout << "Вiдкритий у банку:  " << getBankName() << endl;
	cout << "Поточний баланс:  " << getAccountBalance() << endl;
	cout << "Вiдсоткова ставка:  " << ((getInterest()) * 100) << "%" << endl;
	
	char temp[26];
	asctime_s(temp, 26, &openingDate);
	cout << "Дата вiдкриття рахунку:  " << getOpeningDate() << endl;
	cout << "Термiн дiї рахунку:  " << (periodOfValidity / 365) << " рокiв, " << ((periodOfValidity % 365) / 30) << " мiсяцiв та " << ((periodOfValidity % 365) % 30) << " днiв " << endl;
}
depositAccount::~depositAccount()
{
	cout << "Депозитний рахунок №" << getAccountNumber() << " знищено." << endl;
};

checkingAccount::checkingAccount(unsigned int accountNo, std::string bankN, double balance, double interesto) :account(accountNo, bankN, balance, interesto), lastTransationDate()
{
	
	//lastTransationDate will be nitialised with the date the account is created (current date)
	//char temp[26];
	time_t rawtime;
	time(&rawtime); // Get current time as integer.

	localtime_s(&lastTransationDate, &rawtime); // Convert to local time.
	cout << "Створено новий рахунок (поточний) No " << getAccountNumber() << endl;

	}
std::string  checkingAccount::getLastTransationDate()
{
	char temp[26];
	asctime_s(temp,26, &lastTransationDate);
	return temp;
};
void checkingAccount::setLastTransationDate(tm newDate)
{
	lastTransationDate = newDate;
}
void checkingAccount::printData()
{
	cout << "---Iнформацiя про рахунок №" << getAccountNumber() << "---"<< endl;
	cout << "Вiдкритий у банку:  " <<getBankName()<< endl;
	cout << "Поточний баланс:  " <<getAccountBalance()<< endl;
	cout << "Вiдсоткова ставка:  " << ((getInterest()) * 100 )<< "%" << endl;
	char temp[26];
	asctime_s(temp, 26, &lastTransationDate);
	cout << "Дата останньої тразакцiї:  " << temp << endl;
};
checkingAccount::~checkingAccount()
{
	cout << "Поточний рахунок №" << getAccountNumber() << " знищено." << endl;
};
