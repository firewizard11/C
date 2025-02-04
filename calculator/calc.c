#include <stdio.h>

int main() {
	float op1;
	float op2;
	float result;
	int option;

	printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n");
	printf("Select an Option: ");
	scanf("%d", &option);	
	
	if (option < 1 || option > 4) {
		printf("Error: Select a valid option\n");
		return 1;
	}

	printf("Enter Operand 1: ");
	scanf("%f", &op1);

	printf("Enter Operand 2: ");
	scanf("%f", &op2);

	printf("Operand 1: %f\nOperand 2: %f\n", op1, op2);	

	switch (option) {
		case 1:
			result = op1 + op2;
			break;
		case 2:
			result = op1 - op2;
			break;
		case 3:
			result = op1 * op2;
			break;
		case 4:
			result = op1 / op2;	
			break;
	}

	printf("Result: %f\n", result);
	
	return 0;
}
