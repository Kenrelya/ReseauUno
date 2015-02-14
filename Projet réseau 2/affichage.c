#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"

void menu(Liste *jeu, Liste* joueur1, Liste *joueur2, Liste *cartesol)
{
	int choix;
	do
	{
    		printf("Que voulez-vous faire?\n");
    		printf("1: Voir paquet \n2: Nb cartes paquet\n3: Main joueur1\n4: Nb cartes joueur1\n5: Main joueur2\n6: Nb cartes joueur2\n7: Poser carte\n8: Piocher joueur1\n9: Piocher joueur2\n0: Quitter\t");
    		scanf("%d",&choix);

    		while (choix<0||choix>9)
   	 	{
        		printf("\nMerci d'entrer une valeur valide. \n");
        		printf("1: Voir paquet \n2: Nb cartes paquet\n3: Main joueur1\n4: Nb cartes joueur1\n5: Main joueur2\n6: Nb cartes joueur2\n7: Poser carte\n8: Piocher joueur1\n9: Piocher joueur2\n0: Quitter\t");
        		scanf("%d",&choix);
    		}
	
		switch(choix)
		{	
			case(1):
				afficher(jeu);
        			break;
        		case(2):
        			nbcarte(jeu);
        			break;
        		case(3):
        			affichermain(joueur1);
        			break;
        		case(4):
        			nbcarte(joueur1);
        			break;
        		case(5):
        			affichermain(joueur2);
        			break;
        		case(6):
        			nbcarte(joueur2);
        			break;
        		case(7):
        			premierecarte(jeu,cartesol);
        			break;
        		case(8):
        			piocher(jeu,joueur1);
        			break;
        		case(9):
        			piocher(jeu,joueur1);
        			break;
        		default:	
        			break;
        		fflush(stdin);
        		
    		}
    	}while(choix !=0);
}

int menujoueur(Liste *cjouable)
{
	int choix;
	
	if((cjouable->nb)!=0)
	{
		printf("Que voulez-vous faire ?\n");
		printf("1: Piocher une carte\n");
		printf("2: Jouer une carte\n");
		scanf("%d",&choix);
		while(choix<1 || choix>2)
		{
			printf("Valeur non valide\n");
			printf("1: Piocher une carte\n");
			printf("2: Jouer une carte\n");
			scanf("%d",&choix);
		}
	}		
	else
	{
		printf("Que voulez-vous faire ?\n");
		printf("1: Piocher une carte\n");
		scanf("%d",&choix);
		while(choix!=1)
		{
			printf("Valeur non valide\n");
			printf("0: Voir main\n");
			printf("1: Piocher une carte\n");
			scanf("%d",&choix);   
			
		}
	}
	return choix;
}

