/*
#NUMBER OF ISLANDS

LINK:- https://leetcode.com/problems/number-of-islands/description/
*/

#include<bits/stdc++.h>
using namespace std;

//SIMPLE SOLUTION OF CONNECTED COMPONENT, WE CAN DO THE SAME WITHOUT TAKING ANY VISITED MATRIX
class Solution {
    int row, col;
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y) {
        visited[x][y] = 1;
        queue<pair<int, int>> q;
        q.push({ x,y });

        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, 1, 0, -1 };

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int it = 0; it < 4; it++) {
                int nx = i + dx[it];
                int ny = j + dy[it];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && visited[nx][ny] == -1 && grid[nx][ny] == '1') {
                    visited[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, -1));
        int island = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && visited[i][j] == -1) {
                    island++;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return island;
    }
};

//OPTIMAL SOLUTION
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = 0;

        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0;i < grid.size();i++) {
            for (int j = 0;j < grid[0].size();j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}