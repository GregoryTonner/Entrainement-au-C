#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int age_utilisateur = 0;
    float taille_utilisateur =0;
    const int AGE_REQUIS = 12;
    const float TAILLE_REQUIS = 1.2;
    int accompagne = 0;

    printf("Quel age avez vous, et quelle taille faite vous :");
    scanf("%d%f",&age_utilisateur,&taille_utilisateur);
    printf("Et tu accompagne ? si oui : 1 si non : 0 \n");
    scanf("%d",&accompagne);
    /* On met en place une condition dans laquelle les deux doivent être verifié
       donc l'utilisateur doit avoir au moins l'age requis ET la taille requise
     */
    if(((age_utilisateur >= AGE_REQUIS) && (taille_utilisateur >= TAILLE_REQUIS)) || accompagne == 1)
    {
        printf("Vous pouvez monter");
    }
    else
    {
        printf("Trop jeune ou trop petit");
    }
    return 0;
}

/*
    int age_utilisateur = 25;
    int age_majorite = 18;
    int resultat = (age_utilisateur >= age_majorite);

    printf("Resultat : %d\n",resultat);
*/
