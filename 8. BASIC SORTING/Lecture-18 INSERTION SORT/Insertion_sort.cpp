#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    vector<int> arr;
    int element, n;
    cout<<"Enter the number of elements to be entered "<<endl;
    cin>>n;
    cout<<"Enter the elements in array:- ";
    for(int i = 0; i<n; i++){
        cin>>element;
        arr.push_back(element);
    }cout<<endl;

    insertionSort( n, arr);
    cout<<"elements after isertion sort are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr.at(i)<<" ";
    }cout<<endl;

    return 0;
}