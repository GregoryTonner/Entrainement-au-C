#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define TAILLE 100
/*      Fonction inutile, n'a servie que de démonstration

   int* creerAge(){ // Fonction avec variable créer dans la stack

    int age = 33;   // On créer notre variable 33
    return &age;    // On retourne son adresse, cela va créer une erreur car cette variable disparaîtra en même temps que la fin de la fonction
}*/
int* creerAgeDynamique(){   // Fonction avec variable créer dans le tas

    int* age_dynamique =NULL;   // On créer notre pointeur vers l'age
    age_dynamique =(int*) malloc(sizeof (int)); // On alloue dynamiquement la taille du pointeur
    if(age_dynamique !=NULL){   // Si on a pas d'erreur sur la taille (par exemple manque de place dans la mémoire)
        *age_dynamique = 33; // On dit qu'à l'adresse qu'on pointe = 33
    }
        return age_dynamique;   // On renvoit l'adresse de ce pointeur
}
void libererAgeDynamique(int* age){
    if(age != NULL)
        free(age);
    else
        printf("Pas de memoire alloue pour cette variable\n");
}

int main() {
    printf("Allocation dynamique de la memoire\n");

    int taille_max=100, taille_liste =3;
    char** liste_nom=NULL; // Double étoile car, un tableau est un char* et voulons un pointeur vers se tableau, donc char**
                                    //          3 x sizeof(100) cela va nous créer un tableau dynamique de plusieurs cases
    liste_nom = (char**) malloc(taille_liste * sizeof (char*)); // On fait un malloc qui va faire la taille de la liste x la taille d'une case de notre tableau
    if(liste_nom ==NULL) // On test si echec
    {
        printf("Erreur");
        return -1;  // On sort de la fonction main
    }
    for (int i = 0; i <taille_liste; ++i) { // On parcours chaque ligne du tableau
        char *nom = NULL;   // On créer pour chaque lignes une case de 100 caractères
        nom = (char *) malloc((taille_max + 1) * sizeof(char));
        if (nom != NULL) { // On test si echec
            printf("Indiquez le nom :", nom);  // on récupère les données utilisateurs
            scanf("%s", nom);
            nom = (char *) realloc(nom, (strlen(nom) + 1) * sizeof(char));
            if (nom == NULL) { // On test si echec{
                printf("Erreur");
                return -2;  // On sort de la fonction main
            }
            *(liste_nom + i) = nom; // On entregistre la valeurs indiqué dans les cases du tableau
        } else {
            free(liste_nom); // Si on on a une erreur on libère la mémoire du premier pointeur
            return -2; // On sort de la fonction main
        }
    }
    for (int j = 0; j < taille_liste; ++j) {  // On parcours chaque case de notre tableau
        printf("Vous etes : %s\n", *(liste_nom + j)); // On affiche les noms
        free(*(liste_nom + j));         // Et on libère la mémoire après avoir affiché
        }
    free(liste_nom);

///////////////////////////////////////////////////////////////////////////////////////////////////

    int* p_age = NULL;
    p_age = creerAgeDynamique(); // On récupère l'adresse renvoyé par notre fonction


    if(p_age != NULL)
    {
        //*p_age = 25;
        printf("Tu as %d ans, qui est dans la case memoire %p\n",*p_age,p_age); // On l'affiche
        libererAgeDynamique(p_age);
    }else
        printf("Erreur d'allocation memoire\n");    // On renvoit une erreur si le pointeur renvoie Null

    return 0;
}

/*
 * Il existe 2 types de mémoire, la pile et le tas.
 * La pile évolue en fonction de sa place dans le code, si on appel une fonction on créer des variables local
 * qui seront détruite lorsque la fonction sera terminé.(Sachant que int main est une fonction)
 *
 * Le tas, lui est considéré comme une mémoire dynamique car elle ne dépend pas de son emplacement dans le
 * programme, par exemple une variable qui est déclaré dans le tas ne sera supprimé que si on utilise la
 * fonction "Free", sinon la variable restera alloué dans la mémoire.
 * */