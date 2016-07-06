/*///////////////////////////////////////
����� - ���� ��������                  //
����i����i �������                     //
���� ��������� ������ ����i�          //
*////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <locale>
#include <string>
#include "Accounts.h"

using namespace std;
void loadData();
void getAccounts();
void displayResults();
void getAccountData(unsigned int & accountNo, std::string & bankN, double & balance, double & interesto);//get account data from console entered by user
void getPeriodVal(unsigned int & periodVal);//get period of validity for deposit account
void manualPredef();


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Ukrainian");
	cout << "�������� ����� � ������i" <<endl;
	getAccounts();//get account data from console
	cout << endl;
	cout << "����������i� ������ � ��������" << endl;
	manualPredef();//demonstrate methods
	cout << endl;
	cout << "������������ ����� � �����" << endl;
	loadData(); //demonstrate loading data from file
	_getch();
	return 0;
}

void getAccounts()//create objects according to user input from console
{
	
	char accountType;
	unsigned int numberOfAcc;
	unsigned int accountNo;
	std::string bankN = "";
	double balance, interesto;
	unsigned int periodVal;

	while (1)
	{
		cout << "����i�� �i���i��� ������i�, ��� �� ������ ��������:  ";
		cin >> numberOfAcc;
		if (cin.fail()){ //cin.fail() checks to see if the value in the cin
					//stream is the correct type, if not it returns true,
					//false otherwise.
			cin.clear(); //This skips the left over stream data.
			cin.ignore(); //This corrects the stream.
			cout << "H���������� ��������!" << endl;
		}
		else{
			break;
		}
	}
	if (numberOfAcc == 0){ return; }
	account **accounts = new account*[numberOfAcc];

	for (int i = 0; i < (numberOfAcc); i++)
	{
		cout << "������i�� �  - ��� ��������� ���������� �������,\n" << "D - ��� ����������� �������,\n" << "C - ��� ��������� �������,\n";
		cin >> accountType;
		switch (accountType)
		{
		case 'a':
		case'A':
			getAccountData(accountNo,bankN,balance, interesto);
			accounts[i] = new account(accountNo, bankN, balance, interesto);
			break;
		case 'd':
		case 'D':
			getAccountData(accountNo, bankN, balance, interesto);
			getPeriodVal(periodVal);
			accounts[i] = new depositAccount(accountNo, bankN, balance, interesto,periodVal);

			break;
		case 'c':
		case 'C':
			getAccountData(accountNo, bankN, balance, interesto);
			accounts[i] = new checkingAccount(accountNo, bankN, balance, interesto);
			break;
		default:
			cout << "������� ����������i ���i! \n";
		}
	}

	for (int i = 0; i < (sizeof(accounts) / sizeof(accounts[0])); i++)
	{
		(accounts[i])->printData();
	}
	for (int i = 0; i < (sizeof(accounts) / sizeof(accounts[0])); i++)
	{
		(delete accounts[i]);
	}

	delete[]accounts;
	}


void getAccountData(unsigned int & accountNo, std::string & bankN, double & balance, double & interesto)
{

	while (1)
	{
		cout << "����i�� ����� �������:  ";
		cin >> accountNo;
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "H���������i ���i!"<<endl;
		}
		else{
			break;
		}
	}
	while (1)
	{
		cout << "����i�� ����� �����:  ";
		cin >> bankN;
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "H���������i ���i!" << endl;
		}
		else{
			break;
		}
	}
	while (1)
	{
		cout << "����i�� ���������� ������:  ";
		cin >> balance;
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "H���������i ���i!" << endl;
		}
		else{
			break;
		}
	}
		while (1)
	{
		cout << "����i�� �i�������� ������ � ����������� ������i (����. 0.12):  ";
		cin >> interesto;
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "H���������i ���i!" << endl;
		}
		else{
			break;
		}
	}

}

