#define MAX_DIGITS 8

typedef struct {
    char number[8];
    float balance;
} Account;

typedef struct {
    Account* accounts;
    int n_acc = 0;
} Bank;

void openAccount(Bank* Bank, char number[MAX_DIGITS]);
void closeAccount(Bank* Bank, char number[MAX_DIGITS]);
float checkBalance(Bank* Bank, char number[MAX_DIGITS]);

void depositMoney(Bank* bank, char number[MAX_DIGITS], float amount);
float withdrawMoney(Bank* bank, char number[MAX_DIGITS], float amount);
void transferMoney(Bank* bank, char first[MAX_DIGITS], char sec[MAX_DIGITS], float amount);