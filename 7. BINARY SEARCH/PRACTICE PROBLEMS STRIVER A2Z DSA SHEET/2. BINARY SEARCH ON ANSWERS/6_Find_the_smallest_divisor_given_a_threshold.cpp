/*

#FIND THE SMALLEST DIVISOR GIVEN A THRESHOLD

LINK:- https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
*/


#include<bits/stdc++.h>
using namespace std;

bool findSum(vector<int> nums, int threshold, int divisor){
        int sum = 0;
        for(auto i : nums){
            sum += (i + divisor -1)/divisor;
            if(sum > threshold) return false;
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
       int n = nums.size();
       int l  = 1, r = *max_element(nums.begin(), nums.end());
       int ans = -1;
       while(l<=r){
        int mid = l + (r-l)/2;
        if(findSum(nums, threshold, mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
       }
       return ans; 
    }

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout<<smallestDivisor(nums, threshold);
    return 0;
}