#include <stdio.h>
#include "jeu.h"

int main() {
    printf("TP 11 Bibliotheque de jeu !\n");

    int saisie_utilisateur;
    int choix;

    do {
        introJeu();
        scanf("%d", &saisie_utilisateur);
        choix = selectionJeu(saisie_utilisateur);
    }while (choix != SORTIR);

    return 0;
}
