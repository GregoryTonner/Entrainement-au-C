#include <stdio.h>
#include <stdlib.h>

/*
    Demander un nombre entier à l'utilisateur
    lire la saisie de l'utilisateur
    Si (saisie_utilisateur modulo 2 = 0)
        ecrire("'saisie_utilisateur' est un nombre pair")
    sinon
        ecrire("'saisie_utilisateur' est un nombre impair")

*/

int main()
{
    int saisie_utilisateur = 0;
    int boucle = 0;

    printf("Exo pair ou impair\n");
    while(boucle == 0)
    {
        printf("Veuillez rentrer un nombre entier : ");
        scanf("%d",&saisie_utilisateur);
        // L'opérateur "%2" correpond à modulo 2 et donc on test de voir si il y a un reste dans la division
        // saisie_utilisateur / 2, si il y a un reste alors c'est impair, si il y en a pas alors il est pair
        if(saisie_utilisateur%2 == 0)
            {
                printf("\t%d est un nombre pair\n",saisie_utilisateur);
            }
        else
        {
            printf("\t%d est un nombre impair\n",saisie_utilisateur);
        }
        printf("Voulez vous continuer ?\n \t - Oui = 0\n\t - Non = 1\n");
        scanf("%d",&boucle);
    }

    return 0;
}
