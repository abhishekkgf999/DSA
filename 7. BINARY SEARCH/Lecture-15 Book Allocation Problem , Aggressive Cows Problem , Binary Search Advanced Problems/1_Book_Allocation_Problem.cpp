/*
#BOOK ALLOCATION PROBLEM (LINK:- https://www.codingninjas.com/studio/problems/allocate-books_1090540?leftPanelTab=0)

USING BINARY SEARCH
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid){
    int Studentcount = 1;
    int sum = 0;
    for(int i=0; i < n; i++){
        if(sum+arr[i] <= mid){
            sum += arr[i];
        }
        else{
            Studentcount++;
            if(Studentcount > m || arr[i] > mid){
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(n<m){return -1;}
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }

    int s = 0, e = sum;
    int mid;
    int ans = -1;
    while(s<=e){
        mid = s + (e-s)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    int n;
    int m;
    cout<<"enter the number of books "<<endl;
    cin>>n;
    cout<<"Enter the number of students :- "<<endl;
    cin>>m;
    cout<<"Enter the pages of each book:- "<<endl;
    int element;
    for(int i=0; i<n; i++){
        cin>>element;
        arr.push_back(element);
    }

    cout<<"minimum number of pages assigned to a student is:- "<<findPages(arr, n, m)<<endl;
    return 0;
}