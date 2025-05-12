#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalin(int x) {
        if (x < 0 || (x && x % 10 == 0)) return false;
        int r = 0;
        while (r < x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return x == r || x == r / 10;
    }
};

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    Solution sol;
    cout << (sol.isPalin(x) ? "Palindrome" : "Not a palindrome") << endl;

    return 0;
}
