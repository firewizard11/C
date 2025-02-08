#include <stdio.h>
#include <string.h>


typedef struct {
	char acc_num[10];
	float balance;
} Account;

Account createAccount(char acc_list[10], float balance);


int main() {
	int choice;
	int length = 0;
	char acc_num[10];
	Account cur_acc;
	Account acc_list[100];

	printf("Bank Management System\n");
	printf("1) Create Account\n");
	printf("Select an option: ");
	scanf("%d", &choice);

	switch (choice) {
		case 1:
			printf("Enter Account Number: ");
			scanf("%s", acc_num);

			cur_acc = createAccount(acc_num, 0);
			if (cur_acc.balance == -1) {
				return -1;
			}

			acc_list[length] = cur_acc;
			length++;

			printf("Account Number: %s\n", acc_list[0].acc_num);
			printf("Balance: %.2f\n", acc_list[0].balance);

			break;
		default:
			printf("Enter Valid Options\n");
			return -1;
	}

	return 0;
}	


Account createAccount(char acc_num[10], float balance) {
	Account new_acc;

	if (strlen(acc_num) >= 10) {
		printf("Error: Account Number Too Long\n");
		new_acc.balance = -1;
		return new_acc;
	}

	strcpy(new_acc.acc_num, acc_num);
	new_acc.balance = balance;

	return new_acc;
}