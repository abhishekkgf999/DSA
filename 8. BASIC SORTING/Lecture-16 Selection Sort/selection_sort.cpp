#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector <int> &arr, int n){
    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int j = i+1; j<n ; j++){
            if(arr[j]<arr[min_index]) min_index = j;
        }
    swap(arr[i], arr[min_index]);
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

