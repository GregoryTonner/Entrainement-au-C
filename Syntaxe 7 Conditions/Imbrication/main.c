#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Switch case
    int choix_client = 0;
    printf("Que souhaitez vous manger :\n\t - 1 : Eclair au chocolat\n\t - 2 : Milles_Feuilles\n");
    scanf("%d",&choix_client);
        // Ceci est une condition, si choix_client = 2 on renvoit 10 sinon on reteste de savoir
        // si choix_client = 1, alors on renvoit 3 si aucune des conditions n'est respecté alors on renvoit 0
    int prix = (choix_client ==2)? 10:(choix_client ==1)?3:0;

    switch(choix_client)
    {
        case(1):
            printf("Vous avez choisi l'eclair au chocolat, cela vous fait %d euros",prix);
        break;
        case(2):
            printf("Vous avez choisi le Mille-Feuilles, cela vous fait %d euros",prix);
        break;
        default:
            printf("Vous devez choisir :\n\t - 1 : Eclair au chocolat\n\t - 2 : Milles_Feuilles\n");
        break;
    }

    return 0;
}
/*
 const int AGE_NECESSAIRE = 18, CODE_PIN =1234, ARGENT_NECESSAIRE =250;
    int age_utilisateur = 0, code_pin_utilisateur = 0, argent_utilisateur = 0;


    printf("Quel age a tu ? :");
    scanf("%d",&age_utilisateur);

    if(age_utilisateur >= AGE_NECESSAIRE)
    {
        printf("Quel est le code secret ? :");
        scanf("%d",&code_pin_utilisateur);

        if(code_pin_utilisateur == CODE_PIN)
        {
            printf("Combien d'argent a tu sur toi ? :");
            scanf("%d",&argent_utilisateur);

            if(argent_utilisateur == ARGENT_NECESSAIRE)
            {
                printf("Bienvenue au club");
            }
            else
                printf("Tu n'as pas suffisament d'argent");
        }
        else
            printf("Mauvais code secret");
    }
    else
        printf("Tu est trop jeune");
*/
