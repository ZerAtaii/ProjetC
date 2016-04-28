#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"


double* getTotalSpendingType(bankAccount acc) {
	
	double *spendings = malloc(7*sizeof(double));
	int i;
	for (i = 0; i<acc.size; i++) {
		if (acc.motions[i].amountSpent<0) {
			switch(acc.motions[i].typeS) {
				case(DWELLING): spendings[0] = spendings[0] + acc.motions[i].amountSpent; return;
				case(ENTERTAINEMENT): spendings[1] = spendings[1] + acc.motions[i].amountSpent; break;
				case(GROCERIES): spendings[2] = spendings[2] + acc.motions[i].amountSpent; break;
				case(FINANCE): spendings[3] = spendings[3] + acc.motions[i].amountSpent; break;
				case(TRANSPORT): spendings[4] = spendings[4] + acc.motions[i].amountSpent; break;
				case(COMMUNICATION): spendings[5] = spendings[5] + acc.motions[i].amountSpent; break;
				case(OTHERSPENDING): spendings[6] = spendings[6] + acc.motions[i].amountSpent; break;
			}
		}
	}
	return spendings;
}

double* getTotalEarningType(bankAccount acc) {

	double *earnings = malloc(5*sizeof(double));
	int i;
	for (i = 0; i<acc.size; i++) {
		if (acc.motions[i].amountSpent>0) {
			switch(acc.motions[i].typeE) {
				case(WAGE): earnings[0] = earnings[0] + acc.motions[i].amountSpent; break;
				case(PRESENT): earnings[1] = earnings[1] + acc.motions[i].amountSpent; break;
				case(REFUND): earnings[2] = earnings[2] + acc.motions[i].amountSpent; break;
				case(ALLOWANCE): earnings[3] = earnings[3] + acc.motions[i].amountSpent; break;
				case(OTHEREARNING): earnings[4] = earnings[4] + acc.motions[i].amountSpent; break;
			}
		}
	}
	
	return earnings;
}

double getTotalSpendings(bankAccount acc) {
	double totalSpendings = 0.0;
	int i;
	for (i=0; i<7; i++) {
		totalSpendings = totalSpendings + getTotalSpendingType(acc)[i];
	}
}


double* getStatsSpendings(bankAccount acc) {
	
	double *percentagesSpendings = malloc(7*sizeof(double));
	int i;
	for (i; i<7; i++) {
		percentagesSpendings[i] = getTotalSpendingType(acc)[i]/getTotalSpendings(acc);
	}
	return percentagesSpendings;
	

	
}

/*double getStatsEarnings(bankAccount acc) {
}*/


