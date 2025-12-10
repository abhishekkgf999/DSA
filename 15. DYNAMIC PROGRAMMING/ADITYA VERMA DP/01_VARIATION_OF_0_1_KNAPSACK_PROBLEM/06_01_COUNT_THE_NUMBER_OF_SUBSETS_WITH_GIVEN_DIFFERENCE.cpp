
#include<bits/stdc++.h>
using namespace std;


/*
=> PROBLEM STATEMENT => SUM[S1] - SUM[S2] = DIFF;   --> eq(1)

=> ALSO, WE KNOW THAT => SUM[S1] + SUM[S2] = SUM[ARR];   --> eq(2)   

=> ADD BOTH EQUATIONS, WE GET 2*SUM[S1] = DIFF + SUM[ARR];

=> SUM[S1] = (DIFF + SUM[ARR])/2;

*/

int solve(vector<int> &arr, int start, int sum, int required){
    if(start == arr.size()){
        if(sum == required)return 1;
        return 0;
    }

    return solve(arr, start+1, sum+arr[start], required) + solve(arr, start+1, sum, required);
}

int minDifference(vector<int>& arr, int target) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int required = (target + total_sum)/2;
    return solve(arr, 0, 0, required);
}

int main(){
    vector<int> arr = {1, 1, 2, 3};
    // vector<int> arr2= {-36, 36};
    cout<<minDifference(arr, 1);
    return 0;
}