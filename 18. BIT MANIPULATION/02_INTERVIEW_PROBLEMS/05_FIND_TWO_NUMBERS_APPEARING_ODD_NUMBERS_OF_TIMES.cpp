/*
#FIND THE TWO NUMBERS APPEARING ODD NUMBER OF TIMES

LINK:- https://leetcode.com/problems/single-number-iii/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long num = 0;
        for (auto i : nums) {
            num = num ^ i;
        }

        long mask = (num ^ (num - 1)) & num;

        int a = 0, b = 0;
        for (auto i : nums) {
            if ((mask & i) == 0) b = b ^ i;
            else a = a ^ i;
        }

        return { a,b };
    }
};

int main() {
    Solution sol;

    // Example 1: Standard case
    vector<int> nums1 = { 1, 2, 1, 3, 2, 5 };
    vector<int> result1 = sol.singleNumber(nums1);
    cout << "Input: {1, 2, 1, 3, 2, 5}" << endl;
    cout << "Output: {" << result1[0] << ", " << result1[1] << "}" << endl;
    cout << "---" << endl;

    // Example 2: Array with only two elements
    vector<int> nums2 = { -1, 0 };
    vector<int> result2 = sol.singleNumber(nums2);
    cout << "Input: {-1, 0}" << endl;
    cout << "Output: {" << result2[0] << ", " << result2[1] << "}" << endl;
    cout << "---" << endl;

    // Example 3: Single-element array (shouldn't happen based on constraints but good practice)
    vector<int> nums3 = { 1 };
    vector<int> result3 = sol.singleNumber(nums3);
    cout << "Input: {1}" << endl;
    cout << "Output: {" << result3[0] << ", " << result3[1] << "}" << endl;

    return 0;
}
