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

    printAccount(test_acc);

    return 0;
}

Account createAccount(char number[8], float balance) {
    Account acc;

    strcpy(acc.number, number);
    acc.balance = balance;

    return acc;
}

void printAccount(Account acc) {
    printf("Account Number: %s\n", acc.number);
    printf("Balance: %.2f", acc.balance);
}