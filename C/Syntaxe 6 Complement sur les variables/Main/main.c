#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float pi = M_PI; // "M_PI" est inclus dans la librairie "math.h" et c'est une variable déclaré de base.

    printf("Le nombre pi est egale a :%f\n",pi);

    printf("cos(PI) = %f\n",cos(M_PI)); // On peut aussi utiliser : sin, tan, arcsin, arcos etc..
    printf("Valeur absolu de %f = %f\n",cos(M_PI),fabs(cos(M_PI))); // fabs permet d'afficher la valeur absolu d'un nombre


    /*         "round" affiche l'arrondi d'un nombre
       Mais attention, quand le nombre est négatif il fait un arrondi superieur
       si le nombre est posifif alors il fait un arrondi inferieur
       Tous les arrondi renvoie un double
    */
    printf("Valeur arrondi de %f = %d\n",12.6,(int)round(12.4));
    printf("Entier inferieur de %f = %d\n",-12.6,(int)floor(-12.4)); // "floor" affiche l'arrondi inferieur d'un nombre
    printf("Entier inferieur de %f = %d\n",-12.6,(int)ceil(-12.4)); // "ceil" affiche l'arrondi superieur d'un nombre

    // "pow" permet d'elever à le puissance un nombre par un autre nombre, ici 4 puissance 2 (renvoie un double)
    printf("4^2 = %d\n",(int)pow(4,2));
    printf("Racine carre de %d = %d\n",9,(int)sqrt(9)); // "sqrt" fait la racine carré d'un nombre (renvoie un double)
    return 0;
}

/*
    On peut utiliser l'overflows dans le but de reset la valeur d'une variable
    comme dans le jeux PacMan où si on sort de l'écran à droite et apparait à gauche
    pareil en haut et en bas, CàD que si on atteind la valeur max d'un type alors on
    revient à 0 et on recommence normalement

*** Code à utiliser pour la démonstration ***
    unsigned long mon_long = 65535;
    unsigned short mon_short = 0;

    mon_short -= 10;

    printf("Mon short = %d\n",mon_short);
    printf("Mon long = %ld",mon_long);
*/
/*
    // Transtypage non explicite des variables (A ne pas utiliser car risque d'erreur)

    int mon_int = 64;
    char mon_char ='B';
    printf("Ma valeur = %d, mon caractere est = %c en ASCII\n",mon_int,mon_int);

    printf("Ma valeur = %d, mon caractere est = %c en ASCII",mon_char,mon_char);
______________________________________________________________________________________
    // Transtypage explicite des variable, on demande à notre PC de volontairement transformer un type de donnée en
    // un autre type

    int nombre1=5, nombre2=2;

    printf("%d / %d  = %f\n",nombre1, nombre2, (float)nombre1/(float)nombre2);
*/
/*
        Calcul de convertion de l'euros vers le dollars
        Avec une variable constante (qui n'est pas modifiable dans le code)
*/
/*
   const float TAUX_CHANGE = 1.14;
   float valeur_euros =0.0, valeur_dollars =0.0;

   printf("Convertir de l'euros vers le dollars !\n");
   printf("Veuillez rentrer votre prix en euros :\t");
   scanf("%f",&valeur_euros);

   valeur_dollars = valeur_euros * TAUX_CHANGE;

   printf("\n Pour %f euros vous aurez %f dollars",valeur_euros,valeur_dollars);




   /* Bien faire attention à l'endroit ou est déclaré notre variable
    Pour savoir si elle est local (à une fonction) ou globale dans notre code*/
/*
    int age =0;

    int main()
    {
        printf("Age = %d",age);
        return 0;
    }
*/
