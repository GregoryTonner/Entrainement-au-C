#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Exercice Variable Dynamique\n");
// On alloue dynamique de la mémoire en fonction de la saisie utilisateur dans la limite de la taille d'un int
    int* p_age = (int*)malloc(sizeof(int));
    if(p_age != NULL){
        scanf("%d",p_age);
        printf("Vous avez %d ans, stocke a %p adresse\n",*p_age,p_age);
        free(p_age);
    }


    return 0;
}
