#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int n) {
        return n ? (n - 1) % 9 + 1 : 0;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    cout << "Reduced sum: " << sol.addDigits(n) << endl;

    return 0;
}
