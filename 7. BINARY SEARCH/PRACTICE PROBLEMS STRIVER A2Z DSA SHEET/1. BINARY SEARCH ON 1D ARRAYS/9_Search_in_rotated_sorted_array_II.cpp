/*

#SEARCH IN ROTATED SORTED ARRAY II

LINK:- https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

*/


#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target) return true;
            return false;
        }
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;

            //EDGE CASE (WE HAVE TO SIMPLY REMOVE THE LEFT AND RIGHT POINTERS)
            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++, r--;
                continue;
            }

            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target<=nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(target >= nums[mid] && target<=nums[n-1]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return false;
    }

int main(){
    // vector<int> nums = {1,0,1,1,1};
    // int target = 0;
    // vector<int> nums = {2,5,6,0,0,1,2};
    // int target = 3;

    // vector<int> nums = {1,1};
    // int target = 0;

    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int target = 2;

    bool value = search(nums, target);
    cout<<value;
    return 0;
}