#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("TP 2 memoire et variables \n");
        // Déclaration et définition des variables
    int mon_int = 1;
    long mon_long = 2;
    short mon_short = 3;
    float mon_float = 1.1;
    double mon_double = 1.2;
    char mon_char = 'A';
        // Affiche les valeurs des variables définies plus haut
    printf(" int : %d\n long : %ld\n short : %d\n float : %f\n double : %f\n char : %c\n",mon_int,mon_long,mon_short,mon_float,mon_double,mon_char);
        // Utiliser la fonction sizeoff qui mesure le nombre de case mémoire alloué, dans ce cas la, de chaque type.
    printf("taille en octet :\n int : %d\n long : %d\n short : %d\n float : %d\n double : %d\n char : %d\n",sizeof(int),sizeof(long),sizeof(short),sizeof(float),sizeof(double),sizeof(char));
    return 0;
}
