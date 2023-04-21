#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int CODE_PIN = 1355, FIN_TENTATIVE = 0;
    int saisie_utilisateur =0, compteur_erreur = 3;


        printf("Veuillez entrer votre code PIN a 4 chiffres :");
    do      // Faire
    {
        scanf("%d",&saisie_utilisateur);    // Lire la saisie
        if(saisie_utilisateur != CODE_PIN)  // Si le code pin n'est pas bon
        {
            printf("Code non valide, il vous reste %d tentatives :",--compteur_erreur); // On affiche et on décrémente notre compteur
            if(compteur_erreur == FIN_TENTATIVE)    // Si notre compteur n'a plus de tentative on verrouille le téléphone et on sort de notre boucle
            {
                printf("\nTelephone verrouille\n");
            }
        }
        else if(saisie_utilisateur == CODE_PIN) // Si le code pin est bon, le telephone est deverouillé et on sort de notre boucle
        {
            printf("Telephone deverouille\n");
        }
    }while(saisie_utilisateur != CODE_PIN && compteur_erreur != FIN_TENTATIVE); // Tant que saisie est différente de code pin et que notre compteur a encore des tentative on boucle
    return 0;
}
