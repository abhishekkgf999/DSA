/*
#ROTATE IMAGE

LINK- https://leetcode.com/problems/rotate-image/description/

 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
 *
 *
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/

#include <bits/stdc++.h>
using namespace std;

// MY SOLUTION (TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(N^2))
void rotate1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int iter = n - 1;

    vector<vector<int>> matrixcopy = matrix;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[j][iter] = matrixcopy[i][j];
        }
        iter--;
    }
}

void rotate2(vector<vector<int>> &matrix)
{
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

void anti_rotate(vector<vector<int>> &matrix)
{
    for (auto vi : matrix)
        reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
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
    }cout<<endl;
    
    rotate2(arr);

    for(int i=0; i<nRows; i++){     
        for(int j=0; j<mCols; j++){    
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}