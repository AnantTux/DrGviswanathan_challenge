#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int findNth(int n) {
        int d = 1;
        long c = 9;

        while (1LL * d * c < n) {
            n -= d * c;
            ++d;
            c *= 10;
        }

        int num = pow(10, d - 1) + (n - 1) / d;
        int idx = (n - 1) % d;
        string s = to_string(num);

        return s[idx] - '0';
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    cout << "Nth digit: " << sol.findNth(n) << endl;

    return 0;
}
