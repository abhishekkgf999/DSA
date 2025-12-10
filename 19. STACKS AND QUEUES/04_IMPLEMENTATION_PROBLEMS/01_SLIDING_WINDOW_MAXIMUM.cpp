/*
#SLIDING WINDOW MAXIMUM

LINK:- https://leetcode.com/problems/sliding-window-maximum/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0;
        deque<int> d;
        vector<int> ans;
        while (j < nums.size()) {
            while (!d.empty() && nums[j] >= nums[d.back()]) {
                d.pop_back();
            }

            d.push_back(j);

            if (j - i + 1 == k) {
                ans.push_back(nums[d.front()]);
                if (!d.empty() && i == d.front()) {
                    d.pop_front();
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums, k);
    for (auto i : ans) cout << i << " ";
    return 0;
}