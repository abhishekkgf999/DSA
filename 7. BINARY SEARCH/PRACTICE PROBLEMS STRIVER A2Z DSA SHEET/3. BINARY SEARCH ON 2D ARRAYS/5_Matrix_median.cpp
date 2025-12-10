/*

#MATRIX MEDIAN  (Mark it for revision)

LINK:- https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

*/

#include<bits/stdc++.h>
using namespace std;

int median_bruteforce(vector<vector<int>> &matrix, int R, int C){
        vector<int> temp;

        for(auto i : matrix){
            for(auto j : i){
                temp.push_back(j);
            }
        }

        sort(temp.begin(), temp.end());
        int n = temp.size();

        return temp[n/2];
    }

//OPTIMAL SOLUTION
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int median_optimalSolution(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += upperBound(matrix[i], mid, n);
        }
        if (cnt <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5}, {2,6,9}, {3,6,9}};
    // cout<<median_bruteforce(matrix, 3,3);
    cout<<median_optimalSolution(matrix, 3,3);
    return 0;
}