#include <stdio.h>
#include <string.h>
#include "../include/account.h"


typedef struct {
	Account acc_list[10];
	int acc_num;
} Bank;

Bank* createBank();


int main() {
	char test_num[10];
	float test_balance;
	float buff;
	Account* acc;
	Bank* test_bank;

	printf("Enter Account number: ");
	scanf("%s", &test_num);

	// Account Number Input Validation
	if (strlen(test_num) != 9) {
		printf("Error: Account number must be 9 Digits\n");
		return 1;
	}

	printf("Enter Account Balance: ");
	scanf("%f", &test_balance);

	acc = createAccount(test_num, test_balance);

	// Account Creation Error Check
	if (acc == NULL) {
		printf("Error: Account creation failed\n");
		return 1;
	}

	test_bank = createBank();
	
	depositAccount(acc, 1500);

	if (acc->balance != 3000) {
		printf("Error: Deposit Failed %.2f", acc->balance);
		return 1;
	}

	buff = withdrawAccount(acc, 1500);

	// Account Deposit Fail Check
	if (buff == -1) {
		printf("Error: Not enough Money\n");
		return -1;
	}

	printf("=== Test Account ===\n");
	printf("Account Number: %s\n", acc->num);
	printf("Account Balance: %.2f\n", acc->balance);

	return 0;
}


Bank* createBank() {
	static Bank new_bank;
	new_bank.acc_num = 0;
	return &new_bank;
}