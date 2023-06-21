#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct BankAccount{
	string id;
	string owner;
	string accNumber;
	long ballance;
	string releaseDate;
	string bankName;
};

void getAccountInfo(BankAccount* acc) {
	cout << "<== Enter information for a new account ==>\n";
	cout << "ID: ";
	getline(cin, acc->id);
	cout << "Owner's name: ";
	getline(cin, acc->owner);
	cout << "Account number: ";
	getline(cin, acc->accNumber);
	cout << "Ballance: ";
	cin >> acc->ballance;
	cin.ignore();
	cout << "Release date: ";
	getline(cin, acc->releaseDate);
	cout << "Bank name: ";
	getline(cin, acc->bankName);
}

void showAccInfo(BankAccount* acc) {
	cout << left << setw(10) << "ID" << setw(20) << "Acc Number"
		<< setw(30) << "Owner" << setw(20) << "Bank name"
		<< setw(20) << "Release date" << setw(20) << "Ballance" << endl;
	cout << left << setw(10) << acc->id << setw(20) << acc->accNumber
		<< setw(30) << acc->owner << setw(20) << acc->bankName
		<< setw(20) << acc->releaseDate << setw(20) << acc->ballance << endl;
}

void deposit(BankAccount* acc) {
	cout << "Enter amount of money to deposit: ";
	long amount;
	cin >> amount;
	if (amount > 0) {
		acc->ballance += amount;
		cout << "<== Deposit successfully ==>\n";
	}
	else {
		cout << "<== Invalid deposit amount ==>\n";
	}
}

void withdraw(BankAccount* acc) {
	cout << "Enter amount of money to withdraw: ";
	long amount;
	cin >> amount;
	if (amount > 0 && amount < acc->ballance) {
		acc->ballance -= amount;
		cout << "<== Withdraw successfully ==>\n";
	}
	else {
		cout << "<== Invalid withdraw amount ==>\n";
	}
}

void transfer(BankAccount* acc1, BankAccount* acc2) {
	string acc1Number;
	string acc2Number;
	cout << "Enter number of source account: ";
	getline(cin, acc1Number);
	cout << "Enter number of target account: ";
	getline(cin, acc2Number);
	if (acc1Number.compare(acc2Number) == 0) {
		cout << "<== Two accounts to transfer needed to be different ==>\n";
	}
	else if(acc1Number.length() == 0 ||
		(acc1Number.compare(acc1->accNumber) != 0 &&
		 acc1Number.compare(acc2->accNumber) != 0))
	{
		cout << "<== Invalid source account number ==>\n";
	}
	else if (acc2Number.length() == 0 ||
		(acc2Number.compare(acc1->accNumber) != 0 &&
		 acc2Number.compare(acc2->accNumber) != 0)) {
		cout << "<== Invalid source account number ==>\n";
	}
	else {
		cout << "Enter amount of money to transfer: ";
		long amount;
		cin >> amount;
		if (amount > 0 && acc1->accNumber.compare(acc1Number) == 0 && acc2->accNumber.compare(acc2Number) == 0) {
			acc1->ballance -= amount;
			acc2->ballance += amount;
			cout << "<== Transfer successfully ==>\n";
		}
		else if (amount > 0 && acc2->accNumber.compare(acc1Number) == 0 && acc1->accNumber.compare(acc2Number) == 0) {
			acc2->ballance -= amount;
			acc1->ballance += amount;
			cout << "<== Transfer successfully ==>\n";
		}
		else {
			cout << "<== So du khong du de thuc hien giao dich nay ==>\n";
		}
	}
}

int main() {
	int choice;
	BankAccount* acc1 = new BankAccount();
	BankAccount* acc2 = new BankAccount();
	do {
		cout << "============ OPTION ============\n";
		cout << "1. Create new bank account.\n";
		cout << "2. Display information of current accounts.\n";
		cout << "3. Deposit money.\n";
		cout << "4. Withdraw money.\n";
		cout << "5. Transfer money.\n";
		cout << "6. Check ballance.\n";
		cout << "0. Exit program.\n";
		cout << "Your choice? ";
		cin >> choice;
		cin.ignore();
		switch (choice) 
		{
			case 0:
				cout << "<== Thank you and see you again ==>\n";
				break;
			case 1:
				getAccountInfo(acc1);
				getAccountInfo(acc2);
				break;
			case 2:
				showAccInfo(acc1);
				showAccInfo(acc2);
				break;
			case 3: {
				cout << "Enter account number: ";
				string accNumber;
				getline(cin, accNumber);
				if (acc1->accNumber.compare(accNumber) == 0) {
					deposit(acc1);
				}
				else if (acc2->accNumber.compare(accNumber) == 0) {
					deposit(acc2);
				}
				else {
					cout << "<== Invalid account number ==>\n";
				}
				break;
			}
			case 4: {
				cout << "Enter account number: ";
				string accNumber;
				getline(cin, accNumber);
				if (acc1->accNumber.compare(accNumber) == 0) {
					withdraw(acc1);
				}
				else if (acc2->accNumber.compare(accNumber) == 0) {
					withdraw(acc2);
				}
				else {
					cout << "<== Invalid account number ==>\n";
				}
				break;
			}
			case 5: {
				transfer(acc1, acc2);
				break;
			}
			case 6: {
				cout << "Enter account number: ";
				string accNumber;
				getline(cin, accNumber);
				if (acc1->accNumber.compare(accNumber) == 0) {
					showAccInfo(acc1);
				}
				else if(acc2->accNumber.compare(accNumber) == 0){
					showAccInfo(acc2);
				}
				else {
					cout << "<== Invalid account ==>\n";
				}
				break;
			}
			default:
				cout << "<== Wrong function, please check again ==>\n";
				break;
		}
	} while (choice != 0);

	delete acc1;
	delete acc2;

	return 0;
}