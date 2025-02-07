#include <stdio.h>
#include <string.h>

#include "account.h"

typedef struct {
    Account open_acc[10];
    int num_acc;
} Bank;

Bank createBank();
void openAccount(Bank* bank, char number[8]);
static int searchBank(Bank bank, char number[8]);
void closeAccount(Bank* bank, char number[8]);
void checkAccount(Bank bank, char number[8]);
void depositAccount(Bank* bank, char number[8], float amount);
float withdrawAccount(Bank* bank, char number[8], float amount);

int main() {
    Bank test_bank = createBank();

    openAccount(&test_bank, "12345678");

    checkAccount(test_bank, "12345678");

    depositAccount(&test_bank, "12345678", 1500);

    checkAccount(test_bank, "12345678");

    return 0;
}

Bank createBank() {
    Bank new_bank;
    new_bank.num_acc = 0;

    return new_bank;
}

void openAccount(Bank* bank, char number[8]) {
    bank->open_acc[bank->num_acc] = createAccount(number, 0);
    bank->num_acc += 1;
}

static int searchBank(Bank bank, char number[8]) {
    for (int i = 0; i < bank.num_acc; i++) {
        if (!strcmp(number, bank.open_acc[i].number)) {
            return i;
        }
    }
}

void checkAccount(Bank bank, char number[8]) {
    int idx;
    Account acc;

    idx = searchBank(bank, number);
    acc = bank.open_acc[idx];
    printAccount(acc);
}

void depositAccount(Bank* bank, char number[8], float amount) {
    int idx;

    idx = searchBank(*bank, number);

    addBalance(&bank->open_acc[idx], amount);
}