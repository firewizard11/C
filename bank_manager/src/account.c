#include "../include/account.h"
#include <stdio.h>

Account createAccount(char* number, float balance) {
	Account new_account;

	new_account.number = number;
	new_account.balance = balance;
	
	return new_account;
}

void depositAccount(Account* acc, float amount) {
	acc->balance += amount;
}

float withdrawAccount(Account* acc, float amount) {
	if ((acc->balance - amount) < 0) {
		printf("Error: Balance too low\n");
		return -1;
	}

	acc->balance -= amount;

	return amount;
}