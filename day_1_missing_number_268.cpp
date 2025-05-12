#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNum(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i) ans ^= i ^ nums[i];
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements (excluding missing one): ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (0 to " << n << " but missing one): ";
    for (int &x : nums) cin >> x;

    Solution sol;
    cout << "Missing number: " << sol.missingNum(nums) << endl;

    return 0;
}
