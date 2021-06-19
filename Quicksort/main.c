#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initArray(int*arr, int len) {
    for(int i =0;i<len;i++) arr[i]=rand()%100;
}

int main(int argc, char*argv[]) {
    if(argc!=2) {
        printf("Errore: richiesto il numero di elementi\n");
        return 1;
    }
    int len = atoi(argv[1]);
    if(len<=0) {
        printf("Lunghezza non valida");
        return 1;
    }
    srand(time(NULL));
    int vet[len];
    initArray(vet, len);
    
    return 0;
}