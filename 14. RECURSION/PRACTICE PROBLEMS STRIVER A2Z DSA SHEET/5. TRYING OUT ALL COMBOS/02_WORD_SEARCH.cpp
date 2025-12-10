/*
#WORD SEARCH

LINK:- https://leetcode.com/problems/word-search/
*/

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY :- O(4^(L)*N*M), WHERE L IS THE WORD LENGTH
class Solution_My_Solution {
public:
    /*
    1. VISITED MATRIX
    2. 4 DIRECTIONS
    3. MARKING VISITED MATRIX 0->1
    4. OUT OF COORDINATES CHECK
    5. BASE CONDITION (IF(TEMP.SIZE() == WORD.SIZE()) RETURN TEMP == WORD)
    6. ONCE COVER ALL DIRECTION, BACKTRACK THE VISITED MATRIX BY MARKING IT AGAIN 0, AND ALSO, WHILE TRYING EACH DIRECTION, BACKTRACK CHARACTER AS WELL WHICH IS ADDED TO TEMP STRING WHILE MOVING IN PARTICULAR DIRECTION
    7. WE CAN HAVE MULTIPLE STARTING POSTION, SO TRY FOR EACH STARTING POSITION, WHICH IS POSSIBLE IN MATRIX
    */
    bool valid(int x, int y, vector<vector<int>>& visited, int rows, int cols) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] == 1)return false;
        return true;
    }
    void solve(vector<vector<char>>& board, string word, string& temp, vector<vector<int>>& visited, int start, int end, int rows, int cols, bool& ans) {
        if (ans) return;
        if (temp.size() == word.size()) {
            ans = true;
            return;
        }

        visited[start][end] = 1;

        //UP
        if (valid(start - 1, end, visited, rows, cols) && board[start - 1][end] == word[temp.size()]) {
            temp.push_back(board[start - 1][end]);
            solve(board, word, temp, visited, start - 1, end, rows, cols, ans);
            temp.pop_back();
        }

        //RIGHT
        if (valid(start, end + 1, visited, rows, cols) && board[start][end + 1] == word[temp.size()]) {
            temp.push_back(board[start][end + 1]);
            solve(board, word, temp, visited, start, end + 1, rows, cols, ans);
            temp.pop_back();
        }

        //DOWN
        if (valid(start + 1, end, visited, rows, cols) && board[start + 1][end] == word[temp.size()]) {
            temp.push_back(board[start + 1][end]);
            solve(board, word, temp, visited, start + 1, end, rows, cols, ans);
            temp.pop_back();
        }

        //LEFT
        if (valid(start, end - 1, visited, rows, cols) && board[start][end - 1] == word[temp.size()]) {
            temp.push_back(board[start][end - 1]);
            solve(board, word, temp, visited, start, end - 1, rows, cols, ans);
            temp.pop_back();
        }

        visited[start][end] = 0;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        bool ans = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                string temp = "";
                temp.push_back(board[i][j]);
                if (temp[0] != word[0]) continue;
                solve(board, word, temp, visited, i, j, rows, cols, ans);
                if (ans == true) return ans;
            }
        }

        return ans;
    }
};

//OPTMAL SOLUTION
class Solution {
public:
    vector<vector<int>> directions{ {1,0}, {-1, 0}, {0, 1}, {0, -1} };
    bool find(int i, int j, string word, int idx, vector<vector<char>>& board, int m, int n) {
        if (idx == word.length()) return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
            return false;
        }

        if (board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(new_i, new_j, word, idx + 1, board, m, n)) {
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(i, j, word, 0, board, m, n)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    string word = "ABCCED";
    cout << obj.exist(board, word);
    return 0;
}