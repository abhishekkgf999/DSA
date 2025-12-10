/*

#SPLIT ARRAY LARGEST SUM

LINK:- https://leetcode.com/problems/split-array-largest-sum/description/
*/


#include<bits/stdc++.h>
using namespace std;

int count_subarray(vector<int> nums, int k, int value){
    int count = 1;
    int last_sum = 0;
    for(int i =0; i<nums.size(); i++){
        if(last_sum + nums[i] <= value){
            last_sum += nums[i];
        }
        else{
            count++;
            last_sum = nums[i];
        }
    }
    return count;
}

int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while(l<=r){
            int mid = l + (r-l)/2;
            if(count_subarray(nums, k, mid) <= k){
                r = mid-1;
            }
            else l = mid+1;
        }
        return l;
    }

int main(){
    // vector<int> nums = {7,2,5,10,8};
    // int k = 2;
    // vector<int> nums = {1,2,3,4,5};
    // int k = 2;
    // vector<int> nums = {2,3,1,2,4,3};
    // int k = 5;
    vector<int> nums = {1,4,4};
    int k = 3;

    cout<<splitArray(nums, k);
    return 0;
}