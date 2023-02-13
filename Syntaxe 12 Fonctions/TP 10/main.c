#include <stdio.h>
#include "string.h"

int ecritureGrille(char tab[3][3], int x, int y, char joueur); // Renvoie 1 si l'écriture est faite, sinon on renvoit 0
void saisieUtilisateur(int* x, int* y);
void affichageGrille(char* tab, int nb_ligne, int nb_colonne);


int main() {
    printf("TP 10 Jeu du Morpion\n");

    int fin_de_parti = 0;
    char joueur1 ='X', joueur2 ='O';
    int tour_jeu = 1, tour_joueur1 = 1, tour_joueur2 = 2;
    int nb_colonne = 3, retour_ecriture, nb_ligne = 3;
    int coord_x, coord_y;
    char tab[3][3] =
            {{'_','_','_'},
             {'_','_','_'},
             {'_','_','_'}};

    do {
        retour_ecriture = 2;
        if(tour_jeu == tour_joueur1) {
            printf("Joueur 1, A quelle position souhaitez vous jouer ? (x,y)\n");
            do {
                saisieUtilisateur(&coord_x,&coord_y);
                retour_ecriture = ecritureGrille(tab, coord_x, coord_y, joueur1);
                if(retour_ecriture == 1)
                    tour_jeu = tour_joueur2;
            }while (retour_ecriture == 0);
        }
        else if(tour_jeu == tour_joueur2)
        {
            printf("Joueur 2, A quelle position souhaitez vous jouer ? (x,y)\n");
            do {
                saisieUtilisateur(&coord_x,&coord_y);
                retour_ecriture = ecritureGrille(tab, coord_x, coord_y, joueur2);
                if(retour_ecriture == 1)
                    tour_jeu = tour_joueur1;
            }while (retour_ecriture == 0);
        }
        affichageGrille((char*)tab, nb_ligne,nb_colonne);
        printf("\n");
    }while (fin_de_parti != 1);
    return 0;
}
void affichageGrille(char* tab, int nb_ligne, int nb_colonne)
{
    printf("Grille actuelle : \n");
    for(int l=0;l<nb_ligne;l++) // Permet d'afficher la grille des joueurs
    {
        char* p_ligne = tab + (l * nb_colonne);
        printf("\n\t");
        for(int c=0;c<nb_colonne;c++)
            printf("%c\t",*(p_ligne + c));
    }
    printf("\n");
}
void saisieUtilisateur(int* x, int* y)
{
    scanf("%d%d", x, y);
    fflush(stdin);
    printf("x : %d, y : %d\n",*x,*y);
}
int ecritureGrille(char tab[3][3], int x, int y, char joueur)
{
    if((x < 1 || x > 3) || (y < 1 || y > 3))
    {
            printf("Rentrez une valeur entre 1 et 3\n");
            return 0;
    }
    x -= 1;
    y -= 1;
    if(tab[x][y] == '_')
    {
        tab[x][y] = joueur;
        return 1;
    }
    else if(tab[x][y] != '_')
    {
        printf("Case deja prise\n");
        return 0;
    }
}
/* **Algo**
 * do
 *  si(tour_jeu = 1)
 *      ecrire(Joueur 1, A quelle positon souhaitez vous jouer ? (x,y))
 *      lire saisie_utilisateur
 *      do
 *          si (tab[x][y] == "")
 *              alors
 *                  tab[x][y] = joueur1
 *                  tour_jeu = 2
 *          sinon
 *              ecrire(case dejà prise)
 *      while(tab[x][y] != "")
 *  sinon si (tour_jeu =2)
 *      ecrire(Joueur 2, A quelle positon souhaitez vous jouer ? (x,y))
 *      lire saisie_utilisateur
 *      do
 *          si (tab[x][y] == "")
 *              alors
 *                  tab[x][y] = joueur1
 *                  tour_jeu = 1
 *          sinon
 *              ecrire(case dejà prise)
 *      while(tab[x][y] != "")
 *
 * while(fin_de_parti =!1)
 *
 *
    ** Test avec pointeur pour rendre la fonction dynamique **

    char* p_ligne = tab + (x * y);
    char* p_position = p_ligne + y;
    printf("%c\n",*(tab + x + y));
    if(*p_position == '_')
    {
        *p_position = joueur;
        return 1;
    }
    else if(*p_position != '_')
    {
        printf("Case deja prise\n");
        return 0;
    }
 * */