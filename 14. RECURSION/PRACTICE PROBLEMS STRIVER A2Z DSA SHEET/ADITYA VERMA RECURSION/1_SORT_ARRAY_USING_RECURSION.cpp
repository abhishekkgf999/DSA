#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> & arr, int temp){

    //BASE CONDITION
    if(arr.size() == 0 || arr[arr.size()-1] <= temp){
        arr.push_back(temp);
        return;
    }

    //INDUCTOIN PROCESS
    int value = arr[arr.size()-1];
    arr.pop_back();

    //HYPOTHESIS
    insert(arr, temp);

    // PUSH BACK THE REMOVED VALUE AFTER RECURSION
    arr.push_back(value);

    return;
}

void sort(vector<int> &arr){
    //BASE CONDITION
    if(arr.size() <= 1) return;


    //HYPOTHESIS
    int temp = arr[arr.size()-1];
    arr.pop_back();
    sort(arr);

    //INDUCTION PROCESS
    insert(arr, temp);
}

int main(){
    vector<int> arr = {0,1,5,2};
    sort(arr);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}