/*

#FIND MINIMUM IN ROTATED SORTED ARRAY (SAME AS FINDING PIVOT INDEX)

LINK:- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

*/

#include<bits/stdc++.h>
using namespace std;

//(SAME AS FINDING PIVOT INDEX)
int findMin(vector<int>& nums) {
        
        int n = nums.size();
        if(nums[0] < nums[n-1] || n == 1) return nums[0];

        int l = 0, r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[0] <= nums[mid]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[r];
    }

//
int findMin2(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = INT32_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[l] <= nums[r]){
                ans = min(ans, nums[l]);
                break;
            } 

            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                r = mid-1;
            }
        }
        return ans;
    }


int main(){
    // vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums = {2,1};
    cout<<findMin2(nums);
    return 0;
}