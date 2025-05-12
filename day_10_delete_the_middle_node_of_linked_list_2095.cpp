#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
    ListNode(int x, ListNode* next) : v(x), n(next) {} 
};

class Solution {
public:
    ListNode* delMid(ListNode* h) {
        if (!h || !h->n) return nullptr;

        ListNode* d = new ListNode(0, h), *s = d, *f = h;
        while (f && f->n) { s = s->n; f = f->n->n; }

        ListNode* del = s->n;
        s->n = s->n->n;
        delete del;

        return d->n;
    }
};

ListNode* createLinkedList() {
    int x;
    ListNode* h = nullptr, *t = nullptr;
    std::cout << "Enter values (end with -1): ";
    while (std::cin >> x && x != -1) {
        ListNode* n = new ListNode(x);
        if (!h) h = n;
        else t->n = n;
        t = n;
    }
    return h;
}

void printLinkedList(ListNode* h) {
    while (h) { std::cout << h->v << " "; h = h->n; }
    std::cout << std::endl;
}

int main() {
    ListNode* h = createLinkedList();

    Solution sol;
    h = sol.delMid(h);

    std::cout << "Updated linked list: ";
    printLinkedList(h);

    return 0;
}
