/*
#Subarrays with K Different Integers

LINK:- https://leetcode.com/problems/subarrays-with-k-different-integers/description/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int count = 0;
        while (j < nums.size()) {
            mpp[nums[j]]++;
            while (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)mpp.erase(nums[i]);
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = { 1, 2, 1, 2, 3 };
    int k1 = 2;
    cout << "Input: {1, 2, 1, 2, 3}, k = 2" << endl;
    cout << "Number of subarrays: " << sol.subarraysWithKDistinct(nums1, k1) << endl; // Expected: 7
    cout << endl;

    // Example 2
    vector<int> nums2 = { 1, 2, 1, 3, 4 };
    int k2 = 3;
    cout << "Input: {1, 2, 1, 3, 4}, k = 3" << endl;
    cout << "Number of subarrays: " << sol.subarraysWithKDistinct(nums2, k2) << endl; // Expected: 3
    cout << endl;

    // Example 3
    vector<int> nums3 = { 2, 1, 1, 1, 2 };
    int k3 = 1;
    cout << "Input: {2, 1, 1, 1, 2}, k = 1" << endl;
    cout << "Number of subarrays: " << sol.subarraysWithKDistinct(nums3, k3) << endl; // Expected: 8
    cout << endl;

    return 0;
}
