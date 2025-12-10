/*
#COUND NUMBER OF NICE SUBARRAYS

LINK:- https://leetcode.com/problems/count-number-of-nice-subarrays/

*/

#include<bits/stdc++.h>
using namespace std;


/*
1st we counted number of subarrays, having <= k odd numbers on it
2nd we counted number of subarrays, having <=k-1 odd number on it

then we subtract, and we get exactly k odd number of subarrays
*/
class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int i = 0, j = 0;
        int count_odd = 0;
        int count = 0;
        while (j < nums.size()) {
            if (nums[j] & 1)count_odd++;
            while (count_odd > k) {
                if (nums[i] & 1)count_odd--;
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = { 1,1,2,1,1 };
    int k1 = 3;
    cout << "The number of nice subarrays in {1,1,2,1,1} with k=3 is: " << sol.numberOfSubarrays(nums1, k1) << endl; // Expected output: 2

    vector<int> nums2 = { 2,4,6 };
    int k2 = 1;
    cout << "The number of nice subarrays in {2,4,6} with k=1 is: " << sol.numberOfSubarrays(nums2, k2) << endl; // Expected output: 0

    vector<int> nums3 = { 2,2,2,1,2,2,1,2,2,2 };
    int k3 = 2;
    cout << "The number of nice subarrays in {2,2,2,1,2,2,1,2,2,2} with k=2 is: " << sol.numberOfSubarrays(nums3, k3) << endl; // Expected output: 16

    return 0;
}