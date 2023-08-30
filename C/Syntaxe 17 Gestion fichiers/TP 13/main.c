#include "stdio.h"
#include "stdlib.h"
#include "AffichageScore.h"
#include "EcritureFichier.h"

#define TAILLE_LISTE 5
#define TAILLE_MAX_NOM 10

typedef struct HIGHT_SCORE
{
    char nom[TAILLE_MAX_NOM];
    long score;
}hightScore;

int main()
{
    char *path = "../data/HighScore.txt";
    char* bufferScore;
    hightScore player[TAILLE_LISTE];
    FILE* pt_fichier = fopen(path,"r+");
    rewind(pt_fichier);

  /*  for (int i = 0; i < TAILLE_LISTE; ++i) {
        for (int j = 0; j < TAILLE_MAX_NOM; ++j) {
            player[i].nom[j] = '_';
        }
        player[i].score = 0;
    }*/
    printf("|\t Tableau des scores\t|\n");
    printf("|\tRank  |\tName  |\tScore\t|\n");
    for (int i = 1; i < 3; ++i) {
        fgets(player[i].nom,10,pt_fichier);
        fgets(bufferScore,6  ,pt_fichier);
        strtol(bufferScore,NULL,player[i].score);
        fseek(pt_fichier,3,SEEK_CUR);
        affichageScore(i,player[i].nom,player[i].score);

    }
    fclose(pt_fichier);



    return 0;


}

/*
 * Récupération du nom du joueur
 * Récupération du score du joueur
 *
 * Ouverture du fichier
 *
 * Comparaison du score avec le top 5
 * Si (pas de nom dans le tableau des scores)
 *  Alors
 *      Ecriture du nom et du score en première position
 * Sinon Si (au moins un nom et score dans le tableau)
 *  Alors
 *      Pour (position score lu = 0; position score lu < TAILLE_LISTE; position score lu++)
     *      Comparaison du score actuelle avec les scores enregistré
     *      Si (score actuel > au score en cours de lecture)
     *          Alors
     *              Lecture position dans le classement
     *              Effacer le 5ème top
     *              Descendre les scores enregistrer d'une position dans le classement (A partir de la position lu)
     *              Ecrire le score actuel à la position lu
     *              break
 *
 * Fermeture du fichier
 *
 * */
