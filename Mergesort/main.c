#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int*vet, int p, int q);
void merge(int*vet, int p, int q, int r);
void initArray(int*vet, int len);
void displayArray(int*vet, int len);

int main(int argc, char*argv[]) {
    if(argc!=2) {
        printf("Richiesta la dimensione del vettore\n");
        return 1;
    }
    int len = atoi(argv[1]);
    if(len<=0) {
        printf("Dimensione non valida\n");
        return 1;
    }
    srand(time(NULL));
    int vet[len];
    initArray(vet, len);
    displayArray(vet, len);
    sort(vet, 0, len-1);
    displayArray(vet, len);
    return 1;
}

void initArray(int*vet, int len) {
    for(int i=0;i<len;i++) vet[i]=rand()%100;
}

void displayArray(int*vet, int len) {
    printf("Array: [");
    for(int i=0;i<len;i++) {
        printf("%d", vet[i]);
        if(i<len-1) printf(", ");
    }
    printf("];\n");
}

void sort(int*vet, int p, int r) {
    if(r-p>0) {
        int lock = (r-p)/2+p;
        sort(vet, p, lock);
        sort(vet, lock+1, r);
        merge(vet, p, lock, r);
    }
}

void merge(int*vet, int p, int q, int r) {
    int*temp = malloc(((r-p)+1)*sizeof(int));
    int i =0;
    int j=1;
    int res=0;
    while(p+i<=q&&q+j<=r)
        if(vet[p+i]>=vet[q+j])
            temp[res++]=vet[q+(j++)];
        else
            temp[res++]=vet[p+(i++)];
    while(p+i<=q) temp[res++]=vet[p+(i++)];
    while(q+j<=r) temp[res++]=vet[q+(j++)];
    res=0;
    while(res<=r-p) {
        vet[p+res]=temp[res];
        res++;
    }
    //printf("Status array: %d->%d; %d->%d\n", p, q, q+1, r);
    free(temp);
}