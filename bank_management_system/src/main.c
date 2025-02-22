#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/account.h"
#include "../include/bank.h"


int main() {
	int option, idx_acc;
	char acc_num[10], pin[5];
	Bank bank = createBank(0);

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

			addAccount(&bank, *createAccount(acc_num, pin, 0));
			printf("Account Created\n");
			break;

		case 2:
			idx_acc = searchBank(&bank, acc_num);

			switch (idx_acc) {
				case -1:
					printf("Account Not Found\n");
					break;
				case 0:
					printf("Account Number: %s\n", bank.acc_list[idx_acc].num);
					printf("Pin: %s\n", bank.acc_list[idx_acc].pin);
					printf("Balance: %.2f\n", bank.acc_list[idx_acc].balance);
					break;
			}
	}

	return 0;
}
