/*
#PEAK INDEX IN A MOUNTAIN ARRAY  (PROBLEM N0.:- 852 LEETCODE)

--> LINK:- https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

--> An array arr is a mountain if the following properties hold:

=> arr.length >= 3
=> There exists some i with 0 < i < arr.length - 1 such that:
=> arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
=> arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

=> Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

=>Constraints:

* 3 <= arr.length <= 10^5
* 0 <= arr[i] <= 10^6
* arr is guaranteed to be a mountain array.

*/
#include<bits/stdc++.h>
using namespace std;

//# babbar approach
class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        int mid = left + (right-left)/2;
        while(left<right){
            if(arr[mid]<arr[mid+1]){
                left = mid+1;
            }
            else{
                right = mid;
            }
            mid = left + (right-left)/2;
        }
        return right;
    }
};

//# strivers approach
class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int l = arr.size();
       if(l==1 || arr[0]>arr[1]){return 0;}
       if(arr[l-1]>arr[l-2]){return l-1;}
       int left = 1, right = l-1;
       int mid = left + (right-left)/2;
       while(left<=right){
       if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
           return mid;
       }
       else if(arr[mid]>arr[mid-1]){
           left = mid+1;
       }
       else if(arr[mid]>arr[mid+1]){
           right = mid-1;
       }
       mid = left + (right-left)/2;
       }
        
       return mid;
    }
};