#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

Liste *initialiser()
{
    Liste *liste = malloc (sizeof(*liste));
    liste->premiere = NULL;
    liste->derniere = NULL;
    liste->nb = 0;

    return liste;
}

boolean estVide(Liste *liste)
{
    if (liste->premiere==NULL && liste->derniere==NULL)
        return vrai;
    else
        return faux;
}

void insererEnTete(Liste *liste, char num[10], char color[10])
{
    Cartes *carte = malloc(sizeof(Cartes));

    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(carte->numero,num);
    strcpy(carte->couleur,color);

    if(liste->premiere == NULL)
    {
        liste->derniere = carte;
    }

    carte->next = liste->premiere;
    liste->premiere = carte;
    liste->nb++;
}

void afficher(Liste *liste)
{
	int i=0;
    if(estVide(liste))
    {
        exit(EXIT_FAILURE);
    }

    if(!estVide(liste))
    {
        Cartes *actuel = liste->premiere;

        while(actuel!=liste->derniere->next)
        {
            printf("%d: %s%s\n",i+1,actuel->numero,actuel->couleur);
            actuel = actuel->next;
            i++;
        }
    }
}

void affichermain(Liste *main)
{
    if(estVide(main))
    {
        exit(EXIT_FAILURE);
    }

    if(!estVide(main))
    {
        Cartes *actuel = main->premiere;
	printf("\n\nVotre main: ");
        while(actuel!=main->derniere->next)
        {
            printf("***** %s%s ",actuel->numero,actuel->couleur);
            actuel = actuel->next;
        }
        printf("*****\n\n");
    }
}
void supprimer(Liste *liste, int place)
{
	int i;
	Cartes *asupp = liste->premiere;
	Cartes *suite = malloc(sizeof(Cartes));
	if(estVide(liste))
    	{
        	exit(EXIT_FAILURE);
    	}

    	if(liste->premiere != NULL)
    	{
    		if(liste->premiere == liste->derniere)
    	    	{
    	    	    liste->premiere = NULL;
    	    	    liste->derniere = NULL;
    	    	}
	    	else
	    	{
			if(place > 1)
			{
				for(i=1;i<place-1;i++)
				{
					asupp = asupp->next;
				}
			
	    			suite = asupp->next->next;
	    		        asupp->next = suite;
	    		}
	    		else if(place == 1)
	    		{
	    			liste->premiere = liste->premiere->next;
	    		}
	    		else printf("Aucune carte à supprimer à cet emplacement\n");
		}

    	}
    	liste->nb--;
}

void vider(Liste *liste)
{
	Cartes *asupp = liste->premiere;
    	if (liste == NULL)
    	{
    		exit(EXIT_FAILURE);
    	}
    	
	
	while (liste->premiere != NULL)
	{
		asupp = liste->premiere;
	        liste->premiere = asupp->next;
	        free(asupp);
	}
    	liste->derniere=NULL;
}
