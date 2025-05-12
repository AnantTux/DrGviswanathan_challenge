#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int bulbs(int n) {
        return static_cast<int>(sqrt(n));
    }
};

int main() {
    int n;
    cout << "Enter number of bulbs: ";
    cin >> n;

    Solution sol;
    cout << "Bulbs left on: " << sol.bulbs(n) << endl;

    return 0;
}
