/*
#SET MATRIX ZERO

LINK:- https://leetcode.com/problems/set-matrix-zeroes/
*/

#include<bits/stdc++.h>
using namespace std;


// MY SOLUTION, TIME COMPLEXITY:- O(N^2) AND SPACE COMPLEXITY:- O(M+N)
void setZeroes(vector<vector<int>>& matrix) {
    
    int row = matrix.size();
    int col = matrix[0].size();

    set<int> rows_location;
    set<int> cols_location;
    for(int i =0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(matrix[i][j] == 0){
                rows_location.insert(i);
                cols_location.insert(j);
            }
        }
    }       
    
    for(auto i: rows_location){
        for(int j = 0; j<col; j++){
            matrix[i][j] = 0;
        }
    }

    for(auto j: cols_location){
        for(int i = 0; i<row; i++){
            matrix[i][j] = 0;
        }
    }
        
}   

// BRUTE FORCE SOLUTION (TC :- O(N*M[N+M]), SC :- O(N*M))
/*
=> In this brute force solution we just try to solve the given problem, 
   irrespective of the time complexity and space complexity constraints.

=> In this solution we just create a temporary matrix having the same values
   as given matrix. 

=> Now, we iterate over each element and there is 2 condition may arise:-
   -> i) that element is zero :-
        => Then we just make that element position in temporary matrix zero.

   -> ii) that element is not zero :- 
        => we just check that the current element row and column contains any 
           zero or not.

        => If zero is present either in row or column, then we just make that 
           element position in temporary array is zero.

          
=> At last we just copy the temporary matrix in original matrix.
*/
bool foundzeroRow(vector<vector<int>> &matrix, int row){
    for(int i = 0; i<matrix[0].size(); i++){
        if(matrix[row][i] == 0){
            return true;
        }
    }
    return false;
}

bool foundzeroCol(vector<vector<int>> &matrix, int col){
    for(int i = 0; i<matrix.size(); i++){
        if(matrix[i][col] == 0){
            return true;
        }
    }
    return false;
}

void setZeroes1(vector<vector<int>> &matrix){

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> temp = matrix;

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(matrix[i][j] == 0){
                temp[i][j] = 0;
            }
            else if(foundzeroRow(matrix, i) || foundzeroCol(matrix, j)){
                temp[i][j] = 0;
            }        
        }
    }

    matrix = temp;
}


//LITTLE OPTIMIZATION (TC :- O(N*M), SC:- O(N+M))
/*
=> In the above brute force solution we came with TC:- O(N*M[N+M])

=> Now we try to optimize Time complexity in this solution.

=> In this solution we will store the states of presence of zeroes, present in 
   rows and columns in a separate boolean array, which tells us the presence of  
   zero is there or not, through its index values.

=> Index will represent row/column number and the value present at that index 
   (true/false) tells the presence of zero in that entire row/column.

=> Using these values, we will replace the values in that particular column/row
   with zeros.
*/
void setZeroes2(vector<vector<int>> &matrix){

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<bool> row_state(rows, false);
    vector<bool> col_state(cols, false);

    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(matrix[i][j] == 0){
                row_state[i] = true;
                col_state[j] = true;
            }
        }
    }

    for(int i =0; i<row_state.size(); i++){
        if(row_state[i]){
            for(int j =0; j<cols; j++){
                matrix[i][j] = 0;
            }
        }
    }  

    for(int i =0; i<col_state.size(); i++){
        if(col_state[i]){
            for(int j =0; j<rows; j++){
                matrix[j][i] = 0;
            }
        }
    }  
}

//OPTIMIZE SOLUTION (TC:- O(N*M), SC :- O(1))
/*
=> In the above solution, we optimized TC through O(N*M[N+M]) to O(N*M)

=> Now we try to optimize space complexity

=> In previous solution we need to make separate arrays for "presence_of_zeroes"
   which takes up extra space, Now in this solution we will store that "presence_of_zeroes"
   in the given array itself.

=> We just use 1st row (0th row) and 1st column (0th col) to store that "presence_of_zeroes"

=> "first_row" and "first_col" are boolean variables that track whether the first row or 
    first column should be set entirely to 0 later.

=> First, we iterate through entire array, if that element is zero then we just check
   -> i) Whether that element belongs to 1st row or 1st column.
      => Because at last we need that info to make that changes
      => If yes, then we just make the values of "first_row" and "first_col" bool values
         to true.

   -> ii) And then, we just simply make the values of 0th row and that particular column 
          value zero, and 0th col and that particular row. Which indicates that the 
          particular row or col contain a element with zero value.

=> Second, we again iterate through each element, except for 0th row and col. In this 
   iteration, we just use the "presence_of_zeroes" which we stored in 0th row and col to 
   make the changes in other element. 
 
   It helps us to find that, particular element should be zero or not.

=> At last, we just check that 0th col or row should be zero or not by just checking the 
   boolean valuse of "first_row" and "first_col", if its true, then we just make that enire
   row/col zero accordingly.


--------------------------------------------------------------------------------------------------

#Step-by-Step Explanation:

1. Initialization:

    -> rows and cols store the number of rows and columns in the matrix, respectively.
    -> first_row and first_col are boolean variables that track whether the first row or 
       first column should be set entirely to 0 later.


2. First Pass (Marking Rows and Columns):

    -> The function iterates through each element of the matrix.
    -> If a 0 is found at position (i, j), it marks the entire row i and column j for 
       setting to 0 later:
        => The first cell of the row (matrix[i][0]) is set to 0.
        => The first cell of the column (matrix[0][j]) is set to 0.

    -> Additionally, if the 0 is in the first row or first column, the first_row or 
       first_col flags are set to true.


3. Second Pass (Setting Matrix Cells to Zero):

    -> The function then iterates through the matrix again, starting from the second 
       row and second column (ignoring the first row and first column).
    -> If a cell is not 0, it checks whether its row or column was marked 
       (by checking the first cell of its row or column). If so, it sets that cell to 0.


4. Handle the First Row and First Column:

    -> If the first_row flag is true, it sets all the elements in the first row to 0.
    -> Similarly, if the first_col flag is true, it sets all the elements in the 
       first column to 0.


#Key Points:
=> Marking Strategy: Instead of using extra space (like another matrix or arrays), 
   the function uses the first row and the first column of the matrix to store flags 
   that indicate which rows and columns should be set to 0.

=> Efficiency: This approach only requires two passes through the matrix and uses a 
   constant amount of extra space (for the two boolean flags), making it efficient 
   in terms of both time and space.
*/
void setZeroes3(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();


    bool first_row = false;
    bool first_col = false;

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(matrix[i][j] == 0){
                if(i == 0) first_row = true;
                if(j == 0) first_col = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i<rows; i++){
        for(int j = 1; j<cols; j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(first_row){
        for(int i =0 ;i<cols; i++){
            matrix[0][i] = 0;
        }
    }

    if(first_col){
        for(int i =0 ;i<rows; i++){
            matrix[i][0] = 0;
        }
    }

}


int main(){
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    setZeroes3(matrix);
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0 ; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}