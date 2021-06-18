#include "header.h"

int main(int argc, char*argv[]) {
    if(argc!=2) {
        printf("Numero di argomenti non valido (!=2)\n");
        return 1;
    }
    
    int tot = atoi(argv[1]);
    if(tot<=0) {
        printf("Valore: %d non valido\n", tot);
        return 1;
    }
    srand(time(NULL));

    Node head1=NULL, head2=NULL;

    init(&head1, tot);
    initV2(&head2, tot);
    viewList(head1);
    viewList(head2);
    //removeEven(&head1);
    removeRecursiveEven(&head1);
    viewList(head1);

    return 0;
}