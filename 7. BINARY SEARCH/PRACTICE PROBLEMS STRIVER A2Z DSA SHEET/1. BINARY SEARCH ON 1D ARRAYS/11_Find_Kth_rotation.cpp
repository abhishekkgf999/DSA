/*

#FIND OUT HOW MANY TIMES HAS AN ARRAY BEEN ROTATED

LINK:- https://www.geeksforgeeks.org/problems/rotation4723/1

*/

#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
        int n = arr.size();
        if(arr[0] < arr[n-1] || n == 1) return 0;

        int l = 0, r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(arr[0] <= arr[mid]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }

int findKRotation2(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr = {5, 1, 2, 3, 4};
    cout<<findKRotation(arr);
    return 0;
}