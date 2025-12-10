/*
#POWER SET

LINK:- https://leetcode.com/problems/subsets/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*
For array [1, 2, 3]:
Binary 000 → subset {}
Binary 001 → subset {3}        (rightmost bit = last element)
Binary 010 → subset {2}
Binary 011 → subset {2, 3}
Binary 100 → subset {1}
Binary 101 → subset {1, 3}
Binary 110 → subset {1, 2}
Binary 111 → subset {1, 2, 3}
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = pow(2, n) - 1;
        vector<vector<int>> ans;
        for (int i = start; i <= end; i++) {
            int num = i;
            if (num == 0)
                ans.push_back({});
            else {
                int count = n - 1;
                vector<int> temp;
                while (num) {
                    if (num & 1) {
                        temp.push_back(nums[count]);
                    }
                    count--;
                    num = num >> 1;
                }
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Example from LeetCode
    vector<int> nums1 = { 1, 2, 3 };
    vector<vector<int>> result1 = sol.subsets(nums1);
    cout << "Subsets of {1, 2, 3} are:" << endl;
    for (const auto& subset : result1) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    // Test Case 2: Empty set
    vector<int> nums2 = {};
    vector<vector<int>> result2 = sol.subsets(nums2);
    cout << "Subsets of {} are:" << endl;
    for (const auto& subset : result2) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    // Test Case 3: Single element set
    vector<int> nums3 = { 0 };
    vector<vector<int>> result3 = sol.subsets(nums3);
    cout << "Subsets of {0} are:" << endl;
    for (const auto& subset : result3) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}