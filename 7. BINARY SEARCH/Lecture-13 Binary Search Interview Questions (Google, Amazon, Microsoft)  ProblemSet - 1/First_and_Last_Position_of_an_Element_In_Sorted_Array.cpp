/*
#FIRST AND LAST POSITION OF AN ELEMENT IN SORTED ARRAY - CODE STUDIO

=> PROBLEM STATEMENT
    You have been given a sorted array/list consisting of 'n' elements. You are also given a integer "K".

    Now, your task is to find the first and last occurance of 'k' in 'arr'.

    Given:- 'arr' = [0, 1, 1, 5] , 'k' = 1
    Output:- 1 2

=> Constraints:
1 <= n <= 10^5
0 <= k <= 10^9
0 <= arr[i] <= 10^9

Time Limit : 1 second
 */
int firstocc(int arr[], int n, int key){
    int left = 0; int right = n-1;
    int mid = left + (right - left)/2;
    int ans = -1;
    while(left<=right){
        if(arr[mid]==key){
            ans = mid;
            right = mid-1;
        }
        else if(arr[mid]<key){
            left = mid+1;
        }
        else if(arr[mid]>key){
            right = mid-1;
        }
        mid = left + (right-left)/2;
    }
    return ans;
}

int lastocc(int arr[], int n, int key){
    int left = 0; int right = n-1;
    int mid = left + (right - left)/2;
    int ans = -1;
    while(left<=right){
        if(arr[mid]==key){
            ans = mid;
            left = mid+1;
        }
        else if(arr[mid]<key){
            left = mid+1;
        }
        else if(arr[mid]>key){
            right = mid-1;
        }
        mid = left + (right-left)/2;
    }
    return ans;
}

#include<iostream>
using namespace std;

int main(){

    int arr[8] = {0, 1, 1, 1, 1, 1, 9, 10};

    cout<<"first occurance of 1 is:- "<<firstocc(arr, 8, 1)<<endl;
    cout<<"last occurance of 1 is:- "<<lastocc(arr, 8, 1)<<endl;

    return 0;
}