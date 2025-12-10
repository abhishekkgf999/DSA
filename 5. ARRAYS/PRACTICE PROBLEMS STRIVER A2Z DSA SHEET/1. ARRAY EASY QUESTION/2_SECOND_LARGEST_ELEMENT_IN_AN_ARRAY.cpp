/*
link:- https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

we have to find second largest and second smallest element in an array
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY WILL BE:- O(N), SPACE COMPLEXITY WILL BE:- O(1)
vector<int> getSecondOrderElements(int n, vector<int> arr){
    vector<int> ans(2);
    int large = -9999;
    int s_large = -9999;
    int small = 9999;
    int s_small = 9999;
    for(int i=0; i<n; i++){
        if(arr[i]<small){
            s_small = small;
            small = arr[i];
        }
        else if(arr[i]<s_small){
            s_small = arr[i];
        }
        if(arr[i]>large){
            s_large = large;
            large = arr[i];
        }
    }

    ans.push_back(s_large);
    ans.push_back(s_small);

    return ans;
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
    vector<int> ans = getSecondOrderElements(size, arr);
    cout<<"Second largest element in given array is:- "<<ans[0]<<endl;
    cout<<"Second smallest element in given array is:- "<<ans[1]<<endl;
    return 0;
}