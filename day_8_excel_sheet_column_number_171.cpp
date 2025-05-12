#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int convert(string s) {
        int r = 0;
        for (char c : s) r = r * 26 + (c - 'A' + 1);
        return r;
    }
};

int main() {
    string s;
    cout << "Enter column title: ";
    cin >> s;

    Solution sol;
    cout << "Column number: " << sol.convert(s) << endl;

    return 0;
}
