/*
#NEXT SMALLER ELEMENT

LINK:- https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        vector<int> ans(arr.size(), -1);

        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = { 4, 5, 2, 10, 8 };
    vector<int> result1 = sol.nextSmallerEle(arr1);

    cout << "Input: {4, 5, 2, 10, 8}" << endl;
    cout << "Output: {";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl; // Expected: {2, 2, -1, 8, -1}
    cout << "---" << endl;

    // Example 2
    vector<int> arr2 = { 1, 3, 2, 4 };
    vector<int> result2 = sol.nextSmallerEle(arr2);

    cout << "Input: {1, 3, 2, 4}" << endl;
    cout << "Output: {";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl; // Expected: {-1, 2, -1, -1}

    return 0;
}
