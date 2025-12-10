/*
#SORT 0s, 1s & 2s

link:- https://leetcode.com/problems/sort-colors/description/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(NlogN), SPACE COMLPEXITY:- O(1)
void sortColors1(vector<int>& nums) {
      sort(nums.begin(), nums.end());  
}

//TIME COMPLEXITY :- O(N), SPACE COMPLEXITY:- O(1)
void sortColors2(vector<int>& nums) {
    int freq[3] = {0};
    for(auto i : nums){
        freq[i]++;
    }
    int i =0;
    while(freq[0]--){
        nums[i++] = 0;
    }
    while(freq[1]--){
        nums[i++] = 1;
    }
    while(freq[2]--){
        nums[i++] = 2;
    }
}

//TIME COMPLEXITY :- O(N), SPACE COMPLEXITY:- O(1)
void sortColors3(vector<int>& nums) {
      int low = 0, mid = 0, high = nums.size()-1;
      while(mid<=high){
        switch(nums[mid]){
            case 0:
                swap(nums[mid], nums[low]);
                mid++; low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high]);
                mid++; high--;
                break;
        }
      }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    // vector<int> nums = {0,1,1,0,1,1,2,0};
    sortColors3(nums);
    for(int i : nums){
        cout<<i<<" ";
    }
    return 0;
}
