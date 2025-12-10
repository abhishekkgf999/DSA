/*
                            ***Mark for revision***

#LONGEST CONSECUTIVE SEQUENCE

LINK:- https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(1)
bool search_ele(vector<int> &nums, int ele){
    for(auto i : nums){
        if(i == ele) return true;
    }
    return false;
}
int longestConsecutive1(vector<int>& nums) {
    int n = nums.size();
    int max_length = 0;
    for(int i =0; i<n; i++){
        int count = 1;
        int ele = nums[i]+1;
        while(search_ele(nums, ele)){
            ele++;
            count++;
        }
        max_length = max(count, max_length);
    }

    return max_length;
}


//BETTER SOLUTION
//TIME COMPLEXITY:- O(nlogn)+O(n), SPACE COMPLEXITY:- O(1)
int longestConsecutive2(vector<int>& nums) {
    if(nums.size() <=1) return nums.size();
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int max_count = 1;
    int count = 1;
    for(int i = 1; i<n; i++){
        if(nums[i] == nums[i-1]){
            continue;
        }
        else if(nums[i] == (nums[i-1]+1)){
            count++;
        }
        else{
            max_count = max(count, max_count);
            count = 1;
        }
    }
    return max(max_count, count);
}

//BETTER SOLUTION (BUT IN ANOTHER WAY)
//TIME COMPLEXITY:- O(nlogn)+O(n), SPACE COMPLEXITY:- O(1)
int longestConsecutive3(vector<int> &nums){
    int n = nums.size();
    if(n<=1) return n;
    sort(nums.begin(), nums.end());
    int last_ele = INT32_MIN;
    int max_length = 0;
    int count = 0;
    for(int i= 0; i<n; i++){
        if(nums[i]-1 == last_ele){
            count++;
            last_ele = nums[i];
        }
        else if(nums[i] != last_ele){
            count = 1;
            last_ele = nums[i];
        } 
        max_length = max(max_length, count);
    }

    return max_length;
}

//OPTIMAL SOLUTION
//TIME COMPLEXITY:- O(N) + O(2*N) ~ O(3*N); SPACE COMPLEXITY:- O(N)
int longestConsecutive4(vector<int>& nums) {
    unordered_set<int> s;
    for(auto i : nums){
        s.insert(i);
    }
    int maxi = 0;
    for(auto it : s){
        if(s.find(it-1) == s.end()){
            int count = 1;
            int ele = it;
            while(s.find(ele+1) != s.end()){
                ele++;
                count++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}



int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout<<"maximum consecutive numbers are:- "<<longestConsecutive4(nums);
    return 0;
}