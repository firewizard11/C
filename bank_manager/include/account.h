typedef struct {
	char* number;
	float balance;
} Account;

Account createAccount(char* number, float balance);

void depositAccount(Account* acc, float amount);

float withdrawAccount(Account* acc, float amount);