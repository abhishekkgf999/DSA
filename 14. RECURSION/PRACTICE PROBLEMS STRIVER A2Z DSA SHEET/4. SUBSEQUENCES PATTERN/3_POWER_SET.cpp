/*
#POWER SET

LINK:- https://leetcode.com/problems/subsets/
*/

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){
    // BASE CASE
    if (index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    output.push_back(nums[index]);  
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}