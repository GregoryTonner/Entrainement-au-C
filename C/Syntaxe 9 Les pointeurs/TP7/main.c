#include <stdio.h>

int main() {

    char mot ='C';
    char* p_mot =&mot;

    printf("Information sur ma variable :\n");
    printf("\tType de variable : Char\n");
    printf("\tContenu de la variable : %c\n",*p_mot);
    printf("\tAdresse de la variable : %p\n",p_mot);
    printf("\tTaille de la variable : %d octet\n",sizeof(*p_mot));

    return 0;
}
