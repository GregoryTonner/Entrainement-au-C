#include <stdio.h>

/*
 * Lorsque l'on déclare un tableau celui-çi correspond à un pointeur vers la première case du tableau.
 * c'est pour cela que la première case on la nomme "mon_tableau[0]" car on lui dit
 * Donne moi l'adresse de la première case de mon tableau puis décale de 0 case mémoire.
 * Et ainsi de suite on va parcourir le tableau en prenant en compte la type de tableau que nous avons.
 *
 * "tab" retourne l'adresse du tableau
 * "tab+1" retourne l'adresse de la deuxième case du tableau
 *
 * "*(tab + 0)" retourne la valeur contenue dans le première case du tableau et ainsi de suite (L'étoile devant un pointeur permet de retourner la valeur dans la case pointé)
 *
 * Ne pas mettre les crochet derrière un tableau montre bien leurs fonctionnement en tant que pointeur
 * */

int main() {
    const int TAILLE_TABLEAU = 3;
    int mon_tableau[TAILLE_TABLEAU];

    // init du tableau
    for(int i = 0;i<TAILLE_TABLEAU;i++)     // Permet de parcourir le tableau de l'ID 0 à l'ID TAILLE_TABLEAU-1
    {
        printf("Que souhaitez vous rentrer dans le tableau ?\n > ");
        scanf("%d",mon_tableau + i);        // Permet de lire la saisie utilisateur et de l'envoyer à l'adresse de la position du tableau
        printf("mon_tableau [%d] = %d\n",i,*(mon_tableau + i));     // Lecture de la valeur en fonction de la case du tableau
    }

    return 0;
}

/*   *** Initialisation d'un tableau ***
 *
 *  int tirage_loto_boulle[5] ={1,2,3,4,5};
    int tirage_loto_etoile[]= {6,7};
    char initiales_gagnant[2];
*/