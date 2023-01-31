#include <stdio.h>

int main() {

    const int TAILLE_TAB = 5;
    char mon_tableau[] = {'C','A','T','O','I'};
    printf("*** Normal ***\n");
    for(int i=0;i<TAILLE_TAB;i++)   // Tous connaitre du tableau de manière conventionnelle
    {
        printf("\tmon_tableau[%d] = %c (%p)\n",i,mon_tableau[i],&mon_tableau[i]); // %d pour l'index du tableau, %c car un tableau de char, %p car adresse de l'index
    }
    printf("*** Avec poiteur ***\n");
    for(int i =0;i<TAILLE_TAB;i++)  // Tout connaitre du tableau à travers les poiteurs
    {
        printf("\t*(mon_tableau + %d) = %c (%p)\n",i,*(mon_tableau + i),mon_tableau + i);
    }
    // Test
    return 0;
}
