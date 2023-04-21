#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int CODE_SECRET = 1355;
    int saisie_utilisateur =0;

    printf("Veuillez entrer le code sercret en moins de 3 tentatives\n");
    printf("Ce code est forcement superieur a 0\n");

    for(int nb_tentative=0;nb_tentative<3;nb_tentative++)
    {
        scanf("%d",&saisie_utilisateur);
        if(saisie_utilisateur <= 0)
        {
            printf("Le code doit etre superieur a 0\n");
            continue;
        }
        if(saisie_utilisateur==CODE_SECRET)
        {
            printf("Code bon\n");
            break;
        }

        printf("Erreur de saisie\n");
    }
   /* do
    {
        scanf("%d",&saisie_utilisateur);
        if(saisie_utilisateur!= CODE_SECRET)
            printf("Mauvais code, %d tentatives\n",++nb_tentative);
        else
            printf("Code bon\n");

    }while(saisie_utilisateur != CODE_SECRET && nb_tentative < 3);*/
    return 0;
}
/*
    ***Boucle Do While ***
    // On utilise cette boucle dans le cas ou on ne connait pas le nombre d'itération mais que
    // l'on souhaite exectuter une fois nos instructions

    int saisie_utilisateur = 0;
    do
    {
        printf("Veuillez rentrer un nombre entre 1 et 10 :");
        scanf("%d",&saisie_utilisateur);
    }while(saisie_utilisateur < 1 || saisie_utilisateur > 10);

    printf("%d est votre nombre",saisie_utilisateur);
*/
/*
    *** Boucle For ***
    // Cette boucle est à utiliser dans le cas ou on connait le nombre d'itération

    for(int compteur =10; compteur >0;compteur--)
    {
        printf("Detonnation dans : %d\n",compteur);
    }
    printf("BOOM ! \n");
*/
