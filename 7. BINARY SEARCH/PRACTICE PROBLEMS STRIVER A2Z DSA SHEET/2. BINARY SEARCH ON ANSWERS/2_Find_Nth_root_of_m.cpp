/*

#FIND Nth ROOT OF M

LINK:- https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:
Input: n = 2, m = 9
Output: 3
Explanation: 3^2 = 9

Example 2:
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
*/

#include<bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m){
	int l = 1, r = m;
    while (l <= r) {
    int mid = l + (r - l) / 2;
    long long int value = 1;
        
    for (int i = 0; i < n; ++i) {
        value *= mid;
        if (value > m) break;  // Stop early if value exceeds m
    }

        if (value == m) return mid;
        else if (value > m) r = mid - 1;
        else l = mid + 1;
    }
    return -1;  // If no exact root is found
}

int main(){
    cout<<NthRoot(2, 9);
    return 0;
}