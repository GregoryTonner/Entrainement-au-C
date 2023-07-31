#include <stdio.h>
#include <stdlib.h>

typedef struct st_personnage{
    int pv;
    int pm;
}Personnage;

int main() {
    printf("Fonction calloc pour l'allocation dynamique de la memoire\n");

    Personnage* perso = NULL;
    perso=(Personnage*)malloc(sizeof (Personnage));

    if(perso==NULL){
        return -1;
    }

    perso->pv=10;
    perso->pm=100;

    printf("Votre perso a %dPV et %dPM\n",perso->pv,perso->pm);

    perso=(Personnage*)calloc(1,sizeof (Personnage)); // calloc permet d'allouer de la mémoire et de la setup à 0

    if(perso==NULL){
        return -1;
    }

    printf("Votre perso a %dPV et %dPM\n",perso->pv,perso->pm);
    return 0;
}
