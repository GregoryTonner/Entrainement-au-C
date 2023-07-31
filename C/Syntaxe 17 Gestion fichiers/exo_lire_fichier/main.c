#include <stdio.h>

int main() {
    printf("Exercice lire fichier!\n");

    FILE* pt_fichier = fopen("../hello.txt","r");
    if(pt_fichier == 0){
        printf("Erreur dans la lecture du fichier");
        return -1;
    }
    printf("Contenu du fichier :\n");
    char caractere;
    do {
        caractere = fgetc(pt_fichier);
        printf("%c",caractere);
    } while (caractere != EOF);


    int resultat = fclose(pt_fichier);
    if(resultat != 0){
        printf("Erreur fermeture du fichier\n");
        return -2;
    }
    return 0;
}
