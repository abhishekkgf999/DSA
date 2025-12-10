/*
#SUBSET SUM PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


**NOTE**

=> KNAPSACK PATTERN :- EITHER WE TAKE PARTICULAR NUMBER OR NOT, IF WE ARE TAKING THEN WE JUST SUBTRACTING FORM OUR SUM, AND MOVE TO NEXT ELEMENT
                    :- IF NOT, THEN SIMPLY MOVE NEXT

=> BASE CONDITION :- IF(SUM == 0) THEN RETURN TRUE;
                     IF(SUM < 0 || OUT OF BOUND) RETURN FALSE;

*/

#include<bits/stdc++.h>
using namespace std;

//METHOD 1 (DONE THROUGH, BY TAKING ELEMENT FROM STARTING)
//TIME COMPLEXITY :- O(2^N), N IS THE SIZE OF ELEMENT ARRAY
//SPACE COMPLEXITY :- O(N) DUE TO RECURSIVE STACK DEPTH
bool solve(vector<int>& arr, int sum, int i) {
    if (sum == 0) {
        return true;
    }

    if (i == arr.size() || sum < 0) {
        return false;
    }

    return solve(arr, sum - arr[i], i + 1) || solve(arr, sum, i + 1);
}
bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int i = 0;
    return solve(arr, sum, i);
}

//METHOD 2 (DONE THROUGH BY TAKING ELEMENT FROM END)
bool solve2(vector<int>& arr, int sum, int n) {
    if (sum == 0) {
        return true;
    }

    if (n == 0 || sum < 0) {
        return false;
    }

    return solve2(arr, sum - arr[n - 1], n - 1) || solve2(arr, sum, n - 1);
}
bool isSubsetSum2(vector<int>& arr, int sum) {
    // code here
    int n = arr.size();
    return solve2(arr, sum, n);
}

int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout<<isSubsetSum(arr, sum)<<endl;
    cout<<isSubsetSum2(arr, sum)<<endl;
    return 0;
}