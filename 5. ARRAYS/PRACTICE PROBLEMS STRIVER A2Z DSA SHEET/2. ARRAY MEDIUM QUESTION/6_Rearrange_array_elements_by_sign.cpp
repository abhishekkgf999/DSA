/*
#REARRANGE ARRAY ELEMENTS BY SIGN

LINK:- https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N)
vector<int> rearrangeArray0(vector<int>& nums) {
    int n = nums.size();
    vector<int> positive;
    vector<int> negative;
    for(auto i : nums){
        if(i>0){
            positive.push_back(i);
        }
        else{
            negative.push_back(i);
        }
    }

    vector<int> ans;
    for(int i =0; i<(n/2); i++){
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }

    return ans;
}



int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> ans = rearrangeArray0(nums);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}