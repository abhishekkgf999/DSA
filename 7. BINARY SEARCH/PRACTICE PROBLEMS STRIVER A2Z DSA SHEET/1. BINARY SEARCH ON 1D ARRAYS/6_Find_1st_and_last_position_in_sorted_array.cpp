/*

#FIND FIRST AND LAST POSITION IN SORTED ARRAY

LINK:- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

*/

#include<bits/stdc++.h>
using namespace std;

int firstPosi(vector<int> nums, int n, int target){
    int ans = -1;
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(nums[mid] == target){
            ans = mid;
            r = mid-1;
        }
        else if(nums[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int lastPosi(vector<int> nums, int n, int target){
    int ans = -1;
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(nums[mid] == target){
            ans = mid;
            l = mid+1;
        }
        else if(nums[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {firstPosi(nums, n, target), lastPosi(nums, n, target)};
    }

int main(){
    vector<int> nums = {5,7,7,8,8,10};  
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}