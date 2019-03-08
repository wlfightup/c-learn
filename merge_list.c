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

NodePtr merge(NodePtr head1, NodePtr head2) {
    if(head1 == NULL && head2 == NULL) {
        return NULL;
    }
    NodePtr newhead = NULL;
    NodePtr node = NULL;
    NodePtr end = NULL;
    while(head1 && head2) {
        if(head1->val > head2->val) {
            node = head2;
            head2 = head2->next;
        } else {
            node = head1;
            head1 = head1->next;
        }
        if(newhead == NULL) {
            newhead = node;
            end = node;
        } else {
            end->next = node;
            end = end->next;
        }
    }
    if(head1) end->next = head1;
    if(head2) end->next = head2;

    return newhead;
}

int main() {
    NodePtr a = makeNode(1);
    NodePtr b = makeNode(3);
    NodePtr c = makeNode(5);
    NodePtr d = makeNode(7);
    NodePtr e = makeNode(9);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    print_list(a);

    NodePtr aa = makeNode(0);
    NodePtr ab = makeNode(2);
    NodePtr ac = makeNode(4);
    NodePtr ad = makeNode(10);
    NodePtr ae = makeNode(12);
    aa->next = ab;
    ab->next = ac;
    ac->next = ad;
    ad->next = ae;
    ae->next = NULL;
    print_list(aa);

    NodePtr new = NULL;
    new = merge(a, aa);
    print_list(new);
    return 1;
}
