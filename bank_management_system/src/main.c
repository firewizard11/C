#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/account.h"
#include "../include/bank.h"


int main() {
	int option, option2, option3, idx_acc;
	float amount;
	char acc_num[10], pin[5];
	Bank bank = createBank(0);
	Account* curr_acc;

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

			addAccount(&bank, *createAccount(acc_num, pin, 0));
			printf("Account Created\n");
			break;

		case 2:
			idx_acc = searchBank(&bank, acc_num);

			if (idx_acc == -1) {
				printf("Account Not Found\n");
				return 1;
			}

			if (strcmp(bank.acc_list[idx_acc].pin, pin) != 0) {
				printf("Error: PIN doesn't Match\n");
				return 1;
			} 
			
			curr_acc = &bank.acc_list[idx_acc];

			while (1) {
				printf("1) Deposit\n");
				printf("2) Withdraw\n");
				printf("3) Check Balance\n");
				printf("Select an Option: ");
				scanf("%d", &option2);
	
				if (option2 != 1 && option2 != 2 && option2 != 3) {
					printf("Error: Invalid Option\n");
					continue;
				}
	
				switch (option2) {
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
				scanf("%d", &option3);

				if (option3 == 1) {
					continue;
				} else if (option3 == 2) {
					break;
				}
			}
			
			break;
			}


	saveBank(&bank);
	return 0;
}
