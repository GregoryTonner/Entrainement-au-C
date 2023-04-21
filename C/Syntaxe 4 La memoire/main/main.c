#include <stdio.h>
#include <stdlib.h>
/*
* Le char est compris entre -128 et 127
* De 0 à 127 cela correspond à la décimale des caractère en ASCII
* Pour la partie négatif, cela correspond à un calcul que l'on appel "Bit de complément à 1"
* Et "Bit de complément à 2", "à 1" permet de passer un nombre négatif en positif et inversement pour "à 2"
* Voir sur internet : Pour -4 on prend la valeur 4 en binaire, on inverse tous les bits
* et on ajoute 1.
*/
/* ***EXO 1 ***
int main()
{
            // Les variables une fois déclaré sont stocké dans la RAM jusqu'a ce qu'elle soit détruite
            // Chaque type de variable a une taille différentes, "int" prend soit 2 soit 4 octets en fonction de l'OS et du compilateur que l'on utilise
    int age_utilisateur = 20, taille_utilisateur = 180;

        // On affiche les deux variables, %d permet de dire a notre compilateur que l'on va remplacer le %d par la variable qui suit
    printf("L'age de l'utilisateur est : %d\n",age_utilisateur);
    printf("Sa taille est de : %d cm",taille_utilisateur);

    return 0;
}
*/
int main()
{
    int mon_int = 12;
            // Dans notre cas le int utilise 4 octets de mémoire
    printf("mon int : %d et prend en memoire : %d octets\n",mon_int,sizeof(int));
            // Les types "short" et "long" ne fonctionne que pour les entiers donc pas besoin d'ajouter le "int" derrière ou devant
    short mon_short = 12;
    printf("mon short int : %d et prend en memoire : %d octets\n",mon_short,sizeof(short));

    long mon_long = 2147483647;
    printf("mon long int : %ld et prend en memoire : %d octets\n",mon_long,sizeof(long));

            // unsigned permet d'étendrde le plage de valeur maximal pour les valeurs positive
    unsigned int mon_int_non_signe = 12;
    printf("mon unsigned int : %d et prend en memoire : %d octets\n",mon_int_non_signe,sizeof(unsigned int));

            // Exemple de valeur étendu : = ex: -128 <= char <= 127, 0 <= unsigned char <= 255 (valeur correspondant à la valeur décimal des caractère en ASCII)
    char mon_char = '@';
    printf("mon char : %c et prend en memoire : %d octets\n", mon_char, sizeof(char));

    unsigned char mon_char_non_signe = 'A';
    printf("mon unsigned char : %c et prend en memoire : %d octets\n", mon_char_non_signe, sizeof(unsigned char));

    float mon_float = 3.416;
    printf("mon float : %f et prend en memoire : %d octets\n",mon_float, sizeof(float));

    double mon_double = 12.96587;
    printf("mon double : %f et prend en memoire : %d octets\n",mon_double, sizeof(double));

    return 0;
}
