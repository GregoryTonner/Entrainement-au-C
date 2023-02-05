#include <stdio.h>
#include "string.h"
#include "stdlib.h"


int main()
{
    char mot_a_trouver[] = "PIGNOUF";
    char mot_affiche[] = "-------";
    char saisie_utilisateur;
    int vie = 10, position_max =8, compteur;

    printf("Bienvenu sur votre jeu du pendu !\n");
    do
    {
        printf("Veuillez entrer votre caractere en majuscule :");
        scanf("%c",&saisie_utilisateur); // Récupération saisie utilisateur
        fflush(stdin); // Efface toutes les anciennes saisies dans le terminal stdin
        compteur =0;
        for(int position=0;position<position_max;position++)
        {
            if(saisie_utilisateur == mot_a_trouver[position])
            {
                strcpy(&mot_affiche[position],&saisie_utilisateur);
                compteur ++;
            }
        }
        printf("Votre mot : %s et il vous reste %d vie\n",mot_affiche,vie);
        if(compteur == 0)
        {
            vie--;
            printf("Ce charactere n'est pas dans le mot a trouver !\n");
        }
    }while(vie != 0 && strcmp(mot_affiche,mot_a_trouver)!=0); // Tant qu'il nous reste une vie ou que l'on a pas trouver la bon mot alors on boucle

    return 0;
}
/*
 * char mot_a_trouver []
 * char mot_affiche[]
 * int compteur_essais
 * char saisie_utilisateur[]
 * int essais
 * buffer = mot_affiche
 * int position_max
 *
 * faire
 * {
 *      printf(saisir votre caractère seul en majuscule)
 *      scanf(%c,saisie_utilisateur)
 *      compteur = 0
 *      pour(position =0;position < position_max ; position++)
 *         {
 *         si saisie_utilisateur == char_mot_a_trouver[position]
 *              alors
 *              {
 *                  mot_affiche[position] = saisie_utilisateur
 *                  compteur_essais ++
 *              }
 *         }
 *         si compteur =0
 *              alors
 *              {
 *                  essais--
 *                  printf(ce caractère n'est pas le mot)
 *              }
 *  }
 *  tant que(mot_affiche != mot_a_trouver et essais != 0)
 *
 * */