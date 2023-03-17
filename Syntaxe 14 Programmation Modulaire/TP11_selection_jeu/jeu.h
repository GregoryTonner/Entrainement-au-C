//
// Created by Fleos on 14/03/2023.
//

#ifndef TP11_SELECTION_JEU_JEU_H
#define TP11_SELECTION_JEU_JEU_H

#define MORPION 1
#define PENDU 2
#define MASTERMIND 3
#define SORTIR 0
// *** Bibliotheque de jeu *** //
void introJeu(void);
int selectionJeu(int saisie_utilisateur);
void mastermind(void);
void pendu(void);
void morpion(void);
// *** Pendu ***//

// *** Mastermind ***//
char couleur_random(int, int);

// *** Morpion ***//
int ecritureGrille(char* tab, int x, int y, char joueur, int nb_colonne); // Ecrit dans la tab le caractère correspondant au joueur qui vient de jouer
void saisieUtilisateur(int* x, int* y); // Récupère la saisie de l'utilisateur, dans le but de retourner la position à laquelle il souhaite écrire dans la tab
void affichageGrille(char* tab, int nb_ligne, int nb_colonne);  // On affiche le contenu de la tab
int victoire (char tab[][3],char joueur); // On recherche un cas de victoire (Autre méthode de code pour cette fonction dans la correction du TP)
int grillePleine(char* tab);  // Permet de déterminer si la tab est pleine ou non

#endif //TP11_SELECTION_JEU_JEU_H
