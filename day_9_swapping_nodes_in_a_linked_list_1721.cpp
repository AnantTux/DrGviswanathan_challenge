#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
};

class Solution {
public:
    ListNode* swap(ListNode* h, int k) {
        ListNode* f = h;
        while (--k) f = f->n;

        ListNode* s = h, *fn = f;
        while (f->n) { f = f->n; s = s->n; }

        ListNode* sn = s;
        std::swap(fn->v, sn->v);

        return h;
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
    std::cout << "Enter position to swap: ";
    std::cin >> k;

    Solution sol;
    h = sol.swap(h, k);

    std::cout << "Updated linked list: ";
    printLinkedList(h);

    return 0;
}
