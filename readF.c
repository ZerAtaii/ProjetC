#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"
#include "readF.h"





void readF(bankAccount acc,char* fichierR) {
	FILE* fichier = NULL;
	char* c = malloc(1);
	fichier = fopen(fichierR,"r");
	char *string1,*string2;
	if (fichier == NULL) {
		printf("Oops ! \n");
	}
	else {	
		string1=malloc(50);
		string2=malloc(50);
		while(c[0] != 0x20) {
			fgets(c, 2, fichier);
			strcat(string1,c);			
		}
		strcat(string2,fgets(c, 2, fichier));
		while(c[0] != 0x20) {
			fgets(c,2,fichier);
			strcat(string2,c);
		}
	setName(&acc,string1,string2);




        fclose(fichier); 
    }
	
	
}
