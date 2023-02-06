#include <stdio.h>
#include "string.h"

int main()
{
    char mot_a_trouver[] = "PIGNOUF";
    int taille_mot = strlen(mot_a_trouver); // Permet de rendre plus simple le changement de mot à trouver dans le code
    char mot_affiche[taille_mot+1];         // taille_mot +1 car on oublie pas le caractère de fin de tableau "\0"
    char saisie_utilisateur[taille_mot+1];
    for(int i=0;i<taille_mot;i++)           // On parcours le tableau complet
    {
        mot_affiche[i]='-';                 // On place un "-" à afficher pour le joueur dans toutes les cases du tableau
        mot_affiche[taille_mot]='\0';       // On place en fin de tableau le caractère "\0" pour indiquer à notre OS que l'on arrive à la fin du tableau
    }

    int vie = 10, position_max =8, compteur;

    printf("Bienvenu sur votre jeu du pendu !\n");
    do
    {
        printf("Veuillez entrer votre caractere en majuscule :");
        fgets(saisie_utilisateur,position_max,stdin);               // scanf qui permet de récupérer des string
        fflush(stdin);                                              // Efface toutes les anciennes saisies dans le terminal stdin
        compteur =0;
        if(strcmp(mot_a_trouver,saisie_utilisateur)==0)             // Si mot a trouver = saisie utilisateur
        {
            strcpy(mot_affiche,mot_a_trouver);                      // Copy du tableau mot_a_trouver dans le tableau mot_affiche (obligé car le signe "=" est utilisable que pour les char
        }
        for(int position=0;position<position_max;position++)        // on parcours chaque case du tableau
        {
            if(*saisie_utilisateur == mot_a_trouver[position])      // Si le caractère saisie = caractère dans le tableau du mot à trouver à la position "X"
            {
                mot_affiche[position] = *saisie_utilisateur;        // Alors on copy ce caractère dans le tableau mot_affiche à cette même position "X"
                compteur ++;                                        // On incrémente compteur uniquement lorsque l'on a trouvé un mot
            }
        }
        if(compteur == 0)                                           // Si compteur = 0 alors on à pas trouver une lettre qui match dans le mot a trouver
        {
            --vie;                                                  // Donc on perd un point de vie
            printf("Ce charactere n'est pas dans le mot a trouver !\n");
        }
        if(vie == 0)                                                // Si on a plus de vie alors on a perdu
        {
            printf("Tu as perdu, le mot qu'il fallait trouver etait : %s\n",mot_a_trouver);
        }
        else if(strcmp(mot_affiche,mot_a_trouver) == 0)             // Si le mot affiche = mot a trouver alors on a gagné
        {
            printf("Vous avez gagne le mot qu'il fallait trouver etait: %s en %d tentative\n",mot_a_trouver,10-vie);
        }
        else                                                        // Sinon il nous reste des lettre à trouver donc on indique l'état actuel de notre mot et de nos tentatives restantes
        {
            printf("Votre mot : %s et il vous reste %d vie\n",mot_affiche,vie);
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