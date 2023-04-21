#include <stdio.h>

int ecritureGrille(char* tab, int x, int y, char joueur, int nb_colonne); // Ecrit dans la tab le caractère correspondant au joueur qui vient de jouer
void saisieUtilisateur(int* x, int* y); // Récupère la saisie de l'utilisateur, dans le but de retourner la position à laquelle il souhaite écrire dans la tab
void affichageGrille(char* tab, int nb_ligne, int nb_colonne);  // On affiche le contenu de la tab
int victoire (char tab[][3],char joueur); // On recherche un cas de victoire (Autre méthode de code pour cette fonction dans la correction du TP)
int grillePleine(char* tab,int* compteur);  // Permet de déterminer si la tab est pleine ou non

int main() {
    printf("TP 10 Jeu du Morpion\n");

    int fin_de_parti = 0, compteur=0;
    char partie = 'Y';
    char joueur1 ='X', joueur2 ='O';
    int tour_jeu = 1, tour_joueur1 = 1, tour_joueur2 = 2;
    int nb_colonne = 3, retour_ecriture, nb_ligne = 3;
    int coord_x, coord_y;
    char tab[3][3] =
            {{'_','_','_'},
             {'_','_','_'},
             {'_','_','_'}};
    do {
        do {
            retour_ecriture = 2;    // retour écriture confirme que le joueur à écrit dans le tableau et on passe au joueur suivant si c'est le cas
            if (tour_jeu == tour_joueur1) { // On commence par le joueur 1
                printf("Joueur 1, A quelle position souhaitez vous jouer ? (x,y)\n");
                do {
                    saisieUtilisateur(&coord_x, &coord_y);  // On effectue la saisie utilisateur
                    retour_ecriture = ecritureGrille((char *) tab, coord_x, coord_y, joueur1, nb_colonne);  // On récupère la valeur 1 si le joueur a écrit dans le tableau sinon 0
                    fin_de_parti = victoire(tab, joueur1);   // On cherche un cas de victoire, si oui alors "fin_de_parti" = 1 sinon 0
                    if (retour_ecriture == 1 && fin_de_parti == 0)  // Si on a bien écrit et que la partie n'est pas fini
                        tour_jeu = tour_joueur2;    // On passe au tour du joueur 2
                } while (retour_ecriture == 0);     // On boucle tant que le joueur 1 n'a pas rentré une position valide pour écrire
            } else if (tour_jeu == tour_joueur2) {  // Tour du joueur 2 de jouer
                printf("Joueur 2, A quelle position souhaitez vous jouer ? (x,y)\n");
                do {
                    saisieUtilisateur(&coord_x, &coord_y);
                    retour_ecriture = ecritureGrille((char *) tab, coord_x, coord_y, joueur2, nb_colonne);
                    fin_de_parti = victoire(tab,  joueur2);
                    if (retour_ecriture == 1 && fin_de_parti ==0)
                        tour_jeu = tour_joueur1;
                } while (retour_ecriture == 0);
            }
            if(fin_de_parti == 0)   // Si la partie n'est pas terminée
            {
                compteur = grillePleine((char*)tab,&compteur); // On vérifie que la tab ne soit pas complète grace au compteur
                printf("\nCompteur : %d partie\n",compteur);
                if(compteur != 0)                               // Si le compteur est différent de 0 alors ça veut dire que la tab est pleine
                    fin_de_parti = 1;                           // Donc, on met fin à la partie
            }
            affichageGrille((char *) tab, nb_ligne, nb_colonne);    // On affiche la tab à la fin de chaque tour de jeu
            printf("\n");
        } while (fin_de_parti != 1);                                // On boucle tant que la partie n'est pas fini
        if(compteur != 0){                                          // Si la partie est finie et que le compteur est différent de 0 on dit que c'est un match nul et on propose de refaire une partie
            printf("\nCompteur : %d quand nul\n",compteur);
            printf("Match nul, souhaitez vous refaire une partie :\"Y\" or \"N\" ?\n ");
        }
        else if(compteur == 0){                                     // Si la partie est finie, mais que le compteur = 0 alors ca veut dire qu'un des joueurs a gagné
            printf("Bravo, le joueur %d a gagne, souhaitez vous refaire une partie :\"Y\" or \"N\" ?\n",tour_jeu);  // On annonce le gagnant et on propose de faire une nouvelle partie
        }
        fflush(stdin);
        scanf("%c",&partie);    // Récupération de la saisie utilisateur pour savoir si il veut rejouer ou non
    } while (partie != 'N');    // On boucle tant que l'utilisateur ne retourne pas la lettre "N" pour dire "Non"
    return 0;   // Fin programme
}

