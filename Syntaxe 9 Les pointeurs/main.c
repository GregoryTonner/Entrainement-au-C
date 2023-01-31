#include <stdio.h>

int main() {

    int age = 25, taille = 178;
    int* p_int = 0;
    p_int =&taille;
    printf("Donnez votre age");
    scanf("%d",p_int);

    printf("Vous avez %d ans et votre taille est %d cm",age,taille);

    return 0;
}
/*
    int mon_int = 12;
    int prix = 12000;
    int* p_int = 0;

    p_int = &mon_int;

    printf("mon int = %d adresse = %p\n",mon_int, &mon_int); // %p permet de récupérer l'adresse d'une variable
    printf("Je pointe vers l'adresse = %p, *p_int = %d\n",p_int,*p_int); // %p permet de récupérer l'adresse d'une variable

    p_int = &prix;
    printf("Je pointe vers l'adresse = %p, *p_int = %d\n",p_int,*p_int); // "*" avant un pointeur permet d'afficher la valeur de la case qu'il pointe
 * */
/*
 * short* p_var = 0; // Si un pointeur est initialisé à 0 et utilisé sans changer sa valeur alors Seg Fault

    if(p_var == NULL)
    {
        short var = 123;
        p_var = &var;
        printf("Ma variable contient %d\n", *p_var);
    }
    printf("Ma variable contient %d\n", *p_var); // Pas de soucis de compilation mais l'adresse que pointe p_var existe
                                                        // mais la variable "var" est déclaré uniquement dans le "if" donc cette adresse ne contient pas de valeur


 */