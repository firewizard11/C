#include <stdio.h>
#include <string.h>

struct Account {
	char* number;
	float balance;
};

struct Account createAccount(char* number, float balance);

int main() {
	char* test_number = "1234567890";
	float test_balance = 1500;

	struct Account test_acc = createAccount(test_number, test_balance);
	
	printf("Test Account:\nNumber: %s\nBalance: %.2f\n", test_acc.number, test_acc.balance);
	
	return 0;
}	

struct Account createAccount(char* number, float balance) {
	struct Account new_account;

	new_account.number = number;
	new_account.balance = balance;
	
	return new_account;
}
