//
// Created by Fleos on 14/03/2023.
//
#include "jeu.h"
#include <stdio.h>
#include "string.h"

void introJeu(void)
{

    printf("Bonjour, bienvenue dans votre bibliotheque de jeu en C\n");
    printf("Voici vos choix de jeu :\n\t 1 - Morpion\n\t 2 - Pendu\n\t 3 - Mastermind\n\t 0 - Sortir\n");
    printf("Entrez un chiffre pour valider votre choix ? :\t");
    fflush(stdin);
}
int selectionJeu(int saisie_utilisateur)
{
    switch (saisie_utilisateur) {
        case MORPION:
            morpion();
            break;
        case PENDU:
            pendu();
            break;
        case MASTERMIND:
            mastermind();
            break;
        case SORTIR:
            return SORTIR;
            break;
        default:
            introJeu();
            break;
    }
}
void mastermind()
{

}

int grillePleine(char* tab,int* compteur)
{
    int nb_ligne =3;
    int nb_colonne =3;
    for(int i =0;i<nb_ligne;i++) // On parcours notre tableau
    {
        char* p_ligne_tab = tab + (i *nb_colonne);  // On créer un pointeur vers notre ligne
        for(int p=0;p<nb_colonne;p++)
        {
            if(*(p_ligne_tab +p) != '_')    // Si toutes les cases sont différentes d'une case vide alors on compte
                return 1;
        }
    }
    return 0;   // Sinon on retourne 0 pour indiquer que la partie n'est pas fini
}

void affichageGrille(char* tab, int nb_ligne, int nb_colonne)
{
    printf("Grille actuelle : \n");
    for(int l=0;l<nb_ligne;l++) // Permet d'afficher la grille des joueurs
    {
        char* p_ligne = tab + (l * nb_colonne);         // On parcours notre tableau dans le but d'afficher chaque caractère aux utilisateurs
        printf("\n\t");
        for(int c=0;c<nb_colonne;c++)
            printf("%c\t",*(p_ligne + c));
    }
    printf("\n");
}

void saisieUtilisateur(int* x, int* y)
{
    scanf("%d%d", x, y);        // Lecture et enregistrement de la saisie utilisateur
    fflush(stdin);
}

int ecritureGrille(char* tab, int x, int y, char joueur, int nb_colonne)
{
    if((x < 1 || x > 3) || (y < 1 || y > 3))            // Si les valeurs entrées ne sont pas comprise entre 0 et 3
    {
        printf("Rentrez une valeur entre 1 et 3\n");    // Alors on retourne une erreur de saisie
        return 0;
    }
    x -= 1;                                             // -1 pour que l'utilisateur puisse considérer la première case = 1
    y -= 1;
    char* p_ligne = tab +(x * nb_colonne);
    char* p_position = p_ligne + y;                     // Pointeur vers la position choisir par l'utilisateur
    if(*p_position == '_')                              // Si la position est vide alors on écrit
    {
        *p_position = joueur;
        return 1;
    }
    else if(*p_position != '_')                         // Sinon on retourne que la case est déjà prise
    {
        printf("Case deja prise\n");
        return 0;
    }
}

