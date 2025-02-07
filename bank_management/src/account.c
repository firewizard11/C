#include <string.h>
#include <stdio.h>

#include "account.h"

Account createAccount(char number[8], float balance) {
    Account acc;

    strcpy(acc.number, number);
    acc.balance = balance;

    return acc;
}

void printAccount(Account acc) {
    printf("Account Number: %s\n", acc.number);
    printf("Balance: $%.2f\n", acc.balance);
}

void addBalance(Account* acc, float amount) {
    acc->balance += amount;
}

float removeBalance(Account* acc, float amount) {
    if (acc->balance - amount < 0) {
        printf("Balance too Low\n");
        return 0;
    }

    acc->balance -= amount;
    return amount;
}