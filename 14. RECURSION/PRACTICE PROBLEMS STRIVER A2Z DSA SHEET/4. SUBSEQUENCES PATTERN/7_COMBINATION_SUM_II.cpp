/*
#COMBINATION SUM II

LINK:- https://leetcode.com/problems/combination-sum-ii/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& candidates, vector<int>& temp, int target, vector<vector<int>>& ans, int index) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    if (target < 0 || index == candidates.size()) {
        return;
    }

    /*
    When you consider just consider and move forward, but 
    when you do not consider than do not consider any of it's duplicate, 
    how you make sure it -> just Sort the array and skip all adjacent 
    duplicate elements when you do not consider.
    */

    //Loop through candidates starting from 'index' to avoid recursive previous elements
    for (int i = index; i < candidates.size(); i++) {
        
        //not considering the duplicates elements 
        if (i > index && candidates[i] == candidates[i - 1]) continue;

        //choosing the current element 
        temp.push_back(candidates[i]);

        //recursive call with reduced target, ensuring each element is only used once
        solve(candidates, temp, target - candidates[i], ans, i + 1);

        //backtracking to remove last added element and explore further possibilities
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    solve(candidates, temp, target, ans, 0);
    return ans;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(arr, target);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}