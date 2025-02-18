#include <stdio.h>
#include <string.h>
#include "../include/account.h"


int main() {
	char test_num[10];
	float test_balance;
	float buff;
	Account* acc;

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

	if (acc == NULL) {
		printf("Error: Account creation failed\n");
		return 1;
	}
	
	depositAccount(acc, 1500);

	if (acc->balance != 3000) {
		printf("Error: Deposit Failed %.2f", acc->balance);
		return 1;
	}

	buff = withdrawAccount(acc, 1500);

	if (buff == -1) {
		printf("Error: Not enough Money\n");
		return -1;
	}

	printf("=== Test Account ===\n");
	printf("Account Number: %s\n", acc->num);
	printf("Account Balance: %.2f\n", acc->balance);

	return 0;
}
