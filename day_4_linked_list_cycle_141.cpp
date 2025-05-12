#include <iostream>

struct ListNode {
    int v;
    ListNode *n;
    ListNode(int x) : v(x), n(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* h) {
        ListNode *s = h, *f = h;
        while (f && f->n) {
            s = s->n;
            f = f->n->n;
            if (s == f) return true;
        }
        return false;
    }
};

ListNode* createLinkedList() {
    int x;
    ListNode* h = nullptr, *t = nullptr;
    std::cout << "Enter values (end with -1, repeat a value to create cycle): ";
    while (std::cin >> x && x != -1) {
        ListNode* n = new ListNode(x);
        if (!h) h = n;
        else t->n = n;
        t = n;
    }

    char cycle;
    std::cout << "Create cycle? (y/n): ";
    std::cin >> cycle;
    if (cycle == 'y' && h) t->n = h; // Creates a cycle for testing

    return h;
}

int main() {
    ListNode* h = createLinkedList();

    Solution sol;
    std::cout << "Cycle detected: " << (sol.hasCycle(h) ? "Yes" : "No") << std::endl;

    return 0;
}
