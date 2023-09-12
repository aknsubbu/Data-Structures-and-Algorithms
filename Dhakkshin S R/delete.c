#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* findNode(struct ListNode* head, struct ListNode* current, struct ListNode* potential, int target, int n);

int main(void)
{
    struct ListNode * head = malloc(sizeof(struct ListNode));
    printf("%p\n", findNode(head, head, NULL, n, 1);)
}