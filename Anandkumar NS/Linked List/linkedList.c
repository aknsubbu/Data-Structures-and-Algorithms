#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getData(int data) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p; 
}

int main() {
    struct Node *p1,*p2,*p3;
    p1=getData(1);
    p2=getData(2);
    p3=getData(3);
    p1->next=p2;
    p2->next=p3;
    printf("Data in the new node: %d\n", p1->data);
    printf("Data in the new node: %d\n", p2->data);
    printf("Data in the new node: %d\n", p3->data);




    return 0;
}
// whenevr we print node data, next and address