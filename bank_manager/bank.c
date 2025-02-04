#include <stdio.h>
#include <string.h>

struct Account {
	char* number;
	float balance;
};

int main() {
	struct Account test_acc = {"1234567890", 1500};
	
	printf("Test Account:\nNumber: %s\nBalance: %.2f\n", test_acc.number, test_acc.balance);
	
	return 0;
}	
