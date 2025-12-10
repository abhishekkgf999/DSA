/*
#SUDOKU SOLVER

LINK :- https://leetcode.com/problems/sudoku-solver/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
Approach: Backtracking - try numbers 1-9 in each empty cell and validate.

Algorithm:
1. Traverse board row by row, column by column (x, y coordinates)
2. Handle boundary: When y reaches 9, move to next row (x++, y=0)
3. Base case: When x reaches 9, entire board is filled → return true
4. Skip filled cells: If board[x][y] != '.', move to next cell
5. For empty cells: Try placing digits '1' to '9'
   - Check if placement is valid using check() function
   - If valid → place digit, recursively solve remaining board
   - If recursive call succeeds → return true
   - If fails → backtrack (restore '.' and try next digit)
6. If no digit works → return false

Validation (check function):
- 3×3 box: Check if digit exists in current 3×3 subgrid
- Row: Check if digit exists in current row
- Column: Check if digit exists in current column
- Must satisfy ALL three constraints

Key Components:
- (x/3)*3, (y/3)*3 → find top-left corner of 3×3 box
- board[x][y] = num → place digit
- board[x][y] = '.' → backtrack (remove digit)

Time: O(9^81) worst case, Space: O(81) recursion depth
*/
class Solution {
public:
    bool check(vector<vector<char>>& board, int x, int y, char n) {
        int startRow = (x / 3) * 3;
        int startCol = (y / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == n) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][y] == n) return false;
        }

        for (int j = 0; j < 9; j++) {
            if (board[x][j] == n) return false;
        }

        return true;
    }
    bool solve(vector<vector<char>>& board, int x, int y) {

        if (y == 9) {
            x++;
            y = 0;
        }

        if (x == 9) {
            return true;
        }

        if (board[x][y] != '.') {
            return solve(board, x, y + 1);
        }

        for (char num = '1'; num <= '9'; num++) {
            if (check(board, x, y, num)) {
                board[x][y] = num;
                if (solve(board, x, y + 1)) {
                    return true;
                }

                board[x][y] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};


int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    obj.solveSudoku(board);
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}