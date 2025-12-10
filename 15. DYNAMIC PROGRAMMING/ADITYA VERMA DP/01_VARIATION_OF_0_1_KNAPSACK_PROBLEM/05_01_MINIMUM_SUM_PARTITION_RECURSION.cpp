/*
#MINIMUM SUM PARTITION

LINK:- https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int start, int sum, int total_sum) {
    if (start == arr.size()) {
        int first = sum;
        int second = total_sum - sum;
        return abs(first - second);
    }

    return min(solve(arr, start + 1, sum + arr[start], total_sum), solve(arr, start + 1, sum, total_sum));
}
int minDifference(vector<int>& arr) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int start = 0, sum = 0;
    return solve(arr, start, sum, total_sum);
}

int main(){
    vector<int> arr = {3, 9, 7, 3};
    // vector<int> arr2= {-36, 36};
    cout<<minDifference(arr);
    return 0;
}