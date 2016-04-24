#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "bankAccount.h"

int main(int argc,char *argv[]) {
	bankAccount myAcc;
	initialize(&myAcc);
	setName(&myAcc,"Choné","Antoine");
	changeAmount(&myAcc,8000.0);
	getInfo(&myAcc);
	movements m;
	double i=-25.0;
	spendingType q=DWELLING;
	earningType p=PRESENT;
	setInfoMovements(&m,i,"Ikea",q,NULL);
	movements w;
	setInfoMovements(&w,55,"Merci Papa",NULL,p);
	getInfoMovements(&m);
	getInfoMovements(&w);
	addMovements(&myAcc,&m);
	addMovements(&myAcc,&w);
	getMovements(&myAcc);
	
}
