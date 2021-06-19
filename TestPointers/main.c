#include<stdio.h>
#include<stdlib.h>

struct element {
    int data;
    struct element *next;
};

typedef struct element Node;

void changeFirst(Node*head);

int main() {
    Node*var=NULL;
    var = malloc(sizeof(Node));
    var->data=15;
    var->next=NULL;
    Node**head;
    head=&var;
    printf("Assignment:         'head=&var'\n");
    printf("Address:            %p - 'var'\n", var);
    printf("Address:            %p - '*head'\n", *head);
    printf("Address:            %p - '&var'\n", &var);
    printf("Address:            %p - 'head'\n", head);
    printf("Address:            %p - '&head'\n", &head);
    printf("Data:               %d\n", (*var).data);
    printf("Data:               %d\n", (**head).data);
    printf("NULL:               %p\n", NULL);

    (*head)=malloc(sizeof(Node));
    (*head)->data=13;
    printf("Data:               %d\n", (**head).data);
    printf("Modifica del valore in testa...\n");
    changeFirst(*head);
    printf("Data:               %d\n", (*head)->data);

    printf("\n\nFILE\n");
    FILE*fp=NULL;
    fp=fopen("./test.txt", "r");
    if(fp==NULL) {
        printf("Impossibile aprire il file\n");
        return 1;
    }
    printf("Address:            %p\n", &fp);
    printf("Content address:    %p\n", fp);
    printf("\nFile content:\n");
    rewind(fp);
    char temp;
    int ok;
    while(1) {
        ok = fscanf(fp, "%c", &temp);
        if(ok<=0||feof(fp)) break;
        printf("File Data:          '%c'\n", temp);
        printf("File fp address:    %p\n", fp);
        printf("Status reading:     %d\n", ok);
    }
    return 0;
}

void changeFirst(Node*head) {
    head->data=0;
}