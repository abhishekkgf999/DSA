/*
#SPIRAL PRINT :- Given an m x n matrix, return all elements of the matrix in spiral order.

LINK:- https://leetcode.com/problems/spiral-matrix/description/

1 -> 2 -> 3
          |
          v
4 -> 5    6     ==> EXAMPLE OF SPIRAL MATRIX
^         |
|         v
7 <- 8 <- 9
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>> mat) {
 
  // Define ans array to store the result.
  vector<int> ans;
 
  int n = mat.size(); // no. of nows
  int m = mat[0].size(); // no. of columns
  
  // Initialize the pointers reqd for g traversal.
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
      
    // For moving left to right
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);

    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);

    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);

      left++;
    }
  }
  return ans;
}

int main()
{
    cout<<"Enter the number of rows and columns:- ";
    int nRows, mCols;
    cin>>nRows>>mCols;

    vector<vector<int>> arr(nRows, vector<int>(mCols));
    cout<<"Enter the elements of matrix:- ";
    for(int i=0; i<nRows; i++){
        for(int j=0; j<mCols; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<nRows; i++){     
        for(int j=0; j<mCols; j++){    
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> ans = printSpiral(arr);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}