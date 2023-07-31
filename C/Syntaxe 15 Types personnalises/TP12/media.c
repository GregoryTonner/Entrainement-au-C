//
// Created by SESA583772 on 28/07/2023.
//

#include "media.h"
#include "stdio.h"

void afficherInfoMedia(Media media){
    switch(media.type){
        case 1 :
            printf("Le media correspond a : Livre\n");
            break;
        case 2 :
            printf("Le media correspond a : Musique\n");
            break;
        case 3:
            printf("Le media correspond a : Film\n");
            break;
        case 4:
            printf("Le media correspond a : Jeux\n");
            break;
        default:
            printf("Media pas present dans la mediatheque\n");
    }
    printf("\t Titre : %s\n",media.titre);
    printf("\t Auteur : %s\n",media.auteur);
    printf("\t Il reste : %d exemplaire dans la mediatheque\n",media.nbExemplaire);


}
/*
 * Prendre média
 *
 * Identification client
 * Si client à déjà un empreint
 * alors
 *      Pas possible
 * Sinon
 *      Assigner le media au client
 *
 *
 *      incrémenter variable qui indique qu'un empreint est fait
 *
 * Rendre média
 *
 * Si client n'as pas d'empreint
 * Alors
 *      Pas possible
 * Sinon
 *      Enlever le media au client
 *      décrémenter variable qui indique qu'un empreint est fait
 *
 *
 * */
