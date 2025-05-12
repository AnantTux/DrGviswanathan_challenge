#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        for (int i = d.size() - 1; i >= 0; --i) {
            d[i] = (d[i] + 1) % 10;
            if (d[i]) return d;
        }
        d.insert(d.begin(), 1);
        return d;
    }
};

int main() {
    int n;
    cout << "Enter number of digits: ";
    cin >> n;
    
    vector<int> d(n);
    cout << "Enter digits: ";
    for (int &x : d) cin >> x;

    Solution sol;
    d = sol.plusOne(d);

    cout << "Result: ";
    for (int x : d) cout << x << " ";
    cout << endl;

    return 0;
}
