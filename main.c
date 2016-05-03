#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"
#include "readF.h"
#include "stats.h"


int main(int argc,char *argv[]) {
	bankAccount hisAcc;
	initialize(hisAcc);
	readF(&hisAcc,"DT.txt");	
	getInfo(&hisAcc);
	getMovements(&hisAcc);
	printf("%f \n",getTotalSpendings(hisAcc));
	int i;
	for (i=0; i<8; i++) {
		printSpending(i);
		printf(": %f€ qui représente ",getTotalSpendingType(hisAcc)[i]);
		printf(" %f pourcents des dépenses.\n",getStatsSpendings(hisAcc)[i]);
	}
}
