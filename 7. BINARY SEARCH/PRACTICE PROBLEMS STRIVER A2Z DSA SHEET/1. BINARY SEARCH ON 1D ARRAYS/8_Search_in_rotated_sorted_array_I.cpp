/*

#SEARCH IN ROTATED SORTED ARRAY I

LINK:- https://leetcode.com/problems/search-in-rotated-sorted-array/description/

*/


#include<bits/stdc++.h>
using namespace std;

//SOLUTION-1 (USING PIVOT INDEX)
int getPivot(vector<int> nums){
    int n = nums.size();
    int l = 0, r = n-1;
    while(l<r){
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[0]){
            l = mid+1;
        }
        else r = mid;
    }
    return r;
}

int binarySearch(vector<int> nums, int left, int right, int target){
    int l = left, r = right;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) r = mid-1;
        else l = mid+1;
    }

    return -1;
}

int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums);
        int ans = -1;
        if(target >= nums[pivot] && target<= nums[n-1]){
            ans = binarySearch(nums, pivot, n-1, target);
        }
        else{
            ans = binarySearch(nums, 0, pivot-1, target);
        }

        return ans;
    }

//SOLUTION 2
bool search2(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            
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
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout<<search(nums, target);
    return 0;
}