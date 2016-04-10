#include <stdio.h>
#include <stdlib.h>
#include "bankaccount.c"

int main()
{
    Account myfirstaccount;
    initialize(myfirstaccount);
    printf("Votre solde est de %d",myfirstaccount.amount);
}
