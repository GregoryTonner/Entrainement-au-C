#include <stdio.h>

int main() {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            /*** Déclaration des variables ***/
    int bien_place =0, mal_place =0, nb_essai =3,nb_colonne_max,nb_couleur_affile=4;
    char board[2][4] = {{'R','B','O','V'},{}};
    char choix_joueur;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("TP9 Mastermind ! \n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
do
{
    printf("Bienvenu dans le Mastermind, voulez vous faire une partie : \"Y\" ou \"N\" ?");
    scanf("%c", &choix_joueur);
    if (choix_joueur == 'Y')
    {
        do {
            for (int i = 0; i < nb_colonne_max; i++) {
                printf("Veuillez rentrer vos couleurs dans l'ordre :");
                scanf("%c", board[1][i]);
                if(board[0][i]==board[1][i])
                {
                    bien_place+=1;
                }
                if(bien_place == nb_couleur_affile){
                    printf("C'est gagné !!");
                }
            }
        }while(bien_place!=nb_couleur_affile && nb_essai!=0);
    }
}while(choix_joueur != 'Y');
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
