#include <stdio.h>
/*
 * Les macros sont, les defines sont utilisées dans le préprocesseur et donc avant la compilation
 * cela permet que l'on puisse utiliser des sortes de fonction sans utiliser des cases mémoires
 * Le préprocesseur remplace le nom que nous avons choisi sur notre define par la valeur qui lui correspond.
 * */
#define DOUBLER(x) ((x)*2)
#define MAX(x,y)((x>y)?(x):(y)) // On test la condition si x > y alors on renvoie x sinon on renvoi y
#define MIN(x,y)((x>y)?(y):(x)) // Ici ont fait l'inverse de l'autre macro

#define MAJEUR(age) \
    if(age >= 18)       \
        printf("Vous etes majeur"); \
    else                \
        printf("Vous n'etes pas majeur"); // Créer une macro qui permet de savoir si on est majeur en entrant un paramètre
                                          // Toujours mettre en fin de ligne le caractère "\" qui permet de determiner si la prochaine ligne fait partie de la macro

int main() {

    int bonus = 20;
    int x = 50;
    int y = 6;
    bonus = DOUBLER(bonus);
    printf("Bonus : %d\n",bonus);
    printf("Max : %d et le Min : %d\n",MAX(x,y), MIN(x,y));
    MAJEUR(15)
    return 0;
}
/*
#define TAILLE_TABLEAU 10
#define NUM_VERSION "VO1R00"
#define CONVERTION_J_TO_H 24
#define CONVERTION_H_TO_MIN 60
#define NB_MIN_PAR_JOUR (CONVERTION_J_TO_H*CONVERTION_H_TO_MIN)
#define DEBUG

    int nb_jour =0;
    int nb_minute;
    int age_utilisateur;
    int qi_utilisateur;

        #ifdef NUM_VERSION
            printf("Version : %s\n",NUM_VERSION);
        #else
            printf("Version inconnu\n");
        #endif

        printf("Entree votre Age et votre QI\n");

        #ifdef DEBUG // Permet de créer une condition IF dans le cas ou "DEBUG" est défini dans notre code
            printf("DEBUG MODE\n");
            age_utilisateur = 21;
            qi_utilisateur = 150;
        #else       // Si DEBUG n'est pas définit alors on demande à l'utilisateur d'entrer son age et son QI
            scanf("%d%d",&age_utilisateur,&qi_utilisateur);
        #endif

        printf("Vous avez %d ans et un QI de %d",age_utilisateur,qi_utilisateur);   // On l'affiche quoi qu'il arrive
        printf("Veuillez rentrer le nombre de jour que vous souhaitez convertir");
        scanf("%d",&nb_jour);

        nb_minute =  nb_jour*NB_MIN_PAR_JOUR ;

        printf("%d jour correspond a %d minutes\n",nb_jour,nb_minute);*/
