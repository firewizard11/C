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

	if (acc == NULL) {
		printf("Error: Account creation failed\n");
		return 1;
	}
	
	depositAccount(acc, 1500);

	if (acc->balance != 3000) {
		printf("Error: Deposit Failed %.2f", acc->balance);
		return 1;
	}

	printf("=== Test Account ===\n");
	printf("Account Number: %s\n", acc->num);
	printf("Account Balance: %.2f\n", acc->balance);

	return 0;
}


Account* createAccount(char num[10], float balance) {
	static Account new_acc;
	strcpy(new_acc.num, num); 
	new_acc.balance = balance;
	return &new_acc;
}

void depositAccount(Account* acc, float amount) {
	acc->balance += amount;
}

float withdrawAccount(Account* acc, float amount);