enum spendingType {
	DWELLING, GROCERIES, ENTERTAINEMENT, FINANCE, TRANSPORT, COMMUNICATION, OTHERSPENDING, NONES=10
};
typedef enum spendingType spendingType;

enum earningType {
	WAGE, PRESENT, REFUND, ALLOWANCE, OTHEREARNING, NONE=10
};
typedef enum earningType earningType;

struct movements {
	double amountSpent;
	char *whereSpent;
	spendingType typeS;
	earningType typeE;
	char *date;

};
typedef struct movements movements;

struct bankAccount {
	double amount;
	char *lastName;
	char *firstName;
	int size;
	movements motions[100];
};
typedef struct bankAccount bankAccount;


void initialize(bankAccount *acc);
void setName(bankAccount *acc,char *last,char *first);
void changeAmount(bankAccount *acc,double value);
void getInfo(bankAccount *acc);
void addMovements(bankAccount *acc,movements* m);
void getMovements(bankAccount *acc);
void getInfoMovements(movements m);
void setInfoMovements(movements *m,double value,char *c,spendingType s,earningType e,char *d);
void printEarning(earningType e);
void printSpending(spendingType s);
