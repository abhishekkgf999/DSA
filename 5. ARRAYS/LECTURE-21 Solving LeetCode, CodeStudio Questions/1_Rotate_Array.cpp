/*
#ROTATE ARRAY

LINK:- https://leetcode.com/problems/rotate-array/description/
*/

#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
    }

void rotate2(vector<int> &nums, int k){
    k = k%nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the size of nums array:- "<<endl;
    cin>>n;
    cout<<"ENter the elements of nums array:- "<<endl;
    for(int i = 0; i<n; i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }cout<<endl;

    cout<<"Enter the number from where to rotate:- "<<endl;
    int k;
    cin>>k;

    rotate2(nums,k );

    cout<<"After rotating :- "<<endl;
    for(int i : nums){
        cout<<i<<" ";
    }cout<<endl;

    
    return 0;
}