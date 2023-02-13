#include <stdio.h>
#include "time.h"
#include "stdlib.h"
int De(int nb_face_max);
int Des(int nb_face_max,int nb_de);

int main() {
    int nb_face;
    int nb_des;
    printf("Exercice sur les lancer de des\n");
    printf("Bienvenue sur votre jeux de lancer de des\n");
    printf("Veuillez rentrer le nombre de face que vous souhaitez sur votre des :");
    scanf("%d",&nb_face);
    printf("Vous allez jouer avec un des a %d face, veuillez entrez le nombre de des que vous souhaitez lancer :",nb_face);
    scanf("%d",&nb_des);
    printf("Vous lancez donc %d des a %d face la somme est de : %d",nb_des,nb_face,Des(nb_face,nb_des));
    return 0;
}

int De (int nb_face_max)
{
    const int nb_face_min = 1;
    srand(time(NULL));
    int resultat = (rand() % (nb_face_min + nb_face_max - 1)) + 1;
    return resultat;
}
int Des (int nb_face_max, int nb_de)
{
    int resultat;
    for(int i=0;i<=nb_de;i++)
    {
        resultat = resultat + De(nb_face_max);
    }
    return resultat;
}
