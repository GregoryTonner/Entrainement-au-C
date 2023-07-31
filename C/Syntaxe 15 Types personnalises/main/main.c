#include <stdio.h>
#include <string.h>
#include "personnages.h"
#include "exercice_point.h"
#include "arme.h"


int main() {
    printf("Syntaxe 15\n");


/*Test des fonctionnalités de l'ENUM*/
    Classe personnage = CLASSE_MAGE;
    printf("%c est le numero de votre classe\n", personnage);


/*Test des fonctionnalités des struct*/
/*Création des armes*/
    Arme baton = {"Baton tout claque",-12};
    Arme epee = {"Epee rouille",5};
/*Pour le mage*/
    Personnage mage = {"Alibaba", 10, 100, CLASSE_MAGE,baton}; // Première manière de définir les valeurs dans une structure
    affichageStat(mage);
/*Pour le barbare*/
    Personnage barbare; // On créer notre barbare qui prendra en paramètre les variables de la structure personnage
    strcpy(barbare.nom , "Gengis Khan"); // Strcpy permet d'enregistrer une chaine de caractère dans notre tableau
    barbare.pv = 30;
    barbare.mana = 10;
    barbare.classe = CLASSE_BARBARE;
    barbare.arme = epee;
    affichageStat(barbare);

    equiperArme(&barbare,baton);


/*Exercice sur le calcule de la distance entre deux points*/
   /* Point A ={1.00,0.00};   // On déclare et définit notre premier structure, le point A
    Point B ={12.20,3.00}; // On déclare et définit notre deuxième structure, le point B

    printf("Point A = %f , %f\n",A.x,A.y);  // On affiche la position de A
    printf("Point B = %f , %f\n",B.x,B.y); // On affiche la position de B
    printf("\tDistance AB = %f",calculeDistance(A,B));  // On affiche la distance entre le point A et B*/

    return 0;
}
