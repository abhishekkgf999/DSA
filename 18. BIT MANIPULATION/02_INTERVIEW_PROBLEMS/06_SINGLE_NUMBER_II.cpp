/*
#SINGLE NUMBER II

LINK:- https://leetcode.com/problems/single-number-ii/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & (1 << i))sum++;
            }
            if (sum % 3 == 1) {
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
};

int main() {
    Solution1 sol;

    // Example 1: Standard case
    vector<int> nums1 = { 2, 2, 3, 2 };
    cout << "Input: {2, 2, 3, 2}" << endl;
    cout << "The single number is: " << sol.singleNumber(nums1) << endl; // Expected: 3
    cout << "---" << endl;

    // Example 2: Negative number
    vector<int> nums2 = { -2, -2, 1, 1, 1, 3, 3 };
    cout << "Input: {-2, -2, 1, 1, 1, 3, 3}" << endl;
    cout << "The single number is: " << sol.singleNumber(nums2) << endl; // Expected: 1
    cout << "---" << endl;

    // Example 3: All numbers same except one
    vector<int> nums3 = { 0, 1, 0, 1, 0, 1, 99 };
    cout << "Input: {0, 1, 0, 1, 0, 1, 99}" << endl;
    cout << "The single number is: " << sol.singleNumber(nums3) << endl; // Expected: 99

    return 0;
}