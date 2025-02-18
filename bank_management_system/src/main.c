#include <stdio.h>
#include <string.h>


typedef struct {
	char num[10];
	float balance;
} Account;

Account* createAccount(char num[10], float balance);
void depositAccount(Account* acc, float amount);
float withdrawAccount(Account* acc, float amount);


int main() {
	char test_num[10];
	float test_balance;
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

	printf("=== Test Account ===\n");
	printf("Account Number: %s\n", test_num);
	printf("Account Balance: %.2f\n", test_balance);

	return 0;
}


Account* createAccount(char num[10], float balance) {
	Account new_acc = {*num, balance};
	return &new_acc;
}
