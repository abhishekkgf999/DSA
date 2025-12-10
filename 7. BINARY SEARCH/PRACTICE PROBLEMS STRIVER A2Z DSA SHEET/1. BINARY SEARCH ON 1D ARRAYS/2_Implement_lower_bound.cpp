/*

#IMPLEMENT LOWER BOUND

LINK:- https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154

Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k 
in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).

Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1".

Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).
*/



#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<long long> &v, long long n, long long x) {

        int ans= -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] == x) return mid;
            else if(v[mid] < x){
                ans = mid;
                l = mid+1;
            } 
            else r = mid-1;
        }
      
      return ans;
    }

int main(){
    
    vector<long long> v = {1,2,8,10,11,12,19};
    long long n = v.size();
    long long x = 5;

    cout<<findFloor(v,n,x);

    return 0;
}