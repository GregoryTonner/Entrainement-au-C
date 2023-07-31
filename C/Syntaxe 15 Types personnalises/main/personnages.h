//
// Created by SESA583772 on 27/07/2023.
//
#ifndef MAIN_PERSONNAGES_H
#define MAIN_PERSONNAGES_H

#include "arme.h"


typedef enum CLASSE {
    CLASSE_MAGE = 'M',  // Permet de créer des variable que l'on enumère
    CLASSE_BARBARE = 'B', // Elle peuvent avoir plusieurs types de base, comme un INT, un CHAR, LONG etc..
    CLASSE_SOIGNEUR = 'S',
    CLASSE_VOLEUR = 'V'
}Classe;

struct st_personnage{
    char nom[100];
    int pv;
    int mana;
    Classe classe;
    Arme arme;
};
typedef struct st_personnage Personnage;

void affichageStat(Personnage perso);
void equiperArme(Personnage* perso, Arme arme);
#endif //MAIN_PERSONNAGES_H

/*
 * Personnage
 *
 * */
