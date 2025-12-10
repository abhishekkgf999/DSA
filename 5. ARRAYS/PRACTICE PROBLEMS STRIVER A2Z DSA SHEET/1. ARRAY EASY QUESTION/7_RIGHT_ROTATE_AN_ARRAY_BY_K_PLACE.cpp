/*
#RIGHT ROTATE AN ARRAY BY K PLACE

link:- https://leetcode.com/problems/rotate-array/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[(i+k)%n] = nums[i];
        }

        nums = ans;
    }

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
void rotate2(vector<int>& nums, int k) {

        reverse(nums.begin(), nums.end());    
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }

int main(){
     vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    cout<<"Enter steps to shift left"<<endl;
    int k;
    cin>>k;
    rotate1(arr,k);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}