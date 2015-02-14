#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"


int main()
{
	int a=1;
	Liste *jeu=initialiser();
    	Liste *joueur1=initialiser();
    	Liste *joueur2=initialiser();
    	Liste *cartejouee=initialiser();
   	FILE* lcarte = NULL;
   	FILE* lcouleur = NULL;
    	lcarte = fopen("cartes","r");
    	if(lcarte == NULL)
    	{
    	    printf("Impossible d'ouvrir lcarte\n");
    	    return EXIT_FAILURE;
    	}
   	
    	
    	lcouleur = fopen("couleurs","r");
    	if(lcouleur == NULL)
    	{
    	    printf("Impossible d'ouvrir lcouleur\n");
    	    return EXIT_FAILURE;
    	}
    	
	
	creer_jeu(jeu,lcarte,lcouleur);
   
	fclose(lcarte);
	fclose(lcouleur);
    	
    	

 	creerMain(jeu,joueur1);
 	creerMain(jeu,joueur2);
 	premierecarte(jeu,cartejouee);
   	deroulementJeu(joueur1,joueur2,jeu,cartejouee,&a);


    	return 0;
}
