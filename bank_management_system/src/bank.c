#include <string.h>
#include <stdio.h>
#include "..\include\account.h"
#include "..\include\bank.h"

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

void loadBank(Bank* bank) {
	const char filename[] = "./account.txt";
	char acc_num[10];
	char pin[5];
	float balance;
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

		addAccount(bank, *createAccount(acc_num, pin, balance));
	}

	fclose(fp);
}