void getPeriodVal(unsigned int & periodVal){
	while (1)
	{
		cout << "����i�� ����i� �i� ������� � ����:  ";
		cin >> periodVal;
		if (cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "H���������i ���i!" << endl;
		}
		else{
			break;
		}
	}

}

void displayResults(account** accounts){
	for (int i = 0; i < (sizeof(accounts) / sizeof(accounts[0])); i++)
	{
		(accounts[i])->printData();
	}
}

void manualPredef()//processes predefined sample objects to show methods application
{
	account* A= new	account (456123, "Privatbank", 22233, 0.1);
	depositAccount* B = new depositAccount(456697, "Privatbank", 563, 0.12, 689);
	checkingAccount* C = new checkingAccount(456984, "Raiffaisenbank", 22973, 0.15);
	A->printData();
	B->printData();
	C->printData();
	cout << "������������ �����i� ��� ���������� ����i������� �������: " << endl;
	A->setAccountNumber(5353);
	cout <<"��������� ��� �����i� A->setAccountNumber(5353) + A->getAccountNumber():	"<<A->getAccountNumber() << endl;
	A->setBankName("Aval");
	cout << "��������� ��� �����i� A->setBankName(\"Aval\") + A->getBankName():	" << A->getBankName() << endl;
	A->setAccountBalance(100000);
	cout << "��������� ��� �����i� A->setAccountBalance(100000) + A->getAccountBalance():	" << A->getAccountBalance() << endl;
	A->setInterest(0.15);
	cout << "��������� ��� �����i� A->setInterest(0.15) + A->getInterest():	" << A->getInterest() << endl;
	cout << "��������� ��� ������ A->balanceInDays(100):	" << A->balanceInDays(100) << endl;
	cout << endl;
	cout << "������������ �������������� ��������� ��� ����i������� �������: " << endl;
	cout << "���������� ������ �� ������� A: " << A->getAccountBalance() << endl;
	*A = *A + 1000;
	cout << "��������� ��� ������i� (*A = *A + 1000) + A->getAccountBalance():	" << A->getAccountBalance() << endl;
	cout << endl;
	cout << "������������ �����i� ��� ����������� ����i������� �������: " << endl;
	B->setPeriodOfValidity(5353);
	cout << "��������� ��� �����i� B->setPeriodOfValidity(5353) + B->getPeriodOfValidity():	" << B->getPeriodOfValidity() << endl;
	cout << "��������� ��� ������ B->getOpeningDate():	" << B->getOpeningDate() << endl;
	cout << endl;
	cout << "������������ �����i� ��� ��������� ����i������� �������: " << endl;
	cout << "��������� ��� �����i� C->setLastTransationDate() + C->getLastTransationDate():	" << C->getLastTransationDate() << endl;
	C->setAccountBalance(100000);
	cout << "��������� ��� �����i� C->setAccountBalance(100000) + C->getAccountBalance():	" << C->getAccountBalance() << endl;
	
	delete A;
	delete B;
	delete C;

}
void loadData()//processes objects uploaded from file - predefined file
{
	ifstream inputFile;
	inputFile.open("AccountsDB.txt");
	if (!inputFile.is_open())
	{
		cout << "�������� ���� �� i���" << endl;
		return;
	};
	cout << "�������� ���� �i������" << endl;
	account** accounts=new account*[11];
	int i = 0;
	std::string line;
	while ((i<11) && (inputFile))
	{
		cout << endl;
		cout << line << endl;
		unsigned int accountNo;
		std::string bankN = "";
		double balance, interesto;
		unsigned int periodVal;
		inputFile >> accountNo >> bankN >> balance >> interesto >> periodVal;
		(accounts[i])=new account (accountNo,bankN,balance,interesto);
		i++;
		getline(inputFile, line);
		}
		
	for (int i = 0; i < 11; i++)
		{
		(accounts[i])->printData();
		}
	for (int i = 0; i < 11; i++)
	{
		(delete accounts[i]);
	}
	delete[]accounts;
}
