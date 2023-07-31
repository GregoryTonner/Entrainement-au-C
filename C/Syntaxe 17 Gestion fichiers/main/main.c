#include <stdio.h>
#include "stdlib.h"

int main() {
    printf("Gestion des fichiers !\n");
    int high_score = 200;
    FILE* pt_fichier = fopen("../readme.txt","w");
    if(pt_fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
        return -1;
    }
/*
    fputc('A',pt_fichier); // Permet d'écrire un caractère sur notre fichier actuellement ouvert
    fputs(" - Voici les premieres écritures sur le fichier\n",pt_fichier); // Permet d'écrire une chaine de caractère
    fprintf(pt_fichier,"Voici les scores de jeu de votre équipe :%d\n",high_score); // Permet de faire printf dans notre fichier ouvert.
*/
 /*   char caractere;
    do {
        caractere = fgetc(pt_fichier);
        printf("%c",(char)caractere);
    } while (caractere != EOF);

    char tab[20];
    int age;
    float taille;
    fgets(tab,10,pt_fichier);
    printf("%s",tab);
    fgets(tab,10,pt_fichier);
    printf("%s",tab);
    fscanf(pt_fichier,"%d%f",&age,&taille);
    printf("%d %f",age,taille);*/

    printf("Position %ld\n", ftell(pt_fichier)); // ftell permet de connaitre la positon de notre curseur dans le fichier
    fputc('x',pt_fichier);
    printf("Position %ld\n", ftell(pt_fichier));
    //rewind(pt_fichier); // Rewind permet de faire une remise à 0 de la position de notre curseur
    fseek(pt_fichier,-1,SEEK_END); // fseek permet d'effectuer un déplacement du curseur d'une quantité souhaité
    // On peut mettre en dernier paramètre de fseek -> ""SEEK_SET (début), SEEK_CUR(position actuelle), SEEK_END (fin) du fichier
    printf("Position %ld\n", ftell(pt_fichier));

    int resultat = fclose(pt_fichier);
    if(resultat!=0){
        printf("Errreur lors de la fermeture du fichier\n");
        return -2;
    }

    if(rename("../readme.txt","../data/tuto.txt")!=0) // Permet de renommer ou de déplacer un fichier (déplacement d'un dossier à un autre)
        printf("Erreur lors du renomage\n");
    if(remove("../data/tuto.txt")!=0) // Permet de supprimer un fichier
        printf("Erreur lors de la suppression\n");

    return 0;
}
