/*
#MAJORITY ELEMENT (>n/2 times)

link:- https://leetcode.com/problems/majority-element/description/
*/


#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(1)
int majorityElement(vector<int>& nums) {
      for(int i = 0; i<nums.size(); i++){
        int count = 0;
        for(int j = i; j<nums.size(); j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count > (nums.size()/2)) return nums[i];
      }
      return 0;  
}

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N), IN WORST CASE TIME COMPLEXITY:- O(N^2)
int majorityElement2(vector<int>& nums) {
    int n = nums.size();    
    int k = n/2;
    unordered_map<int, int> mpp; 
    for(int i=0; i<n; i++){
        mpp[nums[i]]++;
    }

    for(auto it : mpp){
        if(it.second > k){
            return it.first;
        }
    }

    return 0;
}

//TIME COMPLEXITY:- O(NlogN), SPACE COMPLEITY:- O(1)
int majorityElement3(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();    
    int k = n/2;
    int count = 1, i =1;
    while(i<n){
        if(nums[i] == nums[i-1]){
            count++; i++;
        }
        else{
            if(count>k) return nums[i-1];
            count = 1;
            i++;
        }
    }
     if (count > k) {
        return nums[i - 1];
    }

    return -1;
}

//TIME COMPLEXITY:- O(NlogN), SPACE COMPLEITY:- O(1)
int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
}

//MOORE'S VOTING ALGORITHM
//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
//DOCUMENTATION LINK:- https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
int majorityElement4(vector<int>& nums) {
    int count = 0;          //for tracking the count of element
    int ele = 0;            //for which element we are counting
    for(int i = 0; i<nums.size(); i++){
        if(count == 0 ){
            ele = nums[i];
            count = 1;
        }
        else if(nums[i] == ele){
            count++;
        }
        else count--;
    }

    int count_ele = 0;

    for(auto i : nums){
        if(i == ele) count_ele++;
    }

    if(count_ele>(nums.size()/2)) return ele;

    return -1;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<"Majority elements in array is:- "<<majorityElement4(nums);
    return 0;
}