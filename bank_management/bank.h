#include "account.h"

typedef struct {
    Account open_acc[10];
    int num_acc;
} Bank;

Bank createBank();
void openAccount(Bank* bank, char number[8]);
static int searchBank(Bank bank, char number[8]);
void closeAccount(Bank* bank, char number[8]); // TODO
void checkAccount(Bank bank, char number[8]);
void depositAccount(Bank* bank, char number[8], float amount);
float withdrawAccount(Bank* bank, char number[8], float amount);