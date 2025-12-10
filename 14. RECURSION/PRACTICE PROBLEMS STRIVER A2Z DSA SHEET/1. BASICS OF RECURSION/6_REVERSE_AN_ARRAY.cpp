/*
#REVERSE AN ARRAY

LINK:- https://takeuforward.org/plus/dsa/problems/reverse-an-array
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int start, int end){
    if(start >= end){
        return;
    }

    swap(arr[start], arr[end]);

    solve(arr, start+1, end-1);
}

void reverse(int arr[], int n){
        int start = 0, end = n-1;
        solve(arr, start, end);
    }

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}