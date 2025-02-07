typedef struct {
    char number[8];
    float balance;
} Account;

Account createAccount(char number[8], float balance);
void addBalance(Account* acc, float amount);
float removeBalance(Account* acc, float amount);
void printAccount(Account acc);