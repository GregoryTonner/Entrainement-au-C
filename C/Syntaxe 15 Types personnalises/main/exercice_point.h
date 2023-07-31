//
// Created by SESA583772 on 27/07/2023.
//

#ifndef MAIN_EXERCICE_POINT_H
#define MAIN_EXERCICE_POINT_H

typedef struct POINT{   // On créer notre structure en typedef pour simplifier son utilisation pour la suite
    float x;
    float y;
}Point; // Point nous permettra d'identifier notre structure plus simplement dans le main.c


float calculeDistance (Point,Point);
#endif //MAIN_EXERCICE_POINT_H
