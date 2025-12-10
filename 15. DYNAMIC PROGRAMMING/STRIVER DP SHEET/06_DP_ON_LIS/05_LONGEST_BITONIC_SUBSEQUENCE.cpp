/*
#LONGEST BITONIC SUBSEQUENCE

LINK:- https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
*/

#include<bits/stdc++.h>
using namespace std;

/*
* inc[i] = LIS ending at i (from left to right).
* dec[i] = LIS ending at i if you go right-to-left (LDS starting at i).

Then the answer = max(inc[i] + dec[i] - 1) for all i.
*/

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int>& nums) {
        // code here
        vector<int> inc(n, 1), dec(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    inc[i] = max(inc[i], inc[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    dec[i] = max(dec[i], dec[j] + 1);
                }
            }
        }

        int max_len = 0;
        for (int i = 0; i < n; i++) {
            if (inc[i] > 1 && dec[i] > 1) {
                max_len = max(max_len, inc[i] + dec[i] - 1);
            }
        }

        return max_len;
    }
};


int main() {
    vector<int> nums = { 1, 11, 2, 10, 4, 5, 2, 1 };
    Solution obj;
    cout << obj.LongestBitonicSequence(8, nums);

    return 0;
}