#include <stdio.h>

int ecritureGrille(char* tab, int x, int y, char joueur, int nb_colonne); // Renvoie 1 si l'écriture est faite, sinon on renvoit 0
void saisieUtilisateur(int* x, int* y);
void affichageGrille(char* tab, int nb_ligne, int nb_colonne);
int victoire (char* tab,int x, int y, char joueur);
int grillePleine(char* tab,char* tab_de_verif,int* compteur);

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
    char tab_de_verif[3][3] =
            {{'_','_','_'},
             {'_','_','_'},
             {'_','_','_'}};
    do {
        do {
            retour_ecriture = 2;
            if (tour_jeu == tour_joueur1) {
                printf("Joueur 1, A quelle position souhaitez vous jouer ? (x,y)\n");
                do {
                    saisieUtilisateur(&coord_x, &coord_y);
                    retour_ecriture = ecritureGrille((char *) tab, coord_x, coord_y, joueur1, nb_colonne);
                    fin_de_parti = victoire((char *) tab, coord_x, coord_y, joueur1);
                    if (retour_ecriture == 1 && fin_de_parti == 0)
                        tour_jeu = tour_joueur2;
                } while (retour_ecriture == 0);
            } else if (tour_jeu == tour_joueur2) {
                printf("Joueur 2, A quelle position souhaitez vous jouer ? (x,y)\n");
                do {
                    saisieUtilisateur(&coord_x, &coord_y);
                    retour_ecriture = ecritureGrille((char *) tab, coord_x, coord_y, joueur2, nb_colonne);
                    fin_de_parti = victoire((char *) tab, coord_x, coord_y, joueur2);
                    if (retour_ecriture == 1 && fin_de_parti ==0)
                        tour_jeu = tour_joueur1;
                } while (retour_ecriture == 0);
            }
            if(fin_de_parti == 0)
            {
                compteur = grillePleine((char*)tab,(char*)tab_de_verif,&compteur);
                if(compteur == 3)
                    fin_de_parti = 1;
            }
            affichageGrille((char *) tab, nb_ligne, nb_colonne);
            printf("\n");
        } while (fin_de_parti != 1);
        if(compteur == 3){
            printf("Match nul, souhaitez vous refaire une partie :\"Y\" or \"N\" ?\n ");
        }
        else if(compteur == 0){
            printf("Bravo, le joueur %d a gagne, souhaitez vous refaire une partie :\"Y\" or \"N\" ?\n",tour_jeu);
        }
        fflush(stdin);
        scanf("%c",&partie);
    } while (partie != 'N');
    return 0;
}

