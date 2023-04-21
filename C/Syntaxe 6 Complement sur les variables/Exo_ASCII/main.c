#include <stdio.h>
#include <stdlib.h>
/*  Utilisateur rentre un caractère
    Affiche la valeur décimal du caractère
    Affiche la valeur hexadécimal du caractère.
*/
int main()
{
    char charactere_utilisateur;

    printf("Exercice conversion ASCII\n");
    printf("Veuillez rentrer un caractere ASCII :\t");

    scanf("%c",&charactere_utilisateur);
    printf("Vous avez entree la lettre \"%c\", soit\n",charactere_utilisateur);
    printf("\t - %d en decimal\n",(int)charactere_utilisateur);
    printf("\t - %x en hexadecimal\n",(int)charactere_utilisateur); // %x permet de convertir la donnée d'un type en héxadécimal.

    return 0;
}
