/*
#PRINTING LONGEST INCREASING SUBSEQUENCE

*/

#include<bits/stdc++.h>
using namespace std;

/*
=> Start from max length position
=> Go backwards looking for targetLen - 1, then targetLen - 2, etc.
=> Ensure the element is smaller than previously picked element
=> Stop when targetLen = 0
*/
vector<int> lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    // Build DP array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find max length and its index
    int maxLen = *max_element(dp.begin(), dp.end());
    int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();

    // Reconstruct LIS
    vector<int> lis;
    int targetLen = maxLen;

    for (int i = maxIndex; i >= 0; i--) {
        if (dp[i] == targetLen && (lis.empty() || nums[i] < lis.back())) {
            lis.push_back(nums[i]);
            targetLen--;
            if (targetLen == 0) break;
        }
    }

    reverse(lis.begin(), lis.end());
    return lis;
}



int main() {
    vector<int> num = { 10,9,2,5,3,7,101,18 };
    vector<int> ans = lengthOfLIS(num);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}