#include <string.h>
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