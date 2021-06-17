#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct element {
    int data;
    struct element*next;
};

typedef struct element elem;
typedef elem*Node;

void init(Node*head, int len);
void initV2(Node*head, int len);
void viewList(Node head);
void removeEven(Node*head);
void removeRecursiveEven(Node*head);