#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
    ListNode(int x, ListNode* next) : v(x), n(next) {}
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    ListNode* insertGCDs(ListNode* h) {
        if (!h) return nullptr;
        ListNode* c = h, *nx = h->n;
        while (nx) {
            int g = gcd(c->v, nx->v);
            c->n = new ListNode(g, nx);
            c = nx;
            nx = nx->n;
        }
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
    h = sol.insertGCDs(h);

    std::cout << "Updated linked list: ";
    printLinkedList(h);

    return 0;
}
