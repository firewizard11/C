#include <stdio.h>

#include "account.h"

int main() {
    Account test_acc = createAccount("12345678", 0);
    printAccount(test_acc);

    addBalance(&test_acc, 1500);
    printAccount(test_acc);

    removeBalance(&test_acc, 1500);
    printAccount(test_acc);

    removeBalance(&test_acc, 2000);
    printAccount(test_acc);

    return 0;
}