/*
#2Sum problem

link:- https://leetcode.com/problems/two-sum/description/
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//TIME COMPLEXITY:- O(N^2), SPCACE COMPLEXITY:- O(1)
vector<int> twoSum(vector<int>& nums, int target) {
     vector<int> ans;
     for(int i=0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        
     } 
     return ans;  
}

//BETTER SOLUTION (USING HASHING) => (TC:- O(N^2) -> in worst case & O(NlogN) -> in best case & SC:- O(N))
vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

//OPTIMAL SOLUTION (TC:- O(nlogn) & SC:- O(1))
vector<int> twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {left, right};
        }
        else if (sum < target) left++;
        else right--;
    }
    return {-1,-1}; 
}

int main(){
    vector<int> nums = {0,-1,1};
    int target = 0;
    vector<int> ans = twoSum(nums, target);

    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}