#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/account.h"


typedef struct {
	Account acc_list[10];
	int num_acc;
} Bank;

Bank createBank(int num_acc);
int searchBank(Bank* bank, char acc_num[10]);
void addAccount(Bank* bank, Account acc);

int validate_acc_num(char acc_num[10]);
int validate_pin(char pin[5]);


int main() {
	int option, idx_acc;
	char acc_num[10], pin[5];
	Bank bank = createBank(0);

	printf("=== Core Banking System ===\n");

	printf("1) Create Account\n");
	printf("2) Access Account\n");

	printf("Select an Option: ");
	scanf("%d", &option);

	printf("Enter Account Number: ");
	scanf("%s", &acc_num);

	if (validate_acc_num(acc_num) != 0) {
		printf("Error: Invalid Account Number\n");
		return 1;
	}

	printf("Enter Pin: ");
	scanf("%s", &pin);

	if (validate_pin(pin) != 0 ) {
		printf("Error: Invalid Pin\n");
		return 1;
	}

	addAccount(&bank, *createAccount("123456789", "0000", 0));

	switch (option) {
		case 1:
			if (searchBank(&bank, acc_num) != -1) {
				printf("Error: Account Already Exists\n");
				return 1;
			}

			addAccount(&bank, *createAccount(acc_num, pin, 0));
			printf("Account Created\n");
			break;
	}

	return 0;
}


Bank createBank(int num_acc) {
	Bank new_bank;
	new_bank.num_acc = num_acc;
	return new_bank;
}

int searchBank(Bank* bank, char acc_num[10]) {
	if (bank->num_acc == 0) {
		return -1;
	}

	for (int i = 0; i < bank->num_acc; i++) {
		if (strcmp(bank->acc_list[i].num, acc_num) == 0) {
			return i;
		}
	}

	return -1;
}

void addAccount(Bank* bank, Account acc) {
	bank->acc_list[bank->num_acc] = acc;
	bank->num_acc++;
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