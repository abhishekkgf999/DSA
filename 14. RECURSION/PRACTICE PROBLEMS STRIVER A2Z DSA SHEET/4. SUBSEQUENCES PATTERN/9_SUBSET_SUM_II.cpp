/*
#SUBSET SUM II

LINK:- https://leetcode.com/problems/subsets-ii/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int index, vector<int> temp, set<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.insert(temp);
        return;
    }

    //EXCLUDE
    solve(nums, index + 1, temp, ans);

    //INCLUDE
    temp.push_back(nums[index]);
    solve(nums, index + 1, temp, ans);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    vector<int> temp;
    solve(nums, 0, temp, ans);
    return vector<vector<int>>(ans.begin(), ans.end());
}

class Solution {
public:
    void backtrack(int ind, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        ans.push_back(subset);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1])continue;
            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset, ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, subset, ans);
        return ans;
    }
};

int main() {
    vector<int> arr = { 1,2,2 };
    vector<vector<int>> ans = subsetsWithDup(arr);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}