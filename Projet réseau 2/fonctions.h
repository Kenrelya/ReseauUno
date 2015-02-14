typedef struct Cartes Cartes;
struct Cartes
{
    char numero[15];
    char couleur[15];
    Cartes *next;
};

typedef struct Main Main;
struct Main
{
    int nbcartes;
    char carte[15];
    char couleur[15];
    Cartes *next;
};
typedef struct Liste Liste;
struct Liste
{
    Cartes *premiere;
    Cartes *derniere;
    int nb;
};

typedef enum {faux,vrai} boolean;
Liste *initialiser();
boolean estVide(Liste *liste);
void insererEnTete(Liste *liste, char num[10], char color[10]);
void afficher(Liste *liste);
void supprimer(Liste *liste, int place);
void affichermain(Liste *main);
void vider(Liste *liste);



void creerMain(Liste *liste, Liste *main);
void creer_jeu(Liste *deck, FILE *lcarte, FILE *lcouleur);
void premierecarte(Liste *liste, Liste *carteJouee);
void piocher(Liste *liste, Liste *main);
void nbcarte(Liste *liste);
void menu(Liste *jeu, Liste* joueur1, Liste *joueur2, Liste *cartesol);
int menujoueur(Liste *cjouable);
void afficherjouable(Liste *main);
Liste *cartejouable(Liste *original, Liste *posee, int *apiocher);
Liste *cartenumero(Liste *original, Liste *posee, int *apiocher);
void jouercarte(Liste *mainj, Liste *posee, Cartes *jouee,int numero);
Liste *cartepiochee(Liste *original, Liste *posee);
Liste *cartecouleur(Liste *original, Liste *posee);
void interface(Liste *j, Liste *posee, Liste *deck, int *apiocher);
void deroulementJeu(Liste *j1, Liste *j2, Liste *deck, Liste *posee, int *apiocher);
