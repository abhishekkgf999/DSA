/*
link: -https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

we have to find largest element in an array
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY WILL BE:- O(N), SPACE COMPLEXITY WILL BE:- O(1)
int largestElement(vector<int> &arr, int n) {
     int max = INT_MIN;
     for(auto i : arr){
         if(i>max) max = i;
         }
    return max;
}

int main(){
    vector<int> arr;
    cout<<"Enter the size of array:- ";
    int size;
    cin>>size;
    cout<<"Enter the elements in array:- ";
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    cout<<"maximum element in an array:- "<<largestElement(arr, size);
    return 0;
}