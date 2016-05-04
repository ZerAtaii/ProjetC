#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAccount.h"
#include "readF.h"





void readF(bankAccount *acc,char* fichierR) {
	FILE* fichier = NULL;
	char* c = malloc(1);
	fichier = fopen(fichierR,"r");
	char *string1,*string2,*i,*n;
	if (fichier == NULL) {
		printf("Oops ! \n");
	}
	else {	
		string1=malloc(50);
		string2=malloc(50);
		i=malloc(50);
		n=malloc(3);
		while(c[0] != 0x20) {    //On recup le nom
			fgets(c, 2, fichier);
			strcat(string1,c);			
		}
		strcat(string2,fgets(c, 2, fichier)); //Le premier caractère apres l'espace
		while(c[0] != 0x20) {  // On recup le prénom
			fgets(c,2,fichier);
			strcat(string2,c);
		}
		while(c[0] != 0x3a) {	//On saute les caractères jusqu'au :
			fgets(c,2,fichier);
		}
		strcat(i,fgets(c, 2, fichier));
		while(c[0] != 0x20) { //On recupère le string qui représentera un double;
			fgets(c,2,fichier);
			strcat(i,c);
		}
		while(c[0] != 0x3a) { //On saute les caractères jusqu'au :
			fgets(c,2,fichier);
		}
		while(c[0] != 0x20) { //On récupère le string qui représentera le nombre de movements
			fgets(c,2,fichier);
			strcat(n,c);
		}
		int nombre=atoi(n);
		movements *tab;
		tab=malloc(nombre*sizeof(movements));
		int compteur=0;
		for (compteur=0;compteur<nombre;compteur++) { //On fait une boucle sur le nombre de transfert
			movements m;
			char *date=malloc(15);
			char *whereSpent=malloc(50);
			char *amountSpent=malloc(20);
			while(c[0] != 0x3a) { //On saute les caractères jusqu'au :
				fgets(c,2,fichier);
			}
			strcat(date,fgets(c,2,fichier));
			while(c[0] != 0x3a) { //On récupère la date
				fgets(c,2,fichier);
				if (c[0]!=0x3a) {
					strcat(date,c); }
				 
			}
			fgets(c,2,fichier);
			while(c[0] != 0x3a) { //On saute les caractères jusqu'au :
				fgets(c,2,fichier);
			}
			while(c[0] != 0x20) { //On récupère le montant sous forme de String
				fgets(c,2,fichier);
				if (c[0]!=0x3a) {
					strcat(amountSpent,c); }
			}
			fgets(c,2,fichier);
			fgets(c,2,fichier); //On saute 2 caractères
			while(c[0] != 0x3a) { //On saute les caractères jusqu'au :
				fgets(c,2,fichier);
			}
			while(c[0] != 0x20) { //On récupère le nom du débiteur
				fgets(c,2,fichier);
				strcat(whereSpent,c);
			}
			setInfoMovements(&(tab[compteur]),atof(amountSpent),whereSpent,10,10,date);
			
		}
		int compteur1=0;
		for (compteur1=0;compteur1<nombre;compteur1++) {
			addMovements(acc,&(tab[compteur1]));
		}
		

        	fclose(fichier); 
    	}
	setName(acc,string1,string2);
	changeAmount(acc,atof(i));
		
	
	
}	
