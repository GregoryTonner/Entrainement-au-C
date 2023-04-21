#include <stdio.h>


int valeurMax1DPointeur(int* tab, int nb_colonne);
int valeurMax2DPointeur(int* tab, int nb_ligne, int nb_colonne);
void ditHello();
void infosPerso(int xp, int lvl);
int puissance(int nombre, int exposant);
int valeurMax1D(int tab[5], int nb_colonne);
int valeurMax2D(int tab[][5], int nb_ligne, int nb_colonne);


int main() {

    int nb_ligne = 2, nb_colonne = 5;

    int tab_1D[] = {22, 50, 2, 6, 66};
    int tab_2D[2][5] = {{22, 50, 2, 6, 14}, {2, 5, 12, 6, 94}};

    int nombre_max_1D =0;
    int nombre_max_2D =0;

    nombre_max_1D = valeurMax1DPointeur(tab_1D,nb_colonne);
    nombre_max_2D = valeurMax2DPointeur((int*)tab_2D,nb_ligne,nb_colonne);

    printf("Le nombre maximum du tablea a 1 dimension est : %d\n", nombre_max_1D);
    printf("Le nombre maximum du tablea a 2 dimension est : %d\n", nombre_max_2D);
    return 0;
}
void ditHello()
{
    printf("Hello, World!\n");
    printf("Formation C\n");
}
void infosPerso(int xp, int lvl){
    xp *=4;
    printf("\txp : %d\n",xp);
    printf("\tlevel : %d\n",lvl);
}
int puissance(int nombre, int exposant) {
    int total = nombre;
    if (exposant > 0) {
        for (int i = 1; i < exposant; i++) {
            total = total * nombre;
        }
    }
    else if (exposant ==0){
        total = 1;
    }
    else if(exposant < 0)
        total = 0;

    return total;
}
int inverser(int* nb1, int* nb2)
{
    if(nb2 == NULL || nb1 == NULL)
    {
        return 1;
    }
    int buffer1 = *nb1;
    *nb1 = *nb2;
    *nb2 = buffer1;
    return 0;
}
// Version sans pointeur
int valeurMax1D(int tab[5], int nb_colonne)
{
    int valeur_max = 0;
    int valeur_actuel;
    for(int i = 0;i<nb_colonne;i++)
    {
        valeur_actuel = tab[i];
        if(valeur_max < valeur_actuel)
        {
            valeur_max = valeur_actuel;
        }
    }
    return valeur_max;
}
int valeurMax2D(int tab[][5], int nb_ligne, int nb_colonne)
{
    int valeur_max = 0;
    int valeur_actuel;

    for(int p=0;p<nb_ligne;p++) {
        for (int i = 0; i < nb_colonne; i++) {
            valeur_actuel = tab[p][i];
            if (valeur_max < valeur_actuel) {
                valeur_max = valeur_actuel;
            }
        }
    }
    return valeur_max;
}
// Version avec pointeur
int valeurMax1DPointeur(int* tab, int nb_colonne)
{
    int valeur_max = 0;
    int valeur_actuel;
    for(int i = 0;i<nb_colonne;i++)
    {
        valeur_actuel = *(tab + i);
        if(valeur_max < valeur_actuel)
        {
            valeur_max = valeur_actuel;
        }
    }
    return valeur_max;
}
int valeurMax2DPointeur(int* tab, int nb_ligne, int nb_colonne) // Cette fonction permet de rentrer autant de ligne et de colonne que l'on souhaite a notre tableau
{
    int valeur_max = 0;
    int valeur_actuel;
    int* p_ligne;
    for(int p=0;p<nb_ligne;p++) {
        p_ligne = tab + (p * nb_colonne); // p_ligne recupère l'adress du tableau à la bonne ligne en lui ajoutant le nombre de colonne que l'on retrouve dans notre tableau
        for (int i = 0; i < nb_colonne; i++) {
            valeur_actuel = *(p_ligne + i);
            if (valeur_max < valeur_actuel) {
                valeur_max = valeur_actuel;
            }
        }
    }
    return valeur_max;
}
