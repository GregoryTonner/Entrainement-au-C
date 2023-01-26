#include <stdio.h>
#include <stdlib.h>

/*
    faire
        lecture saisie d'un nombre entre 1 et 10
        pour(i=0;i<=10;i++)
            valeur_final = saisie_utilisateur * i
            ecrire(valeur_final)
*/
int main()
{
    /*** Table automatique ***/
    for(int id_table;id_table<=10;id_table++)
    {
        printf("Table de %d\n", id_table);
        for(int multiplicateur=0; multiplicateur<=10;multiplicateur++)
        {
            printf("\t%d * %d = %d\n",id_table,multiplicateur, id_table*multiplicateur);
        }
    }
    return 0;
}


    /*** Table sur saisie de l'utilisateur ***/
/*
    int saisie_utilisateur=0, valeur_final =0;
    char sortie_programme;


    printf("Tables de multiplication !\n");
    do
    {
        printf("Voulez vous connaitre une table de multiplication ? : \"Y\" or \"N\"\n");
        scanf("%c",&sortie_programme);
        if(sortie_programme == 'Y')
        {
            printf("Veuillez entre un nombre entier pour afficher sa table :");
            scanf("%d",&saisie_utilisateur);
            for(int multiplicateur=1;multiplicateur<=10;multiplicateur++)
            {
                valeur_final = saisie_utilisateur * multiplicateur;
                printf(\t"%d * %d = %d\n",saisie_utilisateur,multiplicateur,valeur_final);
            }
        }
    }while(sortie_programme != 'N');
*/
