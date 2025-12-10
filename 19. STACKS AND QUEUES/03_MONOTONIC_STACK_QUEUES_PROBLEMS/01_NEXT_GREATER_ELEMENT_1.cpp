/*
#NEXT GREATER ELEMENT 1

LINK:- https://leetcode.com/problems/next-greater-element-i/description/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mpp;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                mpp[nums2[i]] = st.top();
            }
            else if (st.empty()) {
                mpp[nums2[i]] = -1;
            }

            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = mpp[nums1[i]];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = { 4, 1, 2 };
    vector<int> nums2 = { 1, 3, 4, 2 };
    vector<int> result1 = sol.nextGreaterElement(nums1, nums2);

    cout << "Input nums1: {4, 1, 2}" << endl;
    cout << "Input nums2: {1, 3, 4, 2}" << endl;
    cout << "Output: {";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl; // Expected: {-1, 3, -1}
    cout << "---" << endl;

    // Example 2
    vector<int> nums3 = { 2, 4 };
    vector<int> nums4 = { 1, 2, 3, 4 };
    vector<int> result2 = sol.nextGreaterElement(nums3, nums4);

    cout << "Input nums1: {2, 4}" << endl;
    cout << "Input nums2: {1, 2, 3, 4}" << endl;
    cout << "Output: {";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl; // Expected: {3, -1}

    return 0;
}