void morpion()
{
    int fin_de_parti = 0, compteur=0;
    char partie = 'Y';
    char joueur1 ='X', joueur2 ='O';
    int tour_jeu = 1, tour_joueur1 = 1, tour_joueur2 = 2;
    int nb_colonne = 3, retour_ecriture, nb_ligne = 3;
    int coord_x, coord_y;
    char tab[3][3] =
            {{'_','_','_'},
             {'_','_','_'},
             {'_','_','_'}};
    do {
        do {
            retour_ecriture = 2;    // retour écriture confirme que le joueur à écrit dans le tableau et on passe au joueur suivant si c'est le cas
            if (tour_jeu == tour_joueur1) { // On commence par le joueur 1
                printf("Joueur 1, A quelle position souhaitez vous jouer ? (x,y)\n");
                do {
                    saisieUtilisateur(&coord_x, &coord_y);  // On effectue la saisie utilisateur
                    retour_ecriture = ecritureGrille((char *) tab, coord_x, coord_y, joueur1, nb_colonne);  // On récupère la valeur 1 si le joueur a écrit dans le tableau sinon 0
                    fin_de_parti = victoire((char *) tab, coord_x, coord_y, joueur1);   // On cherche un cas de victoire, si oui alors "fin_de_parti" = 1 sinon 0
                    if (retour_ecriture == 1 && fin_de_parti == 0)  // Si on a bien écrit et que la partie n'est pas fini
                        tour_jeu = tour_joueur2;    // On passe au tour du joueur 2
                } while (retour_ecriture == 0);     // On boucle tant que le joueur 1 n'a pas rentré une position valide pour écrire
            } else if (tour_jeu == tour_joueur2) {  // Tour du joueur 2 de jouer
                printf("Joueur 2, A quelle position souhaitez vous jouer ? (x,y)\n");
                do {
                    saisieUtilisateur(&coord_x, &coord_y);
                    retour_ecriture = ecritureGrille((char *) tab, coord_x, coord_y, joueur2, nb_colonne);
                    fin_de_parti = victoire((char *) tab, coord_x, coord_y, joueur2);
                    if (retour_ecriture == 1 && fin_de_parti ==0)
                        tour_jeu = tour_joueur1;
                } while (retour_ecriture == 0);
            }
            if(fin_de_parti == 0)   // Si la partie n'est pas terminée
            {
                compteur = grillePleine((char*)tab,&compteur); // On vérifie que la grille ne soit pas complète grace au compteur
                if(compteur != 0)                               // Si le compteur est différent de 0 alors ça veut dire que la grille est pleine
                    fin_de_parti = 1;                           // Donc, on met fin à la partie
            }
            affichageGrille((char *) tab, nb_ligne, nb_colonne);    // On affiche la grille à la fin de chaque tour de jeu
            printf("\n");
        } while (fin_de_parti != 1);                                // On boucle tant que la partie n'est pas fini
        if(compteur != 0){                                          // Si la partie est finie et que le compteur est différent de 0 on dit que c'est un match nul et on propose de refaire une partie
            printf("Match nul, souhaitez vous refaire une partie :\"Y\" or \"N\" ?\n ");
        }
        else if(compteur == 0){                                     // Si la partie est finie, mais que le compteur = 0 alors ca veut dire qu'un des joueurs a gagné
            printf("Bravo, le joueur %d a gagne, souhaitez vous refaire une partie :\"Y\" or \"N\" ?\n",tour_jeu);  // On annonce le gagnant et on propose de faire une nouvelle partie
        }
        fflush(stdin);
        scanf("%c",&partie);    // Récupération de la saisie utilisateur pour savoir si il veut rejouer ou non
    } while (partie != 'N');    // On boucle tant que l'utilisateur ne retourne pas la lettre "N" pour dire "Non"
}
int victoire (char* tab,int x, int y, char joueur){
    int nb_colonne = 3;
    switch(x) {         // On parcours chaque cas en fonction de l'emplacement choisi par le joueur pour chercher un cas de victoire pour le joueur qui vient de jouer
        case 1:         // Cas ou on est sur la première ligne
            switch (y) {
                case 1: // 1ère colonne
                    if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)      // On regarde si les deux lignes en dessous
                        if (*(tab + ((x + 2) * nb_colonne) + y) == joueur)
                            return 1;
                        else if (*(tab + ((x + 1) * nb_colonne) + y + 1) == joueur) // On regarde la diagonale en bas à droite
                            if (*(tab + ((x + 2) * nb_colonne) + y + 2) == joueur)
                                return 1;
                            else if (*(tab + (x * nb_colonne) + y + 1) == joueur)   // On regarde la ligne à droite
                                if (*(tab + (x * nb_colonne) + y + 2) == joueur)
                                    return 1;
                                else
                                    return 0;
                    break;
                case 2: // 2ème colonne
                    if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)  // On regarde la ligne en dessous
                        if (*(tab + ((x + 2) * nb_colonne) + y) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y + 1) == joueur)   // On regarde à droite puis à gauche
                            if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                                return 1;
                            else
                                return 0;
                    break;
                case 3: // 3ème colonne
                    if (*(tab + ((x + 1) * nb_colonne) + y - 1) == joueur)  // On regarde la diagonale en bas à gauche
                        if (*(tab + ((x + 2) * nb_colonne) + y - 2) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y - 1) == joueur)   // On regarde la ligne à gauche
                            if (*(tab + (x * nb_colonne) + y - 2) == joueur)
                                return 1;
                            else if (*(tab + ((x + 1) * nb_colonne) + y) == joueur) // On regarde la ligne en dessous
                                if (*(tab + ((x + 2) * nb_colonne) + y) == joueur)
                                    return 1;
                                else
                                    return 0;
                    break;
                default:
                    return 0;
            }
        case 2:     // Cas 2ème ligne
            switch (y) {
                case 1: // 1ère colonne
                    if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)  // On regarde au-dessus et à droite
                        if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y + 1) == joueur)   // On regarde la ligne à droite
                            if (*(tab + (x * nb_colonne) + y + 2) == joueur)
                                return 1;
                            else
                                return 0;
                    break;
                case 2: // 2ème colonne
                    if (*(tab + ((x + 1) * nb_colonne) + y + 1) == joueur)  // On regarde la diagonale en bas à droite puis en haut à gauche
                        if (*(tab + ((x - 1) * nb_colonne) + y - 1) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y + 1) == joueur)  // On regarde à droite et à gauche
                            if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                                return 1;
                            else if (*(tab + ((x + 1) * nb_colonne) + y) == joueur) // On regarde à dessus et en dessus
                                if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                                    return 1;
                    if (*(tab + ((x + 1) * nb_colonne) + y - 1) == joueur)  // On regarde la diagonale en bas à gauche puis en haut à droite
                        if (*(tab + ((x - 1) * nb_colonne) + y + 1) == joueur)
                            return 1;
                        else
                            return 0;
                    break;
                case 3: // 3ème colonne
                    if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)  // On regarde en haute et en bas
                        if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y - 1) == joueur)   // On regarde la ligne à gauche
                            if (*(tab + (x * nb_colonne) + y - 2) == joueur)
                                return 1;
                            else
                                return 0;
                    break;
                default:
                    return 0;
            }
        case 3:     // Cas 3ème ligne
            switch (y) {
                case 1: // 1 ère colonne
                    if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)  // On regarde la ligne au-dessus
                        if (*(tab + ((x - 2) * nb_colonne) + y) == joueur)
                            return 1;
                        else if (*(tab + ((x - 1) * nb_colonne) + y + 1) == joueur) // On regarde la diagonale en haut à droite
                            if (*(tab + ((x - 2) * nb_colonne) + y + 2) == joueur)
                                return 1;
                            else if (*(tab + (x * nb_colonne) + y + 1) == joueur)   // On regarde la ligne à droite
                                if (*(tab + (x * nb_colonne) + y + 2) == joueur)
                                    return 1;
                                else
                                    return 0;
                    break;
                case 2: // 2 ème colonne
                    if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)  // On regarde la ligne au-dessus
                        if (*(tab + ((x - 2) * nb_colonne) + y) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y + 1) == joueur)   // On regarde à droite puis à gauche
                            if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                                return 1;
                            else
                                return 0;
                    break;
                case 3: // 3ème colonne
                    if (*(tab + ((x - 1) * nb_colonne) + y - 1) == joueur)  // On regarde la diagonale en haut à droite
                        if (*(tab + ((x - 2) * nb_colonne) + y - 2) == joueur)
                            return 1;
                        else if (*(tab + (x * nb_colonne) + y - 1) == joueur)   // On regarde la ligne à gauche
                            if (*(tab + (x * nb_colonne) + y - 2) == joueur)
                                return 1;
                            else if (*(tab + ((x - 1) * nb_colonne) + y) == joueur) // On regarde la ligne en haut
                                if (*(tab + ((x - 2) * nb_colonne) + y) == joueur)
                                    return 1;
                                else
                                    return 0;
                default:
                    return 0;
            }
        default: // Tous les "default" dans les switch case retourne 0 dans le cas ou on a une erreur.(Il ne se passe donc rien)
            return 0;
    }
}
void pendu()
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
            printf("Vous avez gagne le mot qu'il fallait trouver etait: %s, vous aviez perdu %d vie\n",mot_a_trouver,10-vie);
        }
        else                                                        // Sinon il nous reste des lettre à trouver donc on indique l'état actuel de notre mot et de nos tentatives restantes
        {
            printf("Votre mot : %s et il vous reste %d vie\n",mot_affiche,vie);
        }
    }while(vie != 0 && strcmp(mot_affiche,mot_a_trouver)!=0); // Tant qu'il nous reste une vie ou que l'on a pas trouver la bon mot alors on boucle
}