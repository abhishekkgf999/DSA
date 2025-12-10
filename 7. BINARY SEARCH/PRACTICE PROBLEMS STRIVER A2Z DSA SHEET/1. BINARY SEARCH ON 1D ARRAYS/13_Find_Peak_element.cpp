/*

#FIND PEAK ELEMENT

LINK:- https://leetcode.com/problems/find-peak-element/description/
*/


#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int l = 1, r = n-2;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            //If arr[mid] is the peak:
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            // If we are in the right:
            if(nums[mid] <= nums[mid-1]) r = mid-1;

             // If we are in the left:
            else l = mid+1; 
        }

        return -1;
    }

int main(){
    // vector<int> nums = {1,2,1,3,5,6,4};
    vector<int> nums = {1,2};
    cout<<findPeakElement(nums);
    return 0;
}