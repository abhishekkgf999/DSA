#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, vector<int>& ans, int& sum, int index) {
    if (index == nums.size()) {
        ans.push_back(sum);
        return;
    }


    // Exclude
    solve(nums, ans, sum, index + 1);

    //include
    sum += nums[index];
    solve(nums, ans, sum, index + 1);
    sum -= nums[index]; //revert changes    
}
vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;
    int sum = 0, index = 0;
    solve(nums, ans, sum, index);
    return ans;
}

int main(){
    vector<int> arr = {2,3};
    vector<int> ans = subsetSums(arr);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}