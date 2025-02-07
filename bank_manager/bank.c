#include <stdio.h>
#include <string.h>

typedef struct {
	char* number;
	float balance;
} Account;

Account createAccount(char* number, float balance);
void depositAccount(Account* acc, float amount);
float withdrawAccount(Account* acc, float amount);

int main() {
	char* test_number = "1234567890";
	float test_balance = 1500;

	Account test_acc = createAccount(test_number, test_balance);
	
	printf("Test Account:\nNumber: %s\nBalance: %.2f\n", test_acc.number, test_acc.balance);

	printf("\nTest Deposit\n");

	depositAccount(&test_acc, 1500);

	printf("Balance: %.2f\n", test_acc.balance);
	
	return 0;
}	

Account createAccount(char* number, float balance) {
	Account new_account;

	new_account.number = number;
	new_account.balance = balance;
	
	return new_account;
}

void depositAccount(Account* acc, float amount) {
	acc->balance += amount;
}