int grillePleine(char* tab,int* compteur)
{
    int nb_ligne =3;
    int nb_colonne =3;
    for(int i =0;i<nb_ligne;i++) // On parcours notre tableau
    {
        char* p_ligne_tab = tab + (i *nb_colonne);  // On créer un pointeur vers notre ligne
        for(int p=0;p<nb_colonne;p++)
        {
            if(*(p_ligne_tab +p) == '_')    // Si toutes les cases sont différentes d'une case vide alors on compte
                return 0;
        }
    }
    return 1;   // Sinon on retourne 0 pour indiquer que la partie n'est pas fini
}
void affichageGrille(char* tab, int nb_ligne, int nb_colonne)
{
    printf("Grille actuelle : \n");
    for(int l=0;l<nb_ligne;l++) // Permet d'afficher la tab des joueurs
    {
        char* p_ligne = tab + (l * nb_colonne);         // On parcours notre tableau dans le but d'afficher chaque caractère aux utilisateurs
        printf("\n\t");
        for(int c=0;c<nb_colonne;c++)
            printf("%c\t",*(p_ligne + c));
    }
    printf("\n");
}
void saisieUtilisateur(int* x, int* y)
{
    scanf("%d%d", x, y);        // Lecture et enregistrement de la saisie utilisateur
    fflush(stdin);
}
int ecritureGrille(char* tab, int x, int y, char joueur, int nb_colonne)
{
    if((x < 1 || x > 3) || (y < 1 || y > 3))            // Si les valeurs entrées ne sont pas comprise entre 0 et 3
    {
        printf("Rentrez une valeur entre 1 et 3\n");    // Alors on retourne une erreur de saisie
        return 0;
    }
    x -= 1;                                             // -1 pour que l'utilisateur puisse considérer la première case = 1
    y -= 1;
    char* p_ligne = tab +(x * nb_colonne);
    char* p_position = p_ligne + y;                     // Pointeur vers la position choisir par l'utilisateur
    if(*p_position == '_')                              // Si la position est vide alors on écrit
    {
        *p_position = joueur;
        return 1;
    }
    else if(*p_position != '_')                         // Sinon on retourne que la case est déjà prise
    {
        printf("Case deja prise\n");
        return 0;
    }
}
int victoire (char tab[][3],char joueur){
    // test des lignes
    for(int x=0; x<3; x++)
    {
        if(tab[x][0] == joueur && tab[x][1] == joueur && tab[x][2] == joueur)
            return 1;
    }

    // test des colonnes
    for(int y=0; y<3; y++)
    {
        if(tab[0][y] == joueur && tab[1][y] == joueur && tab[2][y] == joueur)
            return 1;
    }

    //test de la diagonale
    if(tab[0][0] == joueur && tab[1][1] == joueur && tab[2][2] == joueur)
        return 1;

    //test de la diagonale inverse
    if(tab[2][0] == joueur && tab[1][1] == joueur && tab[0][2] == joueur)
        return 1;


    return 0;
}

