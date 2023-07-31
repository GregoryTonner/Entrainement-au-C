//
// Created by SESA583772 on 28/07/2023.
//

#include "client.h"
#include "stdio.h"

void afficherInfoClient(Client client){

    printf("%s a %d ans\n",client.nom, client.age);
    printf("Il a deja empreinte %d fois dans le mediatheque\n",client.empreint);
    if(client.empreintActuel == 1)
    {
        afficherInfoMedia(*client.mediaClient);
    }else
        printf("Pas d'empreint en cours");
}
void prendreMedia(Media* media,Client* client){
    media->nbExemplaire = media->nbExemplaire - 1;
    client->empreint = client->empreint + 1;
    client->empreintActuel =1;
    client->mediaClient = media;
}
void reposerMedia(Client* client){
    if(client->empreintActuel == 1){
        client->mediaClient->nbExemplaire = client->mediaClient->nbExemplaire + 1;
        client->empreintActuel =0;
        client->mediaClient =NULL;
    }
    else
        printf("Ce client n'a pas d'empreint a rendre\n");
}
int demandeUtilisateur(int saisie_utilisateur){
    printf("Veuillez entrer votre choix :\n");
    printf("\t1 - Afficher les information client\n");
    printf("\t2 - Afficher les produits dans la mediatheque\n");
    printf("\t3 - Empreinter un produit\n");
    printf("\t4 - Rendre un produit\n");
    printf("\t5 - Sortir\n");
    scanf("%d", &saisie_utilisateur);
    fflush(stdin);
    return saisie_utilisateur;
}
