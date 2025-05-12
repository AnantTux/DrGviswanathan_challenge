#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* h, int k) {
        if (!h || !h->n) return h;
        ListNode* c = h;
        int len = 0;
        while (c) { ++len; c = c->n; }
        k %= len;
        if (k == 0) return h;

        ListNode* f = h, *s = h;
        while (k--) f = f->n;
        while (f->n) { f = f->n; s = s->n; }

        ListNode* nh = s->n;
        s->n = nullptr;
        f->n = h;
        return nh;
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
    int k;
    std::cout << "Enter rotation count: ";
    std::cin >> k;

    Solution sol;
    h = sol.rotateRight(h, k);

    std::cout << "Rotated linked list: ";
    printLinkedList(h);

    return 0;
}
