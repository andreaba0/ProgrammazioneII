#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10

struct elem {
    int*queue;
    int head;
    int tail;
    int len;
};
typedef struct elem Queue;

int queuePush(Queue*queue, int n) {
    if(queue->head==(queue->tail+1)%queue->len) return 1;
    queue->queue[(queue->tail+1)%queue->len]=n;
    queue->tail=(queue->tail+1)%queue->len;
    return 0;
}

int queuePop(Queue*queue) {
    if(queue->head==queue->tail) return -1;
    int res = queue->queue[queue->head];
    queue->head=(queue->head+1)%queue->len;
    return res;
}

void displayQueue(Queue*queue) {
    printf("Array: [");
    /*for(int i=queue->head;i!=queue->tail;i=(i+1)%queue->len) {
        printf("%d", queue->queue[i]);
        if(i<((queue->tail-1)%queue->len)) printf(", ");
    }*/
    for(int i=0;i<queue->len;i++) {
        printf("%d", queue->queue[i]);
        if(i<queue->len-1) printf(", ");
    }
    printf("];\n");
}

int main(int argc, char*argv[]) {
    srand(time(NULL));
    if(argc!=3) {
        printf("Richiesto il numero di cicli e la dimensione della coda\n");
        return 1;
    }
    int tot = atoi(argv[1]);
    int len = atoi(argv[2]);
    Queue*queue=malloc(sizeof(Queue));
    queue->queue=malloc(len*sizeof(int));
    queue->len=len;
    queue->head=0;
    queue->tail=0;
    int temp;
    int res;
    while(tot-->0) {
        temp=rand()%2;
        if(temp%2==0) {
            res = queuePush(queue, rand()%100);
            if(res) printf("Queue full\n");
        }
        else res=queuePop(queue);
        displayQueue(queue);
    }
    return 0;
}