#include <stdio.h>
#include "stdlib.h"
#include "string.h"

int main() {

    const int TAILLE_TABLEAU =100;
    char nom[TAILLE_TABLEAU];

    printf("Comment tu t'appelles ? ");
    fgets(nom,TAILLE_TABLEAU,stdin); // Permet de lire dans stdin la saisie utilisateur dans la limite de "x" caractère définie graca à TAILLE_TABLEAU et à l'écrire dans le tableau "nom"

    printf("Bonjour, %s",nom);

    return 0;
}
/*      STRLEN / STRCHR / STRCMP
 * strlen permet de renvoyer la taille d'un string
 * strchr qui permet de rechercher un caractère dans un string
 * strcmp permet de comparer deux chaines de caractère pour savoir si elle sont identique ou non
 *
 *  char salut[] = "salut";                      // Permet d'utiliser les tableau comme une chaine de caractère (uniquement si on met "\0" à la fin
    char prenom[100];
    char* p_char =NULL;
    char mot_a_cherche ='t';


    printf("%s quel est ton prenom ?",salut);   // %s permet d'afficher ou de récupérer une chaine de caractère
    scanf("%s",prenom);
    fflush(stdin);                              // Nettoie la console dans le but de ne pas avoir de caractère parasite
    p_char = strchr(prenom, mot_a_cherche);               // "Strchr" Un pointeur vers un char = fonction de recherche d'un caractère dans un tableau de char (Renvoie l'adresse de ce caractère)
    printf("La taille de notre string est de : %llu\n",strlen(prenom));   // "Strlen" renvoie la taille de notre chaine de caractère (%llu = unsigned long long)
    if(*p_char == mot_a_cherche)
    {
        printf("Le caractere %c se trouve a %p adresse dans le message %s\n",*p_char, p_char,prenom);   // Lecture de la valeur et de l'adresse de notre pointeur
    }
    else
    {
        printf("Le caractere %c n'est pas présent dans le message %s\n",mot_a_cherche,prenom);
    }
    switch (strcmp(prenom,salut)) { // strcmp compare deux string et renvoie 3 valeurs
        case (0):   // 0 si les deux chaines sont les même
            printf("Les deux mots %s et %s sont les meme", prenom, salut);
            break;
        case (1): // 1 Si la première chaine est supérieur à la deuxième
            printf("%s est alphabetiquement superieur a %s", prenom,salut);
            break;
        case (-1): // -1 si la deuxième est superieur à la première
            printf("%s est alphabetiquement superieur a %s",salut,prenom);
            break;
        default:
            printf("Message non lu");
    }*/
/*  STRCPY / STRCAT / STRTOL / STRDOL
 *     char message[100] ="Salut";
    printf("mon message = %s\n",message);

    strcpy(message,"1256.4"); // "strcpy"(string copy) permett de copier le message "toto" à la place de l'ancien message dans le tableau "message"
    printf("Nouveau message = %s\n",message);
    strcat(message," et tata"); // "strcat"(string concatener) permet d'ajouter à la suite de notre chaine de caractère le message "et tata"
    printf("Nouveau message = %s\n",message);
    printf("%ld\n",strtol(message,NULL,10)); // Permet de convertir une chaine de caractère en une valeur numérique en base 10 (On peut renvoyer en binaire ou hexa)
    printf("%f\n",strtod(message,NULL));// Permet de faire la même chose que "strtol" mais avec des nombres à virgules
 * */
/*     SPRINTF
 *     int parametre = 500;
    char template[100] = "Votre prix = %d";
    char destination[100];
    -
    sprintf(destination,template,parametre); // Permet d'écrire dans un tableau en rentrant les paramètres que l'on souhaite, c'est un printf que l'on affiche pas dans le terminal, juste on vient écrire dans un tableau
    printf("%s\n",destination);
    sprintf(destination,"J'ai %d ans et je vis a %s avec mes %d enfants",45,"Paris",5); // S'écrit comme un printf à la seule différence que l'on met en premier paramètre de la fonction le tableau de destination
    printf("%s\n",destination);
    return 0;
 * */