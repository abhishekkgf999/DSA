/*
#MAXIMUM SUBARRAY

LINK:- https://leetcode.com/problems/maximum-subarray/
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(1)
int maxSubArray0(vector<int>& nums) {
    int ans = INT32_MIN;
    for(int i = 0; i<nums.size(); i++){
        long long sum = 0;
        for(int j = i; j<nums.size(); j++){
            sum += nums[j];
            if(sum > ans) ans = sum;
        }
    }
    return ans;
}

//OPTIMAL SOLUTION (KADANE'S ALGORITHM)
//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
//A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a 
//part of the subarray with maximum sum.
//we will iterate the given array with a single loop and while iterating we will add the elements in a sum 
//variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to 
//consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.
int maxSubArray(vector<int> &nums){
     int ans = INT32_MIN;
     int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];
        ans = max(ans, sum);
        if(sum < 0) sum = 0;
    }
    return ans;
}

//FOLLOW UP QUESTION:- Given an integer array arr, find the contiguous subarray (containing at least one number) 
// which has the largest sum and returns its sum and prints the subarray.
int PrintmaxSubArray(vector<int> &nums){
    long long ans = INT32_MIN;
    long long sum = 0;
    int ansStart = -1, ansEnd = -1;
    int start = 0;
    for(int i = 0; i<nums.size(); i++){
        if(sum == 0) start = i;
        sum += nums[i];
        if(sum > ans){
            ans = sum;
            ansStart  = start;
            ansEnd = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }
    for(int i = ansStart; i<=ansEnd; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return ans;
}

int main(){
    vector<int> nums = {5,4,-1,7,8};
    cout<<"Subarray with the largest sum:- "<<PrintmaxSubArray(nums);
    return 0;
}