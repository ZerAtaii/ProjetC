#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"

void initialize(bankAccount acc) {
	acc.size=0;
	
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

void addMovements(bankAccount *acc,movements* m) {
	(acc->motions)[acc->size]=*m;
	(acc->size)++;
	
}
void getMovements(bankAccount *acc) { 
	int i=0;
	printf("Liste des mouvements: \n");
	for (i=0;i<(acc->size);i++) {
		getInfoMovements((acc->motions)[i]);	
	}
}

void getInfoMovements(movements m) { 
	printf("Amount: %f € from/to %s  ",m.amountSpent,m.whereSpent);
	if ((m.amountSpent)>=0) { 
		printf("Type: ");
		printEarning(m.typeE);	
	}
	else { 
		printf("Type: ");
		printSpending(m.typeS);
	}
	printf(" at %s \n",m.date);
}
void setInfoMovements(movements *m,double value,char *c,spendingType s,earningType e,char *d) { 
	m->amountSpent=value;
	m->whereSpent=c;
	m->typeS=s;
	m->typeE=e;
	m->date=d;
}

void setEarningType(movements *m,earningType e) {
	m->typeE=e;
}

void setSpendingType(movements *m,spendingType s) {
	m->typeS=s;
}

void setType(bankAccount *acc) {
	int *tab;
	tab=malloc(acc->size*sizeof(int));
	int i;
	for (i=0;i<acc->size;i++) {
		if ((acc->motions[i]).amountSpent<0) {
			printf("What is the type for this movements? \n");
			getInfoMovements(acc->motions[i]);
			int a;
			printf("DWELLING=0, GROCERIES=1, ENTERTAINEMENT=2, FINANCE=3, TRANSPORT=4, COMMUNICATION=5, OTHERSPENDING=6\n");
			scanf("%d",&a);
			tab[i]=a;
		}
		else {
			printf("What is the type for this movements? \n");
			getInfoMovements(acc->motions[i]);
			int a;
			printf("WAGE=0, PRESENT=1, REFUND=2, ALLOWANCE=3, OTHEREARNING=4\n");
			scanf("%d",&a);
			tab[i]=a;
		}
	}
	int j;
	for (j=0;j<acc->size;j++) {
		if ((acc->motions[j]).amountSpent<0) {
			setSpendingType(&(acc->motions[j]),tab[j]);
		}
		else {
			setEarningType(&(acc->motions[j]),tab[j]);
		}
	}
}

void printEarning(earningType e) { 
	switch (e) {
		case(0):printf("WAGE"); break;
		case(1):printf("PRESENT"); break;
		case(2):printf("REFUND"); break;
		case(3):printf("ALLOWANCE"); break;
		case(4):printf("OTHER"); break;
		case(10):printf("NONE");break;
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
		case(10):printf("NONES"); break;
	}
}


