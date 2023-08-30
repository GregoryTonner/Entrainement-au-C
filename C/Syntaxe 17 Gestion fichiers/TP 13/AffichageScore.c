//
// Created by SESA583772 on 21/08/2023.
//
#include "stdio.h"
#include "AffichageScore.h"

void affichageScore(int position,char nomScore[10], int score){

        printf("|_______________________________|\n");
        printf("|%d|\t%s\t  |%d|\n",position,nomScore,score);

}