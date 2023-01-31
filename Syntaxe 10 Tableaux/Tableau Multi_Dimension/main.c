#include <stdio.h>

int main() {

    /* tab[2][3] =
     * |  2 |  5 |  3 |
     * | 89 | 87 | 99 |
     * */
    int tab[2][3] = {{2,5,3}
                    ,{89,87,99}}; // tab [nb_lignes][nb_colonnes]
    for(int ligne =0;ligne<2;ligne++) // On fait varier les lignes
    {
        int* p_ligne = *(tab + ligne); // on créer un buffer pour sauvegarder la ligne actuel
        printf("\n");   // Cela permet de marquer les différences entres les lignes
        for(int colonne=0;colonne<3;colonne++)     // On fait varier les colonnes
        {
            printf("tab[%d][%d] = %d\n",ligne,colonne,*(p_ligne + colonne)); // On affiche les valeurs du tableau  en faisant varier dans un premier temps les colonnes puis les lignes
        }
    }
    return 0;
}
