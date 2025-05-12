#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
    ListNode(int x, ListNode* next) : v(x), n(next) {}
};

class Solution {
public:
    ListNode* middle(ListNode* h) {
        ListNode* s = h, *f = h;
        while (f && f->n) {
            s = s->n;
            f = f->n->n;
        }
        return s;
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
    h = sol.middle(h);

    std::cout << "Middle node: " << h->v << std::endl;

    return 0;
}
