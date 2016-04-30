#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"
#include "readF.h"
#include "stats.h"


int main(int argc,char *argv[]) {
	bankAccount hisAcc;
	initialize(hisAcc);
	changeAmount(&hisAcc,10000);
	//readF(hisAcc,"DT.txt");	
	getInfo(&hisAcc);
	//getTotalSpendings(hisAcc);
	//printf("%f \n",getTotalSpendings(hisAcc));
	//getTotalSpendingType(hisAcc);
	//getStatsSpendings(hisAcc);
	movements m;
	setInfoMovements(&m,-25,"Ikea",DWELLING,NONE,"25/12/2015");

	movements w;
	movements z;
	setInfoMovements(&z,-60,"Decathlon",OTHERSPENDING,NONE,"12/02/2016");
	setInfoMovements(&w,55,"Merci Papa",NONES,PRESENT,"25/03/2016");


	addMovements(&hisAcc,&m);
	addMovements(&hisAcc,&w);
	addMovements(&hisAcc,&z);
	printf("%f \n",getTotalSpendings(hisAcc));
	int i;
	for (i=0; i<7; i++) {
		printf("%f \n",getTotalSpendingType(hisAcc)[i]);
		printf("%f \n",getStatsSpendings(hisAcc)[i]);
	}
}
