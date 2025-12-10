/*

#IMPLEMENT UPPER BOUND

LINK:- https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

Examples:

Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.

Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
Output: 8, -1
Explanation: Floor of 10 is 8 but ceil of 10 is not possible.
*/

#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &v, int x) {
        int n = v.size();
        int ans= -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] == x) return v[mid];
            else if(v[mid] < x){
                ans = v[mid];
                l = mid+1;
            } 
            else r = mid-1;
        }
      
      return ans;
    }

int findCeil(vector<int> &v, int x) {
        int n = v.size();
        int ans= -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] == x) return v[mid];
            else if(v[mid] > x){
                ans = v[mid];
                r = mid-1;
            } 
            else l = mid+1;
        }
      
      return ans;
    }

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        return {findFloor(arr,x) , findCeil(arr, x)};
    }

int main(){
    // vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    // int x = 7;
    vector<int> arr = {36, 82, 88, 56, 21, 17, 73, 86};
    int x = 17;

    vector<int> ans = getFloorAndCeil(x, arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}