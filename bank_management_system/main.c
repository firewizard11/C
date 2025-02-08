#include <stdio.h>

int main() {
	int choice;

	printf("Bank Management System\n");

	printf("1) Create Account\n");
	printf("2) Login to Account\n");
	printf("Select Option: ");
	scanf("%d", &choice);

	switch (choice) {
		case 1:
			printf("Creating Account\n");
			break;
		case 2:
			printf("Logging in\n");
			break;
		default:
			printf("Please check a valid choice\n");
			return 1;
	}

	return 0;
}
