/*
#MAXIMUM CONSECTUIVE ONES

Link:- https://leetcode.com/problems/max-consecutive-ones/
*/

#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n)
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int maxcount = 0;
    for(int i=0; i<n; i++){
        if(nums[i] == 0) count =0;
        else{
            count++;
        }

        if(count>maxcount) maxcount = count;
    }

    return maxcount;
}

int main(){
    vector<int> arr = {0};

    cout<<"maximum consecutive ones in given array is:- "<<findMaxConsecutiveOnes(arr);
    return 0;
}