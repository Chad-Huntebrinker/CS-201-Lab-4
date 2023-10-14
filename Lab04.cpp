// Chad Huntebrinker
// crh92d@umsystem.edu
// 9/17/20
// CS201L Lab 04

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char MainMenu();
float GetValue(string output);
float GetValue(float depositValue, string output);
float GetInterestRate(int creditScore);
void Withdraw(float& accountBalance, float withdrawAmount);
int GetLoanMonths();
int GetCreditRating();
float CalculateLoanAmount(float Principal, float interestRate, int numMonths);
void OutputAccount(float amount);

int main() {
	char userInput;
	string response1, response2;
	float depositValue = 0;
	float withdrawAmount, interestRate, borrowedAmount;
	int creditRating, numberOfMonths;
	response1 = "How much do you want to deposit? ==> ";
	response2 = "How much do you want to withdraw? ==> ";
	cout << fixed << setprecision(2);
	do {
		userInput = MainMenu();
		if (userInput == 'D') {
			depositValue = depositValue + GetValue(response1);
			OutputAccount(depositValue);
		}
		else if (userInput == 'W') {
			withdrawAmount = GetValue(depositValue, response2);
			Withdraw(depositValue, withdrawAmount);
			OutputAccount(depositValue);
		}
		else if (userInput == 'L') {
			creditRating = GetCreditRating();
			interestRate = GetInterestRate(creditRating);
			numberOfMonths = GetLoanMonths();
			cout << "How much do you want to borrow? ";
			cin >> borrowedAmount;
			cout << endl;
			cout << "Interest Rate: " << interestRate << endl;
			cout << "Principal: " << borrowedAmount << endl;
			cout << "Months: " << numberOfMonths << endl;
			cout << "Your total loan amount is " 
				<< CalculateLoanAmount(borrowedAmount, interestRate, numberOfMonths) << endl;


		}
		else {
			userInput = 'Q';
		}
	} while (userInput != 'Q');
	
	return 0;
}

char MainMenu() {
	char userLetter;
	cout << "Main Menu ( Enter one of the following ) \n	(D)eposit, "
		<< "(W)ithdrawl, (L)oan, or (Q)uit" << endl;
	cin >> userLetter;
	cout << endl;
	do {
		if ((userLetter == 'd') || (userLetter == 'D')) {
			userLetter = 'D';
		}
		else if ((userLetter == 'w') || (userLetter == 'W')) {
			userLetter = 'W';
		}
		else if ((userLetter == 'l') || (userLetter == 'L')) {
			userLetter = 'L';
		}
		else if ((userLetter == 'q') || (userLetter == 'Q')) {
		userLetter = 'Q';
		}
		else {
			cout << "You have not entered a valid letter. Please try again.";
			userLetter = 'E';
		}
	} while (userLetter == 'E');
	return userLetter;
}

float GetValue(string output) {
	float userDeposit;
	do {
		cout << output;
		cin >> userDeposit;
		if (userDeposit <= 0) {
			cout << "You must enter an amount greater than 0" << endl;
		}
	} while (userDeposit <= 0);
	return userDeposit;

}

float GetValue(float depositValue, string output) {
	float withdrawAmount;
	do {
		cout << output;
		cin >> withdrawAmount;
		cout << endl;
		if ((withdrawAmount <= 0) || (withdrawAmount > depositValue)) {
			cout << "You must enter an amount less than or equal to " << depositValue << endl;
		}
	} while ((withdrawAmount <= 0) || (withdrawAmount > depositValue));
	return withdrawAmount;
}
float GetInterestRate(int creditScore) {
	float interestRate;
	if (creditScore <= 500) {
		interestRate = 0.05;
		return interestRate;
	}
	else if ((creditScore > 500) && (creditScore <= 700)) {
		interestRate = 0.03;
		return interestRate;
	}
	else if (creditScore > 700) {
		interestRate = 0.01;
		return interestRate;
	}
}
void Withdraw(float& accountBalance, float withdrawAmount) {
	accountBalance = accountBalance - withdrawAmount;
}
int GetLoanMonths() {
	int numMonths;
	cout << "How many months for the loan? 12, 24, 36 or 60 ==> ";
	cin >> numMonths;
	cout << endl;
	if ((numMonths == 12) || (numMonths == 24) || (numMonths == 36) || (numMonths == 60)) {
		return numMonths;
	}
	else {
		cout << endl;
		cout << "You must enter 12, 24, 36 or 60 only" << endl;
	}
}
int GetCreditRating() {
	int creditScore;
	cout << "What is your credit rating? [300 - 850] ==> ";
	cin >> creditScore;
	cout << endl;
	if ((creditScore < 300) || (creditScore > 850)) {
		cout << "You must choose a value between 300 - 850 inclusive." << endl;
	}
	else {
		return creditScore;
	}
}
float CalculateLoanAmount(float Principal, float interestRate, int numMonths) {
	float totalAmount;
	totalAmount = Principal * pow((1 + (interestRate / 12)), (numMonths / 12));
	return totalAmount;
}
void OutputAccount(float amount) {
	cout << endl;
	cout << "==========================================" << endl;
	cout << "Your account total is: $" << amount << endl;
	cout << "==========================================" << endl;
	cout << endl;
}