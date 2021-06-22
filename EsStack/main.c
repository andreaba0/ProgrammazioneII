#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10

int stackPush(int*stack, int n, int*top, int dim) {
    if(*top==dim) return 1;
    stack[(*top)++]=n;
    return 0;
}

int stackPop(int*stack, int*top) {
    if(*top==0) return -1;
    return stack[(*top)--];
}

void displayStack(int*stack, int top) {
    printf("Array: [");
    for(int i=0;i<top;i++) {
        printf("%d", stack[i]);
        if(i<top-1) printf(", ");
    }
    printf("];\n");
}

int main(int argc, char*argv[]) {
    srand(time(NULL));
    if(argc!=3) {
        printf("Richiesto il numero di cicli e la dimensione dello stack\n");
        return 1;
    }
    int tot = atoi(argv[1]);
    int len = atoi(argv[2]);
    int stack[len];
    int temp;
    int top=0;
    int res;
    while(tot-->0) {
        temp=rand()%2;
        if(temp%2==0) {
            res = stackPush(stack, rand()%100, &top, len);
            if(res) printf("Stack full\n");
        }
        else res=stackPop(stack, &top);
        displayStack(stack, top);
    }
    return 0;
}