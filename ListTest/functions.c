#include "header.h"

void init(Node*head, int len) {
    Node temp;
    Node current=*head;
    for(int i=0;i<len;i++) {
        temp=malloc(sizeof(Node));
        temp->data=rand()%100;
        temp->next=NULL;

        if(i==0) {
            *head=temp;
            current=*head;
        } else {
            current->next=temp;
            current=current->next;
        }
    }
}

void initV2(Node*head, int len) {
    Node temp=NULL;
    Node*current=head;
    while(len>0) {
        temp=malloc(sizeof(Node));
        temp->data=rand()%100;
        temp->next=NULL;
        if(*head==NULL) *head=temp;
        else {
            (*current)->next=temp;
            current=&((*current)->next);
        }
        len--;
    }
}

void removeEven(Node*head) {
    Node*current=head;
    Node temp;
    while(*current!=NULL) {
        if((*current)->data%2!=0) {
            temp = *current;
            printf("Indirizzi: %p, %p\n", &temp, current);
            *current=((*current)->next);
            free(temp);
        }
        else 
            current=&((*current)->next);
    }
}

void removeRecursiveEven(Node*head) {
    if(*head==NULL) return;
    if((**head).data%2!=0) {
        Node temp=*head;
        *head=(*head)->next;
        free(temp);
    } else
        head=&((*head)->next);
    removeRecursiveEven(head);
}

void viewList(Node head) {
    int i=0;
    printf("Inizio lista:\n");
    while(head!=NULL) {
        printf("%6d): %3d\n", i++, head->data);
        head=head->next;
    }
    printf("Fine lista\n");
}