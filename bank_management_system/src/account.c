#include <string.h>
#include <ctype.h>
#include "../include/account.h"

Account createAccount(char num[10], char pin[5], float balance) {
	/* Creates an Account struct, expects valid account number, pin and balance
	
	:Parameters:
	- char num[10]: Account Number
	- char pin[5]: Account PIN
	- float balance: Starting Balance

	:Returns:
	- Account new_acc: The Account that was created
	*/
	static Account new_acc;
	strcpy(new_acc.num, num);
	strcpy(new_acc.pin, pin); 
	new_acc.balance = balance;
	return new_acc;
}

void depositAccount(Account* acc, float amount) {
	/* Deposit amount into Account */
	acc->balance += amount;
}

float withdrawAccount(Account* acc, float amount) {
	/* Withdraw Money from an Account Struct
	
	:Parameters:
	- Account* acc: Pointer to an Account struct
	- float amount: Amount to withdraw

	:Returns:
	- float w_amount: Amount that was withdrawn
	- -1: If not enough money in account
	*/

	float w_amount; // Withdraw Amount ** More of a IRL Simulation Thing **

	w_amount = acc->balance - amount;

	if (w_amount < 0) {
		return -1;
	}

	acc->balance -= amount;
	return w_amount;
}

int validate_acc_num(char acc_num[10]) {
	/* 9 Digit Account Number Validator 
	
	:Parameters:
	- char acc_num[10]: 9 Digit Account Number

	:Return: (int)
	- 0: On Valid Account Number
	- 1: On Invalid Account Number
	*/

	int length = strlen(acc_num);

	if (length != 9) {
		return 1;
	}

	for (int i = 0; i < length; i++) {
		if (isdigit(acc_num[i]) == 0) {
			return 1;
		}
	}

	return 0;
}

int validate_pin(char pin[5]) {
	/* 4 Digit Pin Validator 
	
	:Parameters:
	- char pin[5]: A 4 Digit PIN

	:Return: (int)
	- 0: On Valid Pin
	- 1: On Invalid Pin
	*/

	int length = strlen(pin);

	if (length != 4) {
		return 1;
	}

	for (int i = 0; i < length; i++) {
		if (isdigit(pin[i]) == 0) {
			return 1;
		}
	}

	return 0;
}