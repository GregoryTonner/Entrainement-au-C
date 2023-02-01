#include <stdio.h>
#include "stdlib.h"
#include <time.h>

int main() {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            /*** Déclaration des variables ***/
    const int NB_COLONNE_MAX=4,NB_COULEUR_AFFILE=4,NB_COULEUR =5;
    const char COULEURS[] = {'R','V','B','J','O'};
    char couleur_a_trouver[NB_COLONNE_MAX];   // Dans ce cas la, les valeurs du tableau sont intialisé dedans donc on peut déclarer le tableau "tab[]={};"
    char couleur_joueur[NB_COLONNE_MAX]; //On peut initialiser le tableau avec un nombre de colonne que si on ne met rien à l'interieur
    char choix_joueur = 'Y';
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("TP9 Mastermind ! \n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while(choix_joueur != 'N')
{
    if (choix_joueur == 'Y')
    {
        srand(time(NULL)); // Ne dois pas être écrit dans la boucle sinon on récupère les mêmes valeurs à chaque itérations
        for(int i=0;i<NB_COLONNE_MAX;i++) //Permet de générer des lettres aléatoirement
        {
            int id_couleur = rand() %  NB_COULEUR;  // on récupère une valeurs entiere random entre 0 et 4
            couleur_a_trouver[i] = COULEURS[id_couleur]; // On assigne la valeur random dans le tableau des couleurs possible que l'on a créé auparavant
                // On assigne la lettre correpondante à la valeur random à notre case du tableau des couleurs à trouver
        }
        int nb_essai =3;
        do {
            int mal_place =0;   // On remet les deux variables à 0 à chaque tour de jeu
            int bien_place =0;

            printf("Veuillez rentrer vos 4 couleurs dans l'ordre : (Parmis les couleurs suivantes {R, B, J, V, O})\n");
            scanf("%c%c%c%c", &couleur_joueur[0], &couleur_joueur[1], &couleur_joueur[2], &couleur_joueur[3]);  // On écrit dans le tableau la saisie utilisateuR
            fflush(stdin);  // Permet de supprimer la saisie utilisateur dans un fichier, dans ce cas la "Stdin" correspond à la saisie dans le terminal
            nb_essai--; // On décrémente le nombre d'essaie du joueur à chaque tour de jeu

            for (int i = 0; i < NB_COLONNE_MAX; i++) {          // Parcourir les colonnes de la première ligne
                for(int p = 0; p < NB_COLONNE_MAX; p++)         // Parcourir les colonnes de la deuxième ligne
                {
                    if((p == i)&&(couleur_a_trouver[i] == couleur_joueur[p])){   // Si on les deux mêmes couleur sur la même colonne alors
                        bien_place++;  // On dit qu'une boule est bien placé
                    }
                    else if((p != i)&&(couleur_a_trouver[i] == couleur_joueur[p])){ // Si on a la même couleur sur deux colonnes différente alors
                        mal_place ++;      // On dit qu'une boule est mal placé
                    }
                }
            }
            if(bien_place == NB_COULEUR_AFFILE) // Si toutes les couleurs sont bien placé alors on gagne
            {
                printf("Bravo vous avez gagne !\n");
                printf("Les bonnes boules etaient %c %c %c %c\n", couleur_a_trouver[0], couleur_a_trouver[1], couleur_a_trouver[2], couleur_a_trouver[3]);
            }
            else if(nb_essai == 0) // Si on dépasse le nombre d'essais maximum alors on perd
            {
                printf("Ta perdu tes nul\n");
                printf("Les bonnes boules etaient %c %c %c %c\n", couleur_a_trouver[0], couleur_a_trouver[1], couleur_a_trouver[2], couleur_a_trouver[3]);
            }
            else
                printf("Boule bien place : %d\nBoule mal place : %d\nIl vous reste %d essais\n",bien_place,mal_place,nb_essai); // On affiche le nombre de boule bien placé et mal placé
        }while(bien_place != NB_COULEUR_AFFILE && nb_essai != 0); // On sort de la boucle si on gagne ou si on perd
    }
    printf("Voulez vous refaire une partie ? \"Y\" ou \"N\" ?\n"); // Permet de rejouer ou arreter le programme
    scanf("%c", &choix_joueur);
    fflush(stdin);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
/*
 * 1er ligne avec les couleurs definit
 * 2eme ligne avec les couleurs que tu choisi
 * int bien_place = 0
 * int mal_place = 0;
 * int nb_essai = 3;
 *
 *faire
 *   lire(saisie_utilisateur)
 *   pour(colonne_act=0;colonne_act < nb_colonne_max;colonne_act++)
 *
 *      si (tab[0][colonne_act] == tab[1][colonne_act])
 *          alors
 *             bien_place ++
 *   si (bonne couleur == 4 )
 *         alors
 *            ecrire(c'est gagné)
 * tant que (bonne_couleur !=4 ou nb_essai !=0)
 *
 * pour savoir si une couleur est mal placé il faut bloquer sur une case du tableau de la première ligne et faire défiler le reste des cases sur la deuxième ligne
 *
 * */
