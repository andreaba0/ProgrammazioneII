#include<stdlib.h>
#include<stdio.h>

struct element {
    int data;
    struct element*next;
};

typedef struct element elem;
typedef elem*Node;