//
// Created by SESA583772 on 21/08/2023.
//

#include "stdio.h"
#include "stdlib.h"
#include "EcritureFichier.h"

void modificationScore(char* path, char* name,long score){

    FILE *pt_fichier = fopen(path,"r+");
    rewind(pt_fichier);
    if(getc(pt_fichier) == '1'){
        fseek(pt_fichier,11,SEEK_SET);
        long scoreEnregistre = 0;
        fgets(pt_fichier,10,&scoreEnregistre);
        if(scoreEnregistre < score){
            fseek(pt_fichier,-10,SEEK_CUR);
            fputs(name,pt_fichier);
            fseek(pt_fichier,10,SEEK_CUR);
            fprintf(pt_fichier,"%d",score);
        }
    }
    else if(getc(pt_fichier) != '1' && getc(pt_fichier)!= EOF){
        fseek(pt_fichier,11,SEEK_CUR);
    }
    else if(getc(pt_fichier)==EOF){
        fputc('1',pt_fichier);
        fputs(name,pt_fichier);
        fprintf(pt_fichier,"%d\n",score);
    }
    fclose(pt_fichier);
}
/*
 * Liste chainées !!
 *
 *  5 structure players (1 à 5)
 *  Nom
 *  Score
 *
 *  lire le fichier
 *  récup nom et score à chaque position
 *  stocker dans nos différentes structure en fonction de la postion de chacun
 *
 * */