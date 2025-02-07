#include "bank.h"

int main() {
    Bank test_bank = createBank();

    openAccount(&test_bank, "12345678");
    checkAccount(test_bank, "12345678");

    depositAccount(&test_bank, "12345678", 1500);
    checkAccount(test_bank, "12345678");

    withdrawAccount(&test_bank, "12345678", 500);
    checkAccount(test_bank, "12345678");

    return 0;
}