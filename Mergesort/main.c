#include "header.h"

int main(int argc, char*argv[]) {
    if(argc!=2) {
        printf("Numero di argomenti non valido (!=2)\n");
        return 1;
    }
    
    int tot = atoi(argv[1]);
    if(tot<=0) {
        printf("Valore: %d non valido\n", tot);
        return 1;
    }

    return 0;
}