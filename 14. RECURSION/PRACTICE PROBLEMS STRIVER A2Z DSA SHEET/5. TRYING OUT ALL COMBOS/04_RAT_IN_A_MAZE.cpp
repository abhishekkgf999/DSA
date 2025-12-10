/*
#RAT IN A MAZE

LINK:- https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1&selectedLang=python3

*/


#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution {
public:
    bool isSafe(int x, int y, int row, int col, vector<vector<int>>& visited, vector<vector<int>>& mat) {
        if ((x >= 0 && x < row) && (y >= 0 && y < col) && visited[x][y] == 0 && mat[x][y] == 1) {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>& mat, int row, int col, vector<vector<int>>& visited, int x, int y, vector<string>& ans, string path) {
        //BASE CASE :- WHEN WE REACH LAST COORDINATE
        if (x == row - 1 && y == col - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        //4 CHOICES :- DOWN LEFT RIGHT UP

        //MOVING DOWN
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, row, col, visited, mat)) {
            path.push_back('D');
            solve(mat, row, col, visited, newx, newy, ans, path);
            path.pop_back();
        }

        //MOVING LEFT
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, row, col, visited, mat)) {
            path.push_back('L');
            solve(mat, row, col, visited, newx, newy, ans, path);
            path.pop_back();
        }

        //MOVING RIGHT
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, row, col, visited, mat)) {
            path.push_back('R');
            solve(mat, row, col, visited, newx, newy, ans, path);
            path.pop_back();
        }

        //MOVING UP
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, row, col, visited, mat)) {
            path.push_back('U');
            solve(mat, row, col, visited, newx, newy, ans, path);
            path.pop_back();
        }


        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        int row = mat.size(), col = mat[0].size();

        //WHEN DESINATION IS NOT REACHABLE
        if (mat[0][0] == 0 || mat[row - 1][col - 1] == 0) return ans;

        //TRACKING VISITED PATH
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int srcx = 0, srcy = 0;
        string path = "";

        solve(mat, row, col, visited, srcx, srcy, ans, path);

        return ans;
    }
};


int main() {
    vector<vector<int>> mat = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    Solution obj;
    vector<string> ans = obj.findPath(mat);
    for (auto i : ans)cout << i << ", ";
    return 0;
}