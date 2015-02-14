#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

void creer_jeu(Liste *deck, FILE *lcarte, FILE *lcouleur)
{
	char carte[15]="";
    	char couleur[15]="";
    	int i,j;
	
    	for(i=1;i<=108;i++)
    	{
    		if((fgets(carte,15,lcarte)) == NULL) exit(EXIT_FAILURE);
    		if((fgets(couleur,15,lcouleur)) == NULL) exit(EXIT_FAILURE);
    		for(j=0;j<15;j++)
    		{
    			if(carte[j] == '\r') carte[j]='\0';
    			if(couleur[j] == '\r') couleur[j]='\0';
    		}
        	insererEnTete(deck,carte,couleur);
        	for(j=0;j<15;j++)
        	{
        		carte[j]='\0';
        		couleur[j]='\0';
        	}
    	}  
}

void creerMain(Liste *liste, Liste *main)
{
    	int i,j,alea;
    	time_t time1=time(NULL);
    	srand(time1);
	if(estVide(liste))
	{
        	exit (EXIT_FAILURE);
    	}
	
	for(i=0;i<8;i++)
	{
		Cartes *actuel = liste->premiere;
		alea = rand() % liste->nb;
		for(j=0;j<alea;j++)
		{
			actuel = actuel->next;
		}
		supprimer(liste,alea);
		insererEnTete(main,actuel->numero,actuel->couleur);
	}
}

void piocher(Liste *liste, Liste *main)
{
	int i,alea;
	Cartes *actuel = liste->premiere;
	time_t time1=time(NULL);
    	srand(time1);
	if(estVide(liste))
	{
        	exit (EXIT_FAILURE);
    	}
    	
    	
	
	
	alea = rand() % liste->nb;
	for(i=0;i<alea;i++)
	{
		actuel = actuel->next;
	}
	insererEnTete(main,actuel->numero,actuel->couleur);
	supprimer(liste,alea);
}

void premierecarte(Liste *liste, Liste *carteJouee)
{
	do
	{
		vider(carteJouee);
		piocher(liste,carteJouee);
	}while(carteJouee->premiere->numero[0] == '+' || carteJouee->premiere->numero[0] == 'I' || carteJouee->premiere->numero[0] == 'P' || carteJouee->premiere->numero[0] == 'J');
	printf("Carte posée: %s%s\n",carteJouee->derniere->numero,carteJouee->derniere->couleur);
}

void nbcarte(Liste *liste)
{
	printf("Nb cartes: %d\n",liste->nb);
}


Liste *cartejouable(Liste *original, Liste *posee, int *apiocher)
{
	Liste *copie=initialiser();
    	int i;
    	Cartes *actuel = original->premiere;
	if(estVide(original))
	{
        	exit (EXIT_FAILURE);
    	}
	
	for(i=0;i<original->nb;i++)
	{	
		
		if(posee->premiere->numero[0]=='r' && *apiocher>1)
		{
			if(actuel->numero[1]=='4')
			{
				insererEnTete(copie,actuel->numero,actuel->couleur);
			}
			
		}
		else if(posee->premiere->numero[1] =='2')
		{
			if(actuel->numero[1] == '2' || actuel->couleur[0]=='A')
			{
				insererEnTete(copie,actuel->numero,actuel->couleur);
			}
		}
		else
		{
			if((strcmp(posee->premiere->numero,actuel->numero)==0) || (strcmp(posee->premiere->couleur,actuel->couleur)==0) || actuel->couleur[0]=='A')
			{
				insererEnTete(copie,actuel->numero,actuel->couleur);
			}
		}

		actuel = actuel->next;
	}
	return copie;
}

Liste *cartenumero(Liste *original, Liste *posee, int *apiocher)
{
	Liste *copie=initialiser();
    	int i;
	Cartes *actuel = original->premiere;
	if(estVide(original))
	{
        	exit (EXIT_FAILURE);
    	}

	for(i=0;i<original->nb;i++)
	{
		if(posee->premiere->numero[0]=='r' && *apiocher>1)
		{
			if(actuel->numero[1]=='4')
			{
				insererEnTete(copie,actuel->numero,actuel->couleur);
			}
			
		}
		else if(posee->premiere->numero[0]=='r' && *apiocher<=1)
		{
			if(actuel->numero[0]=='J')
			{
				insererEnTete(copie,actuel->numero,actuel->couleur);
			}
		}
		else
		{
		
			if((strcmp(posee->premiere->numero,actuel->numero)==0))
			{
				insererEnTete(copie,actuel->numero,actuel->couleur);
			}
		}
		actuel = actuel->next;
	}
	return copie;
}

Liste *cartepiochee(Liste *original, Liste *posee)
{
	Liste *copie=initialiser();
	Cartes *actuel = original->premiere;
	if(estVide(original))
	{
        	exit (EXIT_FAILURE);
    	}
	
	if((strcmp(posee->premiere->numero,actuel->numero)==0) || actuel->couleur[0]=='A')
	{
		insererEnTete(copie,actuel->numero,actuel->couleur);
	}
	return copie;
}

void jouercarte(Liste *mainj, Liste *posee, Cartes *jouee,int numero)
{
	supprimer(mainj,numero);
	insererEnTete(posee,jouee->numero,jouee->couleur);
}
