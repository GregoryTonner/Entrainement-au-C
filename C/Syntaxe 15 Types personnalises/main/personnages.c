//
// Created by SESA583772 on 27/07/2023.
//

#include "personnages.h"
#include <stdio.h>

void affichageStat(Personnage perso){

    printf("-> %s\n",perso.nom);
    printf("\tPV = %d\n",perso.pv);
    printf("\tPM = %d\n",perso.mana);
    printf("\tClasse = %c\n",perso.classe);
    /*Permet d'afficher directement le contenue des structures sans passer par des fonctions*/
    //printf("\t Arme = %s de degat = %f",perso.arme.nom,perso.arme.degat);

    printf("\t");
    afficherArme(perso.arme);

}
void equiperArme(Personnage* perso, Arme arme){
    //(*perso).arme = arme; // Les deux manière fonctionne, ça permet d'assigner une valeur au pointeur de la structure.
    perso->arme = arme;

    printf("%s est maintenant equipe de l'arme : %s\n",perso->nom,perso->arme.nom);
}