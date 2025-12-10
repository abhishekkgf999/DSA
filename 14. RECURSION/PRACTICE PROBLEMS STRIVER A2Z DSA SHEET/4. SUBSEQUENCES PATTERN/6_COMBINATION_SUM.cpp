/*
#COMBINATION SUM

LINK:- https://leetcode.com/problems/combination-sum/description/

*/

#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;

void solve(vector<int> &candidates, vector<int> &temp, int target, vector<vector<int>> &ans, int index){
    if (target == 0){
        if (s.find(temp) == s.end()){
            ans.push_back(temp);
            s.insert(temp);
        }
        return;
    }
    if (target < 0 || index == candidates.size()){
        return;
    }


    //EITHER INCLUDE UNIQUIELY (ONE TIME)
    temp.push_back(candidates[index]);
    solve(candidates, temp, target - candidates[index], ans, index + 1);

    //EITHER INCLUDE IT DUPLICATELY (MULTIPLE TIME)
    solve(candidates, temp, target - candidates[index], ans, index);
    temp.pop_back();

    //OR DONT INCLUDE AT ALL
    solve(candidates, temp, target, ans, index + 1);
}

//MORE EFFICIENT SOLUTION
void solve2(vector<int> &candidates, vector<int> &temp, int target, vector<vector<int>> &ans, int index){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(target<0 || index == candidates.size()){
        return;
    }

    //No need for separate inclusive recursive call, the iterator will automatically manages for both, inclusion, repetition, and exclusion
    for(int i = index; i<candidates.size(); i++){
        temp.push_back(candidates[i]);
        solve2(candidates, temp, target-candidates[i], ans, i);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>> ans;
    vector<int> temp;
    // solve(candidates, temp, target, ans, 0);
    solve2(candidates, temp, target, ans, 0);
    return ans;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr, target);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}