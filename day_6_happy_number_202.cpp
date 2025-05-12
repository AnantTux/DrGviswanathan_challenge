#include <iostream>
#include <cmath>

class Solution {
public:
    bool isHappy(int n) {
        auto nxt = [](int x) {
            int s = 0;
            while (x > 0) {
                s += std::pow(x % 10, 2);
                x /= 10;
            }
            return s;
        };
        int s = n, f = nxt(n);
        while (s != f) {
            s = nxt(s);
            f = nxt(nxt(f));
        }
        return s == 1;
    }
};

int main() {
    Solution sol;
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << (sol.isHappy(num) ? "Happy Number" : "Not a Happy Number") << std::endl;
    return 0;
}
