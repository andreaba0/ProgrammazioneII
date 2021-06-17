#include<stdio.h>
#include<stdlib.h>

struct element {
    int data;
    struct element *next;
};

typedef struct element Node;

int main() {
    Node*var=NULL;
    var = malloc(sizeof(Node));
    var->data=15;
    var->next=NULL;
    Node**head;
    head=&var;
    printf("Assignment: 'head=&var'\n");
    printf("Address: %p - 'var'\n", var);
    printf("Address: %p - '*head'\n", *head);
    printf("Address: %p - '&var'\n", &var);
    printf("Address: %p - 'head'\n", head);
    printf("Address: %p - '&head'\n", &head);
    printf("Data: %d\n", (*var).data);
    printf("Data: %d\n", (**head).data);
    printf("NULL: %p\n", NULL);
    return 0;
}