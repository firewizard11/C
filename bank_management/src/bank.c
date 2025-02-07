#include <string.h>
#include "bank.h"

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
    int idx = searchBank(*bank, number);

    addBalance(&bank->open_acc[idx], amount);
}

float withdrawAccount(Bank* bank, char number[8], float amount) {
    int idx = searchBank(*bank, number);

    return removeBalance(&bank->open_acc[idx], amount);
}