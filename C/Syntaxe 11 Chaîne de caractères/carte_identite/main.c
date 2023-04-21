#include <stdio.h>

int main() {
    char nom[20];
    char prenom[20];
    char date_naissance[11];
    char couleur_yeux[10];

    printf("Bonjour, veuillez rentrer vos information personnelle:\n");
    printf("\t- Nom:");
    scanf("%s",nom);
    fflush(stdin);
    printf("\t- Prenom:");
    scanf("%s",prenom);
    fflush(stdin);
    printf("\t- Date de naissance (DD/MM/YYYY):");
    scanf("%s",date_naissance);
    fflush(stdin);
    printf("\t- Couleur des yeux:");
    scanf("%s",couleur_yeux);
    fflush(stdin);

    printf("Vous etes %s %s vous etes nee le %s, vos yeux sont de couleur %s",nom,prenom,date_naissance,couleur_yeux);

    return 0;
}
