#include <stdio.h>
#include <stdlib.h>
#include "bankaccount.c"

int main() {
    Account myfirstaccount;
    //setAmount(myfirstaccount,500.0);
    printf("Votre solde est de %f\n", getAmount(myfirstaccount));
    return 0;
}
