#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int*vet, int p, int r);
void sort(int*vet, int p, int r);
void swap(int*vet, int x, int y);

void initArray(int*arr, int len) {
    for(int i =0;i<len;i++) arr[i]=rand()%100;
}

void displayArray(int*vet, int len) {
    printf("Array: [");
    for(int i=0;i<len;i++) {
        printf("%d", vet[i]);
        if(i<len-1) printf(", ");
    }
    printf(" ];\n");
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
    displayArray(vet, len);
    sort(vet, 0, len-1);
    displayArray(vet, len);
    return 0;
}

int partition(int*vet, int p, int r) {
    int pivot = vet[(p+r)/2];
    int pivotpos = (p+r)/2;
    swap(vet, pivotpos, p);
    pivotpos=p;
    int i;
    for(i=p+1;i<=r;i++)
        if(vet[i]<pivot) swap(vet, ++pivotpos, i);
    swap(vet, pivotpos, p);
    return pivotpos;
}

void sort(int*vet, int p, int r) {
    if(p>=r) return;
    printf("%d->%d\n", p, r);
    int q = partition(vet, p, r);
    sort(vet, p, q-1);
    sort(vet, q+1, r);
}

void swap(int*vet, int x, int y) {
    int temp;
    temp=vet[x];
    vet[x]=vet[y];
    vet[y]=temp;
}