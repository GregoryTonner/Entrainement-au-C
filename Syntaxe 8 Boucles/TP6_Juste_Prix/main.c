#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    generation d'un nombre aléatoire entre 1 et 100
 faire
 {
    ecrire("quel est le nombre ?")
    lire la saisie_utilisateur
    si(saisie_utilisateur < nombre aleatoire)
        alors
            ecrire("c'est plus grand !")
            nombre_essaie ++
    sinon si (saisie_utilisateur > nombre aléatoire)
        alors
            ecrire("c'est plus grand")
            nombre_essaie ++
    sinon si (saisie_utilisateur == nombre aléatoire)
                alors
                    ecrire("Juste PRIX !")
 } tant que (saisie_utilisateur != nombre aléatoire ET nombre_essaie != 10)
*/
int main()
{
 // generation d'un nombre aleatoire
    const int NB_MAX_ESSAIS = 10, VALEUR_MIN = 1, VALEUR_MAX = 100;;
    int saisie_utilisateur =0, nombre_essais = NB_MAX_ESSAIS, nombre_aleatoire =0;
    char choix_joueur;

    printf("TP 6 Juste prix !\n");

    do
    {
        printf("Voulez vous jouer ? : \"Y\" \"N\"\n");
        scanf("%c",&choix_joueur);
        if(choix_joueur == 'Y')
        {
            srand(time(NULL)); // initialise le generateur pseudo aléatoire
            nombre_aleatoire = (rand() % (VALEUR_MAX - VALEUR_MIN + 1)) + VALEUR_MIN;
            /*
                La fonction rand permet de créer un pseudo aléatoire qu'on calcul en fonction du
                modulo de la valeur min et max que l'on souhaite.
            */
            do
            {
                printf("Quel est le juste prix ?\n");
                scanf("%d",&saisie_utilisateur);
                if(saisie_utilisateur < nombre_aleatoire)
                    {
                        printf("C'est plus haut, il te reste %d essais\n",--nombre_essais);
                    }
                else if(saisie_utilisateur>nombre_aleatoire)
                    {
                        printf("C'est plus bas, il te reste %d essais\n",--nombre_essais);
                    }
                else
                    {
                        printf("C'est le juste prix !!\n");
                        printf("Tu l'as trouve en %d essais, Bravo !\n",NB_MAX_ESSAIS - nombre_essais);
                    }
                if(nombre_essais == 0)
                    {
                        printf("Dommage c'est perdu !\n");
                    }
            }while(saisie_utilisateur != nombre_aleatoire && nombre_essais != 0);
        }
    }while(choix_joueur != 'N');
    return 0;
}
