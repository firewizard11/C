#include <stdio.h>
#include <string.h>

typedef struct {
    char number[8];
    float balance;
} Account;

Account createAccount(char number[8], float balance);
void addBalance(Account* acc, float amount);
float removeBalance(Account* acc, float amount);
void printAccount(Account acc);

int main() {
    Account test_acc = createAccount("12345678", 0);

    printf("Test Account\n");
    printf("Number: %s\n", test_acc.number);
    printf("Balance: %.2f\n", test_acc.balance);

    return 0;
}

Account createAccount(char number[8], float balance) {
    Account acc;

    strcpy(acc.number, number);
    acc.balance = balance;

    return acc;
}