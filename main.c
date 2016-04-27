#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"

int main(int argc,char *argv[]) {
	bankAccount myAcc;
	initialize(&myAcc);

	setName(&myAcc,"Choné","Antoine");
	changeAmount(&myAcc,8000.0);
	getInfo(&myAcc);

	movements m;
	setInfoMovements(&m,-25,"Ikea",DWELLING,NONE,"25/12/2015");

	movements w;
	movements z;
	setInfoMovements(&z,-60,"Decathlon",OTHERSPENDING,NONE,"12/02/2016");
	setInfoMovements(&w,55,"Merci Papa",NONES,PRESENT,"25/03/2016");

	//getInfoMovements(&m);
	//getInfoMovements(&w);

	addMovements(&myAcc,&m);
	addMovements(&myAcc,&w);
	addMovements(&myAcc,&z);
	getMovements(&myAcc);
	
}
