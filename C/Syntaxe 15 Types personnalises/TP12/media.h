//
// Created by SESA583772 on 28/07/2023.
//

#ifndef TP12_MEDIA_H
#define TP12_MEDIA_H

#define NB_MEDIAS 3
#define NB_CLIENTS 2
typedef enum TYPE{
    LIVRE = 1,
    MUSIQUE,
    FILM,
    JEUX
}Type;
typedef struct st_media{
    char titre [200];
    char auteur[50];
    int type;
    int nbExemplaire;
}Media;

void afficherInfoMedia(Media);

#endif //TP12_MEDIA_H
