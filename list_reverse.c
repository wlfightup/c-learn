#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode Node;
typedef Node *NodePtr;

struct ListNode {
    int val;
    NodePtr next;
};

NodePtr makeNode(int val) {
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}
void print_list(NodePtr node) {
    NodePtr head = node;
    while(head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

NodePtr reverse_list(NodePtr node) {
    NodePtr beforeNode = NULL;
    NodePtr head = node;
    while(head->next) {
        NodePtr next = head->next;
        head->next = beforeNode;
        beforeNode = head;
        head = next;
    }
    head->next = beforeNode;
    return head;
}

NodePtr reverse_list_2(NodePtr node) {
    NodePtr newHead= NULL;
    NodePtr head = node;
    while(head) {
        NodePtr next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

int main() {
    NodePtr a = makeNode(1);
    NodePtr b = makeNode(2);
    NodePtr c = makeNode(3);
    NodePtr d = makeNode(4);
    NodePtr e = makeNode(5);
    NodePtr f = makeNode(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;
    NodePtr g = reverse_list_2(a);
    print_list(g);
    return 1;
}
