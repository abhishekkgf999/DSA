/*
#N-QUEEN

LINK:- https://leetcode.com/problems/n-queens/description/
*/


#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY :- O(n * n!)
//SPACE COMPLEXITY :- O(N^2 + N*S) S = number of solutions.
/*
N-Queens - Simple Logic:

Problem: Place N queens on N×N chessboard such that no two queens attack each other.

Approach: Backtracking - place queens row by row and check validity.

Algorithm:
1. Place one queen per row - start from row 0, go to row N-1
2. For each row: Try placing queen in each column (0 to N-1)
3. Check if placement is safe using check() function:
   - No queen in same column (check upwards)
   - No queen in left diagonal (check up-left)
   - No queen in right diagonal (check up-right)
4. If safe: Place queen, recursively solve for next row
5. Base case: Placed all N queens → convert board to string format and save solution
6. Backtrack: Remove queen and try next column

Key Components:
- visited[x][j] = 1 → place queen at position (x,j)
- check(visited, x, j) → verify no conflicts with previous queens
- Only check upward directions (since we place row by row)
- visited[x][j] = 0 → backtrack (remove queen)

Why only check upwards: We place queens row by row, so no queens exist in rows below current position.

Time: O(N!) - exponential due to trying all valid placements
Space: O(N²) board + O(N) recursion depth
*/
class Solution {
public:
    bool check(vector<vector<int>>& visited, int x, int y) {
        for (int i = x - 1; i >= 0; i--) {
            if (visited[i][y] == 1) return false;
        }

        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (visited[i][j] == 1) return false;
        }

        for (int i = x - 1, j = y + 1; i >= 0 && j < visited.size(); i--, j++) {
            if (visited[i][j] == 1) return false;
        }

        return true;
    }
    void solve(vector<vector<int>>& visited, vector<vector<string>>& ans, int n, int x) {
        if (x == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string t = "";
                for (int j = 0; j < n; j++) {
                    t += (visited[i][j] ? 'Q' : '.');
                }
                temp.push_back(t);
            }
            ans.push_back(temp);
            return;
        }


        for (int j = 0; j < n; j++) {
            if (check(visited, x, j)) {
                visited[x][j] = 1;
                solve(visited, ans, n, x + 1);
                visited[x][j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(visited, ans, n, 0);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(4);
    for (auto i : ans) {
        for (auto j : i) {
            cout << "[ " << j << " ] ";
        }cout << endl;
    }
    return 0;
}