#include <stdio.h>

#include "account.h"

typedef struct {
    Account open_acc[10];
    int num_acc;
} Bank;

Bank createBank();
void openAccount(char number[8]);
static int searchBank(char number[8]);
void closeAccount(char number[8]);
void checkAccount(char number[8]);
void depositAccount(char number[8], float amount);
float withdrawAccount(char number[8], float amount);

int main() {
    Bank test_bank = createBank();

    return 0;
}

Bank createBank() {
    Bank new_bank;
    new_bank.num_acc = 0;

    return new_bank;
}