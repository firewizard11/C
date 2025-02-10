#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char acc_num[10];
	float balance;
} Account;

typedef struct {
	Account* acc_list;
	int capacity;
	int length;
} Bank;

Account createAccount(char acc_num[10]);

Bank createBank(int capacity);
void addAccount(Bank* bank, Account* acc);
int searchAccount(Bank bank, char acc_num[10]);

int main() {
	char test_acc_num[10] = "123456789";
	Bank test_bank = createBank(5);
	Account test_acc = createAccount(test_acc_num);
	
	addAccount(&test_bank, &test_acc);

	int idx = searchAccount(test_bank, test_acc_num);

	if (idx == -1) {
		return -1;
	}

	printf("Test Account\n");
	printf("Account Number: %s\n", test_bank.acc_list[idx].acc_num);
	printf("Balance: %.2f\n", test_bank.acc_list[idx].balance);

	return 0;
}

Account createAccount(char acc_num[10]) {
	Account new_acc;

	strcpy(new_acc.acc_num, acc_num);
	new_acc.balance = 0;

	return new_acc;
}

Bank createBank(int capacity) {
	Bank new_bank;

	new_bank.length = 0;
	new_bank.capacity = capacity;
	new_bank.acc_list = malloc(sizeof(Account)*new_bank.capacity);
	
	return new_bank;
}

void addAccount(Bank* bank, Account* acc) {
	bank->acc_list[bank->length] = *acc;
	bank->length++;
}

int searchAccount(Bank bank, char acc_num[10]) {
	int i;

	for (i = 0; i < bank.length; i++) {
		if (strcmp(acc_num, bank.acc_list[i].acc_num) == 0) {
			return i;
		}
	}

	printf("Account not Found\n");
	return -1;
}
