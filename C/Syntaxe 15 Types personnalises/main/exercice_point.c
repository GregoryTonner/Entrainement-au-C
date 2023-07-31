//
// Created by SESA583772 on 27/07/2023.
//

#include "exercice_point.h"
#include "math.h"

float calculeDistance (Point A, Point B){   // On met en paramètre une structure pour avoir accès aux 2 points de coordonnées

    float resulat;  // on créer notre variable résultat qui va stocké la distance entre les deux points
    resulat = sqrtf(powf(B.x - A.x, 2) + powf(B.y - A.y, 2)); // sqrtf permet de faire la raciné carré d'un float et powf permet d'élevé à la puissance que l'on veut un float

    return resulat; // On renvoit le résultat

}