int grillePleine(char* tab,char* tab_de_verif,int* compteur)
{
    int nb_ligne =3;
    int nb_colonne =3;
    for(int i =0;i<nb_ligne;i++)
    {
        char* p_ligne_tab = tab + (i *nb_colonne);
        char* p_ligne_tab_de_verif = tab_de_verif +(i *nb_colonne);
        for(int p=0;p<nb_colonne;p++)
        {
            *(p_ligne_tab_de_verif+p) = *(p_ligne_tab +p);
            if(*(p_ligne_tab_de_verif +p) != '_')
                *compteur += 1;
            else
                return 0;
        }
    }
}
void affichageGrille(char* tab, int nb_ligne, int nb_colonne)
{
    printf("Grille actuelle : \n");
    for(int l=0;l<nb_ligne;l++) // Permet d'afficher la grille des joueurs
    {
        char* p_ligne = tab + (l * nb_colonne);
        printf("\n\t");
        for(int c=0;c<nb_colonne;c++)
            printf("%c\t",*(p_ligne + c));
    }
    printf("\n");
}
void saisieUtilisateur(int* x, int* y)
{
    scanf("%d%d", x, y);
    fflush(stdin);
    printf("x : %d, y : %d\n",*x,*y);
}
int ecritureGrille(char* tab, int x, int y, char joueur, int nb_colonne)
{
    if((x < 1 || x > 3) || (y < 1 || y > 3))
    {
            printf("Rentrez une valeur entre 1 et 3\n");
            return 0;
    }
    x -= 1;
    y -= 1;
    char* p_ligne = tab +(x * nb_colonne);
    char* p_position = p_ligne + y;
    if(*p_position == '_')
    {
        *p_position = joueur;
        return 1;
    }
    else if(*p_position != '_')
    {
        printf("Case deja prise\n");
        return 0;
    }
}
int victoire (char* tab,int x, int y, char joueur)
{
    int nb_colonne = 3;
      switch(x) {
          case 1:
              switch (y) {
                  case 1:
                      if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
                          if (*(tab + ((x + 2) * nb_colonne) + y) == joueur)
                              return 1;
                          else if (*(tab + ((x + 1) * nb_colonne) + y + 1) == joueur)
                              if (*(tab + ((x + 2) * nb_colonne) + y + 2) == joueur)
                                  return 1;
                              else if (*(tab + (x * nb_colonne) + y + 1) == joueur)
                                  if (*(tab + (x * nb_colonne) + y + 2) == joueur)
                                      return 1;
                                  else
                                      return 0;
                      break;
                  case 2:
                      if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
                          if (*(tab + ((x + 2) * nb_colonne) + y) == joueur)
                              return 1;
                          else if (*(tab + (x * nb_colonne) + y + 1) == joueur)
                              if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                                  return 1;
                              else
                                  return 0;
                      break;
                  case 3:
                      if (*(tab + ((x + 1) * nb_colonne) + y - 1) == joueur)
                          if (*(tab + ((x + 2) * nb_colonne) + y - 2) == joueur)
                              return 1;
                          else if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                              if (*(tab + (x * nb_colonne) + y - 2) == joueur)
                                  return 1;
                              else if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
                                  if (*(tab + ((x + 2) * nb_colonne) + y) == joueur)
                                      return 1;
                                  else
                                      return 0;
                      break;
                  default:
                      return 0;
              }
      case 2:
          switch (y) {
              case 1:
                  if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
                      if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                          return 1;
                      else if (*(tab + (x * nb_colonne) + y + 1) == joueur)
                          if (*(tab + (x * nb_colonne) + y + 2) == joueur)
                              return 1;
                          else
                              return 0;
                  break;
              case 2:
                  if (*(tab + ((x + 1) * nb_colonne) + y + 1) == joueur)
                      if (*(tab + ((x - 1) * nb_colonne) + y - 1) == joueur)
                          return 1;
                      else if (*(tab + (x * nb_colonne) + y + 1) == joueur)
                          if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                              return 1;
                          else if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
                              if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                                  return 1;
                  if (*(tab + ((x + 1) * nb_colonne) + y - 1) == joueur)
                      if (*(tab + ((x - 1) * nb_colonne) + y + 1) == joueur)
                          return 1;
                      else
                          return 0;
                  break;
              case 3:
                  if (*(tab + ((x + 1) * nb_colonne) + y) == joueur)
                      if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                          return 1;
                      else if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                          if (*(tab + (x * nb_colonne) + y - 2) == joueur)
                              return 1;
                          else
                              return 0;
                  break;
              default:
                  return 0;
          }
              case 3:
              switch (y) {
                  case 1:
                      if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                          if (*(tab + ((x - 2) * nb_colonne) + y) == joueur)
                              return 1;
                          else if (*(tab + ((x - 1) * nb_colonne) + y + 1) == joueur)
                              if (*(tab + ((x - 2) * nb_colonne) + y + 2) == joueur)
                                  return 1;
                              else if (*(tab + (x * nb_colonne) + y + 1) == joueur)
                                  if (*(tab + (x * nb_colonne) + y + 2) == joueur)
                                      return 1;
                                  else
                                      return 0;
                      break;
                  case 2:
                      if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                          if (*(tab + ((x - 2) * nb_colonne) + y) == joueur)
                              return 1;
                          else if (*(tab + (x * nb_colonne) + y + 1) == joueur)
                              if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                                  return 1;
                              else
                                  return 0;
                      break;
                  case 3:
                      if (*(tab + ((x - 1) * nb_colonne) + y - 1) == joueur)
                          if (*(tab + ((x - 2) * nb_colonne) + y - 2) == joueur)
                              return 1;
                          else if (*(tab + (x * nb_colonne) + y - 1) == joueur)
                              if (*(tab + (x * nb_colonne) + y - 2) == joueur)
                                  return 1;
                              else if (*(tab + ((x - 1) * nb_colonne) + y) == joueur)
                                  if (*(tab + ((x - 2) * nb_colonne) + y) == joueur)
                                      return 1;
                                  else
                                      return 0;
                  default:
                      return 0;
              }
          default:
              return 0;
      }
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