#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("TP 5\n");

    int nombre1,nombre2 =0;
    char operateur;
    float valeur_final =0;


    printf("Bienvenu dans votre calculatrice");
    printf("Veuillez rentrer un calcul mathematique sans espace sous la forme\n\t - Nombre1 Operateur Nombre2\n");
    printf("Operateur disponible \"+,-,/,*\"\n");

    scanf("%d%c%d",&nombre1,&operateur,&nombre2);
    if(nombre2 != 0 || operateur != '/')
    {
        switch(operateur)
        {
        case('+'):
            valeur_final = (float)nombre1 + (float)nombre2;
            printf("%d %c %d = %f",nombre1,operateur,nombre2,valeur_final);
        break;
        case('-'):
            valeur_final = (float)nombre1 - (float)nombre2;
            printf("%d %c %d = %f",nombre1,operateur,nombre2,valeur_final);
        break;
        case('*'):
            valeur_final = (float)nombre1 * (float)nombre2;
            printf("%d %c %d = %f",nombre1,operateur,nombre2,valeur_final);
        break;
        case('/'):
            valeur_final = (float)nombre1 / (float)nombre2;
            printf("%d %c %d = %f",nombre1,operateur,nombre2,valeur_final);
        break;
        default:
            printf("L'operateur n'est pas correcte");
        break;
        }
    }
    else
        printf("%d %c %d n'est pas peut pas etre calcule",nombre1,operateur,nombre2);
    return 0;
}
