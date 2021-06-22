#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct elem {
    int data;
    struct elem *next;
};

typedef struct elem Node;

int stackPush(Node**head, int n);
int stackPop(Node**head);
void displayStack(Node*head);

int main(int argc, char*argv[]) {
    if(argc!=2) {
        printf("Richiesto il numero di cicli\n");
        return 1;
    }
    srand((unsigned int) time(NULL));
    int cicli = atoi(argv[1]);
    int temp;
    int res;
    Node*head=NULL;
    while(cicli-->0) {
        temp=rand()%2;
        if(temp%2==0) {
            res=stackPush(&head, rand()%100);
            if(res) printf("Stack full\n");
        }
        else res = stackPop(&head);
        displayStack(head);
    }
    return 0;
}

int stackPop(Node**head) {
    if(*head==NULL) return -1;
    Node*temp=*head;
    int res=temp->data;
    *head=(*head)->next;
    free(temp);
    return res;
}

int stackPush(Node**head, int n) {
    Node*temp;
    temp=malloc(sizeof(Node));
    if(temp==NULL) return 1;
    temp->data=n;
    temp->next=*head;
    *head=temp;
    return 0;
}

void displayStack(Node*head) {
    printf("Array: [");
    while(head!=NULL) {
        printf("%d", head->data);
        if(head->next!=NULL) printf(", ");
        head=head->next;
    }
    printf("]\n");
}