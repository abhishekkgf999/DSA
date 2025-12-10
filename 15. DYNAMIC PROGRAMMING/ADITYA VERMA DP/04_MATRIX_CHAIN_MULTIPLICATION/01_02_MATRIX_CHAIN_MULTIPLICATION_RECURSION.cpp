/*
# MATRIX CHAIN MULTIPLICATION (MCM) RECURSION

LINK:- https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

/*
# MATRIX CHAIN MULTIPLICATION (MCM) RECURSION

1. FIND "i" and "j"

2. FIND RIGHT BASE CASE

3. MOVE "k" --> "i" to "j"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int i, int j) {
        if (i >= j) return 0;

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, temp_ans);
        }
        return ans;
    }
    int matrixMultiplication(vector<int>& arr) {
        // code here
        return solve(arr, 1, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = { 2, 1, 3, 4 };
    Solution obj;
    cout << obj.matrixMultiplication(arr);
    return 0;
}
