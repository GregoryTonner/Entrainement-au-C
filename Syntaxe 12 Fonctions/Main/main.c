#include <stdio.h>

void ditHello()
{
    printf("Hello, World!\n");
    printf("Formation C\n");
}
void infosPerso(int xp, int lvl){
    xp *=4;
    printf("\txp : %d\n",xp);
    printf("\tlevel : %d\n",lvl);
}
int main() {
    int xp_mage =1250;
    int lvl_mage = 10;

    ditHello();

    printf("Mage : ");
    infosPerso(xp_mage,lvl_mage);
    printf("\txp : %d\n",xp_mage);

    return 0;
}

