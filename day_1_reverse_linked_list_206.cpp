#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
    ListNode(int x, ListNode* next) : v(x), n(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* h) {
        ListNode* p = nullptr, *nx;
        while (h) {
            nx = h->n;
            h->n = p;
            p = h;
            h = nx;
        }
        return p;
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
    h = sol.reverse(h);

    std::cout << "Reversed linked list: ";
    printLinkedList(h);

    return 0;
}
