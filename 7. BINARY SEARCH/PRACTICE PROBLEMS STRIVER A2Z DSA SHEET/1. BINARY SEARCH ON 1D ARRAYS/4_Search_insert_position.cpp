/*

#SEARCH INSERT POSITION

LINK:- https://leetcode.com/problems/search-insert-position/description/

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
return the index where it would be if it were inserted in order.

*/

#include<bits/stdc++.h>
using namespace std;

/*

=>  if A[m] < target, then the insertion position should be at least at m + 1, because it can be even 
    larger, i.e. to the right of m + 1(including m + 1), we set l = m + 1;

=>  if A[m] > target, the insertion position should be at most m, because it can even smaller.

*/
int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                ans = mid;
                r = mid-1;
            }
            else{
                ans = mid+1;
                l = mid+1;
            }
        }
        return ans;
    }

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 2;

    cout<<searchInsert(nums, target);
    return 0;
}