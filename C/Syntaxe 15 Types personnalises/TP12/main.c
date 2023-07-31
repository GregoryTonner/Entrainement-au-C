#include <stdio.h>
#include "media.h"
#include "client.h"

int main() {
    printf("TP 12 Mediatheque\n");

    int choix_media,saisie_utilisateur, choix_client;


// Création de la bibliothèque de média et de nos profils clients
    Media mediatheque[NB_MEDIAS] ={
            { "Programmer pour les Nuls grand format", "Olivier ENGLER et Wallace WANG", LIVRE, 5 },
            { "Apex legends", "Respawn Entertainment", JEUX, 3 },
            { "MATRIX", "Wachowski", FILM, 2 }
    };
    Client clients[NB_CLIENTS] ={
            { "Arnaud", 33 },
            { "Marc", 23 }
    };
//Fin de création de la bibliothèque
    saisie_utilisateur = demandeUtilisateur(saisie_utilisateur);
    do {
        switch (saisie_utilisateur) {   //Je l'utilise pour avoir les différentes options de l'utilisateur
            case 1: // Affichage info client
                for (int i = 0; i < NB_CLIENTS; ++i) {  // Je fais une boucle pour parcourir le tableau complet
                    afficherInfoClient(clients[i]);
                }
                printf("\n\n");
                break;
            case 2: // Affichage info média
                for (int i = 0; i < NB_MEDIAS; ++i) {   // Une boucle pour parcourir et afficher la totalité du tableau
                    afficherInfoMedia(mediatheque[i]);
                }
                printf("\n\n");
                break;
            case 3: // Empreint d'un média
                printf("Quel client etes vous ? \n");       // Identification client
                for (int i = 0; i < NB_CLIENTS; ++i) {  // Affichage différents choix
                    printf("Numero %d\n\t", i);
                    afficherInfoClient(clients[i]);
                }
                scanf("%d", &choix_client);
                fflush(stdin);
                if(choix_client<NB_CLIENTS & choix_client >0) {
                    if (clients->empreintActuel == 0) {
                        printf("Quel media souhaitez vous empreinter ? \n", NB_CLIENTS);
                        for (int i = 0; i < NB_MEDIAS; ++i) {
                            printf("Numero %d\n\t", i);
                            afficherInfoMedia(mediatheque[i]);
                            printf("\n");
                        }
                        scanf("%d", &choix_media);
                        prendreMedia(&mediatheque[choix_media], &clients[choix_client]);
                        printf("\n\n");
                    } else
                        printf("Ce client a deja un empreint en cours\n");
                }else
                    printf("Vous n'avez que %d choix\n",NB_CLIENTS);
                break;
            case 4:
                printf("Quel client etes vous parmis les %d clients \n", NB_CLIENTS);
                scanf("%d", &choix_client);
                fflush(stdin);
                reposerMedia(&clients[choix_client]);
                printf("\n\n");
                break;
            case 5:
                printf("Fin du programme");
                break;
            default:
                printf("Mauvais numero uniquement entre 1 et 5\n\n");
        }
        saisie_utilisateur = demandeUtilisateur(saisie_utilisateur);
    } while (saisie_utilisateur != 5);
    return 0;
}