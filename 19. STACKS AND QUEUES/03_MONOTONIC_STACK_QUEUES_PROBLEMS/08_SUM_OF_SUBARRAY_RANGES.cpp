/*
#SUM OF SUBARRAY RANGES

LINK:- https://leetcode.com/problems/sum-of-subarray-ranges/description/
*/


#include<bits/stdc++.h>
using namespace std;

/*
-> We will count, how many times a number contributing as smallest, and largest
-> and last, we will subtract all the largest number sum with smallest number sum
*/
class Solution {
public:
    vector<long long > nextSmaller(vector<int>& arr) {
        vector<long long > ans(arr.size());
        stack<long long > st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }

            if (!st.empty()) ans[i] = st.top();
            else ans[i] = arr.size();

            st.push(i);
        }

        return ans;
    }
    vector<long long > prevSmaller(vector<int>& arr) {
        vector<long long > ans(arr.size());
        stack<long long > st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }

            if (!st.empty()) ans[i] = st.top();
            else ans[i] = -1;

            st.push(i);
        }

        return ans;
    }

    vector<long long > nextGreat(vector<int>& arr) {
        vector<long long > ans(arr.size());
        stack<long long > st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }

            if (!st.empty()) ans[i] = st.top();
            else ans[i] = arr.size();

            st.push(i);
        }

        return ans;
    }
    vector<long long > prevGreat(vector<int>& arr) {
        vector<long long > ans(arr.size());
        stack<long long> st;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                st.pop();
            }

            if (!st.empty()) ans[i] = st.top();
            else ans[i] = -1;

            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<long long> nse = nextSmaller(nums);
        vector<long long> pse = prevSmaller(nums);
        vector<long long> nge = nextGreat(nums);
        vector<long long> pge = prevGreat(nums);

        long long sumMin = 0, sumMax = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sumMin += (long long)nums[i] * (i - pse[i]) * (nse[i] - i);
            sumMax += (long long)nums[i] * (i - pge[i]) * (nge[i] - i);
        }

        return sumMax - sumMin;
    }
};

int main() {
    Solution obj;
    vector<int> nums = { 4,-2,-3,4,1 };
    cout << obj.subArrayRanges(nums);
    return 0;
}