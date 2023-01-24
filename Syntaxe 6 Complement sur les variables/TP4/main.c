#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int rayon = 0;
    int diametre =0;
    int hauteur =0;

    float circonference =0.0;
    float aire =0.0;
    float volume_cylindre =0.0;
    float volume_cone =0.0;

    printf("TP 4 Complement sur les variables\n");


    printf("Quel est le rayon d'un cercle :");
    scanf("%d",&rayon);
    printf("Quel est la hauteur du volume :");
    scanf("%d",&hauteur);

    diametre = rayon *2;
    circonference = M_PI*(float)diametre;
    aire = M_PI*pow(rayon,2);

    printf("\nDiametre du cercle :%d\nCirconference du cercle :%f\nAire du cercle :%f\n\n",diametre,circonference,aire);

    volume_cylindre = aire * (float)hauteur;
    volume_cone = volume_cylindre/3;

    printf("Volume du cylindre :%f\nVolume du cone :%f\n",volume_cylindre,volume_cone);

    return 0;
}
