#include <stdio.h>
#include <stdlib.h>

/*
* Le modulo "%" permet de retourner le reste d'une division
* Ex : 5/2 = 2.5, sauf que si on retourne un entier on fera
* 5%2 = 1 car 5/2 retournera 4 (2*2+1 = 5)

   Op�rateur sp�ciale qui peut �tre utilis� sur tous les op�rateurs de base (div, multi, soust et modulo)
    point_vie += 1;
    point_vie ++;
*/


int main()
{
    /*Ce programme permet de lire dans la console l'age de l'utilisateur qui sera rentr�*/
    int age_utilisateur = 0;
    float taille_utilisateur =0.0;
    printf("Salut, quel est ton age et combien mesurez vous ?\n");
    /*La fonction "scanf" permet de lire ce qui est rentr� dans la console, il prend en param�tre
      "%" quelque chose (en fonction de ce que l'on souhaite rentrer) puis on rentre notre variable
      avec comme pr�fixe "&" qui permet de donner l'adresse de la variable et non son nom*/
    scanf("%d%f",&age_utilisateur,&taille_utilisateur);
    printf("Vous avez %d ans et votre taille est de %f m\n",age_utilisateur,taille_utilisateur);
    return 0;
}

/* La priorite sur les op�rateurs : "+" < "-" < "*" < "/" = "%"
__________________________________________________________________________________________________

    int point_vie = 10;
    int potion = 5;
    printf("Nombre de points de vie : %d\n",point_vie);
    // Dans le cas d'un suffixe point de vie = potion et potion s'incr�mente de un apr�s
    // Dans le cas d'un prefixe potion s'incr�mente puis point de vie = potion
    point_vie = ++potion;
    printf("Nombre de points de vie : %d\n",point_vie);
    printf("PDV ajout� de la potion : %d\n",potion);
__________________________________________________________________________________________________

    printf("5 + 3 = %d\n", 5+3);
    printf("5 - 3 = %d\n", 5-3);
    // M�me chose que pour le commentaire en haut, division enti�re donc on fait un arrondi inferieur au r�sultat
    // Pour avoir le bon r�sultat alors il faut que l'on renvoi un "float" ou un "double"
    printf("5 / 3 = %d\n", 5/3);
    printf("5 * 3 = %d\n", 5*3);
  Le caract�re "%" est un caract�re sp�ciale
  Pour dire � notre compilateur que l'on souhaite afficher sans erreur
  on en met deux d'affiler "%%"
  La console retourne donc sans erreur le caract�re "%" dans le printf
  printf("5 %% 3 = %d\n", 5%3);
__________________________________________________________________________________________________
  */


