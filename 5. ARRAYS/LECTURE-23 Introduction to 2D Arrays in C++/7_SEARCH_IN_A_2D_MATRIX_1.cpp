/*
#SEARCH IN A 2D MATRIX-I
LINK:- https://leetcode.com/problems/search-a-2d-matrix/description/

==> n * m matrix convert to an array => matrix[x][y] => a[x * m + y];

==> an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];

we will search using Binary Search, But difference is that the mid index will come as Index stored in memory, we have to find Row no.
and column no. using this mid index:

==> FOR ROW:- mid/col;

==> FOR COL:- mid%col;
*/

#include <bits/stdc++.h>
using namespace std;

// BINARY SEARCH CONSIDERING AS SORTED ARRAY
bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0, e = row * col - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (matrix[mid / col][mid % col] == target)
            return 1;
        else if (matrix[mid / col][mid % col] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return 0;
}

// SEARCHING FROM EXTREME TOP RIGHT ELEMENT, COMING TOWARDS EXTREME BOTTOM LEFT
bool searchMatrix2(vector<vector<int>> &matrix, int target)
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
        else if (search < target)
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

    if(searchMatrix2(arr, target)){
        cout<<target<<" is present in given matrix"<<endl;
    }
    else  cout<<target<<" is not present in given matrix"<<endl;
    
    
    return 0;
}