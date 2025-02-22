#include <string.h>
#include "../include/account.h"

Account* createAccount(char num[10], char pin[5], float balance) {
	static Account new_acc;
	strcpy(new_acc.num, num);
	strcpy(new_acc.pin, pin); 
	new_acc.balance = balance;
	return &new_acc;
}

void depositAccount(Account* acc, float amount) {
	acc->balance += amount;
}

float withdrawAccount(Account* acc, float amount) {
	float w_amount;

	w_amount = acc->balance - amount;

	if (w_amount < 0) {
		return -1;
	}

	acc->balance -= amount;
	return w_amount;
}