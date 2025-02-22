#include <stdio.h>
#include <string.h>
#include "../include/account.h"


typedef struct {
	Account acc_list[10];
	int acc_num;
} Bank;

int validate_acc_num(char acc_num[10]);
int validate_pin(int pin);


int main() {
	int option, pin;
	char acc_num[10];

	printf("=== Core Banking System ===\n");

	printf("1) Create Account\n");
	printf("2) Access Account\n");

	printf("Select an Option: ");
	scanf("%d", &option);

	printf("Enter Account Number: ");
	scanf("%s", &acc_num);

	if (validate_acc_num(acc_num) == 1) {
		printf("Error: Invalid Account Number\n");
		return 1;
	}

	printf("Enter Pin: ");
	scanf("%d", &pin);

	if (validate_pin(pin) == 1) {
		printf("Error: Invalid Pin\n");
		return 1;
	}
}


int validate_acc_num(char acc_num[10]);
int validate_pin(int pin);