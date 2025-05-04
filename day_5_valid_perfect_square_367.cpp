#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1;
        long r = num;
        while (l < r) {
            const long m = (l + r) / 2;
            if (m >= num / m)
                r = m;
            else
                l = m + 1;
        }
        return l * l == num;
    }
};

int main() {
    Solution sol;
    int test1 = 16;
    int test2 = 14;

    cout << "Is " << test1 << " a perfect square? " 
         << (sol.isPerfectSquare(test1) ? "Yes" : "No") << endl;

    cout << "Is " << test2 << " a perfect square? " 
         << (sol.isPerfectSquare(test2) ? "Yes" : "No") << endl;

    return 0;
}