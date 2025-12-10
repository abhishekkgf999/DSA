/*
#SEARCH IN ROTATED SORTED ARRAY

!!Problem statement:- 
==> You have been given a sorted array 'arr' consisting of 'n' elements. You are also given an integer 'k'.

Now the array is rotated at some pivot point unknown to you.

For example, if arr = [1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be
'arr'  = [7, 8, 1, 3, 5].

Now, your task is to find the index at which 'k' is present in 'arr'.

1. If 'k' is not present in 'arr', then print - 1.
2. There are no duplicate elements present in 'arr'.
3. 'arr' can be rotated only in the right direction.

Ex:- Input 'arr' = [12, 15, 18, 2, 4], 'k' = 2
     Output:- 3


1 <= n <= 10^5
0 <= k <= 10^9
0 <= arr[i] <= 10^9

Time Limit: 1 second
*/

//APPROACH 1(TIME COMPLEXITY :- O(Log N) used binary search);
#include<bits/stdc++.h>
using namespace std;


int getPivot(vector<int>& arr, int n){
    int left = 0, right = n-1;
    int mid = left + (right-left)/2;
    while(left<right){
        if(arr[mid]>=arr[0]){
            left = mid+1;
        }
        else{
            right  = mid;
        }
        mid = left + (right-left)/2;
    }
    return left;
}


int binarySearch(vector<int>& arr, int left, int right, int k){
    
    int mid = left +  (right-left)/2;
    while(left<=right){
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            right  = mid-1;
        }
        else{
            left = mid+1;
        }
        mid = left + (right-left)/2;
    }
    return -1;
}


int search(vector<int>& arr, int n, int k)
{
    
    int p = getPivot(arr, n);
    if(k>=arr[p] && k<=arr[n-1]){
        return binarySearch(arr, p, n-1, k);
    }
    else{
        return binarySearch(arr, 0, p-1, k);
    }
}

int main(){
    
    vector<int> arr = {2, 3, 5, 8};
    cout<<"checking key is present or not "<<search(arr, 4, 3);
    return 0;
}

//#APPROACH 2 BETTER THAN PREVIOUS (TIME COMPLEXITY :- O(Log N) used binary search);
int search(vector<int>& arr, int n, int k)
{
    //Binary search approach
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k)return mid;
        //check for the sorted halfs
        if(arr[low]<=arr[mid]) //-->left sorted condition
        {
            //check element exists in that half or not
            if(k>=arr[low] && k<=arr[mid]) //key exists in left therefore eliminate right
                high=mid-1; //eliminating right
            else 
                low=mid+1; //eliminating left
        }
        else//right sorted conditions
        {
            if(k>=arr[mid] && k<=arr[high])//key exists in right therefore eliminate left
                low=mid+1; //eliminating left
            else
                high=mid-1; //eliminating right
        }
    }
    return -1;
}