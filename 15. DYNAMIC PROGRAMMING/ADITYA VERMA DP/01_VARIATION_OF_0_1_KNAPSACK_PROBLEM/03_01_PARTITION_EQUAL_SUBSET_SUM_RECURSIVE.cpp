/*
#PARTITION EQUAL SUBSET SUM

LINK:- https://leetcode.com/problems/partition-equal-subset-sum/

=> SIMILAR TO SUBSET SUM PROBLEM

**CHANGES**

1. IF THE SUM OF THE TOTAL ARRAY IS ODD, WE CANNOT DIVIDE THE GIVEN ARRAY IN TWO EQUAL SUBSETS (ONLY POSSIBLE FOR EVEN TOTAL SUM)

2. FOR EVEN SUM, IF WE CAN FIND A SUBSET EQUAL TO (TOTAL_SUM/2), THEN IT IS POSSIBLE TO PARTITION THE GIVEN ARRAY IN EQUAL SUBSET
    => ONE HAVING (TOTAL_SUM/2), THEN OTHER SUBSET AUTOMATICALLY CONTAIN (TOTAL_SUM/2)

3. NOW THE PROBLEM REDUCED TO FIND SUBSET HAVING SUM EQUAL TO (TOTAL_SUM/2), WHICH WE ALREADY DID EARLIER.


*/

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int n, int required){
    if(required == 0) return true;

    if(n == 0 || required < 0) return false;

    return solve(nums, n-1, required-nums[n-1]) || solve(nums, n-1, required);
}

bool canPartition(vector<int> &nums){
    int n = nums.size();
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    if(total_sum&1) return false;

    int required = total_sum/2;

    return solve(nums, n, required);
}

int main(){
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums);
    return 0;
}