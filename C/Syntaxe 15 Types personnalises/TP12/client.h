//
// Created by SESA583772 on 28/07/2023.
//

#ifndef TP12_CLIENT_H
#define TP12_CLIENT_H
#include "media.h"
typedef struct st_client{
    char nom[50];
    int age;
    int empreint;
    int empreintActuel;
    Media* mediaClient;
}Client;

void afficherInfoClient(Client client);
int demandeUtilisateur(int);
void prendreMedia(Media*,Client*);
void reposerMedia(Client*);
#endif //TP12_CLIENT_H
