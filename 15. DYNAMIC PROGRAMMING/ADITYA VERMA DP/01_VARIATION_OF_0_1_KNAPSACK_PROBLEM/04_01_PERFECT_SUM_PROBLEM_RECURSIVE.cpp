/*
#PERFECT SUM PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1


***SIMILAR TO SUBSET SUM PROBLEM***

=> BUT HERE WE HAVE TO COUNT TOTAL NUMBER OF SUBSET HAVING TARGET SUM

=> IN THIS CODE, THERE IS MINOR CHANGE, WHEN "0" IS PRESNET IN OUR ARRAY, WE HAVE TO ENSURE THAT, FIRST WE TRAVERSE ENTIRE
   ARRAY AND THEN CHECK FOR THE SUBSET SUM EQUAL TO TARGET OR NOT, IF EQUAL THEN INCREASE THE COUNT
*/

#include<bits/stdc++.h>
using namespace std;

//TAKING ELEMENTS FROM BACK
void solve2(vector<int> &arr, int n, int &count, int target) {
    if (n == 0) {
        if (target == 0) count++;
        return;
    }

    // Include current element
    solve2(arr, n-1, count, target - arr[n-1]);

    // Exclude current element
    solve2(arr, n-1, count, target);
}

//TAKING ELEMENTS FROM FRONT
void solve(vector<int>& arr, int start, int& count, int target) {
    if (start == arr.size()) {
        if (target == 0)
            count++;
        return;
    }

    // Include current element
    solve(arr, start + 1, count, target - arr[start]);

    // Exclude current element
    solve(arr, start + 1, count, target);
}

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;
    solve(arr, 0, count, target);

    return count;
}

int main(){
    vector<int> arr = {0, 10, 0};
    int target = 0;
    cout<<perfectSum(arr, target);
    return 0;
}