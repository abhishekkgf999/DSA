/*
#SEARCH IN A 2D MATRIX-II
LINK:- https://leetcode.com/problems/search-a-2d-matrix-ii/

Search from the top-right element and reduce the search space by one row or column at each time.

[[ 1,  4,  7, 11, 15],
 [ 2,  5,  8, 12, 19], 
 [ 3,  6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]]

Suppose we want to search for 12 in the above matrix. compare 12 with the top-right element nums[0][4] = 15. 
Since 12 < 15, 12 cannot appear in the column of 15 since all elements in that column are greater than or equal to 15. 
Now we reduce the search space by one column (the last column).

We further compare 12 with the top-right element of the remaining matrix, which is nums[0][3] = 11. 
Since 12 > 11, 12 cannot appear in the row of 11 since all elements in this row are less than or equal 
to 11 (the last column has been discarded). Now we reduce the search space by one row (the first row).

We move on to compare 12 with the top-right element of the remaining matrix, which is nums[1][3] = 12. 
Since it is equal to 12, we return true.
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;
    while (rowIndex < row && colIndex >= 0)
    {
        int search = matrix[rowIndex][colIndex];
        if (search == target)
            return 1;
        else if (target > search)
            rowIndex++;
        else
            colIndex--;
    }
    return 0;
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

    cout<<"Enter target element to search:- "<<endl;
    int target;
    cin>>target;

    if(searchMatrix(arr, target)){
        cout<<target<<" is present in given matrix"<<endl;
    }
    else  cout<<target<<" is not present in given matrix"<<endl;

    return 0;
}