#include <string.h>
#include <ctype.h>
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

int validate_acc_num(char acc_num[10]) {
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