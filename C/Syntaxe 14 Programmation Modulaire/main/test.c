//
// Created by Fleos on 08/03/2023.
//

#include "test.h"

int puissance (int base, int exposant)
{
    if(base == 0 || exposant ==0)
    {
        return 0;
    }
    int res = base;
    for(int i=0; i<exposant;i++)
    {
        res *= base;
    }
    return res;
}

static int cagnote(int ajout) // Static permet de rendre une fonction locale à son module (source + header)
{
    static int total =0;      // Static sur une variable permet qu'elle ne soit jamais désallouée de la mémoire
    total += ajout;
    return total;
}