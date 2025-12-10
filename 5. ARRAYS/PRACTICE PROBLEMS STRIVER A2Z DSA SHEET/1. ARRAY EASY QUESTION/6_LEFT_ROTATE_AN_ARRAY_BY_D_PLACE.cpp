/*
#Left rotate an array by D places

LINK:- https://www.codingninjas.com/studio/problems/rotate-array_1230543?leftPanelTabValue=SUBMISSION
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N)
vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    vector<int> temp(n);

    for(int i=0; i<n; i++){
        temp[(i-k+n)%n] = arr[i];
    }
   
    return temp;

}


int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    cout<<"Enter steps to shift left"<<endl;
    int k;
    cin>>k;
    vector<int> ans = rotateArray(arr,k);
    for(auto i : ans){
        cout<<i<<" ";
    }
    
    return 0;
}