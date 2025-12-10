/*

#COUNT NUMBER OF OCCURENCE

LINK:- https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:
Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: x = 2 occurs 4 times in the given array so the output is 4.

Example 2:
Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: X = 4 is not present in the given array so the output is 0.
*/


#include<bits/stdc++.h>
using namespace std;

int firstPosi(int arr[], int n, int target){
    int ans = -1;
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target){
            ans = mid;
            r = mid-1;
        }
        else if(arr[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int lastPosi(int arr[], int n, int target){
    int ans = -1;
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target){
            ans = mid;
            l = mid+1;
        }
        else if(arr[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int count(int arr[], int n, int x) {
	    int firstocc = firstPosi(arr, n, x);
	    int lastocc = lastPosi(arr, n, x);
        if(firstocc == -1 || lastocc == -1) return 0;
        return lastocc-firstocc+1;
	}

int main(){
    int arr[] = {1, 1, 2, 2, 2, 2, 3};
    int x =2;
    cout<<count(arr, 7, x);
    return 0;
}