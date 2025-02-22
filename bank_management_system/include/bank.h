typedef struct {
	Account acc_list[10];
	int num_acc;
} Bank;

Bank createBank(int num_acc);
int searchBank(Bank* bank, char acc_num[10]);
void addAccount(Bank* bank, Account acc);