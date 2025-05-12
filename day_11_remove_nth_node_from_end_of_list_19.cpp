#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
    ListNode(int x, ListNode* next) : v(x), n(next) {}
};

class Solution {
public:
    ListNode* removeNth(ListNode* h, int n) {
        ListNode* d = new ListNode(0, h), *f = d, *s = d;
        for (int i = 0; i < n; i++) f = f->n;
        while (f->n) { s = s->n; f = f->n; }
        s->n = s->n->n;
        ListNode* nh = d->n;
        delete d;
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
    int n;
    std::cout << "Enter position from end: ";
    std::cin >> n;

    Solution sol;
    h = sol.removeNth(h, n);

    std::cout << "Updated linked list: ";
    printLinkedList(h);

    return 0;
}
