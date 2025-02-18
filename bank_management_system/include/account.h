typedef struct {
	char num[10];
	float balance;
} Account;

Account* createAccount(char num[10], float balance);
void depositAccount(Account* acc, float amount);
float withdrawAccount(Account* acc, float amount);