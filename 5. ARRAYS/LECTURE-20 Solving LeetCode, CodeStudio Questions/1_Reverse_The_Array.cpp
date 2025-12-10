/*
#   Reverse The Array

QUESTION LINK:- https://www.codingninjas.com/studio/problems/reverse-the-array_1262298

*/

#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	
    int start = m+1;
    int end = arr.size () -1;
    while(start<=end){
        swap(arr[start++], arr[end--]);
        }
}

int main(){
    vector<int> arr;
    int element;
    cout<<"Enter the elements in vector:- "<<endl;
    for(int i=0; i<7; i++){
        cin>>element;
        arr.push_back(element);
    }cout<<endl;

    int m;
    cout<<"enter position to reverse:- "<<endl;
    cin>>m;

    reverseArray(arr, m);

    for(int i=0; i<7; i++){
        cout<<arr.at(i)<<" ";
    }cout<<endl;
    
    return 0;
}