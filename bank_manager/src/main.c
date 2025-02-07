#include <stdio.h>
#include "../include/account.h"

int main() {
	char* test_number = "1234567890";
	float test_balance = 1500;

	Account test_acc = createAccount(test_number, test_balance);
	
	printf("Test Account:\nNumber: %s\nBalance: %.2f\n", test_acc.number, test_acc.balance);

	printf("\nTest Deposit\n");
	depositAccount(&test_acc, 1500);
	printf("Balance: %.2f\n", test_acc.balance);

	printf("\nWithdraw Test\n");
	float res = withdrawAccount(&test_acc, 4000);
	printf("Balance: %.2f\nResult: %.2f\n", test_acc.balance, res);
	
	return 0;
}