/*
#COUNT SUBARRAY WITH GIVEN SUM

LINK:- https://leetcode.com/problems/subarray-sum-equals-k/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
int subarraySum0(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i =0; i<n; i++){
        long long sum = 0;
        for(int j = i; j<n; j++){
            sum += nums[j];
            if(sum == k ) count++;
        }
    }

    return count;
}

/*
A problem can be solved by two pointers when two pointers come into place to help us reduce the 
total cases we need to consider, such that the corresponding time complexity will reduce too.



*/


//OPTIMAL SOLUTION
//TIME COMPLEXITY:- IF WE USE MAP O(N*log(N)), IF WE USE UNORDERED MAP CASE1:- THERE IS NO COLLISION O(N*1), CASE2:- THERE IS COLLISION O(N*N)
int subarraySum3(vector<int>& nums, int k){
    int count = 0;
    map<long long, int> preSumMap;
    // preSumMap[0]++;   // --> significance of storing zero first:- if we encounter having (rem == 0) twice, we can easily get the subarray count
    long long sum = 0;
    for(int i = 0 ; i<nums.size(); i++){
        sum += nums[i];
        if(sum == k) count++;
        long long rem = sum - k;
        count += preSumMap[rem];
        preSumMap[sum]++;
    }

    return count;
}

int main(){
    vector<int> nums = {3,4,7,-2,2,1,4,2};
    int k = 7;
    // vector<int> nums = {3,-3,1,1,1};
    // int k = 3;
    cout<<"Total sub arrays with sum "<<k<<" is:- "<<subarraySum3(nums, k);
    return 0;
}