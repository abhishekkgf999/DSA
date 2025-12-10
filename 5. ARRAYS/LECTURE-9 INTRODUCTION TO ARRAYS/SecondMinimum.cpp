#include<bits/stdc++.h>
using namespace std;

int SecondMini(vector<int> arr){
    int firstsmall = 999;
    int secondsmall = 999;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]<firstsmall){
            secondsmall = firstsmall;
            firstsmall = arr[i];
        }
        else if(arr[i]<secondsmall){
            secondsmall = arr[i];
        }
    }

    return secondsmall;
}

int main(){
    int size;
    cout<<"enter the size of array:- ";
    cin>>size;
    vector<int> arr;
    cout<<"Enter the elements in array:- ";
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }

    cout<<"second smallest in array is:- "<<SecondMini(arr)<<endl;
    return 0;
}