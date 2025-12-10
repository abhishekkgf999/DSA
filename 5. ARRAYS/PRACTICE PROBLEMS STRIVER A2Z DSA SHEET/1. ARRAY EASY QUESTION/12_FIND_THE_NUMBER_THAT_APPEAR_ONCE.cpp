/*
#FIND THE NUMBER THAT APPEAR ONCE IN AN ARRAY

LINK:- https://leetcode.com/problems/single-number/
*/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans = ans^nums[i];
    }        

    return ans;
}

int main(){
    vector<int> arr = {4,1,2,1,2};
    cout<<"The which is appearing once in given arary is:- "<<singleNumber(arr);
    return 0;
}