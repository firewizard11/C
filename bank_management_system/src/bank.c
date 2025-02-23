#include <string.h>
#include <stdio.h>
#include "..\include\account.h"
#include "..\include\bank.h"

Bank createBank(int num_acc) {
	/* Creates a Bank Struct 
	
	:Parameters:
	- int num_acc: Number of accounts to start with (should be 0 most of the time)

	:Returns:
	- Bank new_bank: The Bank struct
	*/

	Bank new_bank;
	new_bank.num_acc = num_acc;
	return new_bank;
}

int searchBank(Bank* bank, char acc_num[10]) {
	/* Searches the Bank struct for the given account number
	
	:Parameters: 
	- Bank* bank: Pointer to bank struct
	- char acc_num[10]: The account number to look for

	:Returns:
	- Index for Account in bank.acc_list
	- -1: If bank is empty or account not found
	*/

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

void loadBank(Bank* bank) {
	char acc_num[10];
	char pin[5];
	float balance;
	const char filename[] = "./account.txt";
	FILE* fp = fopen(filename, "r");

	if (!fp) {
		printf("Error: File Not Present\n");
		return;
	}

	while (fgetc(fp) != -1) { // Returns -1 when EOF
		fseek(fp, - (long) sizeof(char), SEEK_CUR); // Revert the fgetc fp movement

		fgets(acc_num, sizeof(acc_num), fp);
		fseek(fp, 1, SEEK_CUR);
		fgets(pin, sizeof(pin), fp);
		fseek(fp, 1, SEEK_CUR);
		fscanf(fp, "%f", &balance);
		fseek(fp, 2, SEEK_CUR);

		addAccount(bank, createAccount(acc_num, pin, balance));
	}

	fclose(fp);
}

void saveBank(Bank* bank) {
	char acc_num[10];
	char pin[5];
	char s_balance[10]; // String version of balance
	char line[30]; // Line that gets written to file
	float balance;
	const char filename[] = "./account.txt";
	FILE* fp = fopen(filename, "w");

	if (!fp) {
		printf("Error: Save Failed\n");
		return;
	}

	for (int i = 0; i < bank->num_acc; i++) {
		strcpy(line, ""); // Clears the line
		strcpy(acc_num, bank->acc_list[i].num);
		strcpy(pin, bank->acc_list[i].pin);
		balance = bank->acc_list[i].balance;
		sprintf(s_balance, "%.2f", balance);

		strcat(line, acc_num);
		strcat(line, ",");
		strcat(line, pin);
		strcat(line, ",");
		strcat(line, s_balance);

		if (i != (bank->num_acc - 1)) {
			strcat(line, "\n");
		}

		fputs(line, fp);
	}

	fclose(fp);
}