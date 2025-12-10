/*

#SEARCH IN A 2D MATRIX

LINK- https://leetcode.com/problems/search-a-2d-matrix/description/

==> n * m matrix convert to an array => matrix[x][y] => a[x * m + y];

==> an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];

we will search using Binary Search, But difference is that the mid index will come as Index stored in memory, we have to find Row no.
and column no. using this mid index:

==> FOR ROW:- mid/col;

==> FOR COL:- mid%col;
*/

#include<bits/stdc++.h>
using namespace std;

//BINARY SEARCH CONSIDERING AS SORTED ARRAY
bool searchMatrix_method1(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row*col-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid/col][mid%col] == target) return true;
            else if(matrix[mid/col][mid%col] > target) r = mid-1;
            else l = mid+1;
        }

        return false;
    }

//SEARCHING FROM EXTREME TOP RIGHT ELEMENT, COMING TOWARDS EXTREME BOTTOM LEFT
bool searchMatrix_method2(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int rowIndex = 0;
        int ColIndex = col-1;
        while(rowIndex < row && ColIndex >=0){
            if(matrix[rowIndex][ColIndex] == target) return 1;
            else if(matrix[rowIndex][ColIndex] < target) rowIndex++;
            else ColIndex--;
        }
        return 0;
    }

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix_method2(matrix, 6);
    return 0;
}