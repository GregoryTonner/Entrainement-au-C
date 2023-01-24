/* TP 3 Opération sur variable*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Pour un Carré */

    /*int cote_carre = 0;
    int perimetre = 0;
    int surface = 0;

    printf("Quelle est la taille du cote du carre en cm?\n");
    scanf("%d",&cote_carre);

    perimetre = cote_carre *4;
    surface = cote_carre * cote_carre;

    printf("Le perimetre du carre est de %dcm\nLa surface du carre est de %dcm\n",perimetre,surface);
    */
    /* Pour un rectangle */
    int hauteur_rectangle =0;
    int largeur_rectangle =0;
    int surface =0;
    int perimetre =0;

    printf("Quelle est la hauteur et la largeur du rectangle ?\n");
    // On récupère les valeurs de la hauteur et de la largeur du rectangle de la part de l'utilisateur
    scanf("%d%d",&hauteur_rectangle,&largeur_rectangle);
    // On calcul le perimètre et la surface du rectangle
    perimetre = (hauteur_rectangle+largeur_rectangle)*2;
    surface = hauteur_rectangle*largeur_rectangle;
    // On affiche le resultat de nos calculs
    printf("Le perimetre du rectangle est de %dcm\nLa surface du rectangle est de %dcm\n",perimetre,surface);
    return 0;
}
