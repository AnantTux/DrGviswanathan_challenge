#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* sp = head;
        ListNode* fp = head->next;
        while (fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;
        }

        ListNode* prevNode = nullptr;
        ListNode* currentNode = sp->next;
        while (currentNode) {
            ListNode* nextTemp = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextTemp;
        }

        while (prevNode) {
            if (prevNode->val != head->val) {
                return false;
            }
            prevNode = prevNode->next;
            head = head->next;
        }

        return true;
    }
};

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution sol;
    if (sol.isPalindrome(node1)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