void afficherjouable(Liste *main)
{
	int i=0;
    	if(estVide(main))
    	{
        	exit (EXIT_FAILURE);
    	}

    	if(!estVide(main))
    	{
    	    	Cartes *actuel = main->premiere;
        	while(actuel!=main->derniere->next)
        	{
        		printf("%d :: %s%s \n",i+1,actuel->numero,actuel->couleur);
            		actuel = actuel->next;
            		i++;
        	}
        	printf("\n");
    	}
}
void interface(Liste *j, Liste *posee, Liste *deck, int *apiocher)
{
	int choix2=0,choix3;
	int i=1,k;
	int chgmt;
	Liste *cjouable = initialiser();
	int choixC;
	Cartes *actuel = j->premiere;
	Cartes *jouee= malloc(sizeof(Cartes));
	int choix;
	
	affichermain(j);
	cjouable = cartejouable(j,posee,apiocher);

	choix=menujoueur(cjouable);

		switch(choix)
		{	
			case(1):
        			vider(cjouable);
        			if(*apiocher<=1)
        			{
        				piocher(deck,j);
        				cjouable=cartepiochee(j,posee);
        				printf("Carte piochée: **** %s%s **** \n",j->premiere->numero,j->premiere->couleur);
        			}
        			else
        			{	
        				do
        				{
        					piocher(deck ,j);
        					if(*apiocher>1)  *apiocher=*apiocher-1;
        					printf("Carte piochée: **** %s%s **** \n",j->premiere->numero,j->premiere->couleur);
        				}
        				while(*apiocher>1);
        				vider(cjouable);
        			}

        			if(cjouable->nb > 0)
				{
        				do
					{	
						printf("1:Jouer\n");
						printf("2:Passer\n");
						scanf("%d",&choix2);
					}while(choix2<1 || choix2>2);
				}
				
				switch(choix2)
				{
					case(1):
						jouee=cjouable->premiere;
						jouercarte(j,posee,jouee,1);
						if(jouee->couleur[0] == 'A')
						{
							do
							{
							printf("Changement de couleur :\n");
							printf("1: Rouge\n");
							printf("2: Jaune\n");
							printf("3: Vert\n");
							printf("4: Bleu\n");
							scanf("%d",&chgmt);
							}while(chgmt<1 || chgmt>4);
							switch(chgmt)
							{
								case(1):
									insererEnTete(posee,"rien","R");
									break;
								case(2):
									insererEnTete(posee,"rien","J");
									break;
								case(3):
									insererEnTete(posee,"rien","V");
									break;
								case(4):
									insererEnTete(posee,"rien","B");
									break;
							}
							fflush(stdin);
						}
						vider(cjouable);
						break;
					default:
						break;
				}
        			break;
        		case(2):
        			jouee = cjouable->premiere;
        			do
        			{
        				printf("Quelle carte voulez-vous jouer?\n");
        				afficherjouable(cjouable);
        				scanf("%d",&choixC);
        				
				}while(choixC<1||choixC > cjouable->nb);
				i=1;
				while(i != choixC)
				{
					
					jouee = jouee->next;
					i++;
				}
				
				printf("\nCarte jouée : **** %s%s ****\n\n",jouee->numero,jouee->couleur);
				
				
				if(jouee->numero[0] == '+')
				{
					
					if(jouee->numero[1] == '2')  *apiocher += 2;
					else *apiocher += 4;
				}
				
				i=1;
				
				while((strcmp(actuel->numero,jouee->numero)!=0) || (strcmp(actuel->couleur,jouee->couleur)!=0))
				{
					actuel = actuel->next;
					i++;
				}
				for(k=0;k<posee->nb;k++)
				{
					
					if(posee->premiere->numero[0]!='r')
					insererEnTete(deck,posee->premiere->numero,posee->premiere->couleur);
				}
				
				vider(posee);
				
				jouercarte(j,posee,jouee,i);
				
				if(jouee->couleur[0] == 'A')
				{
					do
					{
						printf("Changement de couleur :\n");
						printf("1: Rouge\n");
						printf("2: Jaune\n");
						printf("3: Vert\n");
						printf("4: Bleu\n");
						scanf("%d",&chgmt);
					}while(chgmt<1 || chgmt>4);
					switch(chgmt)
					{
						case(1):
							insererEnTete(posee,"rien","R");
							break;
						case(2):
							insererEnTete(posee,"rien","J");
							break;
						case(3):
							insererEnTete(posee,"rien","V");
							break;
						case(4):
							insererEnTete(posee,"rien","B");
							break;
					}
					fflush(stdin);
				}

				
				vider(cjouable);
				cjouable=cartenumero(j,posee,apiocher);
				affichermain(j);
				while(cjouable->nb >0 && choix2 !=2)
				{
					do
					{
						if(cjouable->nb== 1)
						{
							printf("Autre carte possible: \n");
							afficherjouable(cjouable);
							printf("1:Jouer\n");
							printf("2:Passer\n");
							scanf("%d",&choix2);
						}
						else if(cjouable->nb >1)
						{
							printf("Autres cartes possibles:\n");
							afficherjouable(cjouable);
							printf("1:Jouer\n");
							printf("2:Passer\n");
							scanf("%d",&choix2);
						}
						else choix2=2;
					}while(choix2<1 || choix2>2);
					switch(choix2)
					{
						case(1):
							jouee=cjouable->premiere;
							do
							{
								printf("Quelle carte jouer?\n");
								afficherjouable(cjouable);
								scanf("%d",&choix3);
							}while(choix3<1 || choix3>cjouable->nb);
							i=1;
							while(i != choix3)
							{
								jouee = jouee->next;
								i++;
							}
							i=1;
							actuel = j->premiere;
							
							while((strcmp(actuel->numero,jouee->numero)!=0) || (strcmp(actuel->couleur,jouee->couleur)!=0))
							{
							
								actuel = actuel->next;
								i++;
							}
							printf("\nCarte jouée : **** %s%s ****\n\n",jouee->numero,jouee->couleur);
							
							if(jouee->numero[0] == '+')
							{
								if(jouee->numero[1] == '2')  *apiocher += 2;
								else *apiocher += 4;
							}
							
							for(k=0;k<posee->nb;k++)
							{
								if(posee->premiere->numero[0]!='r')
								insererEnTete(deck,posee->premiere->numero,posee->premiere->couleur);
							}
							vider(posee);
							jouercarte(j,posee,jouee,i);

							if(jouee->couleur[0] == 'A')
							{
								do
								{
									printf("Changement de couleur :\n");
									printf("1: Rouge\n");
									printf("2: Jaune\n");
									printf("3: Vert\n");
									printf("4: Bleu\n");
									scanf("%d",&chgmt);
								}while(chgmt<1 || chgmt>4);
								switch(chgmt)
								{
									case(1):
										insererEnTete(posee,"rien","R");
										break;
									case(2):
										insererEnTete(posee,"rien","J");
										break;
									case(3):
										insererEnTete(posee,"rien","V");
										break;	
									case(4):
										insererEnTete(posee,"rien","B");
										break;
								}
								fflush(stdin);
							}
							
							break;
						default:
							choix2=2;
							break;
					}
					fflush(stdin);
					vider(cjouable);
					cjouable=cartenumero(j,posee,apiocher);
				}
			break;	
       			
       		}
       		fflush(stdin);
}

void deroulementJeu(Liste *j1, Liste *j2, Liste *deck, Liste *posee, int *apiocher)
{

	do
	{	
		do
		{
			printf("Tour du J1\n");
			interface(j1,posee,deck,apiocher);
		}while(posee->premiere->numero[0] == 'P' || posee->premiere->numero[0] == 'I');
		do
		{
			printf("J2\n");
			interface(j2,posee,deck,apiocher);
		}while(posee->premiere->numero[0] == 'P' || posee->premiere->numero[0] == 'I');
	}while(j1->nb>0 && j2->nb >0);
}
