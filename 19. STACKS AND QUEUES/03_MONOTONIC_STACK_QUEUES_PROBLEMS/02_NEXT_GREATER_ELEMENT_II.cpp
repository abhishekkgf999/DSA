/*
#NEXT GREATER ELEMENT II

LINK:- https://leetcode.com/problems/next-greater-element-ii/description/

*/

#include<bits/stdc++.h>
using namespace std;

//TC:- O(2N^2)
class Naive_Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());

        int i = nums.size() - 1;

        nums.insert(nums.end(), nums.begin(), nums.end());

        while (i >= 0) {
            int maxi = -1;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    maxi = nums[j];
                    break;
                }
            }
            ans[i] = maxi;
            i--;
        }
        return ans;
    }
};

class Solution_optimal1 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // store indices

        // Traverse 2n - 1 to 0 (simulate circular array)
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Maintain decreasing stack
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

            // If we are in the first n elements, update answer
            if (i < n) {
                ans[idx] = st.empty() ? -1 : nums[st.top()];
            }

            // Push current index
            st.push(idx);
        }

        return ans;
    }
};

class Solution_optimal2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, -1);
        stack<int> st;

        for (int i = n - 1;i >= 0;i--) {
            st.push(nums[i]);
        }

        for (int i = n - 1;i >= 0;i--) {

            if (!st.empty()) {
                while (!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }
                if (!st.empty())
                    sum[i] = st.top();
            }
            st.push(nums[i]);

        }
        return sum;

    }
};


int main() {
    vector<int> nums = { 1,2,3 };
    nums.insert(nums.end(), nums.begin(), nums.end());
    for (auto i : nums)cout << i << " ";
    return 0;
}






