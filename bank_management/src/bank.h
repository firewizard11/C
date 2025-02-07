#define MAX_DIGITS 8

typedef struct {
    char number[MAX_DIGITS];
    float balance;
} Account;

void openAccount(char number[MAX_DIGITS], float balance);
void closeAccount(char number[MAX_DIGITS]);
float checkAccount(char number[MAX_DIGITS]);

void depositAccount(char number[MAX_DIGITS], float amount);
void withdrawAccount(char number[MAX_DIGITS], float amount);
void transferMoney(char acc1[MAX_DIGITS], char acc2[MAX_DIGITS]);