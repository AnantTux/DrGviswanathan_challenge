#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
};

class Solution {
public:
    ListNode* oddEven(ListNode* h) {
        if (!h) return nullptr;
        ListNode* o = h, *eH = h->n, *eT = eH;
        while (eT && eT->n) {
            o->n = eT->n;
            o = o->n;
            eT->n = o->n;
            eT = eT->n;
        }
        o->n = eH;
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
    
    Solution sol;
    h = sol.oddEven(h);

    std::cout << "Reordered linked list: ";
    printLinkedList(h);

    return 0;
}
