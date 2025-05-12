#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int l, int h) {
        return ((h + 1) >> 1) - (l >> 1);
    }
};

int main() {
    int l, h;
    cout << "Enter lower bound: ";
    cin >> l;
    cout << "Enter upper bound: ";
    cin >> h;

    Solution sol;
    cout << "Count of odd numbers: " << sol.countOdds(l, h) << endl;

    return 0;
}
