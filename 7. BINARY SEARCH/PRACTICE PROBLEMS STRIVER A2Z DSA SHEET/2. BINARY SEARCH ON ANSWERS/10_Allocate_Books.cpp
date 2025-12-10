/*

#ALLOCATE BOOKS

LINK:- https://www.naukri.com/code360/problems/allocate-books_1090540
*/


#include<bits/stdc++.h>
using namespace std;

bool count_students(vector<int> arr, int n, int m, int pages){
    int stu_count = 0;
    int pages_count = 0;
    for(int i = 0; i<n; i++){
        if(pages_count + arr[i] <= pages){
            pages_count += arr[i];
        }
        else{
            stu_count++;
            if(stu_count > m ) return false;
            pages_count = arr[i];
        }
    }

    return true;
}

int findPages_linearSearch(vector<int>& arr, int n, int m) {
    if(n<m) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for(int i = low; i<=high; i++){
        if(count_students(arr, n, m, i)){
            return i;
        }
    }
    return n;
}

int findPages_binarySearch(vector<int>& arr, int n, int m) {
    if(n<m) return -1;
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    while(l<=r){
        int mid = l + (r-l)/2;
        if(count_students(arr,n,m,mid)){
            r = mid-1;
        }
        else l = mid+1;
    }
    return l;
}

int main(){
    vector<int> arr = {25,46,28,49,24};
    // cout<<findPages_linearSearch(arr, arr.size(), 4);
    cout<<findPages_binarySearch(arr, arr.size(), 4);
    return 0;
}