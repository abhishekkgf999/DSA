/*

#SINGLE ELEMENT IN SORTED ARRAY

LINK:- https://leetcode.com/problems/single-element-in-a-sorted-array/description/

*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION -1
int singleNonDuplicate0(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}

//BRUTE FORCE SOLUTION-2 (USING XOR)
int singleNonDuplicate1(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

//OPTIMAL SOLUTION (MY SOLUTION) (USING BINARY SEARCH)
int singleNonDuplicate2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[l] != nums[l+1] && l+1 < n) return nums[l]; 
            if(nums[r] != nums[r-1] && r-1 >=0) return nums[r]; 
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            if(nums[mid] == nums[mid-1]){
                int len = (mid-1) - (l+1) -1;
                if(len%2 == 1){
                    l = l + 2;
                    r = mid-2;
                }
                else{
                    l = mid+1;
                    r = r-2;
                }
            }
            else{
                int len = (mid) - (l+1) -1;
                if(len%2 == 1){
                    l = l+2;
                    r = mid-1;
                }
                else{
                    l = mid + 2;
                    r = r - 2;
                }
            }
        }
        return -1;
}

//OPTIMAL SOLUTION 2
int singleNonDuplicate3(vector<int> nums){

    int n = nums.size();
    if(n == 1) return nums[0];

    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];

    int l = 1, r = n-2;
    while(l<=r){
        int mid = l + (r-l)/2;

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])){
            l = mid+1;
        } 
        else r = mid-1;
    }
    return -1;
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate3(nums);
    return 0;
}