#include <iostream>

using namespace std;

class Solution {
public:
    int zeros(int n) {
        int c = 0;
        while (n > 0) {
            n /= 5;
            c += n;
        }
        return c;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    cout << "Trailing zeroes: " << sol.zeros(n) << endl;

    return 0;
}
