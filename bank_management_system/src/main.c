#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/account.h"


typedef struct {
	Account acc_list[10];
	int acc_num;
} Bank;

int validate_acc_num(char acc_num[10]);
int validate_pin(char pin[5]);


int main() {
	int option;
	char acc_num[10], pin[5];

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
	printf("%d", strlen(pin));

	return 0;
}