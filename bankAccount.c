#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "bankAccount.h"

void initialize(bankAccount *acc) {
	acc->size=0;
}
void setName(bankAccount *acc,char *last,char *first) {
	acc->lastName=last;
	acc->firstName=first;
}

void changeAmount(bankAccount *acc,double value) {
	acc->amount=value;
}

void getInfo(bankAccount *acc) {
	printf("Name: %s %s \nAmount: %f \n",acc->lastName,acc->firstName,acc->amount);
}

void addMovements(bankAccount *acc,movements *m) { 

	(acc->motions)[acc->size]=m;
	(acc->size)++;
}
void getMovements(bankAccount *acc) { 
	int i;
	for (i=0;i<(acc->size);i++) { 
		getInfoMovements(&(acc->motions)[i]);
	}
}

void getInfoMovements(movements *m) { 
	printf("Amount: %f from/to %s  ",m->amountSpent,m->whereSpent);
	if ((m->amountSpent)>=0) { 
		printf("Type: ");
		printEarning(m->typeE);	
	}
	else { 
		printf("Type: ");
		printSpending(m->typeS);
	}
	printf("\n");
}
void setInfoMovements(movements *m,double value,char *c,spendingType s,earningType e) { 
	m->amountSpent=value;
	m->whereSpent=c;
	m->typeS=s;
	m->typeE=e;
}

void printEarning(earningType e) { 
	switch (e) {
		case(0):printf("WAGE"); break;
		case(1):printf("PRESENT"); break;
		case(2):printf("REFUND"); break;
		case(3):printf("ALLOWANCE"); break;
		case(4):printf("OTHER"); break;
	}
}
void printSpending(spendingType s) { 
	switch (s) {
		case(0):printf("DWELLING"); break;
		case(1):printf("GROCERIES"); break;
		case(2):printf("ENTERTAINEMENT"); break;
		case(3):printf("FINANCE"); break;
		case(4):printf("TRANSPORT"); break;
		case(5):printf("COMMUNICATION"); break;
		case(6):printf("OTHER"); break;
	}
}


