#include <stdio.h>
#include <stdlib.h>
/*  Utilisateur rentre un caract�re
    Affiche la valeur d�cimal du caract�re
    Affiche la valeur hexad�cimal du caract�re.
*/
int main()
{
    char charactere_utilisateur;

    printf("Exercice conversion ASCII\n");
    printf("Veuillez rentrer un caractere ASCII :\t");

    scanf("%c",&charactere_utilisateur);
    printf("Vous avez entree la lettre \"%c\", soit\n",charactere_utilisateur);
    printf("\t - %d en decimal\n",(int)charactere_utilisateur);
    printf("\t - %x en hexadecimal\n",(int)charactere_utilisateur); // %x permet de convertir la donn�e d'un type en h�xad�cimal.

    return 0;
}