/* ** Algo pour la fin de partie **
 *
 * On lit la position ou le joueur à écrit
 * On compare si ça fait parti du tableau, les caractère autour de la position ou on a écrit (haut, bas, droite, gauche, diagonale haute et basse à droite et à gauche)
 * si une des position est egale au caractère du même joueur,
 *  alors
 *      on refait la même comparaison dans la même direction en partant de celle analysé la dernière fois, si cette position ne fait pas partie du tableau
 *       alors
 *           on retourne sur la position d'écriture et on lit la case qui est à l'inverse de la première position que l'on a analysé
 *           si les trois caractère sont les même
 *              alors
 *                  Le joueur à gagné, sinon on peut continuer le jeux.
 *
 *  On fait cette analyse à chaque écriture dans le tableau.
 *
 * char* p_position_lire = p_position -1 (Gauche) / p_position +1 (Droite) / tab +((x-1)*nb_colonne)+y (haut) / tab +((x+1)*nb_colonne)+y (bas)
 * tab +((x-1)*nb_colonne)+y-1(diagonale haut gauche)/tab +((x-1)*nb_colonne)+y+1(diagonale haut droite)/tab +((x+1)*nb_colonne)+y-1(diagonale bas gauche)/
 * tab +((x+1)*nb_colonne)+y+1 (diagonale bas droite)
 *
 * Si (p_position_lire == joueur) (A refaire pour chaque valeur de p_position_lire)
 * alors
 *  si( p_position_lire +1 == joueur)(sur x ou y ou les deux en fonction de la direction que l'on a prit de base)
 *    alors
 *      return 1;
 *  sinon si(p_position_lire + 1 != joueur)
 *   alors
 *     si(p_position_lire - 1 == joueur)
 *      alors
 *          return 1;
 *     sinon
 *      return 0; (faire attention au return 0 car elle stop la fonction sans chercher à faire le reste, favoriser
 *                  une variable compteur qui permettra de finalement une fois chaque cas étudié, de renvoyer soit
 *                  1 soit 0)
 *
 *  switch(x)
 *   case 1:
 *      switch(y)
 *      case 1:
 *          si(*(tab + ((x + 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x + 2) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + ((x + 1) * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + ((x + 2) * nb_colonne) + y + 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y + 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *      case 2:
 *          si(*(tab + ((x + 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x + 2) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y - 1) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *      case 3:
 *          si (*(tab + ((x + 1) * nb_colonne) + y - 1) == joueur)
 *             alors
 *                  si(*(tab + ((x + 2) * nb_colonne) + y - 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y - 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y - 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x + 2) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *   break;
 *   case 2:
 *     switch(y)
 *      case 1:
 *          si (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x - 1) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y + 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *      case 2:
 *          si (*(tab + ((x + 1) * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + ((x - 1) * nb_colonne) + y - 1) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y - 1) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x - 1) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          si (*(tab + ((x + 1) * nb_colonne) + y - 1) == joueur)
 *             alors
 *                  si(*(tab + ((x - 1) * nb_colonne) + y + 1) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *      case 3:
 *          si (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x - 1) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y - 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y - 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *   break;
 *   case 3;
 *     switch(y)
 *      case 1:
 *          si(*(tab + ((x - 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x - 2) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + ((x - 1) * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + ((x - 2) * nb_colonne) + y + 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y + 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *      case 2:
 *          si(*(tab + ((x - 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x - 2) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y + 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y - 1) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *      break;
 *      case 3:
 *          si (*(tab + ((x - 1) * nb_colonne) + y - 1) == joueur)
 *             alors
 *                  si(*(tab + ((x - 2) * nb_colonne) + y - 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + (x * nb_colonne) + y - 1) == joueur)
 *             alors
 *                  si(*(tab + (x * nb_colonne) + y - 2) == joueur)
 *                      alors
 *                          return 1;
 *          sinon si (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
 *             alors
 *                  si(*(tab + ((x - 2) * nb_colonne) + y) == joueur)
 *                      alors
 *                          return 1;
 *          sinon
 *              return 0;
 *   break;
 * */
