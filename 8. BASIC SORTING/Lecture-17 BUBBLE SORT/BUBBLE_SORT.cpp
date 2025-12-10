#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector <int> &arr, int n){
    int isSorted = 1;
    for(int i = 0; i<n-1 && isSorted; i++){
        isSorted = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
            swap(arr[j], arr[j+1]);
            isSorted = 1;
        }
    }
}

void printArray(vector <int> &arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr;
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    arr.resize(n);
    cout<<"enter the elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    selection_sort(arr, n);
    printArray(arr, n);
    return 0;
}