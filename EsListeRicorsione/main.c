#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct elem {
    int data;
    struct elem *next;
};
typedef struct elem Node;

Node*initList(int len);
Node*duplicateList(Node*head);
void displayList(Node*head, int f);
Node*duplicateEven(Node*head);

int main(int argc, char*argv[]) {
    if(argc!=2) {
        printf("Inserire il numero di nodi della lista\n");
        return 1;
    }
    int len = atoi(argv[1]);
    if(len<=0) {
        printf("Numero di nodi non valido\n");
        return 1;
    }
    srand(time(NULL));
    Node*head=NULL;
    head=initList(len);
    displayList(head, 0);
    Node*duplicate=duplicateList(head);
    displayList(head, 0);
    Node*evenOnly=duplicateEven(head);
    displayList(evenOnly, 0);
    
    return 0;
}

Node*duplicateEven(Node*head) {
    if(head==NULL) return NULL;
    if(head->data%2!=0) return duplicateEven(head->next);
    Node*temp=malloc(sizeof(Node));
    temp->data=head->data;
    temp->next=duplicateEven(head->next);
    return temp;
}

Node*duplicateList(Node*head) {
    if(head==NULL) return NULL;
    Node*temp = malloc(sizeof(Node));
    temp->data=head->data;
    temp->next=duplicateList(head->next);
    return temp;
}

Node *initList(int len) {
    if(len==0) return NULL;
    Node*temp=NULL;
    temp=malloc(sizeof(Node));
    temp->data=rand()%100;
    temp->next=initList(len-1);
    return temp;
}

void displayList(Node*head, int f) {
    if(head==NULL) return;
    if(f==0) printf("Array: [");
    printf("%d", head->data);
    if(head->next!=NULL) printf(", ");
    else printf("]\n");
    displayList(head->next, 1);
}