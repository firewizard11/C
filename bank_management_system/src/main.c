#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/account.h"
#include "../include/bank.h"


int acc_ops(Bank* bank, char acc_num[10], char pin[5]);


int main() {
	int option, op_result;
	char acc_num[10], pin[5];
	Bank bank = createBank(0);
	loadBank(&bank);

	printf("=== Core Banking System ===\n");
	printf("1) Create Account\n");
	printf("2) Access Account\n");
	printf("Select an Option: ");
	scanf("%d", &option);

	if (!(option == 1) && !(option == 2)) {
		printf("Error: Invalid Option\n");
		return 1;
	}

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

	switch (option) {
		case 1:
			if (searchBank(&bank, acc_num) != -1) {
				printf("Error: Account Already Exists\n");
				return 1;
			}

			addAccount(&bank, createAccount(acc_num, pin, 0));
			printf("Account Created\n");
			break;

		case 2:
			op_result = acc_ops(&bank, acc_num, pin);

			if (op_result == 1) {
				printf("Error: Account Operation Failure\n");
			}
			
			break;
			}


	saveBank(&bank);
	return 0;
}


int acc_ops(Bank* bank, char acc_num[10], char pin[5]) {
	int idx_acc, option, option2;
	float amount;
	Account* curr_acc;
	
	idx_acc = searchBank(bank, acc_num);
	if (idx_acc == -1) {
		printf("Account Not Found\n");
		return 1;
	}

	if (strcmp(bank->acc_list[idx_acc].pin, pin) != 0) {
		printf("Error: PIN doesn't Match\n");
		return 1;
	} 
	
	curr_acc = &bank->acc_list[idx_acc];

	while (1) {
		printf("1) Deposit\n");
		printf("2) Withdraw\n");
		printf("3) Check Balance\n");
		printf("Select an Option: ");
		scanf("%d", &option);

		if (option != 1 && option != 2 && option != 3) {
			printf("Error: Invalid Option\n");
			continue;
		}

		switch (option) {
			case 1:
				printf("Enter Amount: ");
				scanf("%f", &amount);
				depositAccount(curr_acc, amount);
				break;
			case 2:
				printf("Enter Amount: ");
				scanf("%f", &amount);
				withdrawAccount(curr_acc, amount);
				break;
			case 3:
				printf("Balance: %.2f\n", curr_acc->balance);
				break;
		}

		printf("1) More Operations\n");
		printf("2) Quit\n");
		printf("Select an Option: ");
		scanf("%d", &option2);

		if (option2 == 1) {
			continue;
		} else if (option2 == 2) {
			break;
		} else {
			printf("Error: Invalid Option\n");
			break;
		}
	}

	return 0;
}