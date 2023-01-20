#include <stdio.h>
#include <stdlib.h>

/*
* Le modulo "%" permet de retourner le reste d'une division
* Ex : 5/2 = 2.5, sauf que si on retourne un entier on fera
* 5%2 = 1 car 5/2 retournera 4 (2*2+1 = 5)

   Opérateur spéciale qui peut être utilisé sur tous les opérateurs de base (div, multi, soust et modulo)
    point_vie += 1;
    point_vie ++;
*/


int main()
{

    return 0;
}

/* La priorite sur les opérateurs : "+" < "-" < "*" < "/" = "%"
__________________________________________________________________________________________________

    int point_vie = 10;
    int potion = 5;
    printf("Nombre de points de vie : %d\n",point_vie);
    // Dans le cas d'un suffixe point de vie = potion et potion s'incrémente de un après
    // Dans le cas d'un prefixe potion s'incrémente puis point de vie = potion
    point_vie = ++potion;
    printf("Nombre de points de vie : %d\n",point_vie);
    printf("PDV ajouté de la potion : %d\n",potion);
__________________________________________________________________________________________________

    printf("5 + 3 = %d\n", 5+3);
    printf("5 - 3 = %d\n", 5-3);
    // Même chose que pour le commentaire en haut, division entière donc on fait un arrondi inferieur au résultat
    // Pour avoir le bon résultat alors il faut que l'on renvoi un "float" ou un "double"
    printf("5 / 3 = %d\n", 5/3);
    printf("5 * 3 = %d\n", 5*3);
  Le caractère "%" est un caractère spéciale
  Pour dire à notre compilateur que l'on souhaite afficher sans erreur
  on en met deux d'affiler "%%"
  La console retourne donc sans erreur le caractère "%" dans le printf
  printf("5 %% 3 = %d\n", 5%3);
__________________________________________________________________________________________________
  */


