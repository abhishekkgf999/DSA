/*
#MAX CONSECUTIVE ONES III

LINK:- https://leetcode.com/problems/max-consecutive-ones-iii/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
agar one ayenge toh kuch nhi krna, keep track for zeroes only,
we are allowed to switch k zeroes only,

if number zeroes we encountered exceed k, then decrease until it beomes equal to less than k
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count_zeroes = 0;
        int max_len = 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                count_zeroes++;
            }
            while (count_zeroes > k) {
                if (nums[i] == 0) {
                    count_zeroes--;
                }
                i++;
            }
            max_len = max(max_len, j - i + 1);
            j++;
        }

        return max_len;
    }
};


int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> nums1 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int k1 = 2;
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nk = " << k1 << endl;
    cout << "Longest consecutive ones: " << sol.longestOnes(nums1, k1) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 2: K is large
    vector<int> nums2 = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int k2 = 3;
    cout << "Input: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nk = " << k2 << endl;
    cout << "Longest consecutive ones: " << sol.longestOnes(nums2, k2) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 3: K is 0
    vector<int> nums3 = { 1, 1, 1, 0, 1, 1, 0, 1 };
    int k3 = 0;
    cout << "Input: ";
    for (int num : nums3) cout << num << " ";
    cout << "\nk = " << k3 << endl;
    cout << "Longest consecutive ones: " << sol.longestOnes(nums3, k3) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 4: Edge case with empty array
    vector<int> nums4 = {};
    int k4 = 1;
    cout << "Input: Empty array\nk = " << k4 << endl;
    cout << "Longest consecutive ones: " << sol.longestOnes(nums4, k4) << endl;

    return 0;
}