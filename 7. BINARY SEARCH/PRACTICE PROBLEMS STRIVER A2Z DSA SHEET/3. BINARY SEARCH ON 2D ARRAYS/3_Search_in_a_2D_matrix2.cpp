/*

#SEARCH IN A 2D MATRIX 2

LINK:- https://leetcode.com/problems/search-a-2d-matrix-ii/description/
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
    cout<<searchMatrix(matrix, 6);
    return 0;
}