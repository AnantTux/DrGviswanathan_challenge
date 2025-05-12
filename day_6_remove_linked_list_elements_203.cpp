#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* h, int v) {
        ListNode* d = new ListNode(0);
        d->n = h;
        ListNode* c = d;
        while (c->n) {
            if (c->n->v == v) c->n = c->n->n;
            else c = c->n;
        }
        return d->n;
    }
};

ListNode* createLinkedList() {
    int x;
    ListNode* h = nullptr;
    ListNode* t = nullptr;
    std::cout << "Enter values for the linked list (end with -1): ";
    while (std::cin >> x && x != -1) {
        ListNode* n = new ListNode(x);
        if (!h) h = n;
        else t->n = n;
        t = n;
    }
    return h;
}

void printLinkedList(ListNode* h) {
    while (h) {
        std::cout << h->v << " ";
        h = h->n;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* h = createLinkedList();
    int v;
    std::cout << "Enter value to remove: ";
    std::cin >> v;

    Solution sol;
    h = sol.removeElements(h, v);

    std::cout << "Updated linked list: ";
    printLinkedList(h);

    return 0;
}
