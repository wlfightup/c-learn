#include <stdio.h>

typedef struct ListNode Node;
typedef Node *NodePtr;

struct ListNode {
    int val;
    NodePtr next;
};

int print_list(NodePtr node) {
    NodePtr head = node;
    while(head) {
        printf("%d\n", head->val);
        NodePtr head = head->next;
    }
    return 1;
}

int main() {
    struct ListNode a = {1};
    struct ListNode b = {2};
    struct ListNode c = {3};
    struct ListNode d = {4};
    struct ListNode e = {5};
    struct ListNode f = {6};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    //print_list(&a);
    struct ListNode *head = &a;
    while(head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}
