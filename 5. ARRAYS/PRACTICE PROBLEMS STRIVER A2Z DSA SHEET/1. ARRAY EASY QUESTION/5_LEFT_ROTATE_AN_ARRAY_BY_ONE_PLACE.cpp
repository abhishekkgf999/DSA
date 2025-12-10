/*
#Left Rotate an array by one place

link:- https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278
*/
#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N)
vector<int> rotateArray1(vector<int>& arr, int n) {
    vector<int> temp(n);

    for(int i=0; i<n; i++){
        temp[(i-1+n)%n] = arr[i];
    }
   
    return temp;
}

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N)
vector<int> rotateArray2(vector<int>& arr, int n) {
    vector<int> temp(n);
    temp = arr;
    reverse(temp.begin(), temp.end());
    reverse(temp.begin(), temp.begin()+(n-1));
   
    return temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    vector<int> ans = rotateArray1(arr,n);
    for(auto i : ans){
        cout<<i<<" ";
    }


    return 0;
}