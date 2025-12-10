/*
#COMBINATION SUM III

LINK:- https://leetcode.com/problems/combination-sum-iii/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& ans, vector<int>& temp, int k, int n, int start) {
    if (temp.size() > k)
        return;

    if (temp.size() == k && n == 0) {
        ans.push_back(temp);
    }

    for (int i = start; i <= 9; i++) {
        temp.push_back(i);
        solve(ans, temp, k, n - i, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, temp, k, n, 1);
    return ans;
}

int main() {
    vector<vector<int>> ans = combinationSum3(3, 7